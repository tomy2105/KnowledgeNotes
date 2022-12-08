# Microservices, Docker and Kubernetes

<!-- toc -->

- [Microservices](#microservices)
  * [State](#state)
  * [Designing microservice system](#designing-microservice-system)
  * [12-factor design](#12-factor-design)
- [Docker / Containers in general](#docker--containers-in-general)
- [Kubernetes](#kubernetes)
  * [Kubernetes parts](#kubernetes-parts)
  * [Namespaces](#namespaces)
  * [Pods](#pods)
  * [Pod Networking](#pod-networking)
  * [Pod Storage](#pod-storage)
  * [Deployment](#deployment)
  * [Service](#service)
  * [Other resources](#other-resources)
  * [Affinities](#affinities)
  * [Scaling](#scaling)
    + [Vertical Pod Autoscaler](#vertical-pod-autoscaler)
    + [Cluster Autoscaler](#cluster-autoscaler)
  * [Kubernetes' built-in role-based access control (RBAC)](#kubernetes-built-in-role-based-access-control-rbac)
- [Deployments and testing](#deployments-and-testing)
  * [Blue-green deployments](#blue-green-deployments)
  * [Canary deployments](#canary-deployments)
  * [A/B testing](#ab-testing)
  * [Shadow testing](#shadow-testing)
- [Some of the references](#some-of-the-references)

<!-- tocstop -->

## Microservices

The current industry trends which divide a large program into a number of smaller, independent services. 

**Cons**:
- enable teams to work independently and deliver through to production at their own cadence
- allow for independent deployment cycles, including rollback
- increase overall application scalability and reliability through scaling smaller units (able to scale the microservices independently based on their requirements)
- define strong contracts between the various microservices
- minimize test automation and quality assurance overhead
- improve clarity of logging and monitoring
- provide fine-grained cost accounting

**Challenges**:
- difficult to define clear boundaries between services to support independent development and deployment
- increased complexity of infrastructure, with distributed services having more points of failure
- increased latency introduced by network services and the need to build in resilience to handle possible failures and delay
- need to provide security for service-to-service communication, which increases complexity of infrastructure
- requirement to manage and version service interfaces, the need to maintain backward compatibility increases

A little bit Google specific but still general [Sketchnote](https://thecloudgirl.dev/microservices.html) about microservices.

### State 

To achieve complete independence on services, each service should have its own datastore. This lets the best datastore solution for that service to be selected and also keeps the services independent (do not want to introduce coupling between services through a datastore).

Services that do not maintain state but obtain their elewhere (stateless services) are easier to manage. They are easy to scale, to administer and to migrate to new versions because of their lack of state. 

It is generally not possible to avoid using stateful services at some point. Stateful services introduce significant challenges in the ability to scale and upgrade the services (sticky sessions, etc...).

A recognized best practice for designing stateful services is to use backend storage services that are shared by frontend, stateless services. For example, for persistent state stored in some database (SQL or NoSQL) may be suitable. Then to improve the speed of data access, the data can be cached (e.g. Redis). 

### Designing microservice system

Decompose the application by feature or functional groupings to minimize dependencies (product management, reviews, accounts and orders for imaginary sales service), groupings form many applications which expose an API.

Each of these many applications will be implemented by potentially multiple microservices internally, these microservices are then organized by architectural layer, and each should be independently deployable and scalable.

Shared services, such as authentication, are then isolated and deployed separately.

### 12-factor design 

Help decouple components of the application, so that each component can be deployed to the cloud, using continuous deployment and scale up or down seamlessly:
- codebase should be tracked in a version control
- dependencies should be declared explicitly and stored in version control, dependency tracking is performed by language-specific tools, an app and it's dependencies can be isolated by packing them into a container
- every application has a configuration for different environments, this configuration should be kept external to the code and is usually kept in environment variables for deployment flexibility
- every backing service, such as database, cache, or message service, should be accessed via URLs and set by configuration (aim is to be able to swap one backing service for a different implementation, easily)
- software deployment process should be broken into three distinct stages: build, release, and run, each stage should result in an artifact that is uniquely identifiable (allows for easy rollbacks and a visible audit trail of the history of every production deployment)
- services should be exposed using a port number, the applications bundle the web server as part of the application and do not require a separate server
- application should be able to scale out by starting new processes and scale back in as needed to meet demand and load
- applications should be written to be more reliable than the underlying infrastructure which means they should be able to handle temporary failures in the underlying infrastructure and gracefully shut down and restart quickly (acquiring and releasing resources as needed)
- aim should be to have the same environments used in development and test/staging as are used in production, infrastructure as code and Docker containers make this easier
- decouple the collection, processing, and analysis of logs from the core logic of your apps, logging should be to the standard output and aggregating into a single source
- admin processes, usually one-off processes that should be decoupled from the application, should be automated and repeatable, not manual, processes

## Docker / Containers in general

Docker is free platform (with paid additions) used to build and run containers.

Containers are isolated user spaces (all the code that resides above the kernel, includes the applications and their dependencies) for running application code. They are lightweight because they don't carry a full operating system, and can be created and shut down very quickly because you're just starting and stopping the processes that make up the application and not booting up an entire VM and initializing an operating system for each application.

A container image is structured in layers, each instruction in the Dockerfile specifies a layer inside the container image, and are read only. 

When a container runs, it also hasa writable ephemeral topmost layer, all changes made to the running container are written to this thin writable container layer which is lost **forever** when the container is deleted.

Containers use Linux cgroups to control what an application can use, its maximum consumption of CPU time, memory, IO bandwidth, and other resources.

See [docker command line cheatsheet](cheatsheets.md#docker).


## Kubernetes

Kubernetes is an open source platform that helps orchestrate and manage container infrastructure on-premises or in the Cloud. It automates the deployment, scaling, load balancing, logging, monitoring, and other management features of containerized applications. 

Kubernetes supports declarative configurations. Desired state is described and it is Kubernetes' job is to make the deployed system conform to the desired state and then keep it there in spite of failures. Kubernetes also allows imperative configuration in which commands are issued to change the system state but such approach is used only for quick temporary fixes and as a tool in building a declarative configuration.

See [kubectl command line cheatsheet](cheatsheets.md#kubectl).

### Kubernetes parts

One computer is called the control plane and the others are simply called nodes. The job of the nodes is to run parts.

The job of the control plane is to coordinate the entire cluster:
- **Kube-APIserver** -  accept (internal - parts of K8s system and external - *kubectl*) commands that view or change the state of the cluster, including launching pods
- **Etcd** - clusters database, reliably store the state of the cluster, configuration data and more dynamic runtime information
- **Kube-scheduler** - responsible for scheduling pods onto nodes
- **Kube-controller-manager** - continuously monitors the state of the cluster through kube-APIserver, whenever the current state of the cluster doesn't match the desired state, kube-controller-manager will attempt to make changes to achieve the desired state
- **Kube-cloud manager** - manages controllers that interact with the underlying cloud providers
- **Kube-proxy** - maintain the network connectivity among the pods in the cluster

Each node runs a **kubelet**, a Kubernetes agent on each node. When the Kube-APIserver wants to start a pod on a node, it connects to that nodes kubelet. Kubelet uses the container runtime to start the pod and monitors its life cycle, including readiness and liveliness probes and reports back to Kube-APIserver.

### Namespaces

Kubernetes abstracts a single physical cluster into multiple clusters known as **namespaces**, they provide scope for naming resources such as Pods, Deployments, and controllers. 

There are three initial namespaces in a cluster:
- **default** - the default namespace used when no other namespace is specified
- **kube-node-lease** - manages the lease objects associated with the heartbeats of each of the cluster's nodes
- **kube-public** - to be used for resources that may need to be visible or readable by all users throughout the whole cluster
- **kube-system** - used for components created by the Kubernetes system

Not everything belongs to a namespace. For example, nodes, persistent volumes, and namespaces themselves do not belong to a namespace.

### Pods

Kubernetes represents applications as Pods, which are units that represent a container (*or group of tightly-coupled containers*). The Pod is the smallest deployable unit in Kubernetes. 

Pods provide a shared namespace for their contents which means that the two containers inside of our example pod can communicate with each other, and they also share:
- attached volumes
- network namespace - there is one IP address per pod

Lifecycle:
- **Pending** - Pod has been created  but one or more of its containers are not yet running
- **Running** - Pod has been bound to a node, and all of the containers have been created. At least one container is running, is in the process of starting, or is restarting.
- **Succeeded** - All containers in the Pod have terminated successfully. Terminated Pods do not restart.
- **Failed** - All containers in the Pod have terminated, and at least one container has terminated in failure.
- **Unknown** - The state of the Pod cannot be determined.

### Pod Networking

Each Pod has a unique IP address (like any host on the network).

On a node, the Pods are connected through node's network namespace, which allows the two Pods to communicate on the same node.

Nodes network namespace is connected to the node's primary NIC and is able to forward traffic out of that node. IP addresses on the Pods must be routable on the network that the node is connected to.

### Pod Storage

Kubernetes provides through **Volumes** and **PersistentVolumes** resources.

A **Volume** is a directory which is accessible to all of the containers in a Pod (attached to a Pod and not a container), some are are ephemeral (last only as long as the Pod) and others are persistent (can outlive a Pod).

Ephemeral Volumes are:
- **EmptyDir** - simply an empty directory that allows the containers within the Pod to read and write to it and from it (deleted when pod is removed, usually created from the node's local disk or by using a memory backed file system)
- **Configmap** - a way to inject application configuration data into Pods, data in it is referenced as if it were a tree of files and directories
- **Secrets** - similar to Configmaps but for sensitive information like passwords, tokens and ssh files (backed by in-memory file systems, so the Secrets are never written to nonvolatile storage, *common practice to obuscate but beyond that should not assume that Secrets are secret just because of the way they're configured*)
- **DownwardAPI** - a way containers can learn about their Pod environment


**PersistentVolume** resources are used to manage durable storage in a cluster and are cluster resources that exist independently of Pods. Can be provisioned dynamically through **PersistentVolumeClaims**, or can be explicitly created by a cluster administrator. **PersistentVolumeClaim** (request and claims made by Pods to use PersistentVolumes) within which define a volume size, access mode, and storage class.

### Deployment

Deployments are a declarative way to ensure that the number of Pods running is equal to the desired number of Pods. They ensure this by creating a **ReplicaSet** which is responsible for making sure the number of replicas specified are always running. Usually designed for stateless applications. 

Deployments also supports various update mechanisms.

Any Deployment has three different lifecycle states: 
- **Progressing** - task is beening performed, like creating a new ReplicaSet, or scaling up, or scaling down a ReplicaSet
- **Complete** - indicates that all new replicas have been updated to the latest version, and are available, and no old replicas are running
- **Failed** - state occurs when the creation of a new ReplicaSet could not be completed


### Service

Pods aren't meant to be persistent. They can be stopped or started for many reasons - like failed liveness or readiness checks. Such restarts lead to different IP address.

Services provide stable endpoints for Pods by using labels to determine what Pods they operate on. If Pods have the correct labels, they are automatically picked up and exposed by our services.

A Service provides networking and IP support to Pods (by default, the containers are not accessible from the outside/Internet). 

The level of access a service provides to a set of pods depends on the Service's type:
- ClusterIP (internal) - the default type means that this Service is only visible inside of the cluster
- NodePort - gives each node in the cluster an externally accessible IP
- LoadBalancer - adds a load balancer (*from the cloud provider*) which forwards traffic from the service to Nodes within it

### Other resources

**StatefulSet** is similar to a Deployment, however, Pods created using StatefulSet have unique persistent identities, stable network identity and persistent disk storage.

**DaemonSet** ensures that a specific Pod is always running on all or some subset of the nodes (Pods belonging to Deamon set will be set up automatically when new node is added). For example, might be usedto ensure that a logging agent like fluentd is running on all nodes.

**Job** creates one or more Pods required to run a task, when completed, Job will then terminate all those Pods. A related controller is **CronJob**, which runs Pods on a time-based schedule.

**ResourceQuota** defines constraints that will limit resource consumption in a namespace, can specify a limit to object counts (pods, services, stateful sets, etc), total sum of storage resources (persistent volume claims, ephemeral storage, storage classes ), or total sum of compute resources (cpu and memory).

**Pod Disruption Budgets (PDB)** define how to handle disruptions like upgrades, pod removals, running out of resources, etc.... Specify the max-unavailable and/or the min-available number of pods a deployment should have.

### Affinities

**Pod Anti Affinity** ensures that the pod is not scheduled on the same node as some other pod.

**Pod Affinity** ensures pods are scheduled on the same node.

**Node Affinity** ensures applications/pods are run on specific nodes.

### Scaling

Three types of Kubernetes autoscalers:
- **Horizontal Pod Autoscaler (HPA)** - adjusts the number of replicas of an application (deployment, replica set, or stateful set) based on CPU utilization, custom or external metrics
- **Cluster Autoscaler (CA)** - adjusts the number of nodes in a cluster, adds or removes nodes in a cluster when nodes have insufficient resources or when a node remains underutilized (and its pods can be assigned to another node)
- **Vertical Pod Autoscaler (VPA)** - increases or decreases the resource requests and limits of containers in the cluster

#### Vertical Pod Autoscaler 

Three different update policies:
- **Off**: VPA will generate recommendations which need to be applied manually
- **Initial**: recommendations will be used to create new pods once but won't change the pod size afterwards
- **Auto**: pods will regularly be deleted and recreated to match the size of the recommendations

Recommendations include: 
- **Lower Bound**: if pod utilization goes below this, VPA will delete the pod and scale it down
- **Target**: value VPA will use when resizing the pod
- **Uncapped Target**: if no minimum or maximum capacity is assigned this will be the target 
- **Upper Bound**: if pod utilization goes above this, VPA will delete the pod and scale it up

#### Cluster Autoscaler 

The decision of when to remove a node is a trade-off between optimizing for utilization or the availability of resources. Removing underutilized nodes improves utilization, but new workloads will have to wait for resources longer (because the new node will need to be provisioned again).

Autoscaling profile:
- Balanced: The default profile.
- Optimize-utilization: the cluster autoscaler scales down the cluster more aggressively, optimized for use with batch workloads that are not sensitive to start-up latency

**Note**: Most of the system pods will prevent cluster autoscaler from taking down nodes, desired because many of these system pods collect data used in other deployments and services. 

Low priority deployments (called Pause Pods) which are able to be removed and replaced by high priority deployments can be used to minimize latency of provisioning new nodes. Low priority pods which don't actually do anything except reserve buffer space. When the higher-priority pod needs room, the pause pods will be removed and rescheduled to another node, or a new node. Low priority pause pod will need to wait for new node while the higher-priority pod has the room it needs (on already provisioned node) to be scheduled quickly.

### Kubernetes' built-in role-based access control (RBAC)

Within a cluster, access to any resource type (pods, services, deployments, etc) is defined by either a role or a cluster role. Only roles are allowed to be scoped to a namespace. While a role will indicate the resources and the action allowed for each resource, a role binding will indicate to what user accounts or groups to assign that access to.

To create a role in the current namespace, specify the resource type as well as the verbs (update, create, delete, get, watch, list) that will indicate what type of action that will be allowed.


## Deployments and testing

### Blue-green deployments

Used to deploy an application slowly with minimal overhead, minimal performance impact, and minimal downtime and where it is beneficial to modify the load balancers to point to that new version only after it has been fully deployed.

This is achived (using Kubernetes or similar on other platforms) by creating two separate Deployments. **Blue** is used for the old version and **green** for the new version. Service (load balancer) acts as the router, when the **green** version is up and running, switch over to that new version is done by updating the Service.

The advantage is that rollouts can be instantaneous and the newer versions can be tested internally before releasing them to the entire user base by using a separate Service definition for test user access. 

The disadvantage is that the resource usage is doubled during the deployment/upgrade process!

### Canary deployments

Another update strategy based on the blue/green method used when want to test a new deployment in production with a subset of users to mitigate risk associated with new releases.

When this update strategy is used might need to set **sessionAffinity** field to **ClientIP** in the specification of the Service if need a client's first request to determine which Pod will be used for all subsequent connections. Normally Service configuration does not ensure that all requests from a single client will always connect to the same Pod since each request is treated separately and can connect to any Pod deployment. 

### A/B testing

A/B testing is used to measure the effectiveness of functionality in an application unlike deployment patterns above which focus on releasing new software safely and rolling back predictably. 

A/B testing is used to make business decisions (not only predictions) based on the results derived from data. In an A/B test, you route a subset of users to new functionality based on some routing rules which include factors such as browser version, user agent, geolocation and operating system. 

Afterwards measure and compare data between the versions and update the production environment with the version that yielded better results (abtained by monitoring any statistically significant differences in the user behavior).

### Shadow testing

With Shadow testing, a new version is deployed alongside the current version, but in a way that the new version is hidden from users. Each incoming request is processed by the current version and **in addition** mirrored and replayed in the new version (process can happen in real time or asynchronously - a copy of the previously captured production traffic is replayed against the new version). 

Need to ensure that the shadow tests do not trigger side effects that alter the existing production environment/state (maybe have separate states after initial dupliaction of production state)!

Shadow testing has many key benefits. Since the traffic is duplicated, any bugs in new version that is processing the shadow data have no impact on production.

## Some of the references

- [Google Cloud Skills Boost](https://www.cloudskillsboost.google/)
- [Docker Documentation](https://docs.docker.com/)
- [Kubernetes Documentation](https://kubernetes.io/docs/home/)
- 