# Various cheat sheets

<!-- toc -->

- [gcloud](#gcloud)
- [gsutil](#gsutil)
- [bq](#bq)
- [kubectl](#kubectl)
- [docker](#docker)
- [Terraform](#terraform)

<!-- tocstop -->

## gcloud

Type `gcloud [command] --help` or `gcloud help [command]` to get help on any `gcloud` command.

More [info and reference](https://cloud.google.com/sdk/gcloud/reference/).

To install on Linux: `curl https://sdk.cloud.google.com | bash`.

- `gcloud auth login --no-launch-browser` - authenticate/initialize gcloud environment (configuration) without starting browser (link displayed in console)
- `gcloud auth activate-service-account --key-file credentials.json` - authenticate gcloud as service account using service account credentials file
- `gcloud config configurations activate default` - activate different configuration
- `gcloud components list` - list gcloud components (not)installed
- `gcloud components install beta` - install some component (beta)
- `gcloud components update beta` - update some component (beta)
- `gcloud auth list` - list the active account name
- `gcloud auth configure-docker` - register gcloud as a Docker credential helper
- `gcloud auth activate-service-account --key-file credentials.json` - activate service account using json file
- `gcloud config list project` - list the project ID
- `gcloud config list [--all]` - view configuration in the environment
- `gcloud config set project myProjectId` - change the project (set project id)
- `gcloud config set compute/zone` - set default zone
- `gcloud config set compute/region ` - set default region
- `gcloud config get-value compute/region` - get default region
- `gcloud config get-value compute/zone ` - get default region
- `gcloud config get-value project` - get project id
- `gcloud components list` - list components
- `gcloud compute zones list` - list Google Cloud zones 
- `gcloud compute instances list` - list compute instances
- `gcloud compute instances list --filter="name=('somename')"` - list compute instances with filtering
- `gcloud compute instances move` - move instance between zones (within a region)
- `gcloud beta compute reset-windows-password machinename` - reset windows password of the machine
- `gcloud compute firewall-rules list` - list firewall rules
- `gcloud compute firewall-rules list --filter="network='default' AND ALLOW:'icmp'" ` - list firewall rules with filtering
- `gcloud compute firewall-rules list --filter=ALLOW:'80' ` - list firewall rules with filtering
- `gcloud compute firewall-rules create default-allow-http --direction=INGRESS --priority=1000 --network=default --action=ALLOW --rules=tcp:80 --source-ranges=0.0.0.0/0 --target-tags=http-server` - update the firewall rule to allow http for instances with tags
- `gcloud compute project-info describe --project $(gcloud config get-value project)` - get info about project
- `gcloud compute instances create somevmname --machine-type e2-medium --zone` - create a new virtual machine instance
- `gcloud compute instances create somevmname --zone=us-east1-c --machine-type=e2-micro --subnet=somesubnet ` - create a new virtual machine instance on specific subnet
- `gcloud compute instances create somevmname  --service-account someServiceAccountEmail --scopes "https://www.googleapis.com/auth/compute"` - create new virtual machine with service account and scope
- `gcloud compute instances set-machine-type somevmname  --machine-type custom-4-3840` - change machine type of the instance
- `gcloud compute instances add-tags sometag --tags http-server,https-server` - add tag to virtual machine instance
- `gcloud compute instances list --filter=name:gcelab2 --format='value(EXTERNAL_IP)'` - list instances with filtering and formatting
- `gcloud compute instances list --sort-by=ZONE` - list instances with sorting by zone
- `gcloud compute instances delete someInstance` - delete an instance
- `gcloud compute instance-templates create templateName --source-instance=instanceName` - create a template from stopped instance
- `gcloud compute instance-templates list` - list instance templates
- `gcloud compute ssh somevmname --zone us-central1-c` - start ssh connection to a virtual machine
- `gcloud compute ssh vm-internal --zone us-central1-c --tunnel-through-iap` - start ssh connection to a virtual machine without public IP (gcloud will automatically fallback to this when no external IP even when not specified)
- `gcloud compute scp index.html first-vm:index.nginx-debian.html --zone=us-central1-c` - copy file to linux vm instance
- `gcloud compute instances get-serial-port-output instance-1` - check status of instance startup
- `gcloud compute reset-windows-password [instance] --zone us-east1-b --user [username]` - reset and fetch new Windows password
- `gcloud logging logs list` - view available logs
- `gcloud logging logs list --filter="compute"` - view available logs with filtering
- `gcloud logging read "resource.type=gce_instance" --limit 5` - read the logs related to the resource type of gce_instance
- `gcloud logging read "resource.type=gce_instance AND labels.instance_name='gcelab2'" --limit 5` - read the logs specific to a virtual machine
- `gcloud container clusters create hello-world --num-nodes 2 --machine-type n1-standard-1 --zone us-central1-a [--scopes "https://www.googleapis.com/auth/source.read_write,cloud-platform"]` - create GKE cluster with 2 nodes/machines (extra scope for access to Cloud Source Repositories and Google Container Registry)
- `gcloud container clusters get-credentials lab-cluster ` - get authentication credentials for GKE cluster
- `gcloud container clusters delete lab-cluster ` - delete GKE cluster
- `gcloud container clusters get-credentials lab-cluster` - re-authenticate gcloud shell with the GKE cluster
- `gcloud container node-pools create soneNodePool --cluster=hello-demo-cluster --machine-type=e2-standard-2 --num-nodes=1 --zone=us-central1-a` - create new node pool for a cluster
- `gcloud container node-pools delete soneNodePool --cluster hello-demo-cluster --zone us-central1-a` - delete a nodepool
- `gcloud beta container clusters update scaling-demo --enable-autoscaling --min-nodes 1 --max-nodes 5` - enable cluster autoscaling
- `gcloud beta container clusters update scaling-demo --autoscaling-profile optimize-utilization` - set autoscaling profile
- `gcloud container clusters update scaling-demo --enable-autoprovisioning --min-cpu 1 --min-memory 2 --max-cpu 45 --max-memory 160` - enable cluster node autoprovisioning
- `gcloud compute addresses create network-lb-ip-1 --region us-central1` - create static ip address
- `gcloud compute http-health-checks create basic-check` - create legacy HTTP health check resource
- `gcloud compute target-pools create www-pool --region us-central1 --http-health-check basic-check` - create target pool with check resource
- `gcloud compute target-pools add-instances www-pool --instances www1,www2,www3` - add instances to the pool
- `gcloud compute forwarding-rules create www-rule --region  us-central1 --ports 80 --address network-lb-ip-1 --target-pool www-pool` - forward trafic from ip to the pool
- `gcloud compute forwarding-rules describe www-rule --region us-central1` - see info about forwarding rule (including external ip)
- `IPADDRESS=$(gcloud compute forwarding-rules describe www-rule --region us-central1 --format="json" | jq -r .IPAddress)` - store ip adress into variable
- `gcloud compute instance-groups managed create lb-backend-group --template=lb-backend-template --size=2 --zone=us-central1-f --base-instance-name some-name ` - create managed instance group based on template
- `gcloud compute instance-groups managed set-named-ports web-server-group --region=us-east1 --named-ports http:80` - set named ports on managed group
- `gcloud compute instance-groups managed rolling-action replace web-server-group --max-unavailable 50%` - rolling restart of all instances in a group (at least 50% members will be alive while others restart)
- `gcloud compute instance-groups managed rolling-action start-update web-server-group --version template=new-instance-template` - update/restart instance group to use new template
- `gcloud compute instance-groups managed set-autoscaling lb-backend-group --max-num-replicas 2 --target-load-balancing-utilization 0.60` - set autoscaling policy to create more instances if above 60% utilization
- `gcloud compute instance-groups list-instances lb-backend-group` - list instances in a group
- `gcloud compute addresses create lb-ipv4-1 --ip-version=IPV4 --global` - create global static external IP address
- `gcloud compute addresses describe lb-ipv4-1 --format="get(address)" --global` - describe (and get IP) from global static external IP address
- `gcloud compute health-checks create http http-basic-check --port 80` - create a health check for the load balancer
- `gcloud compute backend-services create web-backend-service --protocol=HTTP --port-name=http --health-checks=http-basic-check --global` - create backend service
- `gcloud compute backend-services create web-backend-service --http-health-checks web-backend-frontend-check --port-name frontend --global`` - create backend service
- `gcloud compute backend-services add-backend web-backend-service --instance-group=lb-backend-group --instance-group-zone=us-central1-f --global` - add instance group as the backend to the backend service
- `gcloud compute backend-services get-health web-backend-service --global` - get health state of the backend service
- `gcloud compute backend-services update web-backend-service --enable-cdn --global` - enable usage of caching CDN for a backend service
- `gcloud compute backend-services list` - list backend services
- `gcloud compute backend-services get-health web-backend-service --global` - get health status of backend service
- `gcloud compute url-maps create web-map-http --default-service web-backend-service` - create a URL map to route the incoming requests to the default backend service
- `gcloud compute url-maps add-path-matcher web-map-http --default-service web-backend-service --path-matcher-name mathcerName --path-rules "/api1=other-backend-service,/api2=other-backend-service2"` - modify url map with a mathcer rule to go to some other service
- `gcloud compute target-http-proxies create http-lb-proxy --url-map web-map-http` - create a target HTTP proxy to route requests to your URL map
- `gcloud compute forwarding-rules create http-content-rule --address=lb-ipv4-1 --global --target-http-proxy=http-lb-proxy --ports=80` - create global forwarding rule to route incoming requests to the proxy
- `gcloud functions deploy somefunctionname --stage-bucket [bucket_name] --trigger-topic some_pub_sub_topis --runtime nodejs8` - create new cloud function (--trigger-bucket  or --trigger-http are also used)
- `gcloud functions describe somefunctionname` - get info about cloud function
- `gcloud functions call somefunctionname --data '{"data":"ABCD"}'` - invoke some cloud function
- `gcloud functions logs read somefunctionname` - examine cloud function logs
- `gcloud pubsub topics create sometopic` - create a pub/sub topic
- `gcloud pubsub topics delete sometopic` - delete a pub/sub topic 
- `gcloud pubsub topics list` - list all pub/sub topics
- `gcloud pubsub subscriptions create --topic sometopic somesubscription` - create a pub/sub subscription
- `gcloud pubsub topics list-subscriptions sometopic` - list subscriptions on a pub/sub topic
- `gcloud pubsub topics publish sometopic --message "Hello"` - publish a message to a pub/sub topic
- `gcloud pubsub subscriptions pull --auto-ack somesubscription` - pull ONE message from pub/sub subscription
- `gcloud pubsub subscriptions pull somesubscription --auto-ack --limit=3` - pull 3 messages from pub/sub subscription
- `gcloud compute networks create networkname --subnet-mode=custom --mtu=1460 --bgp-routing-mode=regional` - create a VPC network
- `gcloud compute networks subnets create subnetworkname --range=10.130.0.0/20 --stack-type=IPV4_ONLY --network=networkname --region=us-central1` - create a VPC subnetwork
- `gcloud compute networks list` - view VPC networks
- `gcloud compute networks subnets list --sort-by=NETWORK` - view VPC subnetworks
- `gcloud compute netwokr subnets update subnet-name --enable-private-ip-google-access` - enable private ip acess to Google services
- `gcloud compute firewall-rules create networkname  --direction=INGRESS --priority=1000 --network=managementnet --action=ALLOW --rules=tcp:22,tcp:3389,icmp --source-ranges=0.0.0.0/0  ` - create a firewall rule
- `gcloud compute firewall-rules list --sort-by=NETWORK` - list firewall rules
- `gcloud app create --region=us-central` - create App Engine
- `gcloud app deploy app.yaml [--quiet] [--version=two] [--no-promote]` - deploy the application to App Engine (--no-promote parameter tells App Engine to continue serving requests with the old version)
- `gcloud app browse` - open current App Engine application in a browser (or display url if browser is not detected)
- `gcloud app logs tail -s default` - tail logs from App Engine application
- `gcloud sql connect  myproject-demo --user=root` - connect to Cloud SQL Instance
- `gcloud iam service-accounts keys list --iam-account user@email.com` - list keys associated with service account
- `gcloud iam roles list` - list available roles
- `gcloud iam roles describe roles/compute.instanceAdmin` - describe (list permissions included) some role
- `gcloud iam roles create devops --project $PROJECTID2 --permissions "compute.instances.start,compute.instances.stop"` - create custom role with some permissions
- `gcloud iam service-accounts create serviceAccountName --display-name serviceAccountDisplayName` - create service account
- `gcloud iam service-accounts list --format="value(email)" --filter "displayName=serviceAccountDisplayName"` - list service accounts with filtering and formating
- `gcloud projects add-iam-policy-binding someProjectId --member user:someUserId --role=roles/viewer` - add viewer role for some user on some project
- `gcloud projects add-iam-policy-binding someProjectId --member serviceAccount:someServiceAccountEmail --role=roles/viewer ` - add viewer role for some service account on some project
- `gcloud services enable compute.googleapis.com` - enable the Compute Engine API
- `gcloud services enable cloudprofiler.googleapis.com` - enable the Cloud Profiler
- `gcloud services enable artifactregistry.googleapis.com cloudbuild.googleapis.com run.googleapis.com` - enable  Cloud Build, Artifact Registry, and Cloud Run APIs
- `gcloud services enable container.googleapis.com` -  enable the Container Registry API
- `gcloud compute vpn-gateways create demo-vpn-gw --network some-network --region us-central1` - create HA VPN Gateway
- `gcloud compute vpn-gateways describe demo-vpn-gw  --region us-central1` - describe a gateway
- `gcloud compute routers create demo-router  --region us-central1  --network some-network --asn 65001` - create Cloud Router
- `gcloud compute routers describe demo-router --region us-central1` - describe a router
- `gcloud compute vpn-tunnels list` - list all tunnels (and peers)
- `gcloud compute vpn-tunnels describe demo-tunnel --region us-central1` - describe a tunnel
- `gcloud builds submit --tag gcr.io/${GOOGLE_CLOUD_PROJECT}/an-image:v0.1 .` - submit a new build job to Cloud Build (with source from current directory the last .)
- `gcloud builds submit --config cloudbuild.yaml .` -  submit a new build job configured in a file to Cloud Build
- `gcloud builds submit --tag us-central1-docker.pkg.dev/${GOOGLE_CLOUD_PROJECT}/demo/demo:1.0.0` - submit a build job and store to Docker Artifact Registry 
- `gcloud builds list` - list all build jobs performed
- `gcloud container images delete gcr.io/${GOOGLE_CLOUD_PROJECT}/an-image:1.0.0 --quiet` - Delete the container image for some version 
- `gcloud builds list | grep 'SOURCE' | cut -d ' ' -f2 | while read line; do gsutil rm $line; done` - delete all source tarbals stored for gcloud builds
- `gcloud container clusters update multi-tenant-cluster --zone us-central1-a --resource-usage-bigquery-dataset cluster_dataset` - enable GKE usage metering on the cluster
- `gcloud source repos clone devops-repo` - clone Google Cloud repository
- `gcloud source repos create default` - create Google Cloud repository
- `gcloud run deploy demo --image us-central1-docker.pkg.dev/${GOOGLE_CLOUD_PROJECT}/demo/demo:1.0.0 --region us-central1 [ --concurrency 100]` - deploy a container to Cloud Run
- `gcloud run services list` - list services deployed in Cloud Run
- `gcloud run services describe demo  --platform managed --region us-central1` - describe service deployed in Cloud Run


Create VPN tunnel:
```
gcloud compute vpn-tunnels create demo-tunnel \
    --peer-gcp-gateway peer-gw \
    --region us-central1 \
    --ike-version 2 \
    --shared-secret [SHARED_SECRET] \
    --router demo-router \
    --vpn-gateway demo-vpn-gw \
    --interface 0
```

Create router interface:
```
gcloud compute routers add-interface demo-router \
    --interface-name if-tunnel0 \
    --ip-address 169.254.0.1 \
    --mask-length 30 \
    --vpn-tunnel demo-tunnel \
    --region us-central1
```

Create BGP peering:
```
gcloud compute routers add-bgp-peer demo-router \
    --peer-name bgp-on-prem-tunnel0 \
    --interface if-tunnel0 \
    --peer-ip-address 169.254.0.2 \
    --peer-asn 65002 \
    --region us-central1
```

Create health check rule (130.211.0.0/22,35.191.0.0/16 are Google Cloud health checking systems)
```
gcloud compute firewall-rules create fw-allow-health-check \
  --network=default \
  --action=allow \
  --direction=ingress \
  --source-ranges=130.211.0.0/22,35.191.0.0/16 \
  --target-tags=allow-health-check \
  --rules=tcp:80
```

```
gcloud compute firewall-rules create allow-health-check \
    --allow tcp:8080-8081 \
    --source-ranges 130.211.0.0/22,35.191.0.0/16 \
    --network default
```

Create instance with lots of params including startup script
```
gcloud compute instances create www1 \
    --zone=us-central1-f \
    --tags=network-lb-tag \
    --machine-type=e2-medium \
    --image-family=debian-11 \
    --image-project=debian-cloud \
    --metadata=startup-script='#!/bin/bash
      apt-get update
      apt-get install apache2 -y
      service apache2 restart
      echo "
<h3>Web Server: www1</h3>" | tee /var/www/html/index.html'
```

Create load balancer instance template with lots of params including how to fetch hostname
```
gcloud compute instance-templates create lb-backend-template \
   --region=us-central1 \
   --network=default \
   --subnet=default \
   --tags=allow-health-check \
   --machine-type=e2-medium \
   --image-family=debian-11 \
   --image-project=debian-cloud \
   --metadata=startup-script='#!/bin/bash
     apt-get update
     apt-get install apache2 -y
     a2ensite default-ssl
     a2enmod ssl
     vm_hostname="$(curl -H "Metadata-Flavor:Google" \
     http://169.254.169.254/computeMetadata/v1/instance/name)"
     echo "Page served from: $vm_hostname" | \
     tee /var/www/html/index.html
     systemctl restart apache2'
```

Same as above but with startup script read from file
```
gcloud compute instance-templates create lb-backend-template \
   --region=us-east1 \
   --network=default \
   --subnet=default \
   --tags=allow-health-check \
   --machine-type=f1-micro \
   --image-family=debian-11 \
   --image-project=debian-cloud \
   --metadata-from-file startup-script=startup.sh
```

Same as above but with startup script read from url
```
gcloud compute instances create backend \
    --machine-type=n1-standard-1 \
    --tags=backend \
   --metadata=startup-script-url=https://storage.googleapis.com/somefile.sh
```

Create HTTP health check
```
gcloud compute health-checks create http health-check-name \
    --port 8080 \
    --request-path=/api/orders \
    --check-interval 30s \
    --healthy-threshold 1 \
    --timeout 10s \
    --unhealthy-threshold 3
```

Create HTTP health check
```
gcloud compute http-health-checks create fancy-fe-frontend-hc \
  --request-path / \
  --port 8080
```

Update managed instance group with a health check
```
gcloud compute instance-groups managed update fancy-be-mig \
    --health-check fancy-be-hc \
    --initial-delay 300
```

## gsutil

More [info and reference](https://cloud.google.com/storage/docs/gsutil).

- `gsutil cp somefile.jpg gs://[bucket_name]` - copy object to a bucket (upload)
- `gsutil cp -r gs://[bucket_name]/[object_name_path] .` - copy object from bucket (download)
- `gsutil cp -v somefile.jpg gs://[bucket_name]` - copy with versioning object to a bucket (upload)
- `gsutil cp gs://[bucket_name]/[object_name_path]#version_id recovered.jpg` - copy version of an object from bucket (download)
- `gsutil -m cp -r gs://spls/gsp053/orchestrate-with-kubernetes .
- `gsutil cp gs://[bucket_name]/[object_name_path] gs://[bucket_name]/[dest_folder_path]/` - copy objets from bucket to bucket
- `gsutil ls gs://[bucket_name]` - list objectss in a bucket
- `gsutil ls -l gs://[bucket_name]/[object_name_path] ` - list details for a object in a bucket
- `gsutil ls -a gs://[bucket_name]/[object_name_path]` - list all versions of an object
- `gsutil acl set private gs://[bucket_name]/[object_name_path]` - make object private (only creator/owner has access)
- `gsutil acl ch -u AllUsers:R gs://[bucket_name]/[object_name_path]` - make a object accessible to everyone
- `gsutil acl ch -d AllUsers gs://[bucket_name]/[object_name_path]` - remove permissions on a object
- `gsutil rm gs://[bucket_name]/[object_name_path] ` - remove object from bucket
- `gsutil mb -p [PROJECT_ID] gs://[bucket_name]` - create new storage bucket
- `gsutil signurl -d 10m path/to/privatekey.p12 gs://[bucket_name]/[object_name_path]` - create a signed URL for a object in a bucket
- `gsutil acl get gs://[bucket_name]/[object_name_path]` - show access control list
- `gsutil config -n` - create .boto file (has encryption/decryption keys and lots of other configuration)
- `gsutil rewrite -k gs://[bucket_name]/[object_name_path]` - rewirte with new encryption_key (using decryption_key1 from .boto)
- `gsutil lifecycle get gs://[bucket_name]` - get lifecycle management rules
- `gsutil lifecycle set life.json gs://[bucket_name]` - set lifecycle management rules from a json file
- `gsutil versioning get gs://[bucket_name]` - get versioning rules 
- `gsutil versioning set gs://[bucket_name]` - enable versioning
- `gsutil rsync -r ./somefolder gs://[bucket_name]/somefolder` - syncronize folder with bucket


## bq

More [info and reference](https://cloud.google.com/bigquery/docs/reference/bq-cli-reference).

Run BigQuery query:
```
bq query --location=us --use_legacy_sql=false --use_cache=false \
'select month, avg(mean_temp) as avgtemp from `qwiklabs-resources.qlweather_geo.gsod`
 where station_number = 947680
 and year = 2010
 group by month
 order by month'
```

## kubectl

More [info and reference](https://cloud.google.com/bigquery/docs/reference/bq-cli-reference).


- `kubectl create deployment hello-server --image=gcr.io/google-samples/hello-app:1.0` - create application in GKE cluster
- `kubectl create -f file.yaml` - create application based on yaml file
- `kubectl expose deployment hello-server --type=LoadBalancer --port 8080` - expose GKE cluster application on port
- `kubectl scale deployment hello-node --replicas=4` - scale deployment to 4 replicas
- `kubectl autoscale deployment php-apache --cpu-percent=50 --min=1 --max=10` - automatically scale deployment between 1 and 10 replicas based on cpu
- `kubectl get service` - show KGE cluster services (internal and external IPs, exposed ports, etc....)
- `kubectl get deployments` - show deployments
- `kubectl get replicasets` - show replica sets (or kubectl get rs)
- `kubectl get pods [--show-labels] [-A] [--namespace=someNamespace]` - show pods (-A = all namespaces)
- `kubectl cluster-info` - show info about cluster
- `kubectl config view` - show cluster config
- `kubectl get events` - show cluster events
- `kubectl logs -f <pod-name>` - show pod logs (-f = follow, stream in realtime)
- `kubectl edit deployment hello-node` - interactivly edit deployment yml file and apply
- `kubectl get hpa` - see status of Horizontal Pod Autoscaler
- `kubectl get vpa` - see status of Vertical Pod Autoscaler
- `kubectl set image deployment/hello nginx=nginx:1.9.1` - directly set image of the deloyment to new image
- `kubectl set resources deployment hello-server --requests=cpu=450m` - directoly set cpu resource request to a deployment
- `kubectl rollout pause deployment/hello` - pause rollout (which happens after deployment is edited)
- `kubectl rollout resume deployment/hello` - resume rollout (which happens after deployment is edited)
- `kubectl rollout history deployment/hello` - show rollout history
- `kubectl rollout history deployment/nginx-deployment --revision=5` - show info about specific item revision in history
- `kubectl rollout undo deployment/hello` - undo last rollout
- `kubectl rollout status deployment/hello ` - monitor rollout
- `kubectl explain deployment --recursive
- `kubectl explain deployment.metadata.name
- `kubectl create secret generic tls-certs --from-file tls/
- `kubectl create configmap nginx-frontend-conf --from-file=nginx/frontend.conf` - create configmap
- `kubectl get pods -o jsonpath --template='{range .items[*]}{.metadata.name}{"\t"}{"\t"}{.spec.containers[0].image}{"\n"}{end}'
- `kubectl delete pods healthy-monolith monolith secure-monolith
- `kubectl delete pod monolith
- `kubectl delete services monolith auth frontend hello
- `kubectl delete deployments auth frontend hello hello-canary hello-green
- `kubectl delete service monolith
- `kubectl delete deployment auth
- `kubectl delete secrets tls-certs
- `kubectl delete configmaps nginx-frontend-conf nginx-proxy-conf
- `kubectl describe pods podname` - list pod description, ip addresses, event log, ....
- `kubectl port-forward <pod-name> 10080:80` - set up port forwarding from local machine 10080 to pod 80
- `kubectl exec <pod-name> --stdin --tty -c <pod-name> -- /bin/sh` - start interactive shell on pod
- `kubectl create secret generic tls-certs --from-file tls/` - create generic secrets form a files in folder (tls/)
- `kubectl create configmap nginx-proxy-conf --from-file nginx/proxy.conf` - create config map from a file
- `kubectl label pods pod-name 'secure=enabled'` - add label to a pod
- `kubectl get persistentvolumeclaim` - show current persisten volume claims
- `kubectl completion shellName` - output shell completion code for the specified shell (bash, zsh, fish, or powershell), the shell code must be evaluated to provide interactive completion of kubectl commands e.g. by sourcing it from the .bash_profile (or source <(kubectl completion bash))
- `kubectl api-resources --namespaced=true` - complete list of namespaced resources
- `kubectl get services --namespace=kube-system` - get services belonging to a namespace
- `kubectl run app-server --image=centos --namespace=team-a -- sleep infinity` - run something inside a namespace
- `kubectl config set-context --current --namespace=team-a` - any subsequent commands will be run against the indicated namespace without specifying the --namespace flag
- `kubectl create role pod-reader --resource=pods --verb=watch --verb=get --verb=list` - create a RBAC rule
- `kubectl create rolebinding team-a-developers --role=developer --user=team-a-dev@${GOOGLE_CLOUD_PROJECT}.iam.gserviceaccount.com` - create a "binding" between RBAC role and IAM account
- `kubectl create namespace team-a
- `kubectl create quota test-quota --hard=count/pods=2,count/services.loadbalancers=1 --namespace=team-a` - create a resource quota
- `kubectl describe quota test-quota --namespace=team-a` - list details about a quota (used and limits)
- `kubectl edit quota test-quota --namespace=team-a` - interactively edit quota
- `kubectl cordon nodeName` - cordon node (mark as unschedulable)
- `kubectl uncordon nodeName` - cordon node (mark as schedulable again)
- `kubectl drain --force --ignore-daemonsets --delete-local-data --grace-period=10 nodeName` - drain node (evict workloads from it)
- `kubectl create poddisruptionbudget kube-dns-pdb --namespace=kube-system --selector k8s-app=kube-dns --max-unavailable 1` - create pod disruption budget
- `kubectl create poddisruptionbudget gb-pdb --selector run=gb-frontend --min-available 4` - create pod disruption budget
- `kubectl get nodes -l cloud.google.com/gke-nodepool=somePoolName -o=name` - get nodes (belonging to a node pool somePoolName)
- `kubectl get ingress frontend-ingress` - show ingress status
- `kubectl cluster-info` - show info about cluster (software versions, etc...)
- `kubectl get all` - show all (pods, deployments, etc....)

```
for node in $(kubectl get nodes -l cloud.google.com/gke-nodepool=default-pool -o=name); do
  kubectl drain --force --ignore-daemonsets --grace-period=10 "$node";
done
```

## docker

More [info and reference](https://docs.docker.com/engine/reference/run/).

- `docker build -t gcr.io/blabla/node-app:v1 .` - build image
- `docker run -d -p 8080:8080 gcr.io/blabla/node-app:v1 --name my-app` - run container from an image (-d = detach, run in background, -p expose ports, --name set container instance name)
- `docker ps` - list running container
- `docker stop [CONTAINER ID]` - stop container 
- `docker tag node-app:0.2 gcr.io/blabla/node-app:0.2` - tag container image 
- `docker push gcr.io/blabla/node-app:v1` - push image to registry
- `docker pull gcr.io/blabla/node-app:0.2` - pull image from registry
- `docker images` - list images downloaded localy
- `docker ps [-a] [-q]` - list running container (-a includes one that have finished, -q only container ids)
- `docker stop my-app` - stop running container
- `docker rm my-app` - remove running container
- `docker logs [-f]` - see logs of the container (console logs, -f = follow/tail logs)
- `docker exec -it [container_id] bash` - interactive bash shell on container instance
- `docker inspect --format='{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' [container_id]` - see container instance metadata with formatting

## Terraform

```
terraform {
  required_providers {
    google = {
      source = "hashicorp/google"
    }
  }
}
provider "google" {
  version = "3.5.0"
  project = "unique_project_id"
  region  = "us-central1"
  zone    = "us-central1-c"
}
resource "google_compute_network" "vpc_network" {
  name = "terraform-network"
}
resource "google_compute_instance" "vm_instance" {
  name         = "terraform-instance"
  machine_type = "f1-micro"
  boot_disk {
    initialize_params {
      image = "debian-cloud/debian-11"
    }
  }
  network_interface {
    network = google_compute_network.vpc_network.name
    access_config {
    }
  }
}
resource "google_storage_bucket" "example_bucket" {
  name     = "UNIQUE-BUCKET-NAME"
  location = "US"
  website {
    main_page_suffix = "index.html"
    not_found_page   = "404.html"
  }
}
resource "google_compute_instance" "another_instance" {
  depends_on = [google_storage_bucket.example_bucket]
  name         = "terraform-instance-2"
  machine_type = "f1-micro"
  boot_disk {
    initialize_params {
      image = "cos-cloud/cos-stable"
    }
  }
  network_interface {
    network = google_compute_network.vpc_network.self_link
    access_config {
    }
  }
}

```


variables.tf
```

variable "project_id" {
  type        = string
  default     = "some_id"
  description = "The ID of the project where this all will be created"
}
variable "region" {
  type        = string
  default     = "us-east1"
  description = "The region where this all will be created"
}
variable "zone" {
  type        = string
  default     = "us-east1-c"
  description = "The zone where this all will be created"
}      
```

main.tf
```
terraform {
  required_providers {
    google = {
      source = "hashicorp/google"
    }
  }
}
provider "google" {
  version = "~> 3.45.0"
  project     = var.project_id
  region      = var.region
  zone        = var.zone
}
module "instances" {
  source = "./modules/instances"
  project_id   = var.project_id
  region      = var.region
  zone        = var.zone
}
module "storage" {
  source = "./modules/storage"
}
terraform {
  backend "gcs" {
    bucket  = "tf-bucket-100858"
    prefix  = "terraform/state"
  }
}

module "vpc" {
    source  = "terraform-google-modules/network/google"
    version = "=3.4.0"

    project_id   = var.project_id
    network_name = "tf-vpc-707793"
    routing_mode = "GLOBAL"

    subnets = [
        {
            subnet_name           = "subnet-01"
            subnet_ip             = "10.10.10.0/24"
            subnet_region         = var.region
        },
        {
            subnet_name           = "subnet-02"
            subnet_ip             = "10.10.20.0/24"
            subnet_region         = var.region
        }
    ]
}
resource "google_compute_firewall" "tf-firewall" {
  name    = "tf-firewall"
  network = "projects/myproject-gcp-01-6c7c86c31cb4/global/networks/tf-vpc-707793"

  allow {
    protocol = "tcp"
    ports    = ["80"]
  }
  source_ranges = ["0.0.0.0/0"]
}
```


modules/storage/storage.tf
```
resource "google_storage_bucket" "tf-bucket-546693" {
  name        = "tf-bucket-546693"
  location = "US"
  force_destroy = true
  uniform_bucket_level_access = true
}
```

modules/instances/instances.tf
````
resource "google_compute_instance" "tf-instance-1" {
  name = "tf-instance-1"
  project      = var.project_id
  zone         = var.zone
  machine_type = "n1-standard-2"
  boot_disk {
    initialize_params {
      image = ""
    }
  }
  network_interface {
    network = "tf-vpc-707793"
    subnetwork = "subnet-01"
    access_config {
    }
  }
  metadata_startup_script = <<-EOT
        #!/bin/bash
    EOT
  allow_stopping_for_update = true
}
resource "google_compute_instance" "tf-instance-2" {
  name = "tf-instance-2"
  project      = var.project_id
  zone         = var.zone
  machine_type              = "n1-standard-2"
  boot_disk {
    initialize_params {
      image = ""
    }
  }
  network_interface {
    network = "tf-vpc-707793"
    subnetwork = "subnet-02"
    access_config {
    }
  }
  metadata_startup_script = <<-EOT
        #!/bin/bash
    EOT
  allow_stopping_for_update = true
}
```
