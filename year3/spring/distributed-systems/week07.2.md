
# Week 07.2: Reliability and Availability
## Notes
---

### Overview

- **Reliability**: Continuous and correct service, even during failures.
- **Availability**: Ability to handle high service demand without becoming unresponsive.

#### Key Strategies:
- **Fault Tolerance**: Using replication to maintain service under failure.
- **Load Handling**: Efficient use of system resources (e.g., TP Monitors).

---

### Transaction Processing Monitors (TP Monitors)

- Used in large-scale systems (e.g., banking, airline booking).
- **Problem**: High user load may overwhelm system resources.
- **Solution**: Funnel connections, reuse limited processes.

#### Funnelling:
- Share a limited number of connections among many clients.
- Reduces memory and process load on the server.

---

### Java-Based Funnelling (Example)

- Use a **Manager** that controls a **pool of connections**.
- Clients:
  - Request connections.
  - May sleep and retry if pool is full.
  - Get rejected or wait using `wait()/notifyAll()`.

---

### Replication in Distributed Systems

- **Replication**: Maintain multiple copies of data/services across servers.
- **Use Cases**: Caching, mobile computing, failover systems.

---

### Benefits of Replication

#### Performance:
- Local caching speeds up data access.
- E.g., web browsers, proxies.

#### Availability:
- Alternate servers serve data if one fails.
- Example: 
  - If each server has 5% failure probability:
    - 1 server → 95% availability
    - 2 servers → 99.75% availability

#### Fault Tolerance:
- System behaves correctly despite failures.
- Important for systems like air traffic control.

---

### Byzantine Failures

- **Byzantine Failures**: Arbitrary faults (e.g., corrupted messages, duplicated delivery).
- Hardest to detect and tolerate.

#### Defense:
- Use **voting** among multiple servers.
- If up to **f** can fail, need **2f + 1** to ensure majority correctness.

---

### Replication Models

#### Passive Replication (Primary-Backup)
- One primary handles all requests, backups replicate state.
- If primary fails, a backup takes over.

#### Active Replication
- All replicas handle all requests simultaneously.
- Requires **totally ordered multicast** to ensure consistency.

---

### Totally Ordered Multicast

- All replica managers must receive messages in **the same order**.
- Ensures deterministic state among replicas.
- Required for active replication to succeed.

---

### Transactions Over Replicated Data

- Should behave identically to non-replicated transactions.
- Replicas must coordinate to maintain consistency.

---

### 2PC with Replication

#### General Two-Phase Commit (2PC):
1. **canCommit?** sent to participants.
2. If all vote Yes, **doCommit** is sent.

#### In Replication:
- Replica manager collects votes from its group.
- Replies to transaction coordinator on behalf of group.

---

### 2PC in Replication Models

#### Passive:
- Primary votes and updates backups (eager or lazy).

#### Active:
- Use **read-one/write-all** strategy.
- All writes must go to every replica with locks.

---

### Summary

| Feature          | Description                                  |
|------------------|----------------------------------------------|
| **Reliability**  | Continuity of correct service                |
| **Availability** | Uptime and service responsiveness            |
| **Replication**  | Enhances performance, availability, fault tolerance |
| **Byzantine Tolerance** | Needs 2f + 1 servers for f failures   |
| **2PC over Replication** | Ensures consistency during failure    |

#### Key Formula:
Availability: `a = 1 - p^n`

---
