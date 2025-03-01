# Week 4.2: Indirect Communication
## Notes
---

### Indirect Communication Overview

- **Indirect Communication**: Communication between entities through an intermediary, without direct coupling between sender and receiver.
- **Key Properties**:
    - **Space Uncoupling**: Sender does not need to know the identity of the receiver(s).
    - **Time Uncoupling**: Sender and receiver(s) can have independent lifetimes.

### Group Communication

- **Group Communication**: A message is sent to a group and delivered to all members.
- **Dynamic Group Membership**: Processes can join or leave the group.
- **Reliability and Ordering**:
    - **Reliability**: Messages are delivered to all members (integrity, validity, agreement).
    - **Ordering**: Messages may be delivered in FIFO, causal, or total order.

### Publish-Subscribe Systems

- **Publish-Subscribe Model**:
    - **Publishers**: Publish events to an event service.
    - **Subscribers**: Subscribe to events of interest.
    - **Event Service**: Delivers events to all interested subscribers.
- **Subscription Models**:
    - **Channel-Based**: Subscribers subscribe to named channels.
    - **Topic-Based**: Subscriptions are based on topics.
    - **Content-Based**: Subscriptions are based on event content.
    - **Type-Based**: Subscriptions are based on event types.

### Message Queues

- **Message Queues**: Provide point-to-point communication.
    - **Producer**: Sends messages to a queue.
    - **Consumer**: Receives messages from the queue.
- **Persistence**: Messages remain in the queue until consumed.
- **Receive Styles**:
    - **Blocking**: Wait until a message is available.
    - **Non-Blocking**: Poll the queue for messages.
    - **Notify**: Receive event notifications when messages arrive.
