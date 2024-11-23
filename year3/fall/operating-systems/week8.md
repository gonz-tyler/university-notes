# Week 8: Introduction to Synchronisation

## Notes

---

### Introduction to Synchronisation
- Concurrency:
  - Allows processes to execute interleaved in time on a single processor.
  - Simulates simultaneous execution, enhancing efficiency.
  - Challenges:
    - Processor time allocation.
    - Inter-process communication.
    - Activity synchronisation.
    - Resource sharing and competition.

- Difficulties in Concurrency:
  - Resource Competition:
    - Unordered read/write operations risk race conditions.
    - Potential for deadlocks due to resource allocation issues.
  - Non-Deterministic Behaviour:
    - Debugging is challenging; scheduling patterns are hard to reproduce.

### Synchronisation of Processes
- Mutual Exclusion:
  - Ensures only one process accesses critical resources at a time.
- Condition Synchronisation:
  - Processes must wait for specific conditions to proceed.

#### Key Example:
```c
process1() { read(x); local_y = x - 5; write(local_y); }
process2() { read(x); local_z = x + 2; write(local_z); }

```
- Context switches can lead to inconsistent results, e.g., race conditions.

### Race Conditions
- Occurs when multiple processes read/write shared data.
- Final outcome depends on execution order.
- Solutions:
  - Synchronise processes to avoid stale data and arbitrary context switches.

### Critical Sections
- Definition:
        Part of code accessing shared resources.
- Protocol:
  - Entry Section:
    - Requests permission to enter critical section.
    - Uses inter-process communication.
  - Exit Section:
    - Communicates that the critical section is freed.
- Requirements:
  - Mutual Exclusion: Only one process in a critical section.
  - Progress (Liveness): Processes must not wait indefinitely.
  - Bounded Waiting: Processes must eventually enter their critical sections.

### Implementing Mutual Exclusion
#### Software Approaches:
- Shared Lock Variables:
  - Busy waiting (e.g., spin locks).
- Higher-Level Constructs:
  - Semaphores, monitors, message passing.

#### Hardware Approaches:
- Disable Interrupts.
- Special Instructions:
  - Test-and-Set (TSL).
  - Exchange (Swap).

### Problems in Synchronisation
- Busy Waiting:
  - Wastes CPU cycles and degrades performance.
- Deadlock:
  - Processes wait forever due to circular dependencies.
- Starvation:
  - Some processes are indefinitely delayed.
- Context Switching:
  - Leads to inconsistent states without atomic operations.

### Solutions to the Critical Section Problem
1. Lock Mechanisms:
  - Atomic actions protect critical sections.
  - Example:
  ```c
    process() {
      acquire_lock();
      critical_section();
      release_lock();
      remainder_section();
    }
  ```

2. Hardware Solutions:
  - Atomic Instructions:
    - Test-and-Set: Reads and writes lock in one atomic action.
    ```c
            while (TestAndSet(lock) == TRUE) { /* busy wait */ }
            lock = FALSE;
    ```
    - Swap: Exchanges values of a private and shared variable atomically.
3. Software Protocols:
  - Strict Alternation:
    - Alternates access between two processes.
    - Problem: Can block progress if one process halts.
  - Array of Flags:
    - Uses individual flags for processes to indicate intent to enter critical sections.
    - Can still lead to deadlocks.

### Key Hardware Instructions
- Test-and-Set:
  - Performs read and write in one atomic step.
  - Prevents race conditions by locking shared resources.
  - Example:
  ```assembly
  enter_section:
    TSL REGISTER, LOCK
    CMP REGISTER, #0
    JNE enter_section
    RET
  exit_section:
    MOVE LOCK, #0
    RET
  ```
- Exchange:
  - Swaps the values of a lock and a private variable atomically.
  - Example:
  ```assembly
  enter_section:
    MOVE REGISTER, #1
    XCHG REGISTER, LOCK
    CMP REGISTER, #0
    JNE enter_section
    RET
  exit_section:
    MOVE LOCK, #0
    RET
  ```
### Key Takeaways
- Synchronisation ensures correct and efficient process execution in concurrent systems.
- Critical sections must be carefully managed to avoid race conditions, deadlocks, and starvation.
- Solutions include software protocols and hardware-supported atomic operations.
