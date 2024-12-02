# Week 6: Software Architecture
## Notes
---
### Architectural Design
- architectural design includes
  - overall organization
  - how software is decomposed into components
  - server organization
  - technologies used to build software
- architecture affects performance usability security reliability and maintainability
- minimizing complexity is an important goal
  - more complex a system more difficult and expensive to understand and change
  - more likely to introduce mistakes and bugs and security vulnerabilities when modifying or extending

### Components
- component is an element that implements coherent set of functionality or features
- can be considered as a collection of one or more services that may be used by other components
- design component interfaces, leaving implementation of that interface to a later stage

### Non Functional System Quality Attributes
- responsiveness - system perform actions within reasonable time
- reliability - system performs as expected by both users and developers
- availability - system delivers services when requested by users
- security - system protects itself and users from unauthorized attacks and intrusions
- usability - system users access features quickly without errors
- maintainability - system is able to be updated easily and cheaply
- resilience - system continues to deliver services in event of partial failure or attack

### Trade Offs
#### Maintainability vs Performance
- system maintainability is an attribute that reflects how difficult and expensive it is to make changes to a system after it been released to customers
  - improved by building small self contained parts which can be replaced or enhanced easily
  - system should be decomposed into fine-grain components
  - if many compoinents involved communication could be slow causing performance to drop

#### Security vs Usability
- system protection designed as layers
  - attackers have to penetrate all layers before system is compromised
  - layers might include system authentication layers, critical feature authentication layer, encription layer ...
  - each of these layers is its own component so if compromised by an attacker other layers remain intact
- example layers
  - IP auth -> application auth -> feature auth -> encryption -> protected asset (such as database)
- layered approach affect usability
  - users have to remember information like passwords - interaction with system is slowed down
  - to avoid this you need
    - not too many security layers
    - no enforced unnecessary security
    - provides helper components that reduce load on users (remember me functionality)
    
#### Availability vs Time-to-market
- availability is particularly important in enterprise products
- measured as uptime of system
  - normally expressed as a percentage
- achieved by having redundant and backup components
  - sensors included to detect failure and switch components
- implementing extra components takes time and increases the cost, adds complexity and increases chances of introducing bugs and vulnerabilities

### Architectural Patterns
- layered architecture
- pipe and filter
- shared-data
- event-driven
- model-view-controller
- client-server

### Layered Architecture
- each layer is an abstraction
- one layer provides services to those above and consumes those below
- access to layer is via interfaces (public methods)
- open layers (relaxed) provide services for and consume more than one of the others
  - messages sent to any lower layer
  - no need for extra code to pass messages
  - increase layer dependency
- closed layers (strict) only interact with those immediately above/below them
  - messages only sent to adjacent lower level
  - minimises layer dependency
  - reduces impact of change to interface of any one layer
