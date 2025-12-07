# Tutorial 04: Asymmetric Cryptography

**Instructions:**

- **R** = Review question (look it up in notes)
- **E** = Easy (simple application)
- **M** = Moderate (takes some thought)
- **H** = Harder (takes a lot of thought)
- **O** = Open-ended

---

## Part 1: Public-key Cryptography and RSA

### Question 1 [R, *]

What is the typical use for public-key cryptography when sending enciphered messages between parties?

<details>
<summary>Answer</summary>

> Confidentiality
</details>

---

### Question 2 [R, *]

Why is public-key cryptography not used directly for enciphering large quantities of data?

> **Answer:**
> it is computationally expensive so it is typically used to securely exchange a session key that is then used for efficient symmetric encryption
</details>

---

### Question 3 [R, *]

In the basic textbook RSA scheme (from lectures):

1.  Explain how to encrypt a plaintext $m$, stating the public and private keys used.
2.  Explain how decryption works.
3.  Explain the sense in which the encryption and decryption algorithms are the same, but the key used is changed.

> **Answer:**
> 1. the sender obtains the recipients Public Key $(e, n)$
>   the public key is used to encrypt the message
>   $c = m^e (\mod n)$
> 2. the recipient uses their Private Key $(d, n)$ to decrypt the ciphertext
>   $m = c^d (\mod n)$
> 3. the function is the same
>   $output = input^{key} (\mod n)$
</details>

---

### Question 4 [M, *]

Why might making RSA encryption faster (by taking a small $e$) result in decryption being slower?
_Hint: Think about the conditions on $e, d$. Why might it be an advantage to do this in real systems? What possible problems might it cause? (Think about possible applications in different systems and devices)._

> **Answer:**
> $e \cdot d \equiv 1 \pmod{\phi(n)}$
> e and d are modular inverse
> if you choose a very small number for e the modular inverse algorithm will create a very large number for d
> RSA depends on key size so a small e makes encryption near instant but the large d makes decryption computationally heavy
</details>

---

### Question 5 [E]

**Context:** During key generation, Alice generates a pair of prime numbers 3, 11 to generate the modulus $N$, and then selects $e=7$ to be the 'encryption exponent', and finally $d=3$ as the 'decryption exponent'.

**(a)** What is Alice’s public key? Give the values.

> **Answer:**
> $N = p \times q = 3 \times 11 = 33$
> $key = (e,N) = (7,33)$
</details>

**(b)** Alice receives an encrypted message, $c$, from Bob with the value $16$. What was the value of the corresponding plaintext message, $m$?
_Show your working, starting with the relevant algebraic formula expressed in symbols (using any of $m, c, N, e, d, p, q$ etc.) that shows how to calculate the message $m$._

> **Workings:**
> $m = c^d (\mod N)$
> $m = 16^3 (\mod 33) = 4096 (\mod 33) = 4$
>
> **Final Answer:**
> 4
</details>

---

### Question 6 [R, *]

Apply the textbook RSA encryption and then decryption, where $p=3$, $q=5$, $e=7$.

1.  Compute $n=pq$ and $\phi(n)$ (eulers totient must be secret if not p and q can be found).
2.  What is the (minimal) data in the public key?
3.  What is the (minimal) data in the private key (and explain your reasoning)?
4.  Why is this value of $e$ valid?
5.  Encrypt the message $m=2$ to get ciphertext $c$.
6.  Decrypt $c$ to get back $m$.

> **1. Computation:**
> $n = pq = 3\times 5 = 15$
> $\phi(n) = (p-1)(q-1) = (3-1)(5-1) = 2 \times 4 = 8$
</details>

> **2. Public Key:**
> $Public Key = (e,n) = (7,15)$
</details>

> **3. Private Key:**
> $e \cdot d \equiv 1 \pmod{\phi(n)}$
> $7 \cdot d \equiv 1 \pmod{8}$
> $7\times 7 = 49$
> $49 \div 8 = 6 remainder 1$
> $d=7$
> $Private Key = (d,n) = (7,15)$
</details>

> **4. Validity of $e$:**
> $e=7$
> $\phi(n) = 8$
> $gcd(7,8) = 1$
> Value of e is valid because 7 and 8 are relatively prime (only common denominator is 1)
</details>

> **5. Encryption of $m=2$:**
> $c=m^e (\mod n)$
> $c=2^7 (\mod 15) = 128 (\mod 15) = 8$
> $c = 8$
</details>

> **6. Decryption of $c$:**
> $m=c^d (\mod n)$
> $m=8^7 (\mod 15) = 2097152 (\mod 15) = 2$
> $m = 2$
</details>

