# Week 04.2: Zero-Knowledge Proofs

---

## 1. Protocols and Interactive Proofs

A **protocol** is a series of steps involving two or more parties designed to accomplish a task. A **cryptographic protocol** is one that uses cryptography to achieve its goals, such as securely exchanging a key.

### Interactive Proofs

An **interactive proof** is a type of protocol where one party, the **Prover**, aims to convince another party, the **Verifier**, that a certain statement is true.

-   The process involves a series of **challenges** from the Verifier and **responses** from the Prover.
-   The Prover is trying to prove they possess some knowledge (e.g., a secret password or key) without simply handing it over.
-   The Verifier's goal is to determine if the Prover is telling the truth.

A valid interactive proof must have two key properties:

1.  **Completeness**: If the Prover's statement is **true** and both parties are honest, the Verifier will always be convinced (i.e., they will accept the proof).
2.  **Soundness**: If the Prover's statement is **false**, a cheating Prover can only trick an honest Verifier into accepting the proof with a very small probability.

---

## 2. Zero-Knowledge Proofs (ZKPs) 🤫

A **Zero-Knowledge Proof (ZKP)** is an interactive proof with an additional, powerful property:

> The Prover convinces the Verifier that the statement is true **without revealing any information whatsoever**, apart from the fact that the statement is true.

The Verifier learns nothing about the underlying secret itself. This allows you to prove you know a password without ever sending the password over the network.

### The Alibaba's Cave Analogy

This famous story illustrates the concept of a ZKP intuitively:

-   **The Setup**: There is a circular cave with a single entrance and a magic door at the back connecting the two paths. Peggy (the Prover) wants to prove to Victor (the Verifier) that she knows the magic words to open the door, but she doesn't want to reveal the words.

-   **The Protocol**:
    1.  Peggy enters the cave and walks down one of the two paths (left or right) at random.
    2.  Victor, who didn't see which path she took, walks to the entrance and randomly shouts for her to come out of either the "left" or "right" path.
    3.  Peggy complies. If she is on the same path Victor called, she just walks out. If she is on the other path, she uses the magic words to open the door and cross over to exit from the correct path.
    4.  Victor sees her emerge from the path he called.

-   **The Proof**:
    -   A single trial is not convincing. If Peggy *didn't* know the magic words, she could have just been lucky and chosen the correct path by chance (a 50% probability).
    -   However, if they repeat the protocol many times (e.g., 20 times), the probability of her successfully guessing the correct path every single time becomes infinitesimally small ($1/2^{20}$).
    -   After many successful rounds, Victor is statistically convinced that Peggy must know the secret. Crucially, he never sees her use the magic words and learns nothing about them.

---

## 3. Mathematical Background for FFS

The Feige-Fiat-Shamir protocol is based on the **Quadratic Residuosity Problem**, which is a one-way function.

* **Quadratic Residue**: An integer `v` is a quadratic residue modulo `n` if there exists an `x` such that $x^2 \equiv v \pmod{n}$. This `x` is a **square root** of `v` modulo `n`.
* **The Trapdoor Function**:
    -   **Easy Direction**: Given `x` and `n`, it's easy to compute $x^2 \pmod{n}$.
    -   **Hard Direction**: Given `v` and `n`, it is computationally very difficult to find the square root `x` **unless** you know the prime factors of `n`.
    -   Knowing the prime factors (`p` and `q` such that $n = p \times q$) is the "trapdoor" that makes finding the square root easy.

---

## 4. The Feige-Fiat-Shamir (FFS) Protocol

The FFS protocol is a practical ZKP scheme used for identification. It allows Peggy (Prover) to prove her identity to Victor (Verifier) by demonstrating she knows a secret without revealing it.

### Simplified FFS Protocol

This version demonstrates the core idea with a single secret.

* **Setup**:
    1.  A trusted party chooses two large primes `p` and `q` and computes the public modulus $n = p \times q$.
    2.  A public value `v` is chosen, which is a quadratic residue mod `n`.
    3.  The secret `s` is computed as $s = \sqrt{v^{-1}} \pmod{n}$. This is hard without knowing `p` and `q`.
    4.  Peggy (Prover) is given the secret `s`. Victor (Verifier) is given the public value `v`.

* **The Protocol (one round)**:
    1.  **Commitment**: Peggy chooses a random number `r`, computes $x = r^2 \pmod{n}$, and sends `x` to Victor.
    2.  **Challenge**: Victor sends a random challenge bit `b` (either 0 or 1) to Peggy.
    3.  **Response**: Peggy sends back a value `y` based on the challenge:
        -   If `b = 0`, Peggy sends $y = r$.
        -   If `b = 1`, Peggy sends $y = r \times s \pmod{n}$.
    4.  **Verification**: Victor checks Peggy's response:
        -   If `b = 0`, Victor verifies that $y^2 \equiv x \pmod{n}$. This proves Peggy knows the square root of `x` (which is `r`).
        -   If `b = 1`, Victor verifies that $y^2 \times v \equiv x \pmod{n}$. This proves Peggy knows the square root of $v^{-1}$ (her secret `s`), because $(r \times s)^2 \times v = r^2 \times s^2 \times v = r^2 \times v^{-1} \times v = r^2 = x$.

* **Security**: A cheating Prover would have to guess the challenge `b` in advance. They have a 50% chance of succeeding in a single round. After `t` rounds, their chance of fooling the verifier is only $(1/2)^t$. The full FFS protocol extends this to use multiple secrets ($s_1, \dots, s_k$) and a multi-bit challenge to make it more efficient and secure.
