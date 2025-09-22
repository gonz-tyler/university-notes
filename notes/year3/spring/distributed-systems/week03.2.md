# Week 3.2: Interprocess Communication - More Sockets
## Notes
---

### Unicast vs Multicast Communication

- **Unicast**: Data is sent from one process to another single process.
- **Multicast**: Data is sent from one process to multiple processes simultaneously.

### Types of Sockets

- **UDP (User Datagram Protocol)**:
    - Connectionless communication.
    - Datagrams are sent independently and may arrive out of order.
    - Applications: Live streaming, online games, video calls.
- **TCP (Transmission Control Protocol)**:
    - Connection-oriented communication.
    - Data is guaranteed to arrive in the same order as sent.
    - Applications: Web browsing, email, file transfer.

### Datagram Sockets (UDP)

- **Java API**:
    - `DatagramSocket`: Used for sending and receiving datagrams.
    - `DatagramPacket`: Represents the data packet being sent or received.
- **Sender**:
    - Creates a `DatagramSocket` and binds it to a port.
    - Encodes data into a byte array and creates a `DatagramPacket` with the destination address.
    - Sends the packet using the `send` method.
- **Receiver**:
    - Creates a `DatagramSocket` and binds it to a specific port.
    - Creates a `DatagramPacket` to receive data.
    - Calls the `receive` method to wait for incoming datagrams.

### Multicast Sockets

- **Multicast Communication**: Sends messages from one process to multiple processes concurrently.
- **Java API**:
    - `MulticastSocket`: Extends `DatagramSocket` to support multicast communication.
    - Processes can join or leave multicast groups using `joinGroup` and `leaveGroup`.
- **Multicast Group**: Identified by a class D IP address (224.0.0.0 to 239.255.255.255) and a port number.
- **Example**:
    - A multicast receiver joins a group and waits for messages.
    - A multicast sender sends messages to the group, which are received by all members.

### Stream Sockets (TCP)

- **Stream Communication**: Data is transferred as a continuous stream between a client and server.
- **Java API**:
    - `ServerSocket`: Used by the server to listen for client connections.
    - `Socket`: Used by both client and server for communication.
- **Server**:
    - Creates a `ServerSocket` and waits for client connections using `accept`.
    - Once a connection is accepted, a `Socket` is created for data exchange.
- **Client**:
    - Creates a `Socket` to connect to the server.
    - Uses input and output streams to send and receive data.

### Sending User-Defined Objects

- **Serializable Objects**: Objects can be sent over sockets if they implement the `Serializable` interface.
- **Example**:
    - A client sends an `EmployeeData` object to the server.
    - The server receives the object and prints its fields.