---

### Question 7 [M, *]

Could one ever have an RSA encryption exponent which was an even number?
_[Hint: Think about the conditions involved in setting up the encryption and decryption exponents, $e$ and $d$.]_

> **Answer:**
> No, $e$ can never be an even number.
> $\phi(n)$ is always even
> $e \cdot d \equiv 1 \pmod{\phi(n)}$
> to get a remainder of one when $\phi(n)$ is even then product of $e$ and $d$ must be odd
> any number times an even number is always odd
> this means that both $e$ and $d$ must always be odd
</details>

---

### Question 8 [E, *]

According to the key length of RSA encryption, messages are broken (currently) into chunks of 1024 or 2048 or 4096 bits. This makes it either a stream cipher or a block cipher. Which is correct?

> **Answer:**
> Block Cipher
</details>

---

### Question 9 [M]

Given a modular exponentiation algorithm on n-bit integers that needs about $n^{3}$ operations, how much does performance deteriorate from 1024 to 2048-bit RSA?

> **Answer:**
> $1024^3 = 1073741824$
> $2048^3 = 8589934592$
> $(2n)^3 = 8n^3$
> 8 times slower
</details>

---

### Question 10 [H]

**Context:** In the standard version of RSA called PKCS #1 v1.5, the recommended padding for a message $D$ consists of a byte `00`, followed by a byte `02`, followed by a sequence of bits called $PS$, followed by another byte `00`, followed by the message $D$.
The padded message looks like: `00 02 PS 00 D`.

Let $|X|$ be the number of bytes in any given message $X$. Let $M$ be the padded message above containing the original message $D$. $M$ has a given, fixed number of bytes, $|M|$.

Write down an expression for the number of bits in $PS$. That is, what is $|PS|$?

> **Answer:**
> $|M| = 1 + 1 + |PS| + 1 + |D|$
> $|M| = 3 + |PS| + |D|$
> $|PS| = 8\times (|M| - |D| - 3$)
</details>

---

### Question 11 [R, *]

State the RSA problem.

<details>
<summary>Answer</summary>

> the RSA Problem is the computational task of recovering the plaintext $m$ from a ciphertext $c$, given only the public key $(n, e)$
> it is equivalent to finding the $e$-th root of $c$ modulo $n$
> its difficulty is the basis for the security of RSA encryption.
</details>

---

### Question 12 [E, *]

Briefly explain how the RSA problem relates to an attacker trying to decipher an encrypted message.

> **Answer:**
> the mathematical wall an attacker hits when trying to decrypt a message without the private key
> equivalent to finding the $e$-th root of $c$ modulo $n$
> this calculation is computationally infeasible for large numbers effectively making the message undecipherable
</details>

---

### Question 13 [M, *]

Explain why the RSA problem is no harder than the problem of finding the prime factors $p, q$ of numbers $N$ which are the composite of two primes (i.e. $N=pq$).

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 2: Key Establishment and ElGamal

### Question 14 [R, *]

Explain the Discrete Logarithm Problem (DLP), say over the integers mod $p$ with $p$ prime.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 15 [E, *]

Describe in detail the Diffie-Hellman protocol for three parties: Alice, Bob, and Carol.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 16 [R, *]

Explain the main use of the Diffie-Hellman protocol. Would it be correct to describe this as key transport? That is, is the key ever sent?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 17 [R, *]

Outline a basic man-in-the-middle attack on the unauthenticated Diffie-Hellman scheme.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 18 [M, *]

Apply the ElGamal encryption scheme given in lectures with prime $p=11$, generator $g=2$, private key $x=8$ for Alice.

1.  Encrypt the message $m=5$ with Bob's secret key (random ephemeral key), say $k=7$.
2.  Decrypt the ciphertext to give back the original value of $m$.
    _Show your working!_

<details>
<summary>**Encryption Workings:**</summary>

>
</details>
<details>
<summary>**Decryption Workings:**</summary>

>
</details>

---

### Question 19 [M]

Why would it be bad to encode a message $m=0$ under the textbook ElGamal encryption described in the lecture?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 20 [M]

In ElGamal encryption, a different ephemeral key $k$ is generated for every message $m$, to give the ciphertext pair $(g^{k}, m \cdot g^{xk})$. ElGamal is a randomized encryption algorithm in that encrypting the same plaintext twice will produce different ciphertexts.

List any advantages and disadvantages that you can see in this.

<details>
<summary>**Advantages:**</summary>

>
</details>
<details>
<summary>**Disadvantages:**</summary>

>
</details>
