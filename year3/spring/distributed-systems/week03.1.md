# Week 3.1: External Data Representation
## Notes
---
### What is External Data Representation?
- A standard format for representing data structures and primitive values.
- Needed to ensure data consistency across heterogeneous systems.

### Marshalling and Unmarshalling
- **Marshalling**: Converting data structures into a format suitable for transmission.
- **Unmarshalling**: Reconstructing data structures from a transmitted format.

### CORBA Common Data Representation (CDR)
- Standard format used in CORBA to ensure cross-platform compatibility.
- Supports 15 primitive types (short, long, float, double, boolean, etc.).
- Supports composite types such as structs, sequences, and unions.

### Java Object Serialization
- Java-specific mechanism to serialize and deserialize objects.
- Objects can contain references to other objects, which are serialized recursively.
- Uses reflection to extract and reconstruct object fields.

```java
ObjectOutputStream out = new ObjectOutputStream(...);
out.writeObject(originalPerson);

ObjectInputStream in = new ObjectInputStream(...);
Person thePerson = (Person) in.readObject();
```

### Remote Object References
- Required when invoking objects on a remote server.
- Must be unique across space and time.

### Client-Server Communication
- Uses request-reply protocols for message exchange.
- **Synchronous Communication**: The client blocks until a response is received.
- **Asynchronous Communication**: The client continues processing and retrieves the response later.

### Summary
- External data representation ensures data integrity across distributed systems.
- Marshalling and unmarshalling are essential for transmitting structured data.
- Java serialization simplifies object persistence and transmission.
- CORBA CDR provides language-independent data representation.
