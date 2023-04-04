# Some SQL Server related tips

<!-- toc -->

- [General](#general)
  * [Displaying statistics for a query](#displaying-statistics-for-a-query)
- [Indexes](#indexes)
  * [Index fragmentation](#index-fragmentation)
  * [Index usage](#index-usage)
  * [Missing indexes from past execution plans](#missing-indexes-from-past-execution-plans)
- [Long running queries](#long-running-queries)
  * [Most consuming queries currently executing](#most-consuming-queries-currently-executing)
  * [Queries with missing indexes with CPU usage and query plan](#queries-with-missing-indexes-with-cpu-usage-and-query-plan)
  * [Executed queries that used most cpu](#executed-queries-that-used-most-cpu)
- [Some references](#some-references)

<!-- tocstop -->

## General

### Displaying statistics for a query

- `SET STATISTICS IO ON` to display IO statistics like logical/phyisical reads/writes a query did
- `SET STATISTICS PROFILE ON` to display the profile information for a query execution (estimate rows/IO/CPU, cost, etc...)
- `SET STATISTICS TIME ON` to display timing statistics IO statistics like parse/compile/execution CPU and elapsed time

## Indexes

### Index fragmentation

```sql
SELECT OBJECT_NAME(IDX.OBJECT_ID) AS Table_Name, 
    IDX.name AS Index_Name, 
    IDXPS.index_type_desc AS Index_Type, 
    IDXPS.avg_fragmentation_in_percent  Fragmentation_Percentage,
    IDXPS.page_count  Page_Count
FROM sys.dm_db_index_physical_stats(DB_ID(), NULL, NULL, NULL, NULL) IDXPS 
    INNER JOIN sys.indexes IDX  
        ON IDX.object_id = IDXPS.object_id  AND IDX.index_id = IDXPS.index_id 
ORDER BY Fragmentation_Percentage DESC
```

### Index usage

```sql
SELECT  DB_NAME() AS DatabaseName
	   ,SCHEMA_NAME(s.schema_id) +'.'+OBJECT_NAME(i.OBJECT_ID) AS TableName
	   ,i.name AS IndexName
	   ,i.type_desc AS IndexType
	   ,ius.user_seeks AS Seeks
	   ,ius.user_scans AS Scans
	   ,ius.user_lookups AS Lookups
	   ,ius.user_updates AS Updates
	   ,CASE WHEN ps.usedpages > ps.pages THEN (ps.usedpages - ps.pages) ELSE 0 
		  END * 8 AS IndexSizeKB
	   ,ius.last_user_seek AS LastSeek
	   ,ius.last_user_scan AS LastScan
	   ,ius.last_user_lookup AS LastLookup
	   ,ius.last_user_update AS LastUpdate
FROM sys.indexes i
INNER JOIN sys.dm_db_index_usage_stats ius ON ius.index_id = i.index_id AND ius.OBJECT_ID = i.OBJECT_ID
INNER JOIN (SELECT sch.name, sch.schema_id, o.OBJECT_ID, o.create_date FROM sys.schemas sch 
			 INNER JOIN sys.objects o ON o.schema_id = sch.schema_id) s ON s.OBJECT_ID = i.OBJECT_ID
LEFT JOIN (SELECT OBJECT_ID, index_id, SUM(used_page_count) AS usedpages,
				    SUM(CASE WHEN (index_id < 2) 
						  THEN (in_row_data_page_count + lob_used_page_count + row_overflow_used_page_count) 
						  ELSE lob_used_page_count + row_overflow_used_page_count 
					   END) AS pages
				FROM sys.dm_db_partition_stats
				GROUP BY object_id, index_id) AS ps ON i.object_id = ps.object_id AND i.index_id = ps.index_id
WHERE OBJECTPROPERTY(i.OBJECT_ID,'IsUserTable') = 1
--optional parameters
AND ius.database_id = DB_ID() --only check indexes in current database
--AND i.type_desc = 'nonclustered' --only check nonclustered indexes
--AND i.is_primary_key = 0 --do not check primary keys
--AND i.is_unique_constraint = 0 --do not check unique constraints
--AND (ius.user_seeks+ius.user_scans+ius.user_lookups) < 1  --only return unused indexes
--AND OBJECT_NAME(i.OBJECT_ID) = 'tableName'--only check indexes on specified table
--AND i.name = 'IX_Your_Index_Name' --only check a specified index
ORDER BY i.name
```

### Missing indexes from past execution plans

```sql
SELECT CONVERT(VARCHAR(30), GETDATE(), 126) AS runtime,
    mig.index_group_handle,
    mid.index_handle,
    CONVERT(DECIMAL(28, 1), migs.avg_total_user_cost * migs.avg_user_impact * (migs.user_seeks + migs.user_scans)) AS improvement_measure,
    'CREATE INDEX missing_index_' + CONVERT(VARCHAR, mig.index_group_handle) + '_' + CONVERT(VARCHAR, mid.index_handle) + ' ON ' + mid.statement + ' (' + ISNULL(mid.equality_columns,
        '') + CASE WHEN mid.equality_columns IS NOT NULL
AND mid.inequality_columns IS NOT NULL THEN ','
ELSE ''
END + ISNULL(mid.inequality_columns,
        '') + ')' + ISNULL(' INCLUDE (' + mid.included_columns + ')',
        '') AS create_index_statement,
    migs.*,
    mid.database_id,
    mid.[object_id]
FROM sys.dm_db_missing_index_groups mig
INNER JOIN sys.dm_db_missing_index_group_stats migs ON migs.group_handle = mig.index_group_handle
INNER JOIN sys.dm_db_missing_index_details mid ON mig.index_handle = mid.index_handle
WHERE CONVERT (DECIMAL (28, 1),
               migs.avg_total_user_cost * migs.avg_user_impact * (migs.user_seeks + migs.user_scans)) > 10
ORDER BY migs.avg_total_user_cost * migs.avg_user_impact * (migs.user_seeks + migs.user_scans) DESC
```

## Long running queries

### Most consuming queries currently executing

```sql
SELECT TOP 100 s.session_id,
           r.status,
           r.cpu_time,
           r.logical_reads,
           r.reads,
           r.writes,
           r.total_elapsed_time / (1000 * 60) 'Elaps M',
           SUBSTRING(st.TEXT, (r.statement_start_offset / 2) + 1,
           ((CASE r.statement_end_offset
                WHEN -1 THEN DATALENGTH(st.TEXT)
                ELSE r.statement_end_offset
            END - r.statement_start_offset) / 2) + 1) AS statement_text,
           COALESCE(QUOTENAME(DB_NAME(st.dbid)) + N'.' + QUOTENAME(OBJECT_SCHEMA_NAME(st.objectid, st.dbid)) 
           + N'.' + QUOTENAME(OBJECT_NAME(st.objectid, st.dbid)), '') AS command_text,
           r.command,
           s.login_name,
           s.host_name,
           s.program_name,
           s.last_request_end_time,
           s.login_time,
           r.open_transaction_count
FROM sys.dm_exec_sessions AS s
JOIN sys.dm_exec_requests AS r ON r.session_id = s.session_id CROSS APPLY sys.Dm_exec_sql_text(r.sql_handle) AS st
WHERE r.session_id != @@SPID
ORDER BY r.cpu_time DESC
```

### Queries with missing indexes with CPU usage and query plan

```sql
SELECT
    qs_cpu.total_worker_time / 1000 AS total_cpu_time_ms,
    q.[text],
    p.query_plan,
    qs_cpu.execution_count,
    q.dbid,
    q.objectid,
    q.encrypted AS text_encrypted
FROM
    (SELECT TOP 20000 qs.plan_handle,
     qs.total_worker_time,
     qs.execution_count FROM sys.dm_exec_query_stats qs ORDER BY qs.total_worker_time DESC) AS qs_cpu
CROSS APPLY sys.dm_exec_sql_text(plan_handle) AS q
CROSS APPLY sys.dm_exec_query_plan(plan_handle) p
WHERE p.query_plan.exist('declare namespace 
        qplan = "http://schemas.microsoft.com/sqlserver/2004/07/showplan";
        //qplan:MissingIndexes')=1
```

### Executed queries that used most cpu 

```sql
SELECT TOP 100 st.text AS batch_text,
    SUBSTRING(st.TEXT, (qs.statement_start_offset / 2) + 1, ((CASE qs.statement_end_offset WHEN - 1 THEN DATALENGTH(st.TEXT) ELSE qs.statement_end_offset END - qs.statement_start_offset) / 2) + 1) AS statement_text,
    (qs.total_worker_time / 1000) / qs.execution_count AS avg_cpu_time_ms,
    (qs.total_elapsed_time / 1000) / qs.execution_count AS avg_elapsed_time_ms,
    qs.total_logical_reads / qs.execution_count AS avg_logical_reads,
    qs.total_logical_writes / qs.execution_count AS avg_logical_writes,
    (qs.total_worker_time / 1000) AS cumulative_cpu_time_all_executions_ms,
    (qs.total_elapsed_time / 1000) AS cumulative_elapsed_time_all_executions_ms,
	qs.execution_count
--	, p.query_plan
--  , p.query_plan.exist('declare namespace 
--        qplan = "http://schemas.microsoft.com/sqlserver/2004/07/showplan";
--        //qplan:MissingIndexes') as missing_index
FROM sys.dm_exec_query_stats qs
CROSS APPLY sys.dm_exec_sql_text(sql_handle) st
-- CROSS APPLY sys.dm_exec_query_plan(plan_handle) p
ORDER BY cumulative_cpu_time_all_executions_ms DESC
```


## Some references

- [SQL Server statistics](https://learn.microsoft.com/en-us/sql/t-sql/statements/set-statistics-io-transact-sql)
- [SQLShack - Index statistics and usage](https://www.sqlshack.com/gathering-sql-server-indexes-statistics-and-usage-information/)
- [MS Learn - Troubleshoot high-CPU-usage issues in SQL Server](https://learn.microsoft.com/en-us/troubleshoot/sql/database-engine/performance/troubleshoot-high-cpu-usage-issues)
- [SQLShack - How to resolve deadlocks](https://www.sqlshack.com/how-to-resolve-deadlocks-in-sql-server/)
