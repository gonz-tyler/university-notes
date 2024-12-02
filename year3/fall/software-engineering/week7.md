# Week 7: Making Use of the Cloud and Mobile
## Notes
---

### Perks of using the Cloud
- Scaleability - maintain performance as load increases
- Elasticity - adapt the server configuration to changing demands
- Resilience - maintain service in the event of server failure
- Cost effective - rent what you use as you use it without upfront costs
### Virtual Cloud Servers
- virtual server runs on an underlying physical computer and is made up
of an OS plus a set of software packages that provide the
server functionality required
- virtual server is a stand-alone system that can run on any hardware in
the cloud
  - ‘run anywhere’ characteristic is possible because the virtual server has no
external dependencies
- Virtual machines (VMs) running on physical server hardware, can be
used to implement virtual servers
  - hypervisor provides hardware emulation that simulates the operation of the
underlying hardware
- virtual machine implementing virtual servers have
exactly the same hardware platform as a physical server
### Container-based Virtualization
- if all running services use the same OS simpler virtualization technology called containers can be used
- containers accelerate the deployment process on the cloud
  - containers are MB in size VMs are GB in size
  - containers start in seconds Vms in minutes
- containers allow independent servers to share a single operating system
  - they are particularly useful for providing isolated application services where each user sees their own version of an application
### Docker
- containers developed by Google in 2007 but popularized in 2015
- open source project called Docker provides standard means of container management that is fast and easy to use
- Docker is a container management system that allows users to define software to be included in a container as a Docker image
- also includes a run-time system that can create and manage containers using these Docker images
### Everyting as a service
- infrastructure as a service (IaaS)
  - cloud providers offer different kinds of infrastructure service such as a compute service a network service and a storage service that you can use to implement virtual servers
- platform as a service (PaaS)
  - intermediate level where you use libraries and frameworks provided by the cloud provider to implement your software including a range of functions and access to SQL and NoSQL databases
- software as a service (SaaS)
  - software product runs on the cloud and is accessed by users through a web browser or mobile app
  - software products are being delivered as a service rather than installed on the buyer’s computers
  - software product as a serviceis run on servers which may be rented from a cloud provider
  - customers don’t have to install software and they access the remote system through a web browser or dedicated mobile app
  - payment model for software as a service is usually a subscription model
    - users pay a monthly fee to use the software rather than buy it outright

### Benefits of SaaS for Companies
- cash flow - customers pay regularly so regular cash flow
- update management - you are in control of updates to product and onl one version needs to be maintained - reduces cost and easier to maintain consistent code base
- continuous deployment - new versions can be deployed as soon as they have been made and tested - so can fix bugs quickly and increase software reliability
- payment flexibility - several payment options to attract wider range of customers
- try before you buy - free or low cost versions available for customer feedback on bugs
- data collection - data collection on how product is uses and improve service - also collect customer data for marketing purposes
### Advantages and Disadvantages of SaaS for customers
- advantages
  - acces on any device
  - no upfront costs
  - immediate software updates
  - reduced software management costs
- disadvantages
  - privacy regulation conformance
  - network constraints
  - security concerns
  - loss of control over updates
  - service lock-in
  - data exchange
  
### Data Storage and Management issues for SaaS
- regulation - countries where servers are hosted may have differing regulations to countries where customers will be using the product
- data transfer - software response time may be limited by network speed
- data security - sensitive information may not be secure in cloud based providers
- data exchange - data exchange may be difficult unless an API is provided

### Design issues for SaaS
- local/remote processing
  - software may execute some features locally on browser and others remotely on server
  - local execution reduces network traffic and increases user response speed - useful for slow networks
  - local processing increases electrical power needed to run the system
- authentication
  - users may have to remember another set of credentials
  - many systems allow authentication using users Google Facebook or Linkedin
  - for business products federated authentication system which delegates authentication to the the business may be needed
- information leakage
  - multiple users from multiple organizations can cause data leaks
- multi-tenant and multi-instance systems
  - multi-tenant system all customers are served by single instance of system and multitenant database
  - multi-instance system a separate copy of system and database is made available to each user

### Mobile Development
- monolithic site - all in one place
- devolved site - separate back and front ends
