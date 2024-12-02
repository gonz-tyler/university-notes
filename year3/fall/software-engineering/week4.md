# Week 4: Testing Your Work
## Notes
---

### Verification vs Validation
- verification - software should conform to its specification
  - "are we building the product right"
- validation - software should do what the user really requires
  - "are we building the right product"
- this helps establish confidence that the system is fit for purpose
- depends on system purpose, user expectations and marketing environment
  - software purpose
    - level of confidence depends on how critical the software is to an organisation
  - user expectations
    - users may have low expectations of certain kinds of software
  - marketing environment
    - getting a product to market early may be more important than finding defects in the program

### Software Testign Confirms Behaviour
- software testing is a process in which you execute your program using data that simulates user inputs
- you observe its behaviour to see whether or not your program is doing what it is supposed to do
  - tests pass if behaviour is what you expect - tests fail otherwise
  - if program behaves as expected this shows that for the inputs used the system works
  
### Program Bugs
- two causes of program bugs
  - programming errors
    - accidental faults in program code
  - understanding error
    - misunderstood or unaware of some details of what the program should do

### Types of Testing
- functional testing
  - tests overall system - goals are to discover as many bugs as possible in the implementation of the system and provide convincing evidence that the system is fit for its intended purpose
- user testing
  - tests that software is useful to and usable by end-users - shows features of the system help users do what they want to do and also that they understand how to access the features effectively
- performance and load testing
  - tests speed and load handling of system - shows response and processing time of system is acceptable to users and that the system can handle different loads
- security testing
  - tests integrity and user information protection

### Code Reviews
- code reviews help detect programming errors
- time and effort can be saved by using pair and mob programming practices

### Unit Testing
- as you develop a code unit also developm tests for that code
- if a program unit behaves as expected for a aset of inputs that have some shared characteristics, it will behave the same way for larger sets whose members share these characteristics
- to test a program efficiently, sets of inputs ( equivalence partitions ) that will be treated in the same way in your code should be identified (also include deliberately incorrect inputs)

#### Equivalence Partitions
- testings should always use examples from each partition
  - low medium and high number of inputs
  - small medium and large input values
  
### Feature Testing
- features have to be tested
- testing that all interacting program units behave correctly individually and together
- tests should be done by all developers involved in the development of the individual units

### System and Release Testing
- system testing involves testing the system as a whole rather than individual features
- should focus on
  - testing to discover unexpected and unwanted interactions between features in a system
  - testing to discover if system features work together effectively to support what users really want to do with the system
  - testing to ensure system behaves in the expected way in the different environments where it will be used
  - testing responsiveness, throughput, security and other quality attributes of the system
  
#### Scenario-based Testing
- best way to systematically test a system is to start with a set of scenarios that describe possible uses of the system and then work through these scenarios each time new version of the system is created
- using the scenario, a set of ent-to-end pathways that users might follow when using the system
  - end-to-end pathway is a sequence of actions from starting to use the system for the task, through to completion of the task

#### Release Testing
- release testing is a type of system testing where system thats intended for release is tested
- difference between system and release testing
  - release testing tests system in real operation environment rather than test environment - problems arise from real user data which is more complex and less reliable than test data
  - aim of release testing is to decide if system is good enough to release not to detect bugs in the system - some test fails are ignored if they have minimal consequences for most users
- preparing a system for release involves 
  - packaging system for deployment
  - installing software and libraries used by software
  - define configuration parameters such as
    - root directory
    - database size limit per user
    
### Test Automation
- automated testing is based on teh idea that tests should be executable
- executable test includes input data, expected result, and a check
- large amounts of tests (hundreds or thousands) should be developed
- it is good practice to structure automated tests into three parts
  - arrange - set up system to run test, defining test parameters and mock objects to emulate functionality of code yet not developed
  - action - call unit test with test parameters
  - assert - make an assertion that should hold if the unit test executed successfully
- several automated tests based on correct and incorrect inputs from each partition should be made

### Feedback
- agile approaches provide early feedback
- shortening feedback loop saves and makes money
  - finding problems sooner means they are fixed sooner
  - fixed sooner costs less money
  - fixed sooner means less time spent on them
  - fixed sooner means deploying earlier
  - fixed sooner means earlier revenue

### Interdependence
- increase return on investment - making continuous flow of value
- deliver reliable results - engaging customers in frequent interactions and shared ownership
- expect uncertainty and manage for it - iterations anticipation and adaptation
- unleash creativity and innovation - recognizing individuals are the ultimate source of value and creating an environment where they cna make a difference
- improve effectiveness and reliability - situationally specific strategies processes and practices

### Refactoring
- tests enable safe refactoring
- ensures functionality of code is not changed incorrectly

### Automated Feature Testing
- GUI based testing is expensive - features should be accessible via an API
  - this allows testing to be done automatically
  - allows for the GUI top be re-implemented without affecting the functional components of the software

