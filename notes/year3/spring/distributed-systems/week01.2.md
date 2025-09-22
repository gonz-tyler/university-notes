# Week 1.2: Remote Method Invocation (RMI)
## Notes
---
### What is RMI?
- A mechanism allowing objects in different JVMs to communicate.
- Enables method calls on remote objects as if they were local.

### Components of an RMI Application
1. **Server**
   - Creates remote objects.
   - Registers them in the RMI registry.
   - Waits for client requests.
2. **Client**
   - Looks up remote objects.
   - Invokes methods on remote objects.

### Remote Object Model
- **Remote Object Reference**: Needed to invoke remote methods.
- **Remote Interface**: Defines methods that can be called remotely.

```java
public interface ServiceInterface extends java.rmi.Remote {
    public String doSomething(String s) throws RemoteException;
}
```

### RMI Execution Flow
1. **Server registers remote object**
2. **Client looks up remote object**
3. **Client invokes remote method**
4. **Stub on client forwards request to server**
5. **Server processes request and returns response**

### RMI Middleware
- **Stub (Proxy)**: Represents the remote object on the client side.
- **Skeleton (Dispatcher)**: On the server side, receives method calls and forwards them to the actual object.

### Naming and Lookup
- The `java.rmi.Naming` class is used to register and lookup objects.
- Example of lookup:
```java
String url = "rmi://host:port/objectName";
SomeRemoteInterface obj = (SomeRemoteInterface) Naming.lookup(url);
```

### Security in RMI
- Java Security Manager enforces security policies.
- Example:
```java
System.setProperty("java.security.policy", "rmishout.policy");
System.setSecurityManager(new SecurityManager());
```

### Dynamic Class Loading in RMI
- Allows the transmission of object definitions dynamically.
- Uses `java.io.ObjectOutputStream` and `java.io.ObjectInputStream` for serialization.
- Benefits:
  - New object types can be introduced at runtime.
  - Objects can be downloaded from a remote server.

### Summary
- RMI allows remote objects to communicate seamlessly.
- Uses stubs and skeletons to hide complexities.
- Security management is crucial for protecting applications.
- Dynamic class loading enhances flexibility in distributed applications.
