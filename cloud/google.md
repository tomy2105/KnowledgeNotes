# Google Cloud

<!-- toc -->

- [General](#general)
  * [Regions and zones](#regions-and-zones)
  * [Resource hierarchy](#resource-hierarchy)
  * [Billing](#billing)
- [Services](#services)
  * [Compute](#compute)
    + [Compute Engine](#compute-engine)
      - [Preemptible and Spot VMs](#preemptible-and-spot-vms)
      - [Shielded and Confidential VMs](#shielded-and-confidential-vms)
      - [Sole-tenant Nodes](#sole-tenant-nodes)
      - [Machine images](#machine-images)
      - [Instance groups](#instance-groups)
      - [Scheduled start/stop](#scheduled-startstop)
    + [Google Kubernetes Engine (GKE)](#google-kubernetes-engine-gke)
      - [GKE specifics](#gke-specifics)
      - [Operation modes](#operation-modes)
      - [Cluster types](#cluster-types)
      - [Node pool](#node-pool)
      - [Node Auto Provisioning](#node-auto-provisioning)
      - [Migrate for Anthos](#migrate-for-anthos)
      - [Container-native load balancing](#container-native-load-balancing)
    + [App Engine](#app-engine)
    + [Cloud Run](#cloud-run)
    + [Cloud Functions](#cloud-functions)
    + [Bare Metal Solution](#bare-metal-solution)
    + [VMware Engine](#vmware-engine)
  * [Storage](#storage)
    + [Cloud Storage](#cloud-storage)
    + [Cloud Filestore](#cloud-filestore)
    + [Persistent Disk](#persistent-disk)
      - [Snapshots](#snapshots)
      - [Custom images](#custom-images)
    + [Local SSD](#local-ssd)
  * [Database and Data Analytics](#database-and-data-analytics)
    + [Cloud Bigtable](#cloud-bigtable)
    + [Cloud Firestore](#cloud-firestore)
    + [Cloud Memorystore](#cloud-memorystore)
    + [Cloud Spanner](#cloud-spanner)
    + [Cloud SQL](#cloud-sql)
    + [BigQuery](#bigquery)
    + [Database Migration Service](#database-migration-service)
    + [Dataflow](#dataflow)
    + [Dataprep](#dataprep)
    + [Dataproc](#dataproc)
    + [Datastream](#datastream)
    + [Pub/Sub](#pubsub)
    + [Rest](#rest)
  * [Networking](#networking)
    + [Network Service Tiers](#network-service-tiers)
    + [Egress costs](#egress-costs)
    + [Virtual Private Cloud](#virtual-private-cloud)
      - [Shared VPC networks](#shared-vpc-networks)
      - [VPC network peering](#vpc-network-peering)
    + [Cloud NAT](#cloud-nat)
    + [Cloud Armor](#cloud-armor)
    + [Cloud VPN](#cloud-vpn)
      - [Clasic VPN](#clasic-vpn)
      - [HA VPN](#ha-vpn)
    + [Cloud Interconnect and Peering](#cloud-interconnect-and-peering)
      - [Dedicated Interconnect](#dedicated-interconnect)
      - [Partner Interconnect](#partner-interconnect)
      - [Direct Peering](#direct-peering)
      - [Carrier Peering](#carrier-peering)
    + [Cloud Load Balancing](#cloud-load-balancing)
      - [HTTP(s) Load Balancer](#https-load-balancer)
      - [SSL proxy](#ssl-proxy)
      - [TCP proxy](#tcp-proxy)
      - [Network Load Balancer](#network-load-balancer)
      - [Internal load balancing](#internal-load-balancing)
      - [Internal HTTPS load balancing](#internal-https-load-balancing)
    + [Cloud CDN](#cloud-cdn)
    + [VPC Service Controls](#vpc-service-controls)
    + [Network Intelligence Center](#network-intelligence-center)
    + [Rest](#rest-1)
  * [Operations & Monitoring](#operations--monitoring)
    + [Cloud Monitoring](#cloud-monitoring)
      - [Some general info about metrics](#some-general-info-about-metrics)
    + [Cloud Logging](#cloud-logging)
    + [Error Reporting](#error-reporting)
    + [Cloud Trace](#cloud-trace)
    + [Cloud Profiler](#cloud-profiler)
    + [Cloud Debugger](#cloud-debugger)
  * [Management Tools](#management-tools)
    + [Cloud Console](#cloud-console)
    + [VM Manager](#vm-manager)
    + [Rest](#rest-2)
  * [Application Integration](#application-integration)
    + [Cloud Scheduler](#cloud-scheduler)
    + [Cloud Tasks](#cloud-tasks)
    + [Rest](#rest-3)
  * [API Related](#api-related)
    + [Cloud Endpoints](#cloud-endpoints)
    + [Apigee API Platform](#apigee-api-platform)
    + [API Gateway](#api-gateway)
    + [AppSheet](#appsheet)
  * [Developer Tools](#developer-tools)
    + [Cloud SDK](#cloud-sdk)
    + [Cloud Shell](#cloud-shell)
    + [Cloud Code](#cloud-code)
  * [DevOps CI/CD](#devops-cicd)
    + [Cloud Source Repositories](#cloud-source-repositories)
    + [Container Registry](#container-registry)
    + [Artifact Registry](#artifact-registry)
    + [Cloud Build](#cloud-build)
    + [Cloud Deploy](#cloud-deploy)
    + [Terraform](#terraform)
  * [Migration to Google Cloud](#migration-to-google-cloud)
    + [Cloud Data Transfer](#cloud-data-transfer)
    + [Storage Transfer Service](#storage-transfer-service)
    + [Google Transfer Appliance](#google-transfer-appliance)
    + [Rest](#rest-4)
  * [Identity and Security](#identity-and-security)
    + [Cloud IAM](#cloud-iam)
      - [Roles](#roles)
      - [Policy](#policy)
      - [Members](#members)
      - [Service account](#service-account)
    + [Cloud Identity](#cloud-identity)
    + [Cloud Identity-Aware Proxy](#cloud-identity-aware-proxy)
    + [Cloud Data Loss Prevention (DLP)](#cloud-data-loss-prevention-dlp)
    + [Identity Platform](#identity-platform)
    + [Binary Authorization](#binary-authorization)
    + [Security standards](#security-standards)
    + [Rest](#rest-5)
  * [Hybrid and multi-cloud](#hybrid-and-multi-cloud)
  * [AI and ML](#ai-and-ml)
  * [Mobile (Firebase)](#mobile-firebase)
- [Some of the references](#some-of-the-references)
- [Additional Resources](#additional-resources)

<!-- tocstop -->

## General

### Regions and zones 

Google Cloud resources, are hosted in multiple locations worldwide. These locations are composed of regions and zones. See [regions and network map](https://cloud.google.com/about/locations) here.

A region is a specific geographical location where you can host your resources. Each regions has three or more zones. For list of regions and zones go [here](https://cloud.google.com/compute/docs/regions-zones/).

Resources that live in a zone, such as virtual machine instances or zonal persistent disks, are referred to as **zonal resources**. Zonal resources can only be used by other resources in the same zone. These are: 
- VM Instances
- Persistent disks
- Machine types
- Zonal managed instance groups
- Cloud TPUs

Other resources, like static external IP addresses, are **regional resources**. Regional resources can be used by any resource in that region, regardless of the zone. These are:
- Subnets
- Addresses (regional static external IP addresses used by regional forwarding rules for regional load balancers, and for protocol forwarding)
- Regional managed instance groups
- Regional persistent disks

There are also **global resources** that can be used by any resource withing Google Cloud regardless of the region and/or zone. These are:
- VPC network
- Firewalls
- Routes
- Addresses (Global static external IP addresses used for global load balancers)
- Images
- Snapshots
- Instance templates
- Cloud Interconnects


For up to date info go [here](https://cloud.google.com/compute/docs/regions-zones/global-regional-zonal-resources).

When choosing a region or zone, it's important to think about:
- **Handling failures** - if resources for an app are in one zone only and that zone becomes unavailable, the app will become unavailable. 
- **Decreased network latency** - choose a region or zone that is geographicaly close to customers using it, e.g. if most customers are on the East Coast of the US, choose a primary region and zone that is close to that area

### Resource hierarchy

Resources in Google Clodu are organized hierarchicaly:
- **organization** - is the root node in this hierarchy
- **folders** - the children of the organization, a kind of sub-organizations within the organization used to model different entities likedepartments, and teams within a company
- **projects** - the children of tge folders, and individual resources are the children of the projects

For more info about hierarchy click [here](https://cloud.google.com/resource-manager/docs/cloud-platform-resource-hierarchy).

**Note:** Each resource has exactly one parent and [Cloud IAM](#cloud-iam) roles granted to parent are inherited by all children! For more info related to resouce security [see Cloud IAM](#cloud-iam).

**Labels** are key value pairs that can be attached to a resources and are utility for organizing resources providing more granularity than projects and folders. Can also be used in scripts to help analyze costs or for run bulk operations on multiple resources.

### Billing

Billing is per project, and each resource belongs to a single project. Consumption of all resources under a project accumulates into one billing account.

All resources in Google Cloud are subject to project quotas or limits:
- how many resources can a project create
- how quickly can make API requests in a project or rate limits
- regional quotas - for example, by default, can only have 24 CPUs per region

As use of Google Cloud expands over time, quotas may increase accordingly. If a notable upcoming increase in usage is expected, can proactively request quota adjustments from the quotas page in the Cloud console (or support ticket).

A **budget** can be set up to help with project planning and controlling costs. It enables tracking (combined with budget email/pub/sub alerts) how spending is growing towards desired budget limit. Budget **does not** prevent spending over the limit, it just alerts!!!


## Services

Google Cloud resources and services can be divided into several groups like:
- [Compute](#compute) - variety of machine types that support any type of workload, decide how much control you want over operational details and infrastructure (from manual to fully managed)
- [Storage](#storage) and [Database and Data Analytics](#database-and-data-analytics) - data storage and database options for structured or unstructured, relational or non relational data as well as services that allow you to process and analyze large datasets
- [Networking](#networking) - services that balance application traffic and provision security rules
- [Operations & Monitoring](#operations--monitoring) and [Management Tools](#management-tools) - suite of management, cross-cloud logging, monitoring, trace, and other service reliability tools
- [Application Integration](#application-integration), [Developer Tools](#developer-tools) and [DevOps CI/CD](#devops-cicd) - services and tools that developers can use to enhance their applications or help developers manage deployments and application build pipelines
- [AI and ML](#ai-and-ml) - a suite of APIs/Services that run specific artificial intelligence and machine learning tasks on Google Cloud
- [Identity and Security](#identity-and-security) - a suite of services related to identity and access management applied to all Google Cloud resources
- lots of others.....

For [list go here](https://cloud.google.com/products).

**Note**: Lots of services provide APIs for using them and list of APIs can be seen [here](https://developers.google.com/apis-explorer/).

### Compute

Google Cloud contains a range of compute services: 
- [Compute Engine](#compute-engine) - run virtual machines on-demand in the Cloud, Infrastructure as a Service solution, often base for other services
- [Google Kubernetes Engine (GKE)](#google-kubernetes-engine-gke) - run containerized applications on a Cloud environment in a cluster user manages
- [App Engine](#app-engine) - fully managed platform as a service framework, run code in the Cloud without worrying about infrastructure, just focus on code 
- [Cloud Run](#cloud-run) - a serverless Google managed cluster that lets you run **stateless** containers invoked via web requests or Pub/Sub events 
- [Cloud Functions](#cloud-functions) - completely serverless execution environment or Functions as a Service, executes code in response to events
- [Bare Metal Solution](#bare-metal-solution) - run on bare metal
- [VMware Engine](#vmware-engine) - managed VMware platform

Choosing computer service:
- if load cannot run on virtualized environment choose [Bare Metal Solution](#bare-metal-solution)
- if load requires VMware virtualization choose [VMware Engine](#vmware-engine)
- if load has specific machine and OS requirement (e.g. Windows) choose [Compute Engine](#compute-engine)
- if load runs inside a container choose either:
  - [Google Kubernetes Engine (GKE)](#google-kubernetes-engine-gke) if want to manage own cluster
  - or [Cloud Run](#cloud-run) if want Google to manage cluster
- if load is event driven choose [Cloud Functions](#cloud-functions)
- if not choose [App Engine](#app-engine)

For some more help how to choose compute service see [Visual Note](https://thecloudgirl.dev/gcpcompute.html).

#### Compute Engine

Create and run VMs, GPUs, TPUs on Google infrastructure. Machines are divided into cathegories called [machine types](https://cloud.google.com/compute/docs/machine-types):
- General-purpose (E, N1, N2, T2D) - typicaly 8GB mem/vCPU
- Compute-optimized (C) - typicaly 4GB mem/vCPU
- Memory-optimized (M) - typicaly 14 - 24GB mem/vCPU
- Accelerator-optimized (A)

When choosing a machine type the general purpose machine type family typically offers the best price-performance ratio for a variety of workloads. The general purpose machine types consist of the N-series and E2-series. In general, E2s have similar performance to N1s but, usually, utilizing the E2 machine type alone can help save on costs.

The E2 and N1 series contain shared-core machine types which timeshare a physical core which can be a cost-effective for running small, non-resource intensive apps:
- E2: offers 2 vCPUs for short periods of bursting
- N1: offers `f1-micro` and `g1-small` machine types with up to 1 vCPU available for short periods of bursting

Tau T2D machine series is optimized for scaling out, with cluster-threading disabled, therefore a vCPU is equivalent to an entire core.

GPUs are used to accelerate workloads, attach GPUs to VMs using the N1 machine series or the A2 machine series. 

**Note:**: Once VM is created it cannot change the machine type, the CPU platform, or the zone!!!

All vCPUs, GPUs, and GB of memory are charged a minimum of 1 minute. After 1 minute, instances are charged in 1-second increments. 

**Commited use discounts** lets user purchase contracts or commitments in return for heavily discounted prices for VM usage (hardware and software). When purchased a price is discounted in return for committing to paying for those resources for 1 year or 3 years, the discount is up to 57% for most resources and for some up to 70% (e.g. memory-optimized machine types). See more [here](https://cloud.google.com/compute/docs/instances/signing-up-committed-use-discounts).

**Sustained use discounts** are automatic discounts obtained for running specific Compute Engine resources for a significant portion of the billing month, e.g. when run for more than 25% of a month, Compute Engine automatically gives you a discount for every incremental minute you use for that instance. It increases with usage, up to 30% net discount for instances that run whole month. *It cannot be combineed with commited use discount!*


More info [here](https://cloud.google.com/compute/docs/) and [sketchnote](https://thecloudgirl.dev/gcpsketchnote2.html).

##### Preemptible and Spot VMs

Preemptible and Spot VMs are virtual machine instances that use excess CPU capacity and **significant (60-90%) discounts**, but they might be stopped or deleted preemptively when capacity needs to be reclaimed. Should be used to reduce costs for fault-tolerant workloads that can tolerate being prematurely stopped.

If the instance does not stop after **30 seconds**, compute engine sends an ACPI G3 Mechanical Off signal to the operating system!!!

More info [here](https://cloud.google.com/compute/docs/instances/preemptible) and [here](https://cloud.google.com/compute/docs/instances/spot)

##### Shielded and Confidential VMs

Shielded VMs offer verifiable integrity to VM instances, confident that haven't been compromised by boot or kernel-level malware or rootkits. 

Confidential VMs are a technology that allows encryption of data in use, while it's been processed. Type of N2D Compute Engine VM instance running on hosts based on the second generation of AMD Epyc processors, code-named "Rome", using AMD Secure Encrypted Virtualization (SEV). With the confidential execution environments provided by Confidential VM and AMD SEV, sensitive code and other data is encrypted in memory during processing. Google does not have access to the encryption keys!

More info [here](https://cloud.google.com/security/shielded-cloud/shielded-vm/) and [here](https://cloud.google.com/compute/confidential-vm/docs/).

##### Sole-tenant Nodes

Sole-tenant node is a physical server that is dedicated to hosting VMs of a single project. Used to keep VMs physically separated from VMs in other projects, or to group VMs together on the same host hardware.

More info [here](https://cloud.google.com/compute/docs/nodes/sole-tenant-nodes).

##### Machine images

Stores all the configuration, metadata, permissions and data from multiple disks of a VM instance and can be used in system maintenance, backup and recovery, and instance cloning scenarios.

See [comparison of images, snapshots and templates](https://cloud.google.com/compute/docs/machine-images#when-to-use).

##### Instance groups

An instance group is a collection of virtual machine (VM) instances that managed as a single entity, two kinds of VM instance groups:
- **managed** - operate apps on multiple identical VMs with advantage of automated MIG services: autoscaling, autohealing, regional (multiple zone) deployment, and automatic updating
- **unmanaged** - fleet of VMs that user manages himself

**Note**: In order to create a managed instance group, am instance template needs to be created first. It defines machine type, boot disk image, labels, startup script, and other instance properties. 

An autohealing on an application-based health check to verify that an app is responding as expected.

Autoscaling capabilities automatically add or remove instances from a managed instance group based on increase or decrease in load. Can include scaling based on CPU utilization, load-balancing capacity or monitoring metrics or via queue-based workload. More info [here](https://cloud.google.com/compute/docs/autoscaler/).

Managed instance groups can work with load balancing services to distributor network traffic to all of the instances in the group.

**Note**: Regional managed instance groups are generally recommended over zonal managed instance groups!

More info [here](https://cloud.google.com/compute/docs/instance-groups)

##### Scheduled start/stop 

Instance schedules enable starting and stopping virtual machine instances automatically in order to optimize costs and manage VM instances more efficiently. 

More info [here](https://cloud.google.com/compute/docs/instances/schedule-instance-start-stop).

#### Google Kubernetes Engine (GKE)

For general info about Kubernetes, Docker and Microservices see [here](docker_k8s.md).

Google Kubernetes Engine (GKE) is managed Kubernetes cluster where control planes are provisioned as abstract parts of the GKE service that are not exposed to Google Cloud customers, while nodes are provisioned as Compute Engine virtual machines that run the Kubernetes processes necessary to make them part of the cluster. For more info see [here](https://cloud.google.com/kubernetes-engine/docs/concepts/cluster-architecture).

The world of Kubernetes offers several choices for container runtimes. Linux distribution that GKE uses for its node launches containers using Containerd, the runtime component of Docker. 


GKE cluster offers the benefit of advanced cluster management features that Google Cloud provides:
- Load balancing for Compute Engine instances - [see here](https://cloud.google.com/compute/docs/load-balancing-and-autoscaling)
- Node pools to designate subsets of nodes within a cluster for additional flexibility - [see here](https://cloud.google.com/kubernetes-engine/docs/node-pools)
- Automatic scaling of your cluster's node instance count - [see here](https://cloud.google.com/kubernetes-engine/docs/cluster-autoscaler)
- Automatic upgrades for your cluster's node software - [see here](https://cloud.google.com/kubernetes-engine/docs/node-auto-upgrade)
- Node auto-repair to maintain node health and availability - [see here](https://cloud.google.com/kubernetes-engine/docs/how-to/node-auto-repair)
- Logging and Monitoring with Cloud Monitoring for visibility into your cluster - [see here](https://cloud.google.com/kubernetes-engine/docs/how-to/logging)

More info [here](https://cloud.google.com/kubernetes-engine/docs/) and [sketchnote](https://thecloudgirl.dev/GKE.html) and specifically about manging cost [here](https://cloud.google.com/architecture/best-practices-for-running-cost-effective-kubernetes-applications-on-gke).

##### GKE specifics

**LoadBalancers** give you access to a regional Network Load Balancing configuration by default, to use a global HTTP(S) Load Balancing configuration, you can use an **Ingress** object.

The nodes will get the Pod IP addresses from address ranges assigned to your Virtual Private Cloud.

A PersistentVolume is typically backed by a persistent disk, can also use other storage solutions like NFS.

##### Operation modes

Following modes of operation for clusters are available:
- **Autopilot mode** (recommended) - GKE manages the underlying infrastructure such as node configuration, autoscaling, auto-upgrades, baseline security configurations, and baseline networking configuration
- **Standard mode** - User manages the underlying infrastructure, including configuring the individual nodes

Can't convert a cluster from Standard to Autopilot after cluster creation. For differences see [here](https://cloud.google.com/kubernetes-engine/docs/resources/autopilot-standard-feature-comparison).


##### Cluster types

Available clusters in GKE include zonal (single-zone or multi-zonal) and regional. 

**Single-zone** cluster will be the least expensive option, hwever, for high-availability applications, it is best to distribute cluster’s infrastructure resources across zones.

**Multi-zonal** cluster has at least one additional zone defined but only has a single replica of the control plane running in a single zone. Workloads can still run during an outage of the control plane's zone, but no configurations can be made to the cluster until the control plane is available.

**Regional cluster** has multiple replicas of the control plane, running in multiple zones within a given region. Nodes also run in each zone where a replica of the control plane runs. Regional clusters consume the most resources but offer the best availability (both application and management functionality can withstand the loss of one or more, but not all, zones).

By default, a regional cluster is spread across 3 zones, each containing 1 control plane and 3 nodes.

Prioritizing availability in cluster through a multi-zonal or regional cluster usually results in the best cost-to-performance architecture.

##### Node pool

GKE feature rather than a Kubernetes feature. A subset of nodes within a cluster that share a configuration, such as their amount of memory or their CPU generation which provide an easy way to ensure that workloads run on the right hardware within the cluster. 

Migrate pods to the new node pool by following these steps:
- Cordon the existing node pool - marks the nodes in the existing node pool (node) as unschedulable, Kubernetes stops scheduling new Pods to these nodes once you mark them as unschedulable
- Drain the existing node pool - evicts the workloads running on the nodes of the existing node pool gracefully

##### Node Auto Provisioning 

Adds new node pools that are **sized** to meet demand. Without it, the cluster autoscaler will only be creating new nodes in the specified node pools. Perfect for helping optimize resource usage for batch workloads and other apps that don't need extreme scaling (since creating a node pool that is specifically optimized might take more time than just adding more nodes to an existing pool).

##### Migrate for Anthos

Tool for getting workloads into containerized deployments on Google Cloud, moves existing applications into a Kubernetes environment. Workloads can be on premises, or in other cloud providers. Choice of migrating applications data in one move, or stream it to the cloud until the application is live.

##### Container-native load balancing 

Container-native load balancing allows load balancers to target Kubernetes Pods directly and to evenly distribute traffic to pods.

Without container-native load balancing, load balancer traffic would travel to node instance groups and then be routed via iptables rules to pods which may or may not be in the same node.

Container-native load balancing allows pods to become the core objects for load balancing, potentially reducing the number of network hops.

In addition to more efficient routing, container-native load balancing results in substantially reduced network utilization, improved performance, even distribution of traffic across Pods, and application-level health checks.

In order to take advantage of container-native load balancing, the VPC-native setting must be enabled on the cluster. This is done via `--enable-ip-alias flag` in order to enable the use of alias IPs for pods which is required for container-native load balancing through an **Ingress**.

When the **Ingress** is created, an HTTP(S) load balancer is created along with an NEG (Network Endpoint Group) in each zone in which the cluster runs. 


#### App Engine

Fully managed serverless application platform supporting the building and deploying of applications.
Code can be in Go, Java, Node.js, PHP, Python, Ruby ([App engine standard](https://cloud.google.com/appengine/docs/standard)) and .NET and other custom runtimes ([App engine flexible](https://cloud.google.com/appengine/docs/flexible)).

Applications can be scaled seamlessly from zero upward without having to worry about managing the underlying infrastructure. 

Each Google Cloud project can contain one App Engine application, and an application has one or more services. Each service can have one or more versions, and each version has one or more instances. 

App Engine supports traffic splitting, so it makes switching between versions and strategies, such as canary testing or A/B testing, simple. 

There's also a batch application that generates data reports for management. 

More info [here](https://cloud.google.com/appengine/docs/) and [sketchnote](https://thecloudgirl.dev/appengine.html).

#### Cloud Run

Serverless Google managed cluster that lets you run **stateless** containers that respond to web requests or Pub/Sub events (there is also Cloud Run jobs in preview for code that is not driven by such events).

There is managed Cloud Run where where all container lifecycle is managed by the Cloud Run product itself and Cloud Run on GKE with an additional layer of control which allows bringing your clusters & pods from GKE.

Cloud Run adds and removes container instances automatically. When there are no incoming requests the last remaining container instance will be removed (scale to zero). This negatively impacts the response time for these first requests (when new instance is created), depending on how fast container becomes ready. To avoid this Cloud Run can be configured to keep a minimum amount of container instances active at all times.

More info [here](https://cloud.google.com/run/docs/) and [sketchnote](https://thecloudgirl.dev/run.html).

#### Cloud Functions

Serverless execution environment for building and connecting cloud services. Can write simple, single-purpose functions that are attached to events. Cloud Function is [triggered](https://cloud.google.com/functions/docs/calling) when an event being watched is fired. 

Code executes in a fully managed environment with no need to provision any infrastructure or worry about managing any servers. Cloud Functions have access to the Google Service Account credential and are thus seamlessly authenticated with the majority of Google Cloud services.

Use Cases:
- Data Processing / ETL - Listen and respond to Cloud Storage events such as when a file is created, changed, or removed, e.g. process images, perform video transcoding, validate and transform data, etc...
- Webhooks - Via a simple HTTP trigger, respond to events originating from any 3rd party systems that can send HTTP requests
- Lightweight APIs - compose applications from small, loosely coupled bits of logic that are quick to build and that scale instantly
- Mobile Backend - when using Firebase (Google's mobile platform for app developers), and write mobile backend in Cloud Functions
- IoT - devices streaming data into Cloud Pub/Sub, launching Cloud Functions to process, transform and store data

More info [here](https://cloud.google.com/functions/docs/) and [sketchnote](https://thecloudgirl.dev/CloudFunctions.html).

#### Bare Metal Solution

Dedicated hardware for specialized workloads that cannot be virtualized like Oracle database.

More info [here](https://cloud.google.com/bare-metal/docs) and [sketchnote]( and [sketchnote](https://thecloudgirl.dev/CloudFunctions.html).

#### VMware Engine

Fully managed (Google manages the infrastructure, networking, and management services) service runs the VMware platform in Google Cloud .

More info [here](https://cloud.google.com/vmware-engine/docs) and [sketchnote](https://thecloudgirl.dev/VMwareEngine.html).


### Storage
  
By default, Compute Engine **encrypts ** all data **at rest** without any additional configuration required. For more control user can use either Cloud Key Management Service to create and manage key encryption keys or create and manage your encryption keys on its own.

A data encryption key or DEK using AES 256 symmetric key is used and the key itself is encrypted by Google using a key encryption key, KEK. This is so that the DEK can be stored local to the encrypted data for fast decryption with no visible performance impact to the user.  KEKs are stored in Cloud KMS, all keys are rotated periodically and automatically.

For more info see [here](https://cloud.google.com/security/encryption/default-encryption/), [here](https://cloud.google.com/kms/docs/envelope-encryption) and [Data Security sketchnote](https://thecloudgirl.dev/datasecurity.html).

Data is also encrypted in transit (if Google controled), see [here](https://cloud.google.com/security/encryption-in-transit).

For **unstructured** data use **Filestore** if you need shared file system or **Cloud Storage** if not.
For **structured** data see [Database and Data Analytics](#database-and-data-analytics).

Scaling (includes [Database and Data Analytics](#database-and-data-analytics)):
- Horizontal: Bigtable, Spanner
- Vertical: CloudSQL, Memorystore
- Automatic: Cloud storage, BiqQuery, Firestore

Durability (includes [Database and Data Analytics](#database-and-data-analytics)), Google ensures data is durable in event of hardware failure but backups must be configured manually:
- Cloud storage: good to turn versioning on (and older versions archived as part of lifetime management policy)
- Disks: snapshot jobs
- CloudSQL: SQL database backup jobs
- Spanner, Firestore: export jobs

Cost considerations (includes [Database and Data Analytics](#database-and-data-analytics)):
- Bigtable and Spanner are not cost-effective for small datasets
- Firestore is less expensive per GB stored but the has cost for reads and writes
- Cloud Storage is not as expensive but only suitable for certain data types
- BigQuery storage is relatively cheap but does not provide fast access to records, and a cost is incurred for each query

[sketchnote](https://thecloudgirl.dev/StorageOptions.html) on storage options and more info [here](https://cloud.google.com/compute/docs/disks/).

#### Cloud Storage

Object storage service, worldwide storage and retrieval of any amount of data at anytime. 

Used for range of scenarios including serving website content, storing data for archival and disaster recovery, or distributing large data objects to user via direct download. 

Scalable to exabytes of data, time to first byte is in milliseconds,  very high availability and a single API across storage classes. 

Not a reall file system, collection of buckets that you place objects into (directory is just another object). Buckets are required to have a globally unique name and cannot be nested.

No minimum size to those objects, and scale as much as wanted, as long as quota allows it. 

To access the data you can use the gsutil command or either JSON or XML APIs. 


Data put into buckets are objects that inherit the storage class of the bucket (unless you specify a storage class for each of the objects). Four storage [classes](https://cloud.google.com/storage/docs/storage-classes):
- **standard** - data that is frequently accessed and stored for brief period of time (most expensive, no miminum storage duration, no retrieval cost)
- **nearline** - infrequently accessed data accessed less than once per 30 days, like data backup, long tailed multimedia content, and data archiving (slightly lower availability, minimum storage duration, and costs for data access, lowered storage costs)
- **coldline** - infrequently accessed data accessed less than once per 90 days (slightly lower availability, a 90 day minimum storage duration and higher costs for data access, lowered storage costs)
- **archive** - data archiving, online backup and disaster recovery accessed less than once a year (no availability SLA, higher costs for data access, 365 day minimum storage duration)

Three location types:
- **multi region** - contains two or more geographic places
- **dual region** - specific pair of regions
- a **region**

IAM is used to control which individual users or service account can operate on a bucket, roles are inherited from project to bucket to object. There are two access control ways:
- **Uniform** (recommended) - use IAM alone to manage permissions, also allows you to use features that are not available when working with ACLs, such as IAM Conditions and Cloud Audit Logs.
- **Fine-grained** - use IAM and Access Control Lists (ACLs) together to manage permissions, ACLs specify access and apply permissions at both the bucket level and per individual object, maximum number of ACL entries you can create for a bucket or object is 100.

Signed URL provide a cryptographic key that gives time limited access to a bucket or object. 

Other features:
- **customer supplied encrytion key (CSEK)** - instead of Google managed ones
- **Object Versioning** - maintain multiple versions of objects (object is archived, with ID, before changed), turned on/off on bucket at any time
- **Object Lifecycle Management** - automatically delete (keep specific number of versions) or archive objects (downgrade storage class)
- **Directory Synchronizato**n - syncs VM directory with a bucket
- **Object change notification** - notify application when object changes (at the moment webhook or Pub/Sub)
- **Data import** - [Cloud Data Transfer](#cloud-data-transfer), [Storage Transfer Service](#storage-transfer-service), [Google Transfer Appliance](#google-transfer-appliance)
- **Strong consistency** - all changes are immediately visible

More info [here](https://cloud.google.com/storage/docs/) and [sketchnote](https://thecloudgirl.dev/CloudStorage.html).

#### Cloud Filestore

Managed NFS file storage service for applications that require a file system interface and a shared file system for data using network attached storage with either Compute Engine or Google Kubernetes Engine instances. 

Features:
- supports any NFSV3 compatible clients. 
- scale-out performance
- hundreds of terabytes of capacity
- file locking 

More info [here](https://cloud.google.com/filestore/docs/).

#### Persistent Disk

Block storage for VMs (usually network attached so it can be persisted regardless of VM state) can be:
- Zonal persistent disk: Efficient, reliable block storage
- Regional persistent disk: Regional block storage replicated in two zones

**Note**: The boot disk defaults to being deleted automatically when the instance is deleted. Meed to disable Delete boot disk when instance is deleted to enable creating an image from the boot disk!!!

For shared-core machine type, you can attach up to 16 disks. For the standard, high-memory, high-CUP, memory-optimized and compute-optimized machine types, you can attach up to 128 disks.

More info [here](https://cloud.google.com/compute/docs/disks/) and [sketchnote](https://thecloudgirl.dev/PD.html).

##### Snapshots

Snapshots incrementally back up data from persistent disks and can be used to restore data to a new disk. Can create from disks even while they are attached to running virtual machine (VM) instances.

See [comparison of images, snapshots and templates](https://cloud.google.com/compute/docs/machine-images#when-to-use).

##### Custom images

Custom images are created from source disks, images or snapshots and can be used to create virtual machine (VM) instances (similar purpose as machine images).

**Virtual disk import tool** can be used to import boot disk images from existing systems to Compute Engine.

See [comparison of images, snapshots and templates](https://cloud.google.com/compute/docs/machine-images#when-to-use).

#### Local SSD

Local SSDs, unlike persistent disks, are physically attached to the virtual machine, therefore are **ephemeral** (data will survive a VM reset but not a VM stop/terminate), but provide **very high IOPS**.

Cannot stop a VM with a local SSD via the gcloud CLI or the console, can shut down a VM from inside the guest operating system (OS), **but data is lost**!!!

More info [here](https://cloud.google.com/compute/docs/disks/local-ssd).
  
### Database and Data Analytics 

For structured data choose:
- if workload is analtics:
  - choose **Cloud Bigtable** if need updates or low latency
  - or **BigQuery** otherwise
- if not analytics then:
  - if data is not relational use **Firestore**
  - if relational choose **Cloud Spanner** if need horizontal scalability or **Cloud SQL** if not

See [sketchnote](https://thecloudgirl.dev/dboptions.html) on how to choose database.

#### Cloud Bigtable

Fully managed NoSQL database with petabytes-scale high read/high write volume and low latency **strongly** consistent in a **single** cluster (SLA of 99.5%) while replication adds **eventual** consistency across **two** clusters (SLA to 99.99%). 

It is a key-value store that is designed as a sparsely populated table and can scale to billions of rows and thousands of columns. Scales for throughput (by adding/removing node - each node provides up to 10,000 queries per second -read and write) and learns to adjust to specific access patterns.

Supports the open-source industry standard HBase API, which makes it easy to get started.

Choose when need to store more than one terabyte of structured data, have very high volumes of writes, need read/write latency of less than 10 milliseconds (such as IoT, AdTech, FinTech,...) or need a storage service that is compatible with the HBase API. If high throughput and low latency at scale are not priorities, then another NoSQL database like Firestore might be a better fit.

More info [here](https://cloud.google.com/bigtable/docs/) and [sketchnote](https://thecloudgirl.dev/Bigtable.html).

#### Cloud Firestore

Fast, fully managed, serverless, cloud native, NoSQL, document database with max. document size of 1 MB good for heavy read/write events. Supports ACID transactions, automatic multi region replication and **strong consistency**.

More info [here](https://cloud.google.com/firestore/docs/) and [sketchnote](https://thecloudgirl.dev/cloudnat.html).

#### Cloud Memorystore

Fully managed in-memory, highly scalable, available, secure Redis/Memcached service.

High availability instances are replicated across two zones and provide a 99.9% availability SLA (**eventual consistency** when replicas are used). 

Can easily achieve the sub-millisecond latency and throughput. Support instances up to 300 GB and network throughput of 12 gigabits per second.

More info [here](https://cloud.google.com/memorystore/docs/) and [sketchnote](https://thecloudgirl.dev/memorystore.html).

#### Cloud Spanner

Service built for the cloud that combines the benefits of relational database (schema, SQL and **strong/transactional consistency**) with non relational ones (high availability, **horizontal scalability** and configurable replication).

A Cloud Spanner instance replicates data in end cloud zones which can be within one region or across several regions. The database placement is configurable, choose which region to put your database in. Architecture allows for high availability and global placement.

The replication of data is synchronized across zones using Google's global fiber network and usage of atomic clocks ensures atomicity when updating data. 

More info [here](https://cloud.google.com/spanner/docs/) and [sketchnote](https://thecloudgirl.dev/spanner.html).

#### Cloud SQL

Fully managed service of either MySQL, PostgreSQL, or Microsoft SQL Server databases with high performance and scalability with up to 64 TB of storage capacity, 60,000 IOPS, and 624 GB of RAM per instance. Can easily scale up to 96 processor cores and scale out with **read** replicas.

HA configuration is made up of a primary instance and a standby instance, through synchronous replication to each zones persistent disk, all writes made to the primary instance are replicated to disks in both zones before a transaction is reported as committed. In the event of an instance or zone failure, the persistent disk is attached to the standby instance, and it becomes the new primary instance.

Automated and on-demand backups with point-in-time recovery are provided.

If connecting an application that's hosted within the same Google Cloud project and in the same region, use Private IP connection for most performant and secure connection. 

If connecting from outside there are 3 options:
- [Cloud SQL Proxy](https://cloud.google.com/sql/docs/mysql/sql-proxy) - which handles authentication, encryption and key rotation
- control over the SSL connection, can generate and periodically rotate the certificates yourself
- an unencrypted connection by authorizing a specific IP address to connect 

More info [here](https://cloud.google.com/sql/docs/) and [sketchnote](https://thecloudgirl.dev/gcpsketchnote3.html).

#### BigQuery

A fully-managed petabyte-scale data warehouse for large amounts of relational structured data optimized for large-scale, ad-hoc SQL-based analysis and reporting. Aimed at data analysts and data scientists, can quickly query and filter large datasets, aggregate results, and perform complex operations (supports a standard SQL dialect that is ANSI-compliant). 

Can use [partitioned tables](https://cloud.google.com/bigquery/docs/partitioned-tables) to improve query performance, and you can control costs by reducing the number of bytes read by a query.

More info [here](https://cloud.google.com/bigquery/docs/) and [sketchnote](https://thecloudgirl.dev/bigquery.html).

Also contains some prebuild public data sets that can be used, more info [here](https://cloud.google.com/public-datasets).


#### Database Migration Service

Provides options for one-time and continuous jobs to migrate data to Cloud SQL.

During migration, the destination Cloud SQL database needs to connect to the source database using different connectivity options, including IP allowlists, VPC peering, and reverse SSH tunnels.

To migrate PostgreSQL you need to:
- enable Database Migration API
- enable Service Networking API
- install and configure pglogical database extension
- configure stand-alone PostgreSQL database to allow access from Cloud SQL
- add pglogical database extension to the required databases 
- creating a user (with Replication permissions) for database migration and grant the required permissions

More info [here](https://cloud.google.com/database-migration/docs) and [here](https://cloud.google.com/blog/products/databases/tips-for-migrating-across-compatible-database-engines).

#### Dataflow

Fully managed service for transforming and enriching data, stream and batch modes based on **Apache Beam**.

Supports fast, simplified pipeline development via expressive SQL, Java and Python APIs in the Apache Beam SDK, provides a rich set of windowing and session analysis primitives, as well as an ecosystem of source and sync connectors.

Also tightly coupled with other GCP services, can set up priority alerts and notifications to monitor our pipeline and the quality of data coming in (Pub/Sub, Datastore, Apache Avro, Apache Kafka) and out (BigQuery, AI platform, Bigtable).

More info [here](https://cloud.google.com/dataflow/docs/) and [sketchnote](https://thecloudgirl.dev/dataflow.html).

#### Dataprep

Data service for visually exploring, cleaning and preparing structured and unstructured data for analysis reporting and machine learning (integrated partner service operated by **Trifacta/Trifacta Wrangler**). Serverless and works at any scale, there's no infrastructure to deploy or manage. 

More info [here](https://cloud.google.com/dataprep/docs/) and [sketchnote](https://thecloudgirl.dev/dataprep.html).

#### Dataproc

Fully managed cloud service for running **Apache Spark** and **Apache Hadoop** clusters with per-second billing.

Without it, it can take from 5 to 30 minutes to create Spark and Hadoop clusters. With Cloud Dataproc clusters are quick to start, scale and shut down, with each of these operations taking 90 seconds or less on average.

More info [here](https://cloud.google.com/dataproc/docs/) and [sketchnote](https://thecloudgirl.dev/Dataproc.html).

#### Datastream

Serverless and easy-to-use change data capture and replication service. 

Allows seamless replication of data from relational database sources such as Oracle, MySQL, and PostgreSQL directly into BigQuery or Cloud Storage or into Cloud SQL or Cloud Spanner (for database synchronization), reliably, and with minimal latency and downtime.

More info [here](https://cloud.google.com/datastream/docs) and [sketchnote](https://thecloudgirl.dev/datastream.html).

#### Pub/Sub

Asynchronous global messaging service. 

A **topic** is a shared string that allows applications to connect with one another through a common thread.

Publishers push (or publish) a message to a Cloud Pub/Sub topic.

Subscribers make a "subscription" to a topic where they will either pull messages from the subscription or configure webhooks for push subscriptions. Every subscriber must acknowledge each message within a configurable window of time.

Using the pull command without any flags will output only one message, even if subscribed to a topic that has more held in it.

Once an individual message has been outputted from a particular subscription-based pull command, cannot access that message again with the pull command.

More info [here](https://cloud.google.com/pubsub/docs/) and [sketchnote](https://thecloudgirl.dev/pubsub.html).

There is also a Pub/Sub Lite which is cheaper zonal Pub/Sub, more info [here](https://cloud.google.com/pubsub/lite/docs/) and [sketchnote](https://thecloudgirl.dev/gcpsketchnote4.html).

#### Rest

- [Cloud SQL Insights](https://cloud.google.com/sql/docs/postgres/using-insights) - SQL insights
- [BigQuery BI Engine](https://cloud.google.com/bi-engine/docs/) - in memory analytics
- [BigQuery ML](https://cloud.google.com/bigquery-ml/docs/) - model training/serving
- [BigQuery GIS](https://cloud.google.com/bigquery/docs/gis) - geospatial functions/support
- [BigQuery Data Transfer Service](https://cloud.google.com/bigquery-transfer/docs) - automated data ingestion service.
- [Connected Sheets](https://cloud.google.com/bigquery/docs/connected-sheets) - spreadsheet interface for (big)data
- [Cloud Composer](https://cloud.google.com/composer/docs/) - workflow orchestration based on **Apache Airflow** and [sketchnote](https://thecloudgirl.dev/Composer.html)
- [Cloud Data Fusion](https://cloud.google.com/data-fusion/docs/) - graphically manage data pipelines
- [Data Catalog](https://cloud.google.com/data-catalog/docs/) - metadata management service
- [Google Data Studio](https://datastudio.google.com/overviewdocs/) - collaborative data exploration/dashboarding
- [Looker](https://cloud.google.com/looker/docs) - enterprise BI and analytics


### Networking 

[Sketchnote](https://thecloudgirl.dev/cloudnetworking101.html) and [another sketchnote](https://thecloudgirl.dev/networkingservicesoverview.html) about networking.

#### Network Service Tiers 

There are two tiers:
- **Premium** - higher performance (more cost) by keeping traffic within Google network as much as possible, default tier.
- **Standard** - slower performance (less cost), traffic is routed over internet in general (available in some regions only and for some services only)

More info [here](https://cloud.google.com/network-tiers/docs/) and [sketchnote](https://thecloudgirl.dev/networkservicetiers.html).

#### Egress costs

- Egress in the same zone is free.
- Egress to a different Google Cloud service within the same region using an external IP address or an internal IP address is free, except for some services such as Memorystore for Redis
- Egress between zones in the same region is charged 
- all internet egress is charged

More info about network cost [here](https://cloud.google.com/vpc/network-pricing).

#### Virtual Private Cloud

Software defined networking within Google Cloud, every network is either:
- **auto mode network** - one subnet (/20 mask can be expanded to /16) for each region is automatically created within network, all of these subnets fit within the 10.128.0.0/9 CIDR block. 
- **custom network mode** - does not automatically create subnets

Can convert an auto mode network to a custom mode network however custom mode networks cannot be changed to auto mode networks.

Subnets are across zones (within region), every subnet has four reserved IP addresses in its primary IP range.

Every project is provided with a `default` **auto mode** network with preset subnets and firewall rules that allow ingress for traffic for ICMP, RDP and SSH traffic from anywhere, as well as ingress traffic from within the default network for all protocols and ports.

Every VM instance gets an internal fully qualified domain name (FQDN) that looks like this: `hostName.[ZONE].c.[PROJECT_ID].internal`. 

**Note**: The number of interfaces allowed in an VM instance is dependent on the instance's machine type and the number of vCPUs, e.g. the e2-standard-4 allows up to 4 network interfaces. 

**Note**: In a multiple interface per instance scenario, every interface gets a route for the subnet that it is in. In addition, the instance gets a single default route that is associated with the primary interface. Unless manually configured otherwise, any traffic leaving an instance for any destination other than a directly connected subnet will leave the instance via the default route.

**Note**: Within a region, the bandwidth is limited by the 2 Gbit/s per core egress cap.

**Note**: Hosts withing network communicate with internal IP, if in different networks they need to use public IP (going through Google Edge routers), even if in same zone/region and such communication has different billing and security.

External IP Addresses/ranges lists:
- https://www.gstatic.com/ipranges/cloud.json - provides a JSON representation of Cloud IP addresses organized by region.
- https://www.gstatic.com/ipranges/cloud_geofeed - is a standard geofeed formatted IP geolocation file 
- https://www.gstatic.com/ipranges/goog.json and https://www.gstatic.com/ipranges/goog.txt  are TXT and JSON formatted files respectively that include Google public prefixes in CIDR notation

More info [here](https://cloud.google.com/vpc/docs/).

##### Shared VPC networks

Share a network across several projects in your GCP organization. Designate one project as a host project and attach one or more other service projects to it.

Shared VPC is a centralized approach to multi project networking because security and network policy occurs in the single designated VPC network. 

##### VPC network peering

Configure private communication across projects in same or different organizations.

Admins of both networks need to configure pairing on their side and maintains its own global firewall and routing tables.

VPC network peering is a decentralized or distributed approach to multi project networking because each VPC network configuration remains under the control of separate administrator groups.

VPC network peering does not incur the network latency, security and cost drawbacks that are present when using external IP addresses or VPNs. 


#### Cloud NAT

Managed network address translation service, so that resources without public IP addresses can access the internet while hosts outside their VPC network cannot directly access any of the private resources behind the Cloud NAT gateway.

Private Google access to allow resources that only have internal IP addresses to reach the external IP addresses of Google APIs and services. This is enabled on a subnet by subnet basis!

More info [here](https://cloud.google.com/nat/docs/overview/) and [sketchnote](https://thecloudgirl.dev/cloudnat.html).

#### Cloud Armor

Google provides Infrastructure DDoS support through global load balancers at level 3 and level 4 traffic.
If you have enabled CDN, this will also protect backend resources because a DDOS results in a cache hit instead of hitting your resources as shown on the right. 

For additional features over the built-in DDoS protection, can use Cloud Armor to create network security policies with allow lists that allow known/required addresses through and deny lists to block known attackers. 

In addition to layer 3 and layer 4 security, Cloud armor supports layer 7 application rules.
Predefined rules are provided for cross-site scripting, XSS, and SQL injection attacks. 
Cloud armor also provides a rules language for filtering request traffic (`request.headers['cookie'].contains('80=BLAH')`).

More info [here](https://cloud.google.com/armor/docs/) and [sketchnote](https://thecloudgirl.dev/CloudArmor.html).

#### Cloud VPN

More info [here](https://cloud.google.com/compute/docs/vpn/overview) and [sketchnote](https://thecloudgirl.dev/networkconnectivity.html).

##### Clasic VPN

Securely connects on-premises network to Google Cloud VPC network through an IPsec VPN tunnel and is **useful for low-volume data connections**. 

**Note: Doesn't support use cases where client computers need to “dial in” to a VPN using client VPN software.****

SLA of 99.9% service availability and supports site-to-site VPN, static and dynamic routes, and IKEv1 and IKEv2 ciphers. Ordinary IPsec VPN tunnel is 1.5-3 Gbps per tunnel.

Cloud VPN gateway is a regional resource that uses a regional external IP address and needs on-premises VPN gateway with an external IP address (MTU 1460 max). In order to create a connection between two VPN gateways, must establish two VPN tunnels. Each tunnel defines the connection from the perspective of its gateway, and traffic can only pass when the pair of tunnels is established.

##### HA VPN

High availability Cloud VPN solution securely connects your on-premises network to your Virtual Private Cloud (VPC) network through an IPsec VPN connection in a single region. 

Provides an SLA of 99.99% service availability. To do so must properly configure two or four tunnels from HA VPN gateway to peer VPN gateway or to another HA VPN gateway. 

VPN tunnels connected to HA VPN gateways must use dynamic (BGP) routing using **Cloud Router**s. Depending on the way route priorities for HA VPN tunnels are configured can create an active/active or active/passive routing configuration. 

HA VPN is a regional resource and cloud router that by default only sees the routes in the region in which it is deployed. To reach instances in a different region than the cloud router, need to enable global routing mode for the VPC. 

Steps to set up HA VPN:
- create an HA VPN
- create a cloud router 
- create the first and second VPN tunnel 
- create the (two) router interface
- create the (two) BGP peer
- create needed firewall rules to allow traffic from other (new VPN) network 

#### Cloud Interconnect and Peering

Interconnect provide direct access to **RFC1918 IP addresses** in VPC **with** an SLA (Layer 2). 

Peering services in contrast are for access to Google public **IP addresses only** **without** an SLA (Layer 3).

There are different Cloud Interconnect and peering services available to connect your infrastructure to Google's network:
- Direct Peering - Dedicated Layer 3
- Carrier Peering - Shared Layer 3
- Dedicated Interconnect - Dedicated Layer 2
- Partner Interconnect - Shared Layer 2

[Sketchnote](https://thecloudgirl.dev/networkconnectivity.html) about network connectivity options.

##### Dedicated Interconnect

Dedicated Interconnect provides direct physical connections between on-premise network and Google's network. 

Enables transfer of large amounts of data between networks, which can be more cost effective than purchasing additional bandwidth over the public internet. 

In order to use Dedicated Interconnect, need to provision a cross connect between the Google network and own router in a common colocation facility.

Dedicated Interconnect can be configured to offer a 99.9% or a 99.99% uptime SLA with 10 Gbps per link (100 Gbps in beta).

More info [here](https://cloud.google.com/interconnect/docs/details/dedicated).

##### Partner Interconnect

Partner Interconnect provides connectivity between on-premise network and VPC network through a supported service provider. Useful if on-premise network is in the physical location that cannot reach a Dedicated Interconnect colocation facility, or if data transfer needs don't warrant a Dedicated Interconnect. 

Provides 50 Mbps - 10 Gbps per connection.

More info [here](https://cloud.google.com/interconnect/docs/concepts/partner-overview).

##### Direct Peering

Direct peering with Google is done by exchanging BGP routes between Google and the peering entity.
After a direct peering connection is in place, can use it to reach all the Google services, including the full suite of Google Cloud platform products.

Unlike dedicated interconnect, direct peering does not have an SLA and provides 10 Gbps per link.

More info [here](https://cloud.google.com/interconnect/docs/how-to/direct-peering).

##### Carrier Peering

Peer through a carrier 

Used when access to Google public infrastructure is required but cannot satisfy Goggle's peering requirements, then connect via a carrier peering partner.

Carrier peering also does not have an SLA and speed depends on partner.

More info [here](https://cloud.google.com/interconnect/docs/how-to/carrier-peering).

#### Cloud Load Balancing

Fully distributed, software-defined managed service for load distribution/balancing. Different types of load balancers that can be divided into two categories: global and regional. 

Global load balancers Sit in Google's point of presence and are distributed globally, they are:
- HTTP(S) load balancer - used for external HTTP(S) traffic
- SSL proxy load balancers - used for external TCP traffic when using SSL offload
- TCP proxy load balancers - used for external TCP traffic without SSL offload (need global or IPv6 but don't need to preserve client IPs)

Want to use a global load balancer when users and instances are globally distributed and want to provide access using a single anycast IP address.

The regional load balancers are: 
- internal load balancer (**Andromeda** - GCP's software-defined network virtualization stack) - used for internal TCP/UDP traffic
- network load balancer (**Maglev**) - used for external TCP traffic without SSL offload when need to preserve client IPs or for external UDP traffic (regional and without IPv6 support)

In addition there are regional interal ones (run and scale a service behind a private load-balancing IP address - accessible only in the load balancer's region):
- internal load balancer for HTTP, HTTPS traffic - used for internal HTTP(S) traffic
- proxy-based regional layer 7 load balancer

**Note:** Only the global HTTP(S), SSL proxy and TCP proxy load balancing services support IPv6 clients!

More info [here](https://cloud.google.com/load-balancing/) and [sketchnote](https://thecloudgirl.dev/CLB.html).

##### HTTP(s) Load Balancer 

A HTTPS load balancer has the same basic structure as a HTTP load balancer, but it uses target HTTPS proxy instead of a target HTTP proxy and requires at least one signed SSL certificate installed on the target HTTPS proxy. 

To set up a load balancer with a Compute Engine backend, VMs need to be in an instance group running the backend servers of an external HTTP load balancer.  Requests are always routed to the instance group that is closest to the user, if that group has enough capacity and is appropriate for the request. If the closest group does not have enough capacity, the request is sent to the closest group that does have capacity.

[URL map](https://cloud.google.com/load-balancing/docs/url-map-concepts) is a configuration used to route requests to backend services or backend buckets, some URLs to one set of instances and route other URLs to other instances.

[Forwarding rule](https://cloud.google.com/load-balancing/docs/using-forwarding-rules) and its corresponding IP address represent the frontend configuration of a load balancer. More about the forwarding rules in the [Forwarding rule overview Guide](https://cloud.google.com/load-balancing/docs/forwarding-rule-concepts).

Separate health checks for load balancing and for autohealing should be used. Health checks for load balancing (determine whether an instance receives user traffic) should be more aggressive because want to catch non-responsive instances quickly so you can redirect traffic if necessary. In contrast, health checking for autohealing (causes Compute Engine to proactively replace failing instances) should be more conservative than a load balancing health check.

Steps needed for HTTP(S) load balancer:
- create the instance template
- create a managed instance group based on the template
- create the health check firewall rule
- create a health check for the load balancer
- set up a global static external IP address of load balancer
- create a backend service
- add your instance group as the backend to the backend service
- create a URL map to route the incoming requests to the backend service
- create a target HTTP proxy to route requests to your URL map
- create a global forwarding rule to route incoming requests to the proxy

More info [here](https://cloud.google.com/compute/docs/load-balancing/http/).

##### SSL proxy 

Global load balancing service for encrypted non-HTTP traffic that terminates user SSL connections at the load balancing layer, then balances the connections across instances using the SSL or TCP protocols.

Provides intelligent routing, certificate management, security patching and SSL policies.

Can reduce the management overhead for instances by using self-signed certificates on instances (and valid certificate on proxy only).

##### TCP proxy 

Global load balancing service for unencrypted, non-HTTP traffic that terminates customer's TCP sessions at the load balancing layer then forwards the traffic to instances using TCP or SSL. 

Provides intelligent routing and security patching. 

##### Network Load Balancer 

Regional, non-proxied load balancing service used to load balance UDP or TCP and SSL traffic on ports that are not supported with the TCP proxy and SSL proxy load balancers. 

Uses a back-end service-based or a target-pool as a destination of the requests.

Back-end services enable new features that are not supported with legacy target pools, support for non-legacy health checks, TCP, SSL, HTTP, HTTPS and HTTP/2 auto-scaling with managed instance groups, connection draining and a configurable failover policy. 

Target pools can only be used with forwarding rules that can handle TCP and UDP traffic. 

Each project can have up to 50 target pools, and each target pool can only have one health check. 

Steps needed for network load balancer:
- create a firewall rule to allow external traffic to the VM instances
- create a static external IP address for your load balancer
- add a legacy HTTP health check resource
- add a target pool in the same region as your instances
- add the instances to the pool
- add a forwarding rule (static external IP address to the pool)

More info [here](https://cloud.google.com/compute/docs/load-balancing/network/).

##### Internal load balancing

Regional private load balancing service for TCP and UDP-based traffic that enables running and scaling of services behind a private load balancing IP address (accessible through internal IP addresses only in the same region).

Not based on a device or on a VM instance but is software-defined, lightweight, fully distributed load balancing built on top of **Andromeda**, Google's network virtualization stack.

##### Internal HTTPS load balancing

Proxy-based regional Layer 7 load balancer that also enables running and scaleing services behind an internal load balancing IP address. Back-end services support HTTP, HTTPS and HTTP/2 protocols. 

Internal HTTPS load balancing is a managed service based on the open source **Envoy** proxy and enables rich traffic control capabilities based on HTTPS parameters. 

#### Cloud CDN

Content Delivery Network uses Google's globally distributed edge points of presence to cache HTTP(S) load-balanced content close to users. Can be enabled with a simple checkbox when setting up the backend service of HTTP(S) load balancer. 

Cache modes control the factors that determine whether or not Cloud CDN caches content:
- **USE_ORIGIN_HEADERS** - requires origin responses to set valid cache directives and valid caching headers
- **CACHE_ALL_STATIC** - in addition to responses that set valid caching directives, it automatically caches static content that doesn't have the no-store, private, or no-cache directive
- **FORCE_CACHE_ALL** - unconditionally caches responses, overriding any cache directives (dangerous if dynamic content is produced by the origin)

More info [here](https://cloud.google.com/cdn/docs/) and [sketchnote](https://thecloudgirl.dev/CDN.html).

#### VPC Service Controls

Improves ability to mitigate the risk of data exfiltration from Google Cloud servicesby creating perimeters that protect the resources and data of services that are explicitly specified.

Provides an extra layer of security defense for Google Cloud services that is independent of Identity and Access Management (IAM). While IAM enables granular identity-based access control, VPC Service Controls enables broader context-based perimeter security, including controlling data egress across the perimeter.

More info [here](https://cloud.google.com/vpc-service-controls/).

#### Network Intelligence Center

Google Cloud service that can be used to visualize your VPC network's topology and test network connectivity.

More info [here](https://cloud.google.com/network-intelligence-center/docs/) and [sketchnote](https://thecloudgirl.dev/nic.html).

#### Rest

- [Cloud DNS](https://cloud.google.com/dns/docs/) - programmable DNS serving and [sketchnote](https://thecloudgirl.dev/CloudDNS.html)
- [Cloud Router](https://cloud.google.com/router/docs/) - VPC/on-prem network route exchange (BGP)
- [Network Telemetry](https://cloud.google.com/vpc/docs/using-flow-logs/) - network telemetry service
- [Traffic Director](https://cloud.google.com/traffic-director/docs/) - service mesh traffic management and [sketchnote](https://thecloudgirl.dev/trafficdirector.html)
- [Cloud Domains](https://cloud.google.com/domains/docs/) - register, transfer, manager domains
- [Service Directory](https://cloud.google.com/service-directory/docs) - centrally publish/discover/connect services and [sketchnote](https://thecloudgirl.dev/servicedirectory.html)
- [Private Service Connect](https://cloud.google.com/vpc/docs/private-service-connect) - privately connect services across VPCs
- [Network Connectivity Center](https://cloud.google.com/network-connectivity/docs/network-connectivity-center) - connect VPC & On-prem
- [Packet Mirroring](https://cloud.google.com/vpc/docs/packet-mirroring) - monitor/analyze instance traffic
- [Cloud IDS](https://cloud.google.com/intrusion-detection-system/docs) - detects network based threats


### Operations & Monitoring

Google Cloud's Operations Suite (Stackdriver) has services for monitoring, logging, error reporting, fault tracing and debugging cross plaform (Google Cloud and AWS), dynamic discovery, open source agents and integrations.

More info [here](https://cloud.google.com/stackdriver/docs).

#### Cloud Monitoring

Infrastructure and application monitoring service that dynamically configures monitoring after resources are deployed and has intelligent defaults that allow easy creation of charts for basic monitoring activities. It allows monitoring of platform, system, and application metrics by ingesting data, such as metrics, events, and metadata. Then one can generate insights from this data through dashboards, charts, and alerts. For example, can configure and measure uptime and health checks that send alerts via email. 

**Note:** Make sure to use multiple notification channels like email and SMS (in case one of them fails).

By default Cloud Monitoring can directly access some metrics including CPU utilization, some disk traffic metrics, network traffic, and uptime information. To access additional system resources and application services metrics, the Monitoring Agent should be installed. 

It is generally recommended to alert on symptoms and not necessarily causes, e.g. monitor failing queries of a database and then identify whether the database is down instead of just monitoring database health state. 

A metrics scope is the root entity that holds monitoring and configuration information in Cloud Monitoring and contains the custom dashboards, alerting policies, uptime checks, notification channels, and group definitions that are used with your monitored projects. The first monitored project in a metrics scope is called the hosting project, and it must be specified when metrics scope is created. 

All users with access to that metric scope have access to all data by default. In order to give people different roles per project and to control visibility of the data, place monitoring of those projects in separate metrics scopes.

More info [here](https://cloud.google.com/monitoring/docs/).

##### Some general info about metrics

Need to be SMART:
- Specific (result in 100ms instead of result is fast)
- Measurable
- Achievable (100% is usually not achievable)
- Relevant
- Time bound (is it per year, per second, ...)

Four golden signals in metrics:
- Latency (page load latency, # requests waiting, query duration, service response time, transaction duration, time of first response, time until complete data return)
- Traffic (# requests per second, # requests for static vs dynamic, network io, # concurrent sessions, # transactions per second, # active connections)
- Saturation (% memory, % thread pools, % cache, % disk, % CPU, Disk quota, Memory Quota)
- Errors (# 400/500 codes, # failed requests, # exceptions, # stack traces, # dropped connections, # liveness checks failed)

**SLI** - Service level indicator is a quantitative measure of some aspect of the level of service being provided. 

**SLO** - Service level objective is an agreed-upon target or range of values for a service level that is measured by an SLI. An example of an SLO is that at average latency of HTTP requests for our service should be less than 100 milliseconds. 

**SLA** - Service level agreement is an agreement between a service provider and a consumer. They define the responsibilities for delivering a service, and consequences when these responsibilities are not met. The SLA is a more restrictive version of the SLO. Architect a solution and maintain an agreed SLO so there is a spare capacity against the SLA.


#### Cloud Logging

Centralized logging service allows to store, search, analyze, monitor, and alert on log data and events from GCP an AWS. It includes storage for logs, a user interface called the log viewer, and an API to manage logs programmatically.

Logs are only retained for 30 days, but can be exported to Cloud Storage buckets, BigQuery datasets and Cloud Pub/Sub topics.

To visualize logs connect BigQuery tables to Data Studio, it transforms raw data into the metrics and dimensions that can be used to create easy to understand reports and dashboards.

Similar to monitoring agent, it's a best practice to install the logging agent on all of VM instances.

More info [here](https://cloud.google.com/logging/docs/).

#### Error Reporting

Error Reporting counts, analyses, and aggregates the errors in running Cloud services. It's interface displays the results with sorting and filtering capabilities and can even set up real-time notifications when new errors are detected.

Stack trace parser is able to process Go, Java, NET, Node.js, PHP, Python, and Ruby.

More info [here](https://cloud.google.com/error-reporting/docs/).

#### Cloud Trace

Distributed tracing system that collects latency data from applications/services and displays it in the GCP console. It can track how request propagate through application and receive detailed near real time performance insights. 

Generates latency reports that show performance degradations from traces captured from App Engine, HTTPS load balancers, and applications instrumented with the Stackdriver Trace API. 

More info [here](https://cloud.google.com/trace/docs/).  

#### Cloud Profiler

Statistical, low-overhead service that continuously gathers CPU usage and memory-allocation information from production applications and attributes that information to the application's source code, helping identifying the parts of the application consuming the most resources.

Profiler is able to profile Go, Java, Node.js, or Pythony.

More info [here](https://cloud.google.com/profiler/docs/).

#### Cloud Debugger

Debugger is a live production debugging service that can inspect the state of a running application in real time without stopping it. The debugger adds less than 10 milliseconds to the request latency when the application state is captured and supports multiple languages, including Java, Python, Go, Node.js, and Ruby.

More info [here](https://cloud.google.com/debugger/docs/).

### Management Tools

#### Cloud Console 

Web-based management console, the one and the greates, first thing used when dealing with Google Cloud :100:

There is also a [Google Cloud](https://cloud.google.com/app) which iOS/Android Google Cloud manager mobile application.

#### VM Manager

A suite of tools that can be used to manage operating systems for large VM groups on Compute Engine by automating:
- patch management
- inventory management
- configuration management

More info [here](https://cloud.google.com/compute/docs/vm-manager).

#### Rest 

- [Cloud APIs](https://cloud.google.com/apis/docs/) - APIs for cloud services
- [Cloud Billing and it API](https://cloud.google.com/billing/docs/) - (programmatically) manage Google Cloud billing and cost
- [Cloud Deployment Manager](https://cloud.google.com/deployment-manager/docs/) - templated infrastructure deployment
- [Private Catalog](https://cloud.google.com/private-catalog/docs/) - internal solutions catalog.
- [Carbon Footprint](https://cloud.google.com/carbon-footprint/docs) - Report and reduce carbon emissions.


### Application Integration

See [sketchnote](https://thecloudgirl.dev/serviceorchestration.html) about service orchestration.

#### Cloud Scheduler

Fully managed enterprise-grade cron job scheduler virtually any job, including batch, big data jobs, cloud infrastructure operations, etc... with automatic retries in case of failure.

More info [here](https://cloud.google.com/scheduler/docs/).

#### Cloud Tasks

Execution, dispatch and delivery of a large number of distributed tasks that work asynchronously outside of a user request or service to service request. Tasks can be executed on App Engine or any arbitrary HTTP endpoint.

More info [here](https://cloud.google.com/tasks/docs/).

#### Rest

- [Eventarc](https://cloud.google.com/eventarc/docs/) - event-driven Cloud Run services
- [Workflows](https://cloud.google.com/workflows/docs/) - HTTP services orchestration


### API Related

See [sketchnote](https://thecloudgirl.dev/apimanagement.html) about API management

#### Cloud Endpoints

An API management gateway that helps develop, deploy, and manage APIs (OpenAPI or gRPC) on any Google Cloud backend. Provides functionality to protect and monitor public APIs, control who has access, using, for example, Auth0 and validate every call with a JSON Web Token signed with the service account private key.

Backend can be:
- App Engine
- Compute Engine
- Kubernetes (including GKE)
- Cloud Functions
- Cloud Run (with or without Anthos)
- A Linux or macOS computer or another platform

In addition can transcode RESTful JSON over HTTP into gRPC requests.

More info [here](https://cloud.google.com/endpoints/docs).

#### Apigee API Platform

Native API management to operate APIs with enhanced scale, security, and automation that can:
- build APIs with backends from any app, system, or service (including ones not hosted on Google Cloud with Apigee Hybrid)
- secure every API transaction 
- monitor and analyze traffic
- create API products to generate new revenue streams

More info [here](https://cloud.google.com/apigee/docs).

Also can enable inteligent protection against bot attacks and similar using [Apigee Sense](https://cloud.google.com/apigee/sense).

#### API Gateway

Fully managed API Gateway 

Provides secure access to backend services through a well-defined REST API that is consistent regardless of the service implementation. 

More info [here](https://cloud.google.com/api-gateway/docs).

#### AppSheet

Build and extend applications without coding (a no-code platform).

More info [here](https://cloud.google.com/appsheet).


### Developer Tools  

#### Cloud SDK

Set of command line tools used to manage resources and applications hosted on Google Cloud, include `gcloud`, `gsutil` and `bq`.

More info [here](https://cloud.google.com/sdk/docs/) and [cheatsheet](https://cloud.google.com/sdk/docs/cheatsheet).

And [gcloud command line cheatsheet](cheatsheets.md#gcloud), [gsutil command line cheatsheet](cheatsheets.md#gsutil) and [bq command line cheatsheet](cheatsheets.md#bq).

#### Cloud Shell

Cloud Shell is an interactive shell environment for Google Cloud executed on a VM instance accessed via web browser. It has Google Cloud CLI and other utilities pre-installed and comes with a built-in code editor allowing one to develop, build, debug, and deploy cloud-based apps entirely in the cloud.

More info [here](https://cloud.google.com/shell/docs/).

#### Cloud Code

IDE support for the full development cycle of Kubernetes and Cloud Run applications. Contains run-ready samples, out-of-the-box configuration snippets, and a tailored debugging experience. Also provides a streamlined experience for creation of clusters hosted on Google Cloud and better integration with Google Cloud services like Cloud Source Repositories, Cloud Storage and Cloud Client Libraries. Can be used with Visual Studio, Visual Studio Code, IntelliJ, or Eclipse and Gradle/Maven.

More info [here](https://cloud.google.com/code/docs/) and [here](https://github.com/GoogleCloudPlatform/app-gradle-plugin).


### DevOps CI/CD

#### Cloud Source Repositories

Service provides private Git repositories hosted on Google Cloud. 

More info [here](https://cloud.google.com/source-repositories/docs/).

#### Container Registry

Was a single place for team to manage Docker images or deployment packages, perform vulnerability analysis, and decide who can access what with fine-grained access control. Superseeded by Artifact Registry, Container Registry is still supported but will only receive critical security fixes. 

More info [here](https://cloud.google.com/container-registry/docs/).

#### Artifact Registry

Artifact Registry is the recommended service for managing Docker container images as well as Java/Node.js/Python packages. 

More info [here](https://cloud.google.com/artifact-registry/docs/).

#### Cloud Build

Executes builds on Google Cloud infrastructure:
- import source code from Cloud Storage, Cloud Source Repositories, GitHub, or Bitbucket
- execute a build per specifications (runs in a Docker container, can do anything that can be done from a container, irrespective of the environment)
- produce artifacts such as Docker containers or Java archives

Can configure the [trigger](https://cloud.google.com/build/docs/triggers) to build on any changes to the source repository or only changes that match certain criteria:

**Note**: In some cases (for example building manually from command line) tarbals of sources are stored in Cloud Storage bucket which is created automatically

More info [here](https://cloud.google.com/cloud-build/docs/) and [sketchnote](https://thecloudgirl.dev/CloudBuild.html).

#### Cloud Deploy

Managed service that automates delivery of applications to GKE cluster, Cloud Run service, or other supported runtime. When want to deploy updated application, create a release, whose lifecycle is managed by a delivery pipeline.

More info [here](https://cloud.google.com/deploy/docs/).

#### Terraform

Terraform is one of the tools used for infrastructure as code not specific to Google Cloud.

It manages provisioning of cloud resources such as virtual machines, containers, storage and networking with the declarative configuration files (using HCL language) and allows for concise descriptions of resources using blocks, arguments and expressions. This approach allows specifying what the configuration should be and let the system figure out the steps to take. 

Infrastructure as code allows for quickly provisioning and removing of infrastructures:
- infrastructure can be provisioned on demand, and the deployment complexity is managed in code
- blueprint of data center can be versioned and treated as any other code
- deployment can be repeated over and over with consistent results
- can delete a whole deployment with one command


Terraform has a planning step in which it generates an **execution plan** which shows what Terraform will do when you the apply command is executed. In addition it builds **a graph** of all resources and parallelizes the creation and modification of any non-dependent resources. With these it is exactly know what Terraform will change and in what order, which helps avoid possible human errors.

Commands :
- `terraform init` - to initialize the new Terraform configuration
- `terraform init -migrate-state` - to initialize the new Terraform configuration and migrate current state to it
- `terraform validate`  - validates the Terraform files
- `terraform plan` - determines what actions are necessary to achieve the desired state specified in the configuration files (convenient way to check changes without making them)
- `terraform apply`   - creates the infrastructure defined in the files 
- `terraform destroy` - destroys the infrastructure defined in the files 
- `terraform import`  - imports existing infrastructure into the files 
- `terraform refresh` - update local state file against real resources
- `terraform taint`   - manually mark a resource for recreation
- `terraform untaint` - manually unmark a resource as tainted
- `terraform show`      - inspect Terraform state or plan
- `terraform graph`     - create a visual graph of Terraform resources
- `terraform console`   - interactive console for Terraform interpolations

Output prefixes:
- `+` means that Terraform will create the resource
- `-` means that Terraform will destroy the resource
- `~` means that Terraform will update the resource in-place. 
- `-/+` means that Terraform will destroy and recreate the resource

By default Terraform writes some data into the terraform.tfstate file. This state file is extremely important because it keeps track of the IDs of created resources. There are backend providers other than local which offer solution for situations when wanting to keep state synced between different developers, machines, etc...

More info [here](https://developer.hashicorp.com/terraform/language), [here](https://registry.terraform.io/providers/hashicorp/google/latest/docs) and [here](https://cloud.google.com/docs/terraform).

See [Terraform sample configurations](cheatsheets.md#terraform).

### Migration to Google Cloud  

See [sketchnote](https://thecloudgirl.dev/datatransfer.html) on various options to move data to Googled Cloud.

To see some other migration paths for whole workloads see [Migration Center](https://cloud.google.com/solutions/migration-center) and [Migration to Google Cloud: Getting started](https://cloud.google.com/architecture/migration-to-gcp-getting-started).

#### Cloud Data Transfer

Can transfer data to cloud using `gsutil` command line utility. In particular `gsutil rsync` for synchronization. Recommended for transfers with less than 1TB data.

More info [here](https://cloud.google.com/storage/docs/gsutil)

#### Storage Transfer Service

Online/on-premises data transfer which can be done in number of ways:
- The Google Cloud console
- REST APIs
- The gcloud command-line tool
- Java and Python client libraries

Supports one time or continuous synchronization. 

Recommended to move or back up data from other cloud storage providers or from on-premise for more than 1TB data.

Supported other cloud providers are:
- Amazon S3
- Microsoft Azure Blob Storage

More info [here](https://cloud.google.com/storage-transfer-service/).

#### Google Transfer Appliance

Rentable high-capacity storage device that which data is uploaded on-premise, securely ship to a Google upload facility, where Google upload data to Cloud Storage. Used if "more than one week to upload data over the network" (which is around, little below, 100 TB at 1GB/s upload speed).

More info [here](https://cloud.google.com/transfer-appliance/docs/).

#### Rest 

- [BigQuery Data Transfer Service](https://cloud.google.com/bigquery/transfer/docs/) - bulk import analytics data
- [Migrate for Anthos and GKE](https://cloud.google.com/migrate/anthos/docs/getting-started) - migrate VMs to GKE
- [Migrate for Compute Engine](https://cloud.google.com/velostrata/docs/) - Compute Engine migration tools


### Identity and Security

#### Cloud IAM

Identity and Access Management (IAM) is a service for creating and managing permissions for Google Cloud  resources, it is a way of identifying who can do what on which resource.

Who can be a person, group or application. What refers to specific privileges or actions, and the resource could be any Google Cloud service.

Components within Cloud IAM are organizations, roles, members and service accounts.

More info [here](https://cloud.google.com/iam/docs/) and [sketchnote](https://thecloudgirl.dev/iamauthorization.html) and [best practices](https://cloud.google.com/iam/docs/using-iam-securely).

##### Roles

A **role** is a list of permissions defined by IAM and can be one of the three types:
- **basic** roles - broad ones (**owner**, **editor** and **viewer**, **billing administrator** - manage billing and add or remove administrators without the right to change the resources)
- **predefined** roles - specific to each service, provides granular access to specific resources, these roles are a collection of permissions, because to do any meaningful operations, one usually needs more than one permission
- **custom** roles - the least privileged model in which each person in organization is given the minimal privileges needed to do their job

**Note:** It's consifered better to use predefined roles over custom roles. Google has predefined roles for a reason, and it should be an exceptional use case that requires custom roles (e.g. production environment required very limited permissions).

**Note:** Custom roles can only be applied at orgs or projects, not folders!

Basic roles:
- **roles/viewer** - permissions for read-only actions that do not affect state, such as viewing (but not modifying) existing resources or data
- **roles/editor** - all viewer permissions, plus permissions for actions that modify state, such as changing existing resources
- **roles/owner** - all editor permissions and permissions for the following actions: Manage roles and permissions for a project and all resources within the project as well as set up billing for a project
- **roles/browser** - read access to browse the hierarchy for a project, including the folder, organization, and Cloud IAM policy (doesn't include permission to view resources in the project).

Some example predefined roles:
- **Google Workspace or Cloud Identity superadmin** - assign organization admin role (point of contact in case of - disaster recovery)
- **Organization admin** - access to administer all resources belonging to his organization, following the- principle  of least privilege, this role, by default, does not include the permission to perform other actions
- **Organization viewer** - view access to all resources
- **Folder admin** - full controlo over folders
- **Folder creator** - browse folder hierarchy and create folders
- **Folder viewer** - view foldersd and projects below folder
- **Project creator** - create and migrate projects (automatically set to owner) within her organization
- **Project deleter** - delete projects
- **Compute Admin** - full control of all Compute Engine resources.
- **Network Admin** - permissions to create, modify and delete network resources, except for firewall rules and SSL - certificates (read only)
- **Storage admin** - contains permissions to create, modify, and delete disks, images, and snapshots

##### Policy 

A **policy** is a collection of access statements attached to a resource that contains a set of roles and role members, with resources inheriting policies from their parent (*child policies cannot restrict access granted at the parent level*). 

**Conditions** allow defining and enforcement of conditional, attribute-based access control for resources. With them one can choose to grant resource access to identities, members, only if configured conditions are met. Implemented using Common Expression Language, or CEL, see more [here](https://cloud.google.com/iam/docs/conditions-overview).

##### Members

There are five different types of **members**:
- Google accounts (user)
- service accounts (application)
- Google Groups (collection of user accounts or service accounts),
- Google Workspace domains (organization's Internet domain name, such as Example.com)
- Cloud Identity domains (lets you manage users and groups using Google Admin console)

It is recommended to create groups. That way, one just need to add members to a group and new members automatically acquire the permissions of the group (same applies for removing members from a group, which also removes the permissions of that group). Groups should be defined carefully and made more granular than job roles, it is better to use multiple groups for better control.

**Note**: IAM cannot be used to create or manage users or groups, Cloud Identity or Workspace is used instead for that purpose.

##### Service account

The service account is the identity of the service/application and defines permissions which control the resources the service/application can access. It is both an identity and a resource:
- used as an identity for your application or service to authenticate, e.g. when a Compute Engine VM running as a service account you need to grant the relevant Cloud IAM roles to the service account
- used as a resource to be permissioned to limit who can create VMs using that service account (**ServiceAccountUser** role used for users trusted to use the service account)

Service accounts differ from user accounts in a few key ways:
- do not have passwords, and cannot log in via browsers or cookies
- associated with public/private RSA key pairs that are used for authentication
- can enable other users or service accounts impersonate a service account
- do not belong to Google Workspace domain

Three types of service accounts:
- all projects come with a built in **default** service account *which is automatically granted editor role on a project*
- **Google Cloud Platform API** service account, designed to run internal Google processes on service/application behalf

There are two types of service account keys:
- GCP managed keys - used by GCP services such as App Engine and Compute Engine, cannot be downloaded and are automatically rotated (used for a maximum of two weeks)
- user managed keys - create a new key pair, download the private key (not retained by Google), user is for security of the private key and rotation (via Cloud IAM API, gcloud command-line tool, or the service accounts page in the Cloud Console), up to 10 key-pairs per service account to support key rotation

To minimize the potential risk caused by unmanaged keys, use **Cloud Key Management Service** (Cloud KMS) to help securely manage keys.

Access scopes are a legacy method of specifying permissions for a VM, before the existence of IAM roles. It is now prederred to use IAM roles for user created service accounts. Scopes are used to determine whether an authenticated identity is authorized. Scopes can be customized when creating an instance using the default service account (Storage, BigQuery, etc...).

More info about service accounts [here](https://cloud.google.com/iam/docs/understanding-service-accounts).

#### Cloud Identity

Managed Identity as a Service (IDaaS). An administrator can use Cloud Identity to manage users, apps, and devices from a central location.

**Cloud Directory Sync** synchronizes (one way, origin is never modified) users and groups from existing active directory or LDAP system with users and groups in Cloud Identity domain. 

Can continue using existing system and processes with SSO configured. When authentication is required, Google will redirect to existing system. If the user is authenticated in existing system, access to Google Cloud is given. Otherwise, the user is prompted to sign in. If existing authentication system supports SAML 2 SSO, configuration is as simple as three links and a certificate.

More info [here](https://cloud.google.com/identity/solutions/overview/) and [sketchnote](https://thecloudgirl.dev/iamauthentication.html).

#### Cloud Identity-Aware Proxy

Enables establishing of a central authorization layer for applications accessed by HTTPS (App Engine standard environment, App Engine flexible environment, Compute Engine, and GKE) instead of relying on network level firewalls. Applications and resources can only be accessed through the proxy by users and groups with the correct Cloud IAM role. 

IAP TCP forwarding allows establishing an encrypted tunnel over which SSH, RDP, and other traffic to private VM instances (without external IP address) is forwarded. In order to connect to private instance through IAP, need to open an appropriate port on the firewall. IAP connections come from a specific set of IP addresses (35.235.240.0/20), hence, can limit firewall rule to this CIDR range only.

See [IAP Desktop](https://github.com/GoogleCloudPlatform/iap-desktop/), a Remote Desktop and SSH client enabling connecting to Google Cloud VM instances using Identity-Aware-Proxy.

More info [here](https://cloud.google.com/iap/docs/).

#### Cloud Data Loss Prevention (DLP)

Fast scalable classification and redaction for sensitive data elements like credit card numbers, names, social security numbers, US and selected international identifier numbers, phone numbers, and Google Cloud credentials.

Data can be in Cloud Storage, BiqQuery or Firestore and can also scan images.

Cloud DLP classifies this data using more than 90 predefined detectors to identify patterns, formats, and checksums, and even understands contextual clues. 

Can optionally redact data as well, using techniques like masking, secure hashing, tokenization, bucketing, and format preserving encryption.

More info [here](https://cloud.google.com/dlp/docs/) and [sketchnote](https://thecloudgirl.dev/dlp.html) and few blog posts [here](https://cloud.google.com/blog/products/identity-security/taking-charge-of-your-data-using-cloud-dlp-to-de-identify-and-obfuscate-sensitive-information) and [here](https://cloud.google.com/architecture/de-identification-re-identification-pii-using-cloud-dlp).

#### Identity Platform

Identity Platform is a service that make it easy (by providing  back-end services, SDKs, and UI libraries) to authenticate users to your apps and services. In other words, it provides sign up and sign-in for end user applications. A broad range of protocol support is available, including SAML, OpenID, e-mail and password, phone, social, and Apple.

More info [here](https://cloud.google.com/identity-platform/docs).

#### Binary Authorization

Service that provides software supply-chain security for container-based applications. Configure a policy that the service enforces when an attempt is made to deploy a container image on one of the supported container-based platforms.

More info [here](https://cloud.google.com/binary-authorization/docs/).

#### Security standards

Important security standards and compliance: 
- [PCI DSS](https://cloud.google.com/security/compliance/pci-dss)
- [HIPAA](https://cloud.google.com/security/compliance/hipaa)
- [COPPA](https://cloud.google.com/security/compliance/coppa)
- [GDPR](https://cloud.google.com/privacy/gdpr)

#### Rest

- [Access Transparency](https://cloud.google.com/logging/docs/audit/access-transparency-overview/) - audit cloud provider access
- [Assured Workloads](https://cloud.google.com/assured-workloads/docs) - workload compliance controls
- [Certificate Authority Service](https://cloud.google.com/certificate-authority-service/docs) - managed private CAs
- [Cloud Asset Inventory](https://cloud.google.com/asset-inventory/docs/overview) - all assets, one place
- [Cloud Audit Logs](https://cloud.google.com/logging/docs/audit/) - audit trails for Google Cloud
- [Cloud HSM](https://cloud.google.com/kms/docs/hsm/) - hardware security module service
- [Cloud External Key Manager (EKM)](https://cloud.google.com/kms/docs/ekm/) - controlling external keys
- [Cloud Key Management Service](https://cloud.google.com/kms/docs/) - hosted key management service
- [Resource Manager](https://cloud.google.com/resource-manager/docs/) - project metadata management
- [Security Command Center](https://cloud.google.com/security-command-center/docs/) - security management and data risk platform
- [Managed Service for Microsoft Active Directory](https://cloud.google.com/managed-microsoft-ad/docs/) - managed Microsoft Active Directory
- [Secret Manager](https://cloud.google.com/secret-manager/docs/) - store and manage secrets
- [Titan Security Key]https://cloud.google.com/titan-security-key/) - two-factor authentication (2FA) device
- [VPC Service Controls](https://cloud.google.com/vpc-service-controls/docs/) - VPC data constraints
- [Chronicle](https://chronicle.security/products/platform) - find threats from security telemetry
- [VirusTotal](https://chronicle.security/products/virustotal/) - research/hunt for malware 
- [Risk Manager](https://cloud.google.com/risk-manager/docs) - evaluate organization's security posture 
- [reCAPTCHA Enterprise](https://cloud.google.com/recaptcha-enterprise/docs/) - protection against bot/spam/abuse
- [BeyondCorp Enterprise](https://cloud.google.com/beyondcorp-enterprise/docs) - zero trust secure access and [sketchnote](https://thecloudgirl.dev/zerotrustbeyondcorp.html).
- [Access Context Manager](https://cloud.google.com/iap/docs/cloud-iap-context-aware-access-howto/) - end-user attribute-based access control
- [Access Context Manager](https://cloud.google.com/access-context-manager/docs) - fine-grained, attribute based access-control
- [Web Security Scanner](https://cloud.google.com/security-command-center/docs/concepts-web-security-scanner-overview) - identifies web-app security vulnerabilities
- [Web Security Scanner](https://cloud.google.com/security-scanner/docs/) - app engine security scanner


### Hybrid and multi-cloud

- [Anthos](https://cloud.google.com/anthos/docs/) - enterprise hybrid/multi-cloud platform and [one sketchnote](https://thecloudgirl.dev/AnthosDeployment.html) and [another sketchnote](https://thecloudgirl.dev/Anthos.html)
- [Anthos clusters](https://cloud.google.com/anthos/gke/docs/on-prem/) - hybrid/on-premises GKE
- [Anthos Config Management](https://cloud.google.com/anthos-config-management/docs) - policy and security automation.
- [Anthos Service Mesh](https://cloud.google.com/service-mesh/docs) - managed service mesh (Istio)
- [Cloud Run for Anthos](https://cloud.google.com/run/docs/quickstarts/prebuilt-deploy-gke) - serverless development for Anthos
- [Google Cloud Marketplace for Anthos](https://cloud.google.com/marketplace/docs/kubernetes-apps) - pre-configured containerized apps
- [Migrate for Anthos and GKE](https://cloud.google.com/migrate/anthos/docs/getting-started) - migrate VMs to GKE
- [Traffic Director](https://cloud.google.com/traffic-director/docs/) - service mesh traffic management


### AI and ML

See [sketchnote](https://thecloudgirl.dev/datascience.html) about data science in Google Cloud.


- [Deep Learning VM Images](https://cloud.google.com/deep-learning-vm/docs/) - preconfigured VMs for deep learning
- [Deep Learning Containers](https://cloud.google.com/ai-platform/deep-learning-containers/docs/) - preconfigured containers for deep learning
- [Cloud TPU](https://cloud.google.com/tpu/docs/) - hardware acceleration for ML
- [Vertex AI](https://cloud.google.com/vertex-ai) - managed platform for ML
  - [AutoML](https://cloud.google.com/vertex-ai/docs/training-verview#automl) - custom low-code models
  - [Data Labeling](https://cloud.google.com/vertex-ai/docs/tart/ai-platform-users#data_labeling) - data labeling by humans
  - [Workbench](https://cloud.google.com/ertex-ai/docs/workbench) - Jupyter-based environment for Data Science
  - [Matching Engine](https://cloud.google.com/vertex-ai/ocs/matching-engine) - vector similarity searches
  - [Predictions](https://cloud.google.com/ai-platform/rediction/docs/overview) - autoscaled model serving
  - [Training](https://cloud.google.com/ai-platform/training/ocs/overview) - distributed AI training
  - [Explainable AI](https://cloud.google.com/vertex-ai/ocs/explainable-ai) - understand ML model predictions.
  - [Feature Store](https://cloud.google.com/vertex-ai/ocs/featurestore/overview) - managed ML feature repository
  - [Metadata](https://cloud.google.com/ertex-ai/docs/ml-metadata/introduction) - artifact, lineage, and execution tracking
  - [Model Monitoring](https://cloud.google.com/vertexi/docs/model-monitoring/overview) - monitor models for skew/drift
  - [Tensorboard](https://loud.google.com/vertex-ai/docs/experiments/tensorboard-overview) - managed TensorBoard for ML-experiment Visualization
  - [Vizier](https://cloud.google.com/vertex-ai/docsizier) - black-box hyperparameter tuning
- [Speech-To-Text](https://cloud.google.com/speech/docs/) - convert audio to text
- [Text-To-Speech](https://cloud.google.com/text-to-speech/docs/) - convert text to audio
- [Cloud Translation](https://cloud.google.com/translate/docs/) - language detection and translation
- [Natural Language](https://cloud.google.com/natural-language/docs/reference/rest) - natural language understanding (sentiment analysis, entity recognition, entity sentiment analysis, and other text annotations)
- [Contact Center AI](https://cloud.google.com/solutions/contact-center/) - AI in your contact center
- [Dialogflow](https://cloud.google.com/dialogflow-enterprise/docs/) - create conversational interfaces
- [Document AI](https://cloud.google.com/document-understanding/docs/) - analyze, classify, search documents
- [Recommendations AI](https://cloud.google.com/recommendations-ai/docs/) - create custom recommendations
- [Talent Solutions](https://cloud.google.com/job-discovery/docs/) - job search with ML
- [Cloud Video Intelligence API](https://cloud.google.com/video-intelligence/docs/) - scene-level video annotation
- [Cloud Vision](https://cloud.google.com/vision/docs/) - image recognition and classification
- [Vision Product Search](https://cloud.google.com/vision/product-search/docs/) - visual search for products


### Mobile (Firebase)  
  
- [Cloud Firestore](https://firebase.google.com/products/firestore/) - document store and sync
- [Cloud Functions for Firebase](https://firebase.google.com/products/functions/) - event-driven serverless applications
- [Cloud Storage for Firebase](https://firebase.google.com/products/storage/) - object storage and serving
- [Crashlytics](https://fabric.io/kits/android/crashlytics/summary) - crash reporting and analytics
- [Firebase A/B Testing](https://firebase.google.com/products/ab-testing/) - create A/B test experiments
- [Firebase App Distribution](https://firebase.google.com/products/app-distribution/) - trusted tester early access
- [Firebase Authentication](https://firebase.google.com/products/auth/) - drop-in authentication
- [Firebase Cloud Messaging](https://firebase.google.com/products/cloud-messaging/) - send device notifications
- [Firebase Dynamic Links](https://firebase.google.com/products/dynamic-links/) - link to app content
- [Firebase Extensions](https://firebase.google.com/products/extensions) - pre-packaged development solutions
- [Firebase Hosting](https://firebase.google.com/products/hosting/) - web hosting with CDN/SSL
- [Firebase In-App Messaging](https://firebase.google.com/products/in-app-messaging/) - send in-app contextual messages
- [Firebase Performance Monitoring](https://firebase.google.com/products/performance/) - app/web performance monitoring
- [Firebase Predictions](https://firebase.google.com/products/predictions/) - predict user targeting
- [Firebase Realtime Database](https://firebase.google.com/products/realtime-database/) - real-time data synchronization
- [Firebase Remote Config](https://firebase.google.com/docs/remote-config/) - remotely configure installed apps
- [Firebase Test Lab](https://firebase.google.com/docs/test-lab/) - mobile testing device farm
- [Google Analytics for Firebase](https://firebase.google.com/products/analytics/) - mobile app analytics
- [ML Kit for Firebase](https://firebase.google.com/products/ml-kit/) - ML APIs for mobile

## Some of the references

- [Google Cloud documentation](https://cloud.google.com/docs/)
- [Google Cloud Products in 4 words or less](https://github.com/priyankavergadia/google-cloud-4-words)
- [The Google Cloud Developer's Visual Notes](https://github.com/priyankavergadia/GCPSketchnote) or [The Cloud Girl](https://thecloudgirl.dev/)
- [Google Cloud Skills Boost](https://www.cloudskillsboost.google/)

  
## Additional Resources

- [Google Cloud Blog](https://cloud.google.com/blog)
- [Google Cloud Platform Podcast](https://GoogleCloudpodcast.com/)
- [Kubernetes Podcast from Google](https://kubernetespodcast.com/)
- [Google Cloud Medium Publication](https://medium.com/google-cloud)
- [Google Cloud Certifications](https://cloud.google.com/certification)
- [Google Developers Blog](https://developers.googleblog.com) 
- [Kubernetes Blog](https://kubernetes.io/blog)
- [Google Cloud Architecture Diagram Tool](https://googlecloudcheatsheet.withgoogle.com/architecture)
- [Google Codelabs Git](https://github.com/orgs/googlecodelabs/repositories?type=all)
