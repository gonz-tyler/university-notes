# Week 03.1: Asymmetric Cryptography I Revision Notes

---

## 1. Asymmetric Cryptography Overview

### Key Differences

- **Symmetric Cryptography**: Communicating parties share the **same** secret key for both encryption and decryption.
- **Asymmetric Cryptography**: Uses a pair of **different but related keys**: a public key (v) and a private key (s).

### Trapdoor Functions

The core concept behind public-key cryptography is the **trapdoor function**.

- It is a function that is easy to compute in one direction (A $\rightarrow$ B) but difficult to reverse (B $\rightarrow$ A) without special information (the "trapdoor" or secret).
- **Examples**:
  - **Factoring**: Easy to multiply two large primes $p$ and $q$ to get $n$. Hard to factor $n$ back into $p$ and $q$.
  - **Discrete Logarithm**: Easy to compute $y = x^k \pmod n$. Hard to find $k$ given $y, x, n$.

### Two Main Uses

1.  **Confidentiality (Encryption)**:

    - Encrypt with the recipient's **public key**.
    - Decrypt with the recipient's **private key**.
    - Ideally used for small messages, like exchanging a symmetric session key.
    - Requirement: $D(s, E(v, m)) = m$.

2.  **Authentication/Integrity (Digital Signatures)**:
    - Sign (encrypt) with the sender's **private key**.
    - Verify (decrypt) with the sender's **public key**.
    - Requirement: $D(v, E(s, m)) = m$.

---

## 2. The RSA Algorithm

### History

- Described publicly by Rivest, Shamir, and Adleman (MIT) in 1978.
- Independently discovered earlier by Clifford Cocks (GCHQ) in 1973, but kept secret.

### Key Generation Steps

1.  **Choose Primes**: Select two large, distinct prime numbers, $p$ and $q$.
2.  **Compute Modulus**: Calculate $n = p \times q$. This $n$ is public.
3.  **Compute Totient**: Calculate Euler's totient function, $\phi(n) = (p-1) \times (q-1)$.
4.  **Choose Encryption Key**: Select an integer $e$ such that $1 < e < \phi(n)$ and $gcd(e, \phi(n)) = 1$ (i.e., $e$ and $\phi(n)$ are relatively prime).
5.  **Compute Decryption Key**: Calculate $d$ such that $e \cdot d \equiv 1 \pmod{\phi(n)}$. This means $d$ is the modular multiplicative inverse of $e$ modulo $\phi(n)$.

**Keys**:

- **Public Key**: $(e, n)$
- **Private Key**: $(d)$

### Encryption and Decryption

- **Encryption**: To encrypt a message $m$ (where $m < n$), compute ciphertext $c = m^e \pmod n$.
- **Decryption**: To decrypt ciphertext $c$, compute plaintext $m = c^d \pmod n$.
- **Why it works**: Based on Fermat's Little Theorem, $m^{ed} \equiv m \pmod n$.

---

## 3. Mathematical Background

### Modular Arithmetic

- **Congruence**: $a \equiv b \pmod n$ means $n$ divides $(a - b)$. Essentially, $a$ and $b$ have the same remainder when divided by $n$.
- **Properties**: Commutative, associative, and distributive. You can perform addition, subtraction, and multiplication within the modulus at any step.

### Prime Numbers

- Integers greater than 1 with only two factors: 1 and themselves.

### Greatest Common Divisor (GCD)

- $gcd(a, b)$ is the largest number that divides both $a$ and $b$.
- If $gcd(a, b) = 1$, then $a$ and $b$ are **relatively prime**.
- **Euclid's Algorithm**: An efficient way to find the GCD. Repeatedly apply $gcd(a, b) = gcd(b, a \pmod b)$ until $b=0$.

### Extended Euclidean Algorithm (EEA)

- Used to find integers $x$ and $y$ such that $ax + by = gcd(a, b)$.
- **Crucial for RSA**: It allows us to find the modular inverse. To find $d = e^{-1} \pmod{\phi(n)}$, we solve for $x$ in $ex + \phi(n)y = 1$. The resulting $x$ is our private key $d$.

### Euler's Totient Function $\phi(n)$

- Counts the number of positive integers less than $n$ that are relatively prime to $n$.
- If $n$ is prime, $\phi(n) = n - 1$.
- If $n = p \times q$ (where $p, q$ are prime), $\phi(n) = (p-1)(q-1)$.

### Modular Exponentiation

- Computing $a^b \pmod n$ for large $b$ is computationally intensive if done directly.
- **Repeated Squaring**: An efficient algorithm. Convert the exponent $b$ to binary. Iterate through bits:
  - If bit is 0: Square the current value.
  - If bit is 1: Square the current value and multiply by $a$.
  - Perform modulo $n$ at each step to keep numbers small.
