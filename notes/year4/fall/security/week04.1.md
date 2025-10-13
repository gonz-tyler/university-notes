# Week 04.1: Digital Signatures

---

## 1. Introduction to Signatures

Just like a handwritten signature on a paper document, a **digital signature** is a mechanism to verify the authenticity and integrity of a digital document or message.

### Properties of a Signature

A good signature, whether physical or digital, should provide several guarantees:

1.  **Authenticity**: It convinces the recipient that the message was created and sent by the claimed sender.
2.  **Integrity**: It ensures that the message has not been altered or tampered with after it was signed.
3.  **Non-repudiation**: It provides proof that the sender signed the message, preventing them from later denying it.
4.  **Unforgeable & Not Reusable**: The signature cannot be forged by someone else, nor can it be lifted from one document and attached to another.

---

## 2. How Digital Signatures Work

A digital signature is a mathematical scheme that uses **asymmetric cryptography** to bind a digital document to a specific identity. A digital signature scheme consists of three core algorithms.

### The Three Algorithms of a Signature Scheme

1.  **Key Generation Algorithm**:
    -   This algorithm generates a unique **public-private key pair**.
    -   The **private key** is kept secret by the signer and is used to create signatures.
    -   The **public key** is shared openly and is used by others to verify signatures.

2.  **Signing Algorithm**:
    -   **Input**: A message and the signer's **private key**.
    -   **Output**: A value called the **digital signature**.

3.  **Signature Verification Algorithm**:
    -   **Input**: The original message, the digital signature, and the signer's **public key**.
    -   **Output**: A `yes` or `no` result, confirming whether the signature is valid for that specific message and public key.

### The Role of Hashing in Digital Signatures

In practice, we don't sign the entire document. Instead, we sign a **hash** (or "message digest") of the document.

-   **Process**:
    1.  The **signer** creates a fixed-size hash of the original message (e.g., using SHA-256).
    2.  The signer then uses their **private key** to sign this hash.
    3.  The signature is sent along with the original message.
    4.  The **verifier** independently creates a hash of the received message.
    5.  The verifier then uses the signer's **public key** to decrypt the signature, revealing the original hash.
    6.  If the verifier's calculated hash matches the hash from the signature, the signature is valid.

-   **Why use hashing?**
    -   **Efficiency**: Hashing a large document and signing the small, fixed-size hash is much faster than signing the entire document with a computationally expensive asymmetric algorithm.
    -   **Security**: It prevents certain types of attacks and ensures the signature is tied to the exact content of the document.

---

## 3. RSA Signatures

The RSA algorithm can be used for digital signatures by reversing its encryption/decryption process.

* **Signing**: To sign a message `m`, the sender first computes its hash, `h(m)`. Then, they use their **private key `d`** to create the signature `S`:
    $$
    S = (h(m))^d \pmod{n}
    $$

* **Verification**: To verify the signature, the recipient uses the sender's **public key `(e, n)`**. The signature is considered valid if the following equation holds true:
    $$
    S^e \equiv h(m) \pmod{n}
    $$
    This works because $(h(m)^d)^e = h(m)^{de} \equiv h(m) \pmod{n}$, which is the fundamental property of RSA.

---

## 4. ElGamal Signatures

The ElGamal signature scheme is another popular algorithm, which is based on the difficulty of the **Discrete Logarithm Problem**. Unlike RSA, its signing and verification processes are not simple reversals of encryption.

* **Key Generation**: A public key `(p, g, y)` and a private key `x` are generated, where `p` is a large prime, `g` is a generator, and $y = g^x \pmod{p}$.

* **Signing**: To sign a message `m`, the signer performs two steps:
    1.  Choose a secret, random, single-use number `k`.
    2.  Compute two values, $s_1$ and $s_2$:
        -   $s_1 = g^k \pmod{p}$
        -   $s_2$ is found by solving the equation $m = (x \cdot s_1 + k \cdot s_2) \pmod{p-1}$
    3.  The signature is the pair **(s₁, s₂)**.

* **Verification**: The verifier checks if the following complex equation holds true. If it does, the signature is valid:
    $$
    y^{s_1}s_1^{s_2} \equiv g^m \pmod{p}
    $$

---

## 5. Attacks on Digital Signatures

The goal of an attacker is to **forge** a signature. There are different levels of success for an attacker:

* **Existential Forgery**: The attacker can create a valid signature for at least one message, even if the message is random and meaningless.
* **Selective Forgery**: The attacker can create a valid signature for a *specific message* of their choice.
* **Total Break**: The attacker discovers the signer's private key, allowing them to sign any message.

These attacks can be attempted with different levels of knowledge, from only having the public key (**key-only attack**) to being able to trick the legitimate signer into signing messages chosen by the attacker (**chosen-message attack**).
