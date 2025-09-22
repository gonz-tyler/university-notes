# Week 5.1: Transactions and Concurrency Control
## Notes
---

### Transactions Overview

- **Transaction**: A controlled sequence of actions for manipulating a database.
- **Objective**: Ensure data consistency and avoid data loss or corruption.
- **Problems**:
    - **System Failure**: Hardware/software crashes during data manipulation.
    - **Concurrent Access**: Multiple users interfering with each other's data.

### Transaction Properties

- **Atomicity**: Transactions are "all-or-nothing". Either all operations are completed, or none are.
- **Consistency**: Transactions transform the database from one consistent state to another.
- **Isolation**: Incomplete transactions do not reveal intermediate states to other transactions.
- **Durability**: Once committed, the transaction's results persist even after system failure.

### Transaction Lifecycle

- **Commit**: Transaction ends successfully, and all changes are saved.
- **Abort**: Transaction is undone, and the database returns to its previous state.
- **Rollback**: Undo operations in case of abort or system failure.

### Concurrency Problems

- **Lost Update**: Two transactions overwrite each other's updates.
- **Inconsistent Retrieval**: A transaction reads uncommitted data from another transaction (dirty read).

### Concurrency Control

- **Serialisability**: Ensures that concurrent transactions produce the same result as if they were executed serially.
- **Conflict Between Operations**:
    - **Read-Read**: No conflict.
    - **Read-Write**: Conflict (order matters).
    - **Write-Write**: Conflict (order matters).

### Two-Phase Locking (2PL)

- **Phase 1 (Growing Phase)**: Acquire all locks.
- **Phase 2 (Shrinking Phase)**: Release locks after commit or abort.
- **Strict 2PL**: Locks are released only after the transaction commits or aborts.

### Serialisability Condition

- **Conflict Rules**:
    - Transactions must execute conflicting operations in the same order.
    - Ensures that the schedule is equivalent to a serial schedule.
