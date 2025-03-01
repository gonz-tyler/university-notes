# Week 2.1: Serialization, Callbacks, RMI Activation
## Notes
---

### Serialization

#### Overview

- **Java Serialization**: The process of converting an object or a set of connected objects into a serial form suitable for storage or transmission.
- **Deserialization**: The reverse process of converting a serialized byte stream back into an object.

#### Key Concepts

- **Serialization in Java**: Achieved by implementing the `java.io.Serializable` interface.
    
    ```java
    public class MyClass implements java.io.Serializable {
        static final long serialVersionUID = 1L;
    }
    ```
    
- **Byte Streams**: Used to transmit serialized objects over the network or save them to files.
- **Object Streams**: Classes like `ObjectInputStream` and `ObjectOutputStream` are used to read/write objects from/to streams.

#### Customizing Serialization

- **Custom Serialization**: Override `defaultWriteObject()` and `defaultReadObject()` methods to customize serialization behavior.
- **Custom Read/Write Methods**: Implement `readObject()` and `writeObject()` methods for more control over serialization.

#### Mobile Code

- **Mobile Code**: Serialization can be used to send Java objects as "intelligent" messages between client and server.
    - The server can execute methods contained within the serialized object.

#### Parameter Passing

- **By Value**: A copy of the object is passed between client and server. Changes to one copy do not affect the other.
- **By Reference**: A reference to the remote object is passed. Both client and server see the same object in memory.

### Callbacks

#### Overview

- **Callback**: A mechanism where the server can invoke a method on the client, allowing asynchronous communication.
- **Implementation in RMI**:
    - Client defines a remote interface for a callback object.
    - Server records the client's callback object reference and invokes methods on it when necessary.

#### Advantages

- **Asynchronous Communication**: The client does not need to wait for the server to complete its task.
- **Reduced Polling**: Clients do not need to frequently poll the server for updates.

### RMI Activation

#### Overview

- **RMI Activation Service**: Allows remote objects to be created on demand, improving robustness and scalability.
- **Key Features**:
    - Automatic generation of remote objects triggered by requests.
    - Restarting remote objects if they are destroyed due to system failure.

#### Creating Activatable Remote Objects

- **Subclassing `Activatable`**: Remote object implementations should extend `java.rmi.activation.Activatable`.
- **Registration**: The remote object and its activation method must be registered with the RMI activation service (`rmid`).

#### Persistent Remote References

- **Persistent References**: References to activatable objects remain valid even if the object is not currently running or has been garbage collected.

#### Client Invocation

- **Normal Reference Acquisition**: Clients obtain remote references through the naming service (`rmiregistry`).
- **On-Demand Activation**: The activation service starts the remote object if it is not already running.
