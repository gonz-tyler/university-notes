# Week 7.1: Distributed Deadlocks

## Notes

---

### What is a Deadlock?

- A **deadlock** occurs when processes or transactions are waiting indefinitely for resources held by each other.
- Caused by resource locking (common in databases and distributed systems).

#### Elements:

- **Process/Transaction**: Executes actions and holds resources.
- **Resource**: Data objects that are locked during execution.

---

### Coffman Conditions for Deadlock

A deadlock occurs if all of the following are true:

1. **Mutual Exclusion**: Resources are non-shareable.
2. **Hold and Wait**: A process holds a resource and waits for another.
3. **No Preemption**: A resource cannot be forcibly taken.
4. **Circular Wait**: Processes form a closed loop, each waiting for another.

---

### Related Concepts

- **Livelock**: Continuous state change without progress.
- **Starvation**: A process never gets scheduled due to lower priority.

---

### Deadlock Detection and Resolution

#### Techniques:

- **Abort a transaction** to break the cycle.
- Use **timestamps** or **complexity** to choose which to abort.
- **Timeouts**: Impose limits; if exceeded, abort.

---

### Wait-for Graph

- Graph model to detect deadlocks.
- **Nodes** = transactions
- **Edges** = wait-for relations
- **Cycle** in graph = deadlock

---

### Read and Write Locks Deadlock

- Deadlocks can occur when read/write lock combinations are in place.
- **Promotion** of read to write locks can create deadlocks.
- Wait-for graphs help visualize complex interdependencies.

---

### Breaking Deadlocks

- Abort a transaction in all cycles (e.g., the one appearing most).
- After breaking the cycle, others proceed normally.

---

### Deadlock Handling Strategies

#### Detection:

- Use wait-for graphs.
- Abort based on age or complexity.

#### Prevention:

- Lock all needed resources at start (limits concurrency).
- Impractical in dynamic/interactive scenarios.

#### Timeouts:

- Locks become vulnerable after time.
- Risks aborting without real deadlocks.

---

### Distributed Deadlocks

- Deadlocks can span multiple servers.
- Local wait-for graphs cannot detect global cycles.

#### Global Wait-for Graph:

- Combines all local graphs.
- May reveal cycles missed locally.

---

### Centralized Deadlock Detection

- Central server collects local graphs.
- Builds global graph and detects cycles.

#### Problems:

- Single point of failure.
- Bottlenecks and communication overhead.
- Can detect **phantom deadlocks** due to outdated info.

---

### Phantom Deadlocks

- Detected due to stale data in global graph.
- May lead to unnecessary transaction aborts.

---

### Edge Chasing – Distributed Detection

#### Concept:

- Uses **probes** instead of global graphs.
- Probes track the wait chain across servers.

#### Steps:

1. **Initiation**: Start probe when waiting.
2. **Detection**: Forward probe with updated wait path.
3. **Resolution**: If cycle detected, abort one transaction.

---

### Edge Chasing Example

- Probe travels: `<T→U→V→T>`
- Cycle means deadlock.
- Abort the transaction with the lowest priority.

#### In depth example
![[Pasted image 20250426190458.png]]
- A probe is initiated when  
	1. A server notes that a transaction T starts waiting for  another transaction U to release a resource  
	2. Transaction U itself waits for release of a locked resource  on another server  
- The probe is initialised with the path `<T-->U>` and sent to the server where the locked resource is managed

![[Pasted image 20250426190724.png]]
- When a server receives a probe `<T-->U>`, it first checks whether U is waiting itself for a resource to be released at the server: 
	- If U is waiting for, e.g., transaction V to release b, then V is added to the path recorded by the probe, a new probe `<T- ->U-->V>` is constructed 
	- If transaction V itself, again, is waiting for an object on some other server, the probe is forwarded to that server

![[Pasted image 20250426190918.png]]
- When a server receives a probe, it also checks for a deadlock
	- If there is a transaction blocking access to a data object at the server and itself waiting, it is added to the probe
	- If the probe contains now a cycle – e.g. `<T-->U-->V-->T>`,  then a deadlock has been detected
- One of T, U or V must be aborted  

---

### Prioritization and Probe Optimization

- Use **transaction priorities** (e.g., timestamps).
- Abort the transaction with **lowest priority**.
- Probes only go "downhill" (high to low priority).

---

### Limitations of Priority-based Probes

- Some deadlocks may be **missed**.
- **Queuing probes** makes algorithm complete but adds complexity.

---

### Summary

| Method               | Description                              |
| -------------------- | ---------------------------------------- |
| Wait-for Graph       | Detect cycles, usually centralized       |
| Timeouts             | Simple but may cause false aborts        |
| Edge Chasing         | Distributed and dynamic detection        |
| Centralized Detector | Bottleneck and single point of failure   |
| Phantom Deadlocks    | False detection due to stale information |

---
