# Week 3.1: Interprocess Communication - External Data Representation
## Notes
---

### External Data Representation

#### Overview

- **External Data Representation**: An agreed standard for representing data structures and primitive values in a format suitable for transmission over a network.
- **Marshalling**: The process of converting data structures into a byte stream for transmission.
- **Unmarshalling**: The process of converting a byte stream back into data structures at the destination.

#### Key Concepts

- **Data Representation Problems**:
    - Different systems may use different internal data representations (e.g., big-endian vs. little-endian).
    - Marshalling and unmarshalling ensure that data is correctly interpreted across different systems.
- **Middleware Role**: Marshalling and unmarshalling are typically handled by middleware, reducing the risk of errors.

#### CORBA Common Data Representation (CDR)

- **CORBA CDR**: A standard for external data representation used in CORBA (Common Object Request Broker Architecture).
- **Primitive Types**: Supports 15 primitive types (e.g., short, long, float, double, char, boolean).
- **Composite Types**: Supports constructed types like sequences, strings, arrays, structs, and unions.
- **Example**: A struct with fields `{'Smith', 'London', 1934}` is marshalled into a byte stream with length prefixes for strings.

#### Java Object Serialization

- **Serialization**: The process of converting Java objects into a byte stream for storage or transmission.
- **Deserialization**: The process of reconstructing Java objects from a byte stream.
- **Java Serialization Example**:
    - A `Person` class with fields `name`, `place`, and `year` can be serialized into a byte stream.
    - The serialized form includes class information, instance variable names, and their values.
- **Reflection**: Java uses reflection to dynamically inspect and manipulate class properties during serialization and deserialization.

#### Remote Object References

- **Remote Object References**: Used in distributed systems to uniquely identify and access remote objects.
- **Structure**: Typically includes:
    - Internet address and port number of the process that created the object.
    - Creation time and a local object number.
    - Interface information for accessing the remote object.
- **Uniqueness**: Remote object references must be unique across space and time to ensure correct object identification.

#### Client-Server Communication

- **Request-Reply Communication**: A synchronous communication pattern where the client sends a request and waits for a reply from the server.
- **Asynchronous Communication**: The client can continue execution without waiting for the server's reply, useful for long-running operations.
- **Request-Reply Protocol**: Involves three primitives:
    - `doOperation`: Sends a request message to a remote object.
    - `getRequest`: Acquires a client request at the server.
    - `sendReply`: Sends a reply message back to the client.
