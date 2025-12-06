# Week 09.1: Network Security I Revision Notes

---

## 1. Introduction: Networks and Threats

Computer networks form the backbone of distributed systems, but their open nature introduces significant security risks.

### Network Protocol Layers

Networks use a layered model (like TCP/IP) to organize communication.

- **Application Layer**: (e.g., HTTP, FTP, SSH) Where user applications operate.
- **Transport Layer**: (e.g., TCP, UDP) Handles end-to-end communication and data reliability.
- **Internet (Network) Layer**: (e.g., IPv4, IPv6, IPsec) Handles routing and addressing of packets.
- **Link Layer**: (e.g., Ethernet, Wi-Fi) Handles physical transmission of data frames.

### Types of Attackers

- **Passive Attackers**: Focus on **interception** (sniffing, eavesdropping) and **traffic analysis** (inferring patterns, who is talking to whom). They listen but don't alter data.
- **Active Attackers**: Focus on **modification** (altering messages), **fabrication** (spoofing identities, inserting messages), and **interruption** (Denial of Service - DoS).

### Secure Tunnels and VPNs

- **Secure Tunnel**: A logical connection using cryptography to secure data between two endpoints over an insecure network.
- **VPN (Virtual Private Network)**: Uses tunneling protocols (like IPsec or SSL/TLS) to create a private network across a public one (like the Internet), connecting remote users or sites securely.

---

## 2. TCP/IP Basics and Vulnerabilities

The TCP/IP suite is the foundation of the internet, but it wasn't designed with security as a primary focus.

### TCP (Transmission Control Protocol)

- **Function**: Provides reliable, connection-oriented communication. It breaks data into packets and reassembles them at the destination.
- **The Handshake**: A 3-way handshake establishes a connection:
  1.  Client sends `SYN` (with a random sequence number $SN_C$).
  2.  Server sends `SYN/ACK` (with its own $SN_S$ and acknowledges $SN_C$).
  3.  Client sends `ACK`.
- **Vulnerability: Connection Spoofing**: If initial sequence numbers are predictable, an attacker can forge a connection request (spoofing a trusted IP) and blindly complete the handshake without seeing the server's response. This allows them to execute commands as a trusted user.

### IP (Internet Protocol)

- **Function**: Handles addressing and routing packets across networks.
- **Vulnerability: Packet Sniffing**: IP packets are typically sent in cleartext. A promiscuous network card can read all traffic on the local network (passwords, emails, etc.).
- **Vulnerability: Source Spoofing**: There is no built-in authentication for the source IP address. An attacker can easily forge the source IP in a packet header to hide their identity or impersonate someone else.

### Routing Vulnerabilities

- **ARP Spoofing**: Attacker sends fake ARP messages to link their MAC address with a legitimate IP (like the gateway), intercepting local traffic.
- **BGP/OSPF Attacks**: Attackers can advertise false routes, causing internet traffic to be misdirected through compromised systems for interception or DoS.

---

## 3. IPsec (Internet Protocol Security)

IPsec is a suite of protocols designed to secure IP communications by authenticating and encrypting each IP packet. It operates at the **Internet Layer**, meaning it can transparently secure any upper-layer application (web, email, etc.) without requiring changes to the software.

### Two Main Protocols

1.  **Authentication Header (AH)**:
    - Provides **integrity** and **authentication**.
    - Protects against replay attacks.
    - **Does NOT** provide confidentiality (data is not encrypted).
    - It authenticates the payload and the static parts of the IP header.
2.  **Encapsulating Security Payload (ESP)**:
    - Provides **confidentiality** (encryption).
    - Can also provide **integrity** and **authentication**.
    - Encrypts the payload and optionally provides a digital signature for verification.

### Two Modes of Operation

1.  **Transport Mode**:
    - Only the **payload** (data from transport layer) is encrypted/authenticated.
    - The original IP header remains visible.
    - Used for **end-to-end** communication between two specific hosts. Both hosts must support IPsec.
2.  **Tunnel Mode**:
    - The **entire original IP packet** (header + payload) is encrypted and encapsulated inside a _new_ IP packet.
    - Used for **gateway-to-gateway** communication (e.g., connecting two corporate offices via VPN). The end hosts don't need to know about IPsec; the routers handle it.
