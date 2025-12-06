# Week 09.2: Network Security II Revision Notes

---

## 1. Transport Layer Security: SSL/TLS

TLS (Transport Layer Security), the successor to SSL (Secure Sockets Layer), secures connections between applications (e.g., a web browser and a server). It sits between the Application Layer and the Transport Layer (TCP).

### Purpose

- **Confidentiality**: Encrypts data to prevent eavesdropping.
- **Integrity**: Ensures data hasn't been altered during transit.
- **Authentication**: Verifies the identity of the server (and optionally the client) using digital certificates.

### TLS Protocol Stack

TLS consists of two main layers:

1.  **Handshake Protocol**: Sets up the secure session.
    - Negotiates the cipher suite (algorithms for encryption, hashing, key exchange).
    - Authenticates the server (via certificate).
    - Establishes a shared secret (master secret) used to generate session keys.
2.  **Record Protocol**: Uses the keys established in the handshake to secure the actual data.
    - Fragments application data into manageable blocks.
    - Compresses the data (though often disabled due to vulnerabilities).
    - Computes a MAC (Message Authentication Code) for integrity.
    - Encrypts the data + MAC for confidentiality.
    - Appends a header and transmits the record via TCP.

### Sessions vs. Connections

- **Session**: A long-lasting association created by the handshake. It defines the security parameters (keys, algorithms).
- **Connection**: A transient peer-to-peer link. Multiple connections can share the same session state, avoiding the expensive handshake process for every new request.

---

## 2. SSH: Secure Shell

SSH is an application-layer protocol for secure remote login and command execution.

- **Functionality**: Replaces insecure protocols like Telnet and FTP. It provides a secure tunnel for:
  - Remote command execution.
  - Secure file transfer (scp, sftp).
  - Port forwarding (tunneling other protocols like HTTP or SMTP through SSH).
- **Security Mechanisms**:
  - **Confidentiality**: Symmetric encryption (e.g., AES).
  - **Integrity**: Hashing (MACs).
  - **Authentication**: Users authenticate via password or public-key cryptography.

---

## 3. Firewalls

A firewall is a network security system that monitors and controls incoming and outgoing network traffic based on predetermined security rules. It acts as a barrier between a trusted internal network and an untrusted external network (like the Internet).

### Firewall Policies

- **Default Allow (Permissive)**: Everything is allowed unless explicitly denied. Easier to use but less secure (if you forget to block a threat, you are vulnerable).
- **Default Deny (Restrictive)**: Everything is blocked unless explicitly allowed. More secure but harder to manage (can block legitimate traffic).

### Types of Firewalls

1.  **Packet Filtering Router**: Operates at the network layer. Inspects packet headers (IP address, port number, protocol) and blocks/allows based on rules. Fast but has low context awareness (doesn't understand application data).
2.  **Application-Level Gateway (Proxy)**: Acts as an intermediary for specific applications (e.g., Telnet, FTP). It understands the application protocol and can filter specific commands. More secure but slower due to extra processing.
3.  **Circuit-Level Gateway**: Sets up two separate TCP connections (one to the outside, one to the inside) and relays data between them without inspecting the payload.

### Modern Concepts

- **Zero Trust Architecture**: Assumes no user or device is trusted by default, even if inside the network perimeter. Requires continuous verification.
- **DMZ (Demilitarized Zone)**: A sub-network that exposes external-facing services (like web servers) to the internet while keeping the internal network isolated behind another firewall.

---

## 4. Intrusion Detection Systems (IDS)

An IDS monitors network or system activities for malicious acts or policy violations. Unlike a firewall (which blocks), an IDS primarily **detects and alerts**.

### Detection Methods

1.  **Misuse (Signature) Detection**: Looks for known patterns of attack (signatures). Effective for known threats but fails against new, unknown attacks (zero-days).
2.  **Anomaly Detection**: Establishes a baseline of "normal" behavior and flags deviations. Can detect new attacks but has a higher rate of false positives.

### Deployment Types

- **NIDS (Network-based IDS)**: Monitors network traffic (packets) for suspicious activity.
- **HIDS (Host-based IDS)**: Monitors a single host (logs, file integrity) for suspicious activity.

### Intrusion Prevention Systems (IPS)

An evolution of IDS that not only detects threats but **actively blocks** them (e.g., dropping packets, resetting connections).

### Honeypots

Decoy systems designed to lure attackers. They contain no real valuable data, so any interaction with them is suspicious. They are used to study attacker behavior and gather intelligence.
