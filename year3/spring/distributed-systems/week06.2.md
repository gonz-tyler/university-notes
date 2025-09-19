# Week 6.1: Distributed Transactions II

## Notes

---

### Two-Phase Commit Protocol (2PC)

#### Roles:

- **Coordinator**: Initiates and controls the transaction.
- **Participants**: Join transaction and respond to the coordinator.

#### Two Phases:

1. **Voting Phase** (Prepare to Commit)
2. **Completion Phase** (Commit or Abort)

---

### 2PC Flow Summary

#### Phase 1: Voting

- Coordinator sends `canCommit?` to all participants.
- Participants vote `Yes` or `No`.

#### Phase 2: Completion

- If **all vote Yes**: coordinator sends `doCommit`.
- If **any vote No** or timeout: coordinator sends `doAbort`.

---

### Failure Scenarios and Handling

#### Participant Failure (Phase 1)

- Coordinator times out and sends `doAbort`.
- Non-blocking: other participants do not wait.
- Recovered participant asks coordinator for decision.

#### Participant Failure (Phase 2)

- Recovered participant calls `getDecision()`.
- Non-blocking if coordinator is responsive.

#### Coordinator Failure (Phase 1)

- Before sending `canCommit?`: participants timeout and abort (non-blocking).
- After sending `canCommit?`: participants prepare but are left uncertain if no further response.

#### Coordinator Failure (Phase 2)

- Participants are in uncertain state.
- Some may have received commit/abort message.
- **If one knows the decision**: it can share it.
- **If none knows**: elect a new coordinator.

---

### Strategies for Coordinator Failure

- **Elect a new coordinator**
- Restart 2PC:
  - If all votes received, proceed.
  - If some votes missing (due to crash), abort.

---

### Problematic Case: Coordinator + One Participant Fail

- Remaining participants elect new coordinator → may decide to abort.
- Crashed participant may have already committed based on old coordinator's message.
- ❗ Possibility of **inconsistency/conflict**.

---

### 2PC Limitations

- **Blocking Protocol**:
  - Participants in prepared state must wait for coordinator’s decision.
  - Locks on data remain in place.
  - Delays transaction completion in failure scenarios.

---

### Introduction to 3PC (Three-Phase Commit Protocol)

- Designed to be **non-blocking**.
- Adds an extra phase to avoid the uncertainty.

---

### Three-Phase Commit (3PC) Phases

#### Phase 1: Voting

- Coordinator sends `canCommit?`
- If all vote Yes → go to pre-commit.

#### Phase 2: Pre-Commit

- Coordinator sends `doPrepare`
- Participants acknowledge (ACK) → now all are prepared.

#### Phase 3: Commit

- Coordinator sends `doCommit`
- Participants commit and send `haveCommitted`.

---

### Benefits of 3PC

- Ensures that no single failure causes indefinite blocking.
- Participants in **PRECOMMIT** state can commit after timeout.
- Coordinator or participant recovery no longer mandatory for decision finalization.

---

### 3PC vs 2PC

| Feature          | 2PC     | 3PC      |
| ---------------- | ------- | -------- |
| Phases           | 2       | 3        |
| Blocking         | Yes     | No       |
| Message Overhead | Lower   | Higher   |
| Failure Handling | Limited | Enhanced |

---

### Timeout and Recovery Scenarios in 3PC

- **Coordinator Timeout (Phase 1)**: Sends `doAbort`
- **Coordinator Timeout (Phase 2)**: Sends `doAbort`
- **Participant Timeout (Phase 2)**: Aborts
- **Participant Timeout (Phase 3)**: Commits

---

### Key Takeaways

- 2PC is **reliable but blocking**.
- 3PC is **non-blocking**, but more complex.
- 3PC introduces a **PRECOMMIT** phase to reduce uncertainty.
- Recovery and timeout strategies are essential to ensure consistency.

---
