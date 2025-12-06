# Week 03.2: Asymmetric Cryptography II Revision Notes

---

## 1. Asymmetric Cryptography Recap

- **Symmetric vs. Asymmetric**:
  - **Symmetric**: Both parties share the **same** secret key. The main challenge is securely distributing this key.
  - **Asymmetric**: Uses a pair of keys: a **public key** for encryption/verification and a **private key** for decryption/signing.
- **Key Distribution**: A major advantage of asymmetric cryptography is facilitating key distribution. It allows two parties to establish a shared secret over an insecure channel without prior contact.

---

## 2. Mathematical Background

### The Discrete Logarithm Problem (DLP)

A core "hard problem" used in asymmetric cryptography (unlike RSA which uses factorization).

- **Modular Exponentiation**: Calculating $y = g^x \pmod p$ is easy.
- **Discrete Logarithm**: Given $y, g, p$, calculating $x$ is computationally **hard**. This one-way function property is the basis for Diffie-Hellman and ElGamal.

### Order and Generators

- **Order**: The smallest positive integer $r$ such that $m^r \equiv 1 \pmod n$.
- **Generator**: An element $g$ is a generator of a set $\mathbb{Z}_n^*$ if taking powers of $g$ produces every element in that set. In Diffie-Hellman, we use a generator $g$ for the group $\mathbb{Z}_p^*$.

---

## 3. Diffie-Hellman Key Exchange (DH)

A protocol that allows two parties (Alice and Bob) to agree on a shared secret key over an insecure channel.

### The Protocol (2 Parties)

1.  **Agreement**: Alice and Bob publicly agree on a large prime $n$ and a generator $g$.
2.  **Private Choices**:
    - Alice picks a random private integer $x$.
    - Bob picks a random private integer $y$.
3.  **Public Exchange**:
    - Alice computes $X = g^x \pmod n$ and sends it to Bob.
    - Bob computes $Y = g^y \pmod n$ and sends it to Alice.
4.  **Shared Secret**:
    - Alice computes $k = Y^x \pmod n = (g^y)^x = g^{xy} \pmod n$.
    - Bob computes $k = X^y \pmod n = (g^x)^y = g^{xy} \pmod n$.
    - Both now share the secret key $k = g^{xy} \pmod n$.

### Vulnerability: Man-in-the-Middle (MITM)

Diffie-Hellman does **not** authenticate the participants.

- **Attack**: Mallory intercepts Alice's public value $X$ and sends her own value $X'$ to Bob. She intercepts Bob's $Y$ and sends $Y'$ to Alice.
- **Result**: Alice thinks she shares a key with Bob, but she shares one with Mallory. Bob also shares a different key with Mallory. Mallory can now decrypt, read, modify, and re-encrypt all messages between them.

---

## 4. ElGamal Cryptosystem

An asymmetric encryption and signature algorithm based on Diffie-Hellman.

### Key Generation

1.  Choose a large prime $p$ and a generator $g$.
2.  Choose a private key $x$.
3.  Compute public key component $y = g^x \pmod p$.
4.  **Public Key**: $(p, g, y)$.
5.  **Private Key**: $x$.

### Encryption

To encrypt a message $M$ for Bob (using Bob's public key):

1.  Choose a random ephemeral (temporary) secret $k$.
2.  Compute $c_1 = g^k \pmod p$.
3.  Compute $c_2 = M \cdot y^k \pmod p$.
4.  **Ciphertext**: The pair $(c_1, c_2)$. Note that the ciphertext is twice the size of the plaintext.

### Decryption

To decrypt ciphertext $(c_1, c_2)$ (using Bob's private key $x$):

1.  Compute the shared secret $s = c_1^x \pmod p$.
2.  Compute $M = c_2 \cdot s^{-1} \pmod p$.
    - This works because $c_2 \cdot s^{-1} = (M \cdot y^k) \cdot (g^{kx})^{-1} = M \cdot g^{xk} \cdot g^{-xk} = M$.

### Digital Signatures with ElGamal

ElGamal can also be used for signing.

1.  **Sign**: The signer uses their private key $x$ and a random $k$ to generate a signature pair $(s_1, s_2)$ for message $M$.
2.  **Verify**: The verifier uses the signer's public key $(p, g, y)$ to check if $y^{s_1} s_1^{s_2} \equiv g^M \pmod p$.
