# Week 5.2: Improving Concurrency
## Notes
---

### Concurrency Control Techniques

1. **Locking**: Enforces mutual exclusion by reserving data objects for exclusive access.
2. **Optimistic Concurrency Control**: Transactions proceed without locking, and conflicts are detected at commit time.
3. **Timestamp Ordering**: Transactions are ordered based on timestamps to ensure serialisability.

### Locking

- **Simple Locking**: Transactions lock objects before accessing them.
- **Problems**:
    - Deadlocks.
    - Reduced concurrency due to exclusive locks.
- **Two-Phase Locking (2PL)**:
    - **Growing Phase**: Acquire locks.
    - **Shrinking Phase**: Release locks after commit or abort.
    - Ensures serialisability but can reduce concurrency.

### Optimistic Concurrency Control

- **Overview**: Transactions proceed without locking, and conflicts are detected at commit time.
- **Phases**:
    - **Working Phase**: Read and write operations occur on tentative copies.
    - **Validation Phase**: Check for conflicts with other transactions.
    - **Update Phase**: Commit changes if no conflicts are found.
- **Advantages**:
    - No locking overhead.
    - Higher concurrency.
- **Disadvantages**:
    - Transactions may need to abort and restart if conflicts are detected.

### Validation of Transactions

- **Backward Validation**: Check for conflicts with already committed transactions.
- **Forward Validation**: Check for conflicts with active transactions.
- **Conflict Rules**:
    - **Rule 1**: A transaction must not read objects written by another transaction.
    - **Rule 2**: A transaction must not write objects read by another transaction.
    - **Rule 3**: A transaction must not write objects written by another transaction.

### Conflict Detection

- **Read Set**: Objects read by the transaction.
- **Write Set**: Objects written by the transaction.
- **Conflict**: Intersection between read/write sets of different transactions.

### Update Phase

- **Successful Validation**: Tentative copies are made permanent.
- **Read-Only Transactions**: Can commit immediately after validation.
- **Write Transactions**: Commit after tentative versions are recorded in permanent storage.
