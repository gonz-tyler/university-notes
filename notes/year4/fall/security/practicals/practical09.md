# Tutorial 09: Protocols

**Instructions:**

- **R** = Review question (look it up in notes)
- **E** = Easy (simple application)
- **M** = Moderate (takes some thought)
- **H** = Harder (takes a lot of thought)
- **O** = Open-ended

---

## Part 1: Protocol and Kerberos Questions

### Question 1 [R]

Write out in English the meaning of:
$$A \rightarrow B: \{A, K_{AB}\}_{K_B}$$
_(Note: Interpretation of OCR text `АВ: А. {{АЗКА, В}КВ` adjusted to standard notation based on context)_

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 2 [R]

Explain what a **nonce** is in security, what its main purpose is, and what type of attack it foils.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 3 [R]

What is a **replay attack**? Write out an explanation. Give an example.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 4 [R]

What is a **man-in-the-middle attack**? Write out an explanation. Give an example.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 5 [R]

What is a **reflection attack**? Write out an explanation. Give an example.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 6 [R]

What is the purpose of the **Needham-Schroeder protocol**?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 7 [R]

Here is the Needham-Schroeder protocol:

1.  $A \rightarrow S: A, B, N_{A}$
2.  $S \rightarrow A: \{N_A, B, K_{AB}, \{K_{AB}, A\}_{K_{BS}}\}_{K_{AS}}$
3.  $A \rightarrow B: \{K_{AB}, A\}_{K_{BS}}$
4.  $B \rightarrow A: \{N_{B}\}_{K_{AB}}$
5.  $A \rightarrow B: \{N_{B}-1\}_{K_{AB}}$

_(Note: Each key $K_{ij}$ is another name for the key shared between i and j)_

**(a)** Explain the roles of A, B, and S in this set-up. Why is encryption with $K_{AS}$ required in Message 2? 

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** What is $N_{A}$ in message 1? Why is it present in this protocol? What is the purpose of $N_{B}$?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** Suppose that the attacker has compromised $K_{AB}$. Explain how it could subsequently gain access to B using a replay attack.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 8 [R]

**(a)** What is the purpose of **Kerberos**?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** Are users completely trusted in the intended environment? Give examples.

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** What is the main reason why the trusted third party (key distribution center) is split into two parts in Kerberos? To which of the Kerberos requirements does this correspond?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 9 [R]

What do each of the **nonce**, the **lifespan**, and the **timestamp** do in the Kerberos given in lectures?

<details>
<summary>**Answer:**</summary>

>
> - **Nonce:**
> - **Lifespan:**
> - **Timestamp:**
</details>

---

### Question 10

In lectures, we discussed a form of man-in-the-middle attack in which a pair of attackers acted together to open a car door. This sub-type of attack is known as a **relay attack**.
Contactless smartcards are used these days to make payments in shops or at security barriers.

Outline how a pair of attackers could conduct a relay attack against a victim who has the card in their wallet and is not near a legitimate pay contactless card acceptor device (CAD). Indicate how this can work even with mutual authentication.

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 2: More Interesting Questions

### Question 1

Alice and Bob have invented the following protocol for sending a message securely from A to B. The protocol is based on the ideas of the one-time pad, but without a common, shared secret. Instead, for each message, both A and B invent a random nonce and execute the following protocol to send message $M$ from A to B:

1.  $A \rightarrow B: M_{1}$
2.  $B \rightarrow A: M_{2}$
3.  $A \rightarrow B: M_{3}$

Where:

- $M_{1} = M \oplus N_{A}$
- $M_{2} = M_{1} \oplus N_{B}$
- $M_{3} = M_{2} \oplus N_{A}$

Assume that an attacker is able to intercept messages.

**(a)** Show that B can recover M.

<details>
<summary>**Workings:**</summary>

>
</details>

**(b)** Is the system secure?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 2

Alice and Bob have a shared secret bit string $k$ and have decided to use it in the following protocol, which enables Alice to identify Bob as the party at the other end:

