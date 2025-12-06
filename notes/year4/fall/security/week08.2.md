# Week 08.2: Protocols and Key Management Revision Notes

---

## 1. Key Distribution and KDCs

A **Key Distribution Center (KDC)** is a trusted system designed to solve the problem of exchanging secret keys between users.

- **The Problem**: In symmetric cryptography, every pair of users needs a shared secret key. If there are $N$ users, this requires $\frac{N(N-1)}{2}$ keys, which becomes unmanageable as $N$ grows (the $N^2$ problem).
- **The KDC Solution**: Each user shares a single permanent secret key with the KDC. When two users (e.g., Alice and Bob) want to communicate, they contact the KDC, which generates a temporary **session key** for them to use just for that conversation.
- **Structure**: KDCs can be organized in different ways:
  - **Flat**: Multiple KDCs operate at the same level.
  - **Hierarchical**: KDCs are organized in a tree structure (Local $\rightarrow$ National $\rightarrow$ International).

---

## 2. Attacks on Protocols

### Man-In-The-Middle (MITM) Attack

This occurs when an attacker (Mallory) sits between two communicating parties (Alice and Bob) and deceives them.

- **The Attack**: Mallory intercepts Alice's public key as it's sent to Bob and replaces it with his own. He does the same for Bob's key sent to Alice. Now, Alice encrypts messages for "Bob" using Mallory's key. Mallory decrypts them, reads/modifies them, and re-encrypts them with Bob's real key. Neither Alice nor Bob realizes they aren't communicating securely.
- **Solution (Interlock Protocol)**: To defeat this, Alice and Bob send their encrypted messages in two halves. They only send the second half after receiving the first half from the other person. An attacker cannot decrypt or forge the first half without the key, and they cannot get the key without committing to a message first. _Note: This only works if the public keys themselves are authenticated._

### Replay Attack

An attacker copies a valid message (like an authentication response or a ticket) and sends it again later to impersonate a legitimate user or gain unauthorized access. Timestamps and nonces (random numbers used once) are common defenses.

### Reflection Attack

A special MITM attack on mutual authentication. The attacker tricks a system into answering its own challenge. For example, if Server A challenges Attacker E, E simply sends that same challenge back to Server A. If A answers it, E can use that answer to solve the original challenge.

---

## 3. Key Distribution Protocols

### Needham-Schroeder Protocol

A classic protocol for distributing a session key using a KDC.

1.  Alice sends a request to the KDC including a nonce ($R_A$).
2.  The KDC sends back a message encrypted with Alice's key. This message contains the session key ($K_{AB}$), Alice's nonce ($R_A$), and a "ticket" encrypted with Bob's key.
3.  Alice keeps the session key and forwards the ticket to Bob.
4.  Bob decrypts the ticket to get the session key.
5.  Alice and Bob exchange encrypted nonces to verify they both have the correct session key.

- **Weakness**: Vulnerable to **replay attacks** if an old session key is compromised. An attacker could replay an old ticket to Bob, tricking him into using an old, compromised key.

### Otway-Rees Protocol

Designed to fix the replay weakness of Needham-Schroeder.

- It uses a common session ID ($R$) and distinct nonces ($R_A, R_B$) for Alice and Bob.
- Alice and Bob exchange messages _before_ contacting the KDC.
- The KDC provides the session key to both parties in a single step (via Bob).
- Because the KDC's response includes the nonces generated specifically for _this_ session, it prevents replay attacks.

### Kerberos

A widely used, real-world authentication protocol based on Needham-Schroeder. It allows users to access network services securely without sending passwords over the network.

- **Components**:
  - **Authentication Server (AS)**: Verifies the user's login and issues a **Ticket Granting Ticket (TGT)**.
  - **Ticket Granting Server (TGS)**: Uses the TGT to issue **Service Tickets** for specific resources (e.g., a file server or printer).
- **Process**:
  1.  **Login**: The client authenticates to the AS and gets a TGT.
  2.  **Request Service**: The client presents the TGT to the TGS to request access to a specific service.
  3.  **Access**: The TGS issues a Service Ticket. The client presents this ticket to the Service Server to gain access.
- **Security**: Uses **timestamps** heavily to prevent replay attacks (requires synchronized clocks). Uses session keys for all communications.
