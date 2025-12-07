# Tutorial 10: Network Security

**Instructions:**

- **[R]** = Review question (covered in lectures).
- **[C]** = Challenge question (may be harder than typical exam questions).
- **Note:** Use the space provided to write your answers or draw diagrams where requested.

---

## Part 1: TLS and Threats

### Question 1

Consider the following threats to security. Describe how each is (or is not) countered by a particular feature of TLS:

**(a) Brute-force cryptanalytic attack:** An exhaustive search of the key space for a conventional encryption algorithm.

<details>
<summary>**Answer:**</summary>

>
</details>

**(b) Known-plaintext dictionary attack:** Many messages will contain predictable plaintext (e.g., HTTP GET). An attacker encrypts known plaintexts with all possible keys to build a dictionary and looks up intercepted ciphertext.

<details>
<summary>**Answer:**</summary>

>
</details>

**(c) Replay attack:** Earlier TLS messages are replayed.

<details>
<summary>**Answer:**</summary>

>
</details>

**(d) Man-in-the-middle attack:** An attacker interposes during key exchange, acting as the client to the server, and as the server to the client.

<details>
<summary>**Answer:**</summary>

>
</details>

**(e) Password sniffing:** Passwords in HTTP or other application traffic are eavesdropped.

<details>
<summary>**Answer:**</summary>

>
</details>

**(f) IP spoofing:** Uses forged IP addresses to fool a host into accepting bogus data.

<details>
<summary>**Answer:**</summary>

>
</details>

**(g) IP Hijacking:** An active, authenticated connection between two hosts is disrupted, and the attacker takes the place of one of the hosts.

<details>
<summary>**Answer:**</summary>

>
</details>

**(h) SYN Flooding:** An attacker sends TCP SYN messages to request a connection but does not respond to the final message, clogging the TCP module.

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 2: Network Boundaries and Firewalls

### Question 2 [R]

Why do we not often need to panic that our internal network is compromised just because the web pages are defaced on the web server, or emails are stolen from the email server?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 3

Give examples of three different technologies that make defining the boundaries of modern corporate networks difficult. In each case, give an example of a situation in which data can flow in or out with little management oversight.

**1. Mobile computing devices**

<details>
<summary>**Example:**</summary>

>
</details>

**2. Removable media**

<details>
<summary>**Example:**</summary>

>
</details>

**3. Encrypted tunneling**

<details>
<summary>**Example:**</summary>

>
</details>

### Question 4

Consider rules of the following form for a stateless packet filtering firewall:

| Rule Name | Direction | Source Address  | Destination Address | Dest. Port | Action |
| :-------- | :-------- | :-------------- | :------------------ | :--------- | :----- |
| $r_{1}$   | Inbound   | 172.16.51.70    | 192.168.10.0        | 23         | Permit |
| $r_{2}$   | Inbound   | 139.133.231.186 | 192.168.10.0        | 23         | Deny   |

Suggest a simple way in which an attacker, operating from external address `139.133.231.185`, could be permitted to initiate a connection to destination port 23 on the target at internal IP address `192.168.10.0`.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 5

Continuing with the example from Question 4, suppose that it has been decided that any inbound packet to an internal host from source port 23 on an external host will only be allowed if it follows an outbound packet between the same ports on the same two hosts.

What technology can be used to perform such control, and how does it do this?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 6 [R]

Some firewalls do **deep-packet inspection** where they look at the data carried in the body of TCP segments (protocol data units at the transport layer for the TCP protocol).

- Can this be done by a packet filter?
- Can it be done by an application filter?

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 3: FTP Security [C]

### Question 7 (Active FTP)

**Context:** FTP uses two pairs of ports.

- **Command Connection:** Client (port X, e.g., 1026) $\to$ Server (port 21).
- **Data Connection (Active):** Server (port 20) $\to$ Client (port Y, e.g., 1027).

**(a)** Draw a diagram for the messages involved in setting up the FTP connection. (For the 3-way connection messages, just label them SYN, SYN-ACK, ACK appropriately).

<details>
<summary>**Diagram Description/ASCII Art:**</summary>

>
</details>

**(b)** Add to your diagram messages for copying data back to the client.

<details>
<summary>**Addition:**</summary>

>
</details>

**(c)** Suppose the server is inside a firewall. If we want to support clients connecting from outside, what does this mean for the rules of a packet filter?
_Hint: Recall that handshakes usually start with an unpredictable high-numbered port on the client._

<details>
<summary>**Answer:**</summary>

>
</details>

**(d)** Suppose that we have a (stateless) packet filter that allows the packets in both directions on port 21. Suppose the client is inside the firewall.

- Why is it still not possible to formulate a policy that distinguishes between a legitimate outbound FTP client connection, and others that might use 20 on the server and 1027 on the client?
- Why is this still a problem even for stateful packet filters that can only dynamically generate rules regarding pairs of ports that have already been seen?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 8 (Passive FTP)

**Context:** Passive FTP solves some firewall problems.

- Client initiates command connection (21 to 1026).
- Client requests Passive mode.
- Server replies with the port it will listen on (e.g., 2024).
- Client initiates the data connection (1027 to 2024).

**(a)** Draw a picture of this sequence (don't worry about the internals of the 3-way handshakes this time).

<details>
<summary>**Diagram Description/ASCII Art:**</summary>

>
</details>

**(b)** How does this solve the problem discussed in Question 7d?

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 4: Firewall Products and Architecture

### Question 9

**Context:** Read the documentation for a modern firewall product (e.g., SonicWall or Dell examples). In the following questions, focus on fundamental methods rather than product-specific details.

**(a)** Name, and explain in at most two short sentences, five different functionalities supported in this product that have been discussed in the course.

<details>
<summary>**Answer:**</summary>

> **1.**
>
> **2.**
>
> **3.**
>
> **4.**
>
> **5.**
> </details>

**(b)** How are known (outbound or inbound) files (for example, a confidential document that should not be leaked out), or other data packets, detected?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** As well as just dropping all packets for a particular connection, or allowing them all through, what other functionality does this product have to control connections?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 10

**Context:** Refer to the "Architecture using multiple interior routers" diagram (Figure 2), which shows a Firewall, Exterior Router, Perimeter Network (with Bastion Host), Interior Routers, and Internal Network. The diagram includes a warning: _"We recommend against this configuration."_

What problems do you think might arise with the perimeter network configuration shown? (Just one of the problems relates to the route that might be taken by packets between interior network nodes).

<details>
<summary>**Answer:**</summary>

>
</details>