1.  Alice picks a random bit string with the same length as $k$, and sends it as a challenge to Bob.
2.  Bob responds with $r \oplus k$ (using the bitwise XOR).

Alice's and Bob's analysis of the protocol is this: The protocol does indeed provide identification, since Alice can check that the sender of message 2 knows $k$. It is also secure, since only random numbers are ever sent on the communication channel.

**(a)** How does Alice check that the sender of message 2 knows $k$?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** Do you agree with Alice and Bob about the security of their protocol? Explain your answer.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 3

In the notation we have used in lectures, we have used encryption as a constructor for messages. One of the ways this is used is to prove knowledge of a key, in order to prove identity.

Explain why a similar proof could also be achieved using **signatures** and **keyed hashes (MACs)**.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 4

The **ssh (secure shell)** remote login tool allows a user to connect from their local machine to a remote host. The tool can use an RSA or DSA signature instead of encryption for proof of identity. A private key is stored on the user's machine.

For simplicity, suppose that the name of the local machine is just the name of the user (Alice). The protocol works (roughly) as follows:

1.  **Alice $\rightarrow$ Host:** `Alice, LOGIN`
2.  **Host $\rightarrow$ Alice:** $N_{Host}$
3.  **Alice $\rightarrow$ Host:** $Sign_{Alice}(N_{Host})$

The `LOGIN` message here indicates that the initiating party wishes to log in.

**(a)** Is this mutual authentication? Who has proved their identity?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** What assumption is there about storage of secret data?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** Assume that some attacker has the ability to control a machine that can masquerade as the remote host (i.e., the attacker can trick the user to log in thinking it is connecting to the true host).

**i.** How could the attacker get Alice to sign arbitrary messages?

<details>
<summary>**Answer:**</summary>

>
</details>

**ii.** Why is it potentially dangerous for Alice to use the same key for signing messages in this entity authentication application, and for signing messages for message authentication (and non-repudiation) applications?

<details>
<summary>**Answer:**</summary>

>
</details>

**iii.** Explain how the attacker could perform a man-in-the-middle attack against this type of authentication.
<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 3: Bluetooth [C]

### Context

Bluetooth allows pairs of 'bonded' devices to communicate. The initial set-up is the **Bluetooth Pairing Protocol**. In legacy pairing (device with keyboards/screens):

1.  One device is Master, one is Slave. Master sends random value `IN_RAND`.
2.  Human types a PIN into both devices.
3.  An initialization key is generated using `IN_RAND` and the PIN.
4.  Peers generate a secret Link Key using the initialization key.
5.  In subsequent sessions, the Link Key is used for mutual authentication (Challenge-Response via MAC).

---

### Question 1

What is the secure channel in the initial pairing?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 2

Suppose that an adversary can listen to communications in the pairing and authentication protocols. Suppose also the adversary can recover the PIN somehow (say, by exhaustive search).
How does this lead to the protocol being insecure?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 3

Write out a mutual authentication challenge-response protocol, with both parties using a MAC.

- If you can, try to do this so that reflection attacks don't work.
- As a further challenge, explain how to include an exponential backoff so that repeatedly failed authentications take longer-and-longer (Bluetooth does this).

<details>
<summary>**Protocol Design:**</summary>

>
</details>
<details>
<summary>**Exponential Backoff Explanation:**</summary>

>
</details>

### Question 4

In this exercise, we study one potential weakness in the real Bluetooth Pairing Protocol. Assume a Bluetooth device A is setting up a pairing protocol with a new peer device B and B happens to be the first challenger (i.e., A authenticates itself to B first). Suppose this pairing protocol between A and B finally passes successfully.

**(a)** Assume that A uses a short PIN using only numbers. Why cannot we place 100% trust on the authenticity of B?
_Hint: Think brute force, exhaustive search just after A has sent its MAC to B._

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** What do you propose to fix the above problem?

<details>
<summary>**Answer:**</summary>

>
</details>
