# Week 4.1: Threads Creation and Coordination
## Notes
---

### Threads Overview

- **Thread**: A single sequential flow of control within a program.
- **Multithreading**: Multiple threads can work together to accomplish a common goal.
- **Advantages**:
    - Easier to program (one thread per task).
    - Better performance (threads run when needed).
    - Resource sharing among threads.
- **Disadvantages**:
    - Overhead of switching between threads.
    - Potential for deadlock.

### Creating Threads

- **Approach 1: Extending the `Thread` Class**:
    - Override the `run` method to define the thread's behavior.
    - Call `start` to begin execution.
- **Approach 2: Implementing the `Runnable` Interface**:
    - Implement the `run` method.
    - Pass the `Runnable` object to a `Thread` constructor and call `start`.

### Thread Life-Cycle

- **States**:
    - **New**: Thread created but not started.
    - **Runnable**: Thread is ready to run.
    - **Blocked**: Thread is waiting for an event (e.g., I/O).
    - **Dead**: Thread has finished execution.
- **Methods**:
    - `start()`: Starts the thread.
    - `sleep()`: Pauses the thread for a specified time.
    - `join()`: Waits for another thread to terminate.
    - `yield()`: Suggests that the thread give up the CPU.

### Thread Coordination

- **Thread Termination**:
    - Threads consume resources and should be terminated when no longer needed.
    - Use `interrupt()` to signal a thread to stop.
- **Thread.join()**:
    - Causes the calling thread to wait until the referenced thread terminates.
    - Useful for aggregating results from multiple threads.

### Thread Scheduling

- **Priority**:
    - Threads are scheduled based on priority (higher priority threads run first).
    - Default priority is `NORM_PRIORITY` (5).
    - Priorities can be set using `setPriority()`.
- **yield()**:
    - Suggests that the current thread give up the CPU to other threads of the same priority.
