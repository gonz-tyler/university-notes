# Unit 7: Introduction to Scheduling

## Notes
---

## Key Concepts in Scheduling
- **CPU Scheduling**: Selection of the next process from the ready queue for execution on a processor.
  - Processes alternate between:
    - **CPU Bursts**: Performing computations.
    - **I/O Bursts**: Waiting for data transfer.

---

## Types of Scheduling
1. **Preemptive Scheduling**:
   - OS interrupts the current process.
   - Ensures fair resource sharing.
   - Used in most modern operating systems.
   - Example: Round-Robin Scheduling.

2. **Non-Preemptive Scheduling**:
   - Once a process starts, it runs until it finishes or voluntarily yields.
   - Example: First Come First Serve (FCFS).

---

## Scheduling Goals
- **System Perspective**:
  - Maximize CPU utilization and throughput.
  - Fair allocation of resources.
  - Balance priorities among processes.
- **User Perspective**:
  - Minimize waiting, turnaround, and response times.
  - Meet deadlines, particularly in real-time systems.

---

## Performance Criteria
1. **User Concerns**:
   - **Turnaround Time**: Time to complete a process.
   - **Waiting Time**: Time spent in the ready queue.
   - **Response Time**: Delay before starting a process.
   - **Deadline Adherence**: Crucial in real-time systems.
   - **Predictability**: Consistent execution times.

2. **System Concerns**:
   - **Processor Utilization**: Keeping CPU busy.
   - **Throughput**: Number of completed processes.
   - **Fairness**: Avoiding process starvation.
   - **Priority Enforcement**: Respecting priority rules.

---

## Scheduling Algorithms

### Non-Priority Algorithms
1. **First Come First Serve (FCFS)**:
   - **Policy**: Processes executed in arrival order (FIFO).
   - **Advantages**: Simple, fair for long processes.
   - **Disadvantages**: High waiting times, convoy effect.
   - **Example**: Reordering can reduce average waiting times.

2. **Round-Robin (RR)**:
   - **Policy**: Processes are assigned time quanta in a cycle.
   - **Advantages**: Fair, no starvation.
   - **Disadvantages**: Overhead due to frequent context switches.

---

### Priority-Based Algorithms
1. **Shortest Job First (SJF)**:
   - **Policy**: Execute shortest expected job first.
   - **Advantages**: Minimizes average waiting time.
   - **Challenges**: Predicting burst times.

2. **Priority Scheduling**:
   - **Policy**: Higher-priority processes executed first.
   - **Dynamic Priorities**: Adapt based on past performance.
   - **Static Priorities**: Fixed at process creation.

---

## Real-Time Scheduling
- Used when timely response is critical (e.g., air traffic control).
- **Key Types**:
  - **Hard Real-Time**: Deadlines are strict; failure is unacceptable.
  - **Soft Real-Time**: Missing occasional deadlines is tolerable.

### Scheduling Approaches
1. **Static Scheduling**:
   - Predefined schedule based on known tasks.
   - Analysis and schedule creation offline.
   - **Static Table-Driven**: Fixed schedule based on arrival time, execution time, and deadlines.
   - **Static Priority-Driven**: Priorities are assigned offline; preemptive execution allowed.

2. **Dynamic Scheduling**:
   - Scheduling decisions are made at runtime.
   - **Earliest Deadline First (EDF)**: Processes with the closest deadlines are prioritized.
---

## Real-Time Scheduling Criteria
1. **Periodic Events**:
   - Occur at regular intervals.
   - Processing must be completed within the period.

2. **Aperiodic Events**:
   - Occur unpredictably with deadlines.

---

## Example: Schedulability Analysis
- **Task Utilization Formula**:
  - \( U = \sum (C_i_ / T_i_) \leq 1 \)
  - Where \( C_i_ \): CPU time for task \( _i_ \), \(
