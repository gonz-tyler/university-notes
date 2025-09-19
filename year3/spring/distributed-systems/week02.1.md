# Week 2.1: Serialisation, Callbacks, Remote Object Activation
## Notes
---

### Serialization
- Converts Java objects into a byte stream for transmission or storage.
- Deserialization reconstructs objects from a byte stream.
- Implemented using `java.io.Serializable`.
- Ensures object state can be persisted and reconstructed.
- Used for sending objects in distributed computing environments.

#### Custom Serialization
- Customize serialization using `writeObject()` and `readObject()` methods.
- Allows control over how objects are serialized and deserialized.

```java
private void writeObject(ObjectOutputStream out) throws IOException {
    out.defaultWriteObject();
}

private void readObject(ObjectInputStream in) throws IOException, ClassNotFoundException {
    in.defaultReadObject();
}
```

### Java Streams
- **Byte Streams**: Raw binary data (e.g., `FileInputStream`, `FileOutputStream`).
- **Character Streams**: Handles character data (`FileReader`, `FileWriter`).
- **Object Streams**: Serializes Java objects (`ObjectInputStream`, `ObjectOutputStream`).

### Callbacks in RMI
- Instead of polling, a server can invoke a remote method on the client.
- Requires clients to export remote objects for the server to call.
- Allows real-time event notification from server to client.

### RMI Activation Service
- Automatically starts remote objects when requested.
- Increases robustness and scalability.
- Uses `rmid`, the RMI Activation System Daemon.
- Ensures remote objects persist beyond server restarts.
