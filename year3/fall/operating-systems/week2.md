# Week 2: Operating System Architecture and Processes

## Notes

---

**Kernel Architectures**

1. **Monolithic Kernels**: In this architecture, the entire operating system (OS) is running in a single address space. All system services (like device drivers, file systems, etc.) are included in the kernel. This can lead to faster performance due to less overhead, but it can also make the kernel more complex and harder to maintain.
2. **Microkernels**: Microkernels aim to minimize the amount of code running in kernel mode. They include only the most essential services (like communication between processes) in the kernel, while other services (like device drivers and file systems) run in user space. This can improve system stability and security but might incur performance overhead due to more frequent context switches.
3. **Hybrid Kernels**: This architecture combines aspects of both monolithic and microkernels. It retains some of the performance benefits of a monolithic kernel while still aiming for modularity and flexibility.

**Process Execution**

- **Process**: A process is an instance of a program in execution. It includes the program code, its current activity (represented by the program counter), a stack containing temporary data, and a data section containing global variables.
- **Execution States**: Processes can be in several states, including:
    - **New**: The process is being created.
    - **Ready**: The process is ready to run and waiting for CPU time.
    - **Running**: The process is currently being executed.
    - **Waiting**: The process is waiting for an event to occur (like I/O completion).
    - **Terminated**: The process has finished execution.

**Process Switching**

- **Context Switching**: This is the process of storing the state of a currently running process so it can be resumed later, and loading the state of the next process to be executed. This involves saving and restoring registers, memory maps, and the process control block (PCB).
- **Overhead**: Context switching can incur significant overhead because it involves multiple steps, including updating various data structures and moving the CPU state from one process to another.

**Process Creation and Termination**

- **Creation**: A process can be created using system calls like `fork()` in UNIX/Linux systems. The new process (child) is an almost exact copy of the parent process, but it has a unique process ID. The child process can then execute a different program using an `exec()` call.
- **Termination**: A process can terminate itself or be terminated by another process. Upon termination, the operating system must reclaim resources associated with the process, such as memory and open file descriptors.
- **Zombie State**: After a process terminates, it may enter a zombie state until its parent process reads its exit status. This ensures that the operating system can clean up the remaining resources.

These concepts provide a foundational understanding of how operating systems manage processes and handle execution.
