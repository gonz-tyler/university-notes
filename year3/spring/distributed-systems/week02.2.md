# Week 2.2: Interprocess Communication - Sockets
## Notes
---

### Introduction

#### Overview

- **Interprocess Communication (IPC)**: Communication between processes, typically using client-server or group communication models.
- **Middleware**: Provides higher-level communication abstractions like RPC and RMI, built on top of lower-level protocols like UDP and TCP.

#### Communication Patterns

- **Client-Server Communication**: Request-reply communication, used in RPC and RMI.
- **Group Communication**: Sending the same message to multiple processes.

### UDP and TCP

#### UDP (User Datagram Protocol)

- **Message Passing**: Simplest form of IPC, where messages (datagrams) are sent independently.
- **Characteristics**:
    - No guarantee of order preservation.
    - Possible message loss and duplication.
- **Java API**: `DatagramPacket` class is used to create and manage datagrams.

#### TCP (Transmission Control Protocol)

- **Stream Communication**: Provides a reliable, two-way stream of data between processes.
- **Characteristics**:
    - Messages can be of any size.
    - Lost messages can be resent.
    - Flow control matches the speed of data transmission.
- **Java API**: `ServerSocket` and `Socket` classes are used for TCP communication.

### Sockets

#### Overview

- **Socket**: An endpoint for communication between two processes over a network.
- **Binding**: Sockets must be bound to a port number and an internet address to send/receive messages.
- **Transport Protocols**: Each socket uses either TCP or UDP.

#### Characteristics of IPC

- **Synchronous vs Asynchronous Communication**:
    - **Synchronous**: Both send and receive operations are blocking.
    - **Asynchronous**: Send operation is non-blocking, and receive can be blocking or non-blocking.
- **Message Destinations**: Messages are sent to a local port, specified by a port number.
- **Reliability**: Reliable communication ensures message delivery, integrity, and no duplication.

### TCP Stream Communication

#### Java API

- **ServerSocket**: Used by the server to listen for client connection requests.
    - `accept()` method blocks until a connection request arrives.
- **Socket**: Used by both client and server for communication.
    - Provides `getInputStream()` and `getOutputStream()` methods for data exchange.

#### Issues in Stream Communication

- **Matching Data Items**: The reader must read data in the same order as the writer writes it.
- **Blocking**: Data is kept in a queue at the destination socket, and the receiver process blocks until data is available.
- **Threads**: Servers typically create a new thread for each client connection.

### Request-Reply Example

#### Client-Server Communication

- **Server**: Opens a server socket on a specific port and listens for client connections.
- **Client**: Connects to the server using the server's IP address and port number.
- **Data Exchange**: The client sends a message to the server, and the server replies with a response.

#### Example Code

```java
// Client Code
Socket socket = new Socket("localhost", 50000);
ObjectOutputStream outputStreamToServer = new ObjectOutputStream(socket.getOutputStream());
ObjectInputStream inputStreamFromServer = new ObjectInputStream(socket.getInputStream());

outputStreamToServer.writeObject("Message To Server");
String result = (String) inputStreamFromServer.readObject();
System.out.println("Received from server: " + result);
```

### Remarks

- **Closed Sockets**: Once a socket is closed, its input and output streams can no longer be used.
- **EOFException**: Occurs when attempting to read from an empty queue after the socket is closed.
- **Threads**: Should be used to handle blocking operations to avoid freezing the application.
