# Week 2.2: Interprocess Communication (Sockets)
## Notes
---

### Communication Types
1. **UDP (User Datagram Protocol)**: Connectionless, faster but unreliable.
2. **TCP (Transmission Control Protocol)**: Connection-oriented, reliable.

### Characteristics of Interprocess Communication
- **Synchronous vs. Asynchronous**: Blocking vs. non-blocking communication.
- **Message Destinations**: Messages sent to specific ports.
- **Reliability**: Ensures data integrity and delivery.

### Sockets
- Endpoints for communication.
- Java provides `Socket` and `ServerSocket` classes for TCP communication.
- UDP uses `DatagramSocket` and `DatagramPacket`.
- Sockets facilitate direct interprocess communication between distributed nodes.

### Example: TCP Server
```java
ServerSocket serverSocket = new ServerSocket(50000);
Socket socket = serverSocket.accept();
ObjectInputStream inputStream = new ObjectInputStream(socket.getInputStream());
ObjectOutputStream outputStream = new ObjectOutputStream(socket.getOutputStream());
```

### Example: TCP Client
```java
Socket socket = new Socket("localhost", 50000);
ObjectOutputStream outputStream = new ObjectOutputStream(socket.getOutputStream());
ObjectInputStream inputStream = new ObjectInputStream(socket.getInputStream());
```

### Advantages of TCP over UDP
- Reliable data transmission.
- Error detection and correction.
- Ordered and complete message delivery.

### Summary
- Serialization enables data transmission in distributed systems.
- RMI supports remote object interactions.
- Sockets facilitate interprocess communication.
- TCP ensures reliability, while UDP prioritizes speed.
