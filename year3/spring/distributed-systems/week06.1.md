# Week 6.1: Distributed Transactions

## Notes

---

### What is a Distributed Transaction?

A **distributed transaction** performs operations across multiple servers.

**Example:**

```
T = openTransaction()
a.withdraw(4)
c.deposit(4)
b.withdraw(3)
d.deposit(3)
closeTransaction(T)
```

- Accesses multiple remote objects.
- Needs to maintain atomicity and consistency across all involved servers.

---

### Atomicity in Distributed Transactions

- **Atomicity**: All parts of the transaction must succeed or none at all.
- This is challenging due to:
  - Server crashes
  - Network failures
  - Partial updates

➡ **Solution**: Use a commit protocol to coordinate actions.

---

### Distributed Systems Challenges

- Unreliable communication
- Crash failures
- Partial success of operations
- Need to ensure:
  - Atomicity
  - Durability
  - Consistency
  - Non-blocking progress

---

### Distributed Commit Protocol

Used to decide whether to **commit** or **abort** a distributed transaction.

#### Roles:

- **Coordinator**: Manages the process.
- **Participants**: Servers that perform operations.

---

### Coordinator and Participants

- **Coordinator**: Starts and coordinates the transaction.
- **Participants**: Join the transaction and execute their local operations.

---

### Types of Commit Protocols

#### One-Phase Commit:

- Coordinator sends commit command directly.
- Issues:
  - Blocking
  - No way for participants to abort unilaterally
  - Not failure-resilient

#### Two-Phase Commit (2PC):

- Reliable voting-based protocol for atomic commitment.

---

### Two-Phase Commit Protocol (2PC)

#### Phase 1: Voting Phase

1. **Coordinator → Participants**: `canCommit?`
2. **Participants → Coordinator**: vote `Yes` or `No`
   - If **Yes**: log actions, enter prepared state.
   - If **No**: abort immediately.

#### Phase 2: Commit/Abort Phase

- If **all votes are Yes**:
  - Coordinator sends `doCommit`
- If **any vote is No**:
  - Coordinator sends `doAbort`

---

### Key Operations in 2PC

| Operation         | From → To                 | Purpose                               |
| ----------------- | ------------------------- | ------------------------------------- |
| `canCommit(Tid)`  | Coordinator → Participant | Ask if participant is ready to commit |
| `doCommit(Tid)`   | Coordinator → Participant | Instruct to commit                    |
| `doAbort(Tid)`    | Coordinator → Participant | Instruct to abort                     |
| `haveCommitted()` | Participant → Coordinator | Acknowledge commit                    |
| `getDecision()`   | Participant → Coordinator | Ask for final decision after crash    |

---

### ACID Properties – Focus on Durability

- If a participant votes Yes, it **must** be able to commit later.
- Changes are logged to **persistent storage**.
- After a crash, the log allows recovery and completion.

---

### Failure Handling

#### Timeouts:

- **Coordinator Timeout**: If no votes, abort transaction.
- **Participant Timeout (before voting)**: Abort unilaterally.
- **Participant Timeout (after voting Yes)**: Must wait – **blocking**.

#### Coordinator Crash:

- Participants in prepared state must wait.
- Can query using `getDecision()` after recovery.

---

### Blocking in 2PC

- Once a participant votes **Yes**, it cannot abort on its own.
- If the coordinator crashes before sending `doCommit`/`doAbort`, participant must **wait indefinitely**.
- This is why 2PC is called a **blocking protocol**.

---

### Flow of 2PC

#### Phase 1: Voting

```
Coordinator → canCommit?
Participants → Yes/No
```

#### Phase 2: Completion

```
If all Yes: Coordinator → doCommit → Participants
If any No:  Coordinator → doAbort  → Participants
Participants → haveCommitted (if committed)
```

---

### Summary

| Feature      | 2PC Guarantees                   |
| ------------ | -------------------------------- |
| Atomicity    | All or nothing                   |
| Durability   | Through logging                  |
| Consistency  | Maintains integrity              |
| Non-blocking | Can block if coordinator crashes |

---

### Key Terms

- **Atomicity**: All-or-nothing execution
- **Durability**: Changes survive failures
- **Coordinator**: Server that leads the protocol
- **Participant**: Server that executes operations
- **Prepared State**: Ready to commit, waiting for decision
- **Blocking**: Waiting indefinitely due to coordinator failure

---

### Beyond 2PC

- **Three-Phase Commit (3PC)** protocols attempt to solve the blocking problem.
- 3PC adds another phase but has **higher message overhead** in failure-free scenarios.

---
