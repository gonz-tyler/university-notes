# Week 3: Processes and Threads

## Notes

---

**Processes**

- **Definition**: A process is an instance of a program in execution, encompassing the program code, current activity (program counter), stack, data segment, and various attributes (like process ID, state, and resource management).
- **Isolation**: Processes are isolated from each other. Each process has its own memory space, meaning that the data and code of one process cannot be accessed directly by another process. This provides stability and security but can lead to higher overhead when processes need to communicate.

**Threads**

- **Definition**: A thread (or lightweight process) is a smaller unit of execution within a process. A process can have multiple threads that share the same memory space and resources.
- **Shared Resources**: Threads within the same process share the same address space, which allows for more efficient communication and resource sharing compared to inter-process communication (IPC). However, this shared access also raises issues like synchronization and data consistency.

**Relationships Between Processes and Threads**

- **Structure**: A process can contain multiple threads, each executing independently but sharing the process's resources. This allows for concurrent execution within a single process.
- **Execution**: Threads can run in parallel on multi-core processors, making them ideal for tasks that can benefit from parallelism, like handling multiple client requests in a server application.

**Operating System Handling**

1. **Single-threaded Processes**: Traditional operating systems may treat processes as single-threaded entities, meaning each process has one main execution thread. This simplifies process management but limits concurrency.
2. **Multithreaded Processes**: Modern operating systems support multithreading, allowing a single process to have multiple threads. This capability improves responsiveness and resource utilization.
3. **User-level vs. Kernel-level Threads**:
    - **User-level Threads**: These are managed by user-level libraries. The operating system is unaware of these threads, and scheduling is handled in user space. While this can lead to low overhead, it may limit performance if one thread blocks the entire process.
    - **Kernel-level Threads**: The operating system kernel manages these threads, providing better support for scheduling and concurrency. If one thread blocks, others can still run, improving overall performance.
4. **Thread Libraries**: Different operating systems offer various threading libraries (like POSIX threads on UNIX/Linux or Windows threads) to facilitate thread management. These libraries provide APIs for creating, synchronizing, and managing threads.
5. **Synchronization Mechanisms**: Since threads within a process share the same memory space, synchronization mechanisms (like mutexes, semaphores, and condition variables) are crucial to prevent race conditions and ensure data integrity.

**Summary**

  * In summary, processes are fundamental units of execution that encapsulate program code and resources, while threads are lighter-weight entities that allow concurrent execution within a process. Operating systems handle processes and threads differently, with a trend towards supporting multithreading and providing robust synchronization mechanisms to enhance performance and responsiveness.
