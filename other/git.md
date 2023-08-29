# Simple GIT commands

<!-- toc -->

- [Basics](#basics)
  * [Offline work](#offline-work)
- [Configuration](#configuration)
  * [Config levels](#config-levels)
  * [Basics](#basics-1)
  * [Show config with source and scope](#show-config-with-source-and-scope)
  * [Set author name and email](#set-author-name-and-email)
  * [Enable usage of symlinks](#enable-usage-of-symlinks)
  * [Enable long path support under Windows](#enable-long-path-support-under-windows)
  * [Set Notepad++ as core editor](#set-notepad-as-core-editor)
  * [Rebase instead of merge](#rebase-instead-of-merge)
  * [Automatically recurse submodules](#automatically-recurse-submodules)
  * [Include/Exclude LFS](#includeexclude-lfs)
- [Clone](#clone)
  * [Single branch](#single-branch)
  * [Shallow](#shallow)
- [Commit](#commit)
  * [Commit all](#commit-all)
  * [Author and date](#author-and-date)
- [Push](#push)
  * [Submodules](#submodules)
- [Pull](#pull)
  * [Merge](#merge)
  * [Rebase](#rebase)
  * [Pull with submodules](#pull-with-submodules)
  * [Merge via pull](#merge-via-pull)
  * [Shallow](#shallow-1)
- [Reset](#reset)
- [Cherry-pick](#cherry-pick)
- [Log](#log)
  * [Sorting](#sorting)
  * [Formatting options](#formatting-options)
  * [Show graph](#show-graph)
  * [Ref names in log](#ref-names-in-log)
  * [Other](#other)
- [Branch](#branch)
  * [List all branches](#list-all-branches)
  * [Create new branch](#create-new-branch)
  * [Switch branch](#switch-branch)
  * [Delete branch](#delete-branch)
- [Large File Storage](#large-file-storage)
  * [Import existing files to LFS](#import-existing-files-to-lfs)
  * [Track new files as LFS](#track-new-files-as-lfs)
  * [Track and make lockable](#track-and-make-lockable)
  * [Make file lockable but not LFS](#make-file-lockable-but-not-lfs)
  * [Clone without fetching LFS files](#clone-without-fetching-lfs-files)
  * [Prune](#prune)
- [Misc](#misc)
  * [Git commands with bash autocomplete](#git-commands-with-bash-autocomplete)

<!-- tocstop -->

## Basics

### Offline work

When working off line, two Git tasks cannot be performed: fetching/pulling updates from the server, 
and pushing changes to the server. All other commands work. 

**Note:** All other commands actually work on local clone of the repository so the don't need access to the remote server.
**But they work on the data last fetched/pulled, not the data that is on the server!!!**

## Configuration

### Config levels

- System - applies to whole machine (`git config --system`)
- Global - applies to single user and all his/her repositories (`git config --global`)
- Local/Repository - applies to single repository (`git config` with no flags)
- There is also worktree one..... [more on worktrees](https://levelup.gitconnected.com/git-worktrees-the-best-git-feature-youve-never-heard-of-9cd21df67baf)

### Basics

To set config: `git config [--system/--global] config.name value`.

To unset config: `git config [--system/--global] --unset config.name`.

To get effective config value: `git config --get config.name`.

To list all values: `git config [--system/--global] --list`.

### Show config with source and scope

Show config for git repository (starts with system, then global, then local/repository specific).

```
D:\Projects\some_git>git config --list --show-origin --show-scope
system  file:C:/Program Files/Git/etc/gitconfig core.symlinks=false
system  file:C:/Program Files/Git/etc/gitconfig pull.rebase=false
global  file:C:/Users/Admin/.gitconfig  user.name=tomy2105
global  file:C:/Users/Admin/.gitconfig  user.email=t.petrovic@inet.hr
local   file:.git/config        submodule.recurse=true
local   file:.git/config        push.recursesubmodules=check
```

### Set author name and email

```
git config [--system/--global] user.name "Tomislav Petrovi�"
git config [--system/--global] user.email t.petrovic@inet.hr
```

### Enable usage of symlinks

```
git config [--system/--global] core.symlinks true
```

### Enable long path support under Windows 

Git has a limit of 4096 characters for a filename, except on Windows when Git is compiled with msys. 

Msys uses an older version of the Windows API and there's a limit of 260 characters for a filename, it's a limitation of msys and not of Git (https://github.com/msysgit/git/pull/110).

Either use another Git client on Windows or:
```
git config [--system/--global] core.longpaths true
```

### Set Notepad++ as core editor

```
git config [--system/--global] core.editor "'C:/Program Files/Notepad++/notepad++.exe' -multiInst -notabbar -nosession -noPlugin"
```


### Rebase instead of merge

Make pull commands rebase instead of merge.

```
git config [--system/--global] pull.rebase true
```


### Automatically recurse submodules

For fetching and pulling:
```
git config pull.recursesubmodules true
git config fetch.recursesubmodules true
git config submodule.recurse true
```

For pushing there is `check` (just check if submodule's SHA is present on remote) and `on-demand` (push submodule too if needed):
```
git config push.recursesubmodules check
```

### Include/Exclude LFS

```
git config lfs.fetchexclude "BigFiles/*,*.zip"
git config lfs.fetchinclude "MustHave/*,*.pdf"
```


## Clone

Clones a repository into a newly created directory and creates and checks out an initial branch from the cloned repository’s branch.

```
git clone --progress --branch branch_name https://gitserver/some.git some-folder
```

**Note:** `--progress` is optional and displays progress on standard error


### Single branch

```
git clone --branch branch_name --single-branch https://gitserver/some.git some-folder
git submodule update --single-branch --init
```

If want to fetch all branches afterwards:
```
git config remote.origin.fetch "+refs/heads/*:refs/remotes/origin/*" 
git remote update 
git submodule update --init
```

### Shallow

**Note:** when operating on shallow clone some merges can fail if merge base revision is not present in shallow history!

Fetch only `n` history items:
```
git.exe clone --depth n https://gitserver/some.git some-folder
git submodule update --init --depth n
git.exe clone --recursive --shallow-submodules --depth n https://gitserver/some.git some-folder

```

***Note:** There is also `--depth n` on `pull` command too!

Fetch only history since:
```
git.exe clone --shallow-since "Jan 01, 2023" https://gitserver/some.git some-folder
git submodule update --init --shallow-since "Jan 01, 2023" 
git.exe clone --recursive --shallow-submodules --shallow-since "Jan 01, 2023" https://gitserver/some.git some-folder
```

If want to fetch all branches afterwards:
```
git fetch --unshallow
```

## Commit

Create a new commit containing the current contents of the change index (if no specific items are specified).
Items are added to change index using `git add` or `git rm`.

### Commit all

Commit all modified know files and automatically remove know file that have been delete from working tree.

```
git commit -all --message "Message"
```

### Author and date

```
git commit --message "Message" --author "tomy2105 <t.petrovic@inet.hr" --date "some date" file.txt
```

## Push

Push local changes to the remote. If target is not specified pushes pushes to (simplified, red the help!!!) origin and the corresponding remote branch.

-`--all` - pushes all branches
-`--prune` - deletes remote branches that don't have local counterparts
-`--delete` - deletes remote branch
-`--tags` - pushes all tags

### Submodules

```
git push --recurse-submodules check
```

-`check` - verify that all submodule commits are available on at remote of the submodule
-`on-demand` - all submodules will be pushed too (if needed)
-`only` - all submodules will be pushed, superproject is left unpushed
-`no` - don't push submodules even if config requires it

## Pull

Default strategy (merge or rebase) is determined by config [Rebase instead of merge](#rebase-instead-of-merge).

### Merge

```
          A---B---C master on origin
         /
    D---E---F---G master
        ^
        origin/master in local repository
        
git pull --no-rebase


          A---B---C origin/master
         /         \
    D---E---F---G---H master

```


### Rebase

```
          A---B---C master on origin
         /
    D---E---F---G master
        ^
        origin/master in local repository
        
git pull --rebase
           
    D---E---A---B---C---F'---G' master
                    ^
                    origin/master

F' - commit F replayed on top of C
G' - commit G replayed on top of F'
```


### Pull with submodules

```
git pull
git submodule update --init
```

or

```
git pull --recurse-submodules
```

### Merge via pull

Behind the scenes pull does merge or rebase so if you specify to pull different branch you can use pull to merge branches.

```
git pull --no-rebase origin otherBranch
```

```
git pull --rebase origin otherBranch
```


### Shallow

Flags existing on clone also exist on pull for further manipulation of shallow history.

## Reset

Go back to previous index and local file state.

**Note:** there is also `revert` that creates new commit that undoes changes, `reset` goes to previous state (as if commits in between did not exist).

See [explanation of reset modes](https://stackoverflow.com/questions/34149356/what-exactly-is-the-difference-between-all-the-git-reset-modes).

## Cherry-pick

"Replay" selected commits from one branch onto another.

```
git cherry-pick -x commitSha
```

**Note:** `-x` adds an sha hash/link of existing commit into default commit message of new commit.

## Log

There are two timestamp, and two emails/names (author and committer), associated with each commit:
- author timestamp - timestamp commit has been initial committed 
- commit timestamp - timestamp commit has been last modified (for example by rebase).

### Sorting

Parent commits are always shown before/after child ones but when having parallel history there are various sorting options:
- `--date-order` - show commits in the commit timestamp order
- `--author-date-order` - show commits in the author timestamp order
- `--topo-order` - avoid showing commits on multiple lines of history intermixed
- `--reverse` - output the commits in reverse order (applied after filtering)

### Formatting options

Set with `--pretty` or `--format`, some are:
-`oneline` - hash and message in one line
-`short` - hash, author and message each on own line(s)
-`medium` - hash, author, author date  and message each on own line(s)
-`full` - hash, author and committer each on own line(s)
-`fuller` - hash, author, author date, committer, commit date and message each on own line(s)
-`format:<string>`

For descriptions of all formats see [here](https://www.git-scm.com/docs/git-log/#_pretty_formats).

### Show graph

Graph is best combined with some oneline output (otherwise IMHO unreadable).

```
git log --graph --oneline 
```

### Ref names in log

Decorate `--decorate` determines if ref names are displayed and how:
-`short` - default, ref name prefix is not shown (e.g. `origin/master`)
-`full` - full ref name is displayed (e.g. `refs/remotes/origin/master`)
-`auto` - `short` if on terminal, `no` otherwise
-`no` - no ref names displayed

There is also `log.decorate` config value to override the default `auto`.

### Other

-`--all` - all branches (default is only current one)
-`--follow` - follow renames
-`-<number>`, `-n <number>` or `--max-count=<number>` - limit the number of commits shown
-`--skip=<number>` - skip number commits before starting
-`--since=<date>` or `--after=<date>` - commits more recent than a specific date
-`--until=<date>` or `--before=<date>` - commits older than a specific date.
-`--author=<pattern>` and/or `--committer=<pattern>` - limit the commits to ones with author/committer specified
-`--patch` - generate and show patch
-`--name-only` - show names of changed files
-`--name-status` - show names and status of changed files

And many [others](https://www.git-scm.com/docs/git-log/).

## Branch

### List all branches

Local and remote:
```
git branch -a
```

### Create new branch

And switch to it.
```
git checkout -b newBranchName existingBranchName
```

**Note:** using `-B` instead of `-b` overrides (read destroys) local branch `newBranchName` if it exists (along with all its unpushed/unmerged commits).

Create but don't switch to it.
```
git branch newBranchName existingBranchName
```

**Note:** `existingBranchName` is optional, uses current branch if not specified. And it can also be a hash or tag, not just branch name.

### Switch branch

```
git checkout branchName
```

### Delete branch

To delete local branch.
```
git branch -d/-D branchName
```

To delete remote branch

```
git push -d remoteName branchName
```



## Large File Storage

Replaces large files with text pointers inside Git, while storing the file contents on a remote server.

**After each change don't forget to commit and push `.gitattributes`!**

Git LFS lockable files will be read-only on the local file system automatically. This prevents users from accidentally editing a file without locking it first.

### Import existing files to LFS

```
git lfs migrate import --everything --include="*.mpg"
git lfs push --all
```

If push above hangs (https://github.com/git-lfs/git-lfs/issues/4350) then instead of push do:
```
git lfs uninstall # disable LFS hooks
git lfs push origin --object-id `find lfs/objects/ -type f -printf "%f "` # push LFS objects
git push # push regular Git objects
git lfs install # re-enable LFS hooks
```
**Workaround works for reasonable amount of lfs files (there is a limit on how many ids can be passed)! After that you need to split into more lfs pushes.**

### Track new files as LFS

```
git lfs track "*.mpg"
```

### Track and make lockable

**Bitbucket (as of July 2023) [does not support LFS locking](https://jira.atlassian.com/browse/BCLOUD-14454)!!!**

```
git lfs track "*.mpg" --lockable
```

### Make file lockable but not LFS

Just append line to `.gitattributes`:
```
*.txt lockable
```

### Clone without fetching LFS files

```
GIT_LFS_SKIP_SMUDGE=1 git clone  https://gitserver/some.git some-folder
```

On Windows:
```
set GIT_LFS_SKIP_SMUDGE=1 
git clone  https://gitserver/some.git some-folder
```

Afterwards to fetch LFS files (but before that configure [Include/Exclude LFS](#includeexclude-lfs)!):
```
git lfs pull
```

[Include/Exclude LFS](#includeexclude-lfs) configuration can be specified while cloning:
```
set GIT_LFS_SKIP_SMUDGE=1 
git clone --config lfs.fetchexclude="BigFiles/*,*.zip" --config lfs.fetchinclude="MustHave/*,*.pdf" https://gitserver/some.git some-folder
```

Or add exclude/include just for this pull via:
```
git lfs pull --exclude "BigFiles/*,*.zip" --include "MustHave/*,*.pdf"
```

To later temporary pull just one file which is exclude via [Include/Exclude LFS](#includeexclude-lfs):
```
git lfs pull --exclude "" --include "zlib/zlib.3.pdf"
```

Or change [Include/Exclude LFS](#includeexclude-lfs) config and `git lfs pull` again.

### Prune

Deletes local copies of LFS files which are old, thus freeing up disk space.

```
git lfs prune
```


## Misc

### Git commands with bash autocomplete

```
apt-get install git-core bash-completion
```
