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

> the RSA problem is no harder than integer factorization because factorization provides a direct method to break RSA
> if an attacker can find the factors $p$ and $q$
> they can trivially calculate $\phi(N)$ and the private key $d$
> allowing them to decipher the message
> therefore breaking RSA is included in the set of things you can do if you can factor integers
</details>

---

## Part 2: Key Establishment and ElGamal

### Question 14 [R, *]

Explain the Discrete Logarithm Problem (DLP), say over the integers mod $p$ with $p$ prime.

<details>
<summary>**Answer:**</summary>

> Given a large prime number $p$, a generator $g$ (a primitive root modulo $p$), and a value $h$, the Discrete Logarithm Problem is the task of finding the integer $x$ such that:
> $g^x \equiv h \pmod p$
> this problem acts as a One-Way Function:
> Easy Direction (Exponentiation): Given $x$, it is computationally fast to calculate $h = g^x \pmod p$.
> Hard Direction (Logarithm): Given $h$, it is computationally infeasible to recover $x$ when $p$ is sufficiently large (e.g., 2048 bits).
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

> $K = g^{abc} \pmod p$
> 1. Setup (Public Parameters)
> Everyone agrees on two public numbers 
> - a large prime number $p$
> - a generator $g$
> 2. Private Keys
> Each person generates a random secret private key:
> - Alice: $a$
> - Bob: $b$
> - Carol: $c$
> 3. The Protocol (Round Robin)
> The goal is for everyone to calculate $g^{abc} \pmod p$. 
> Since there are 3 people, this requires two rounds of message passing.
> - Round 1: Injecting the First Key
>   Everyone calculates their "Public Key" ($g^{private}$) and passes it to the person on their right
>   - Alice computes $g^a$ and sends to $\rightarrow$ Bob
>   - Bob computes $g^b$ and sends to $\rightarrow$ Carol
>   - Carol computes $g^c$ and sends to $\rightarrow$ Alice
> - Round 2: Injecting the Second Key
>   Everyone takes the value they received, raises it to the power of their own private key, and passes it to the right again.
>   - Bob received $g^a$ from Alice computes $(g^a)^b = \mathbf{g^{ab}}$ and sends to $\rightarrow$ Carol
>   - Carol received $g^b$ from Bob computes $(g^b)^c = \mathbf{g^{bc}}$ and sends to $\rightarrow$ Alice
>   - Alice received $g^c$ from Carol computes $(g^c)^a = \mathbf{g^{ca}}$ and sends to $\rightarrow$ Bob
> - Final Step: The Final Computation
> Everyone takes the value they just received and raises it to their private key one last time. They do not pass this on (this is the secret).
>   - Carol receives $g^{ab}$ computes $(g^{ab})^c = \mathbf{g^{abc}}$
>   - Alice receives $g^{bc}$ computes $(g^{bc})^a = \mathbf{g^{abc}}$
>   - Bob receives $g^{ca}$ computes $(g^{ca})^b = \mathbf{g^{abc}}$
> Conclusion
> Alice, Bob, and Carol now all possess the identical value $g^{abc}$.An attacker listening to the network only ever saw the partial values ($g^a, g^b, g^{ab}, \dots$), but never the final complete combination, and never the private keys.
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

> Setup Alice Public Key
> $y = g^x (\mod p)$
> $y = 2^8 (\mod 11) = 256 (\mod 11) = 3
> Alices Public Key - $(p=11,g=2,y=3)$
> Bob encrypts message using his random key and Alices public key resulting in ciphertext pair $(c_1,c_2)$
> $c_1=g^k (\mod p)$
> $c_1=2^7 (\mod 11) = 128 (\mod 11) = 7$
> Shared secret
> $S=y^k (\mod p)$
> $S=3^7 (\mod 11) = 2187 (\mod 11) = 9$
> $c_2=m\cdot S (\mod p)$
> $c_2=5\cdot 9 (\mod 11) = 45 (\mod 11) = 1$
> Final ciphertext $(c_1,c_2) = (7,1)$
</details>
<details>
<summary>**Decryption Workings:**</summary>

> $S=c_1^x (\mod p)$
> $S=7^8 (mod 11) = 5764801 (mod 11) = 9$
> Inverse of S
> $S \cdot S^{-1} \equiv 1 (\mod p)$
> $9 \cdot x \equiv 1 (\mod 11)$
> $9 \times 2 = 18 \equiv 7$
> $9 \times 3 = 27 \equiv 5$
> $9 \times 4 = 36 \equiv 3$
> $9 \times 5 = 45 \equiv 1$
> $S^{-1} = 5$
> Message
> $m = c_2\cdot S^{-1} (\mod p)$
> $m = 1\cdot 5 (\mod 11) = 5$
</details>

---

### Question 19 [M]

Why would it be bad to encode a message $m=0$ under the textbook ElGamal encryption described in the lecture?

<details>
<summary>**Answer:**</summary>

> if $m=0$ the ciphertext component $c_2$ becomes 0 regardless of the random key $k$ used
> Reasoning:
> the formula is $c_2 = m \cdot y^k \pmod p$
> if $m=0$, then $c_2 = 0 \cdot y^k = 0$
> this completely destroys the masking provided by the random key
> allowing an attacker to instantly deduce that the plaintext message was 0 just by looking at the ciphertext.
</details>

---

### Question 20 [M]

In ElGamal encryption, a different ephemeral key $k$ is generated for every message $m$, to give the ciphertext pair $(g^{k}, m \cdot g^{xk})$. ElGamal is a randomized encryption algorithm in that encrypting the same plaintext twice will produce different ciphertexts.

List any advantages and disadvantages that you can see in this.

<details>
<summary>**Advantages:**</summary>

> sending the same message twice produces different ciphertexts and so patterns cannot be detected in traffic
> because encryption is randomised attacker cannot verify a guess by encrypting it as it will return a different ciphertext
</details>
<details>
<summary>**Disadvantages:**</summary>

> It is difficult to generate truly random numbers every single time and is slower computationally to do different calculations with large primes for each message
> storage is doubled for message m you need two ciphertexts
> if a key is accidentally used twice patterns emerge and encryption breaks entirely
</details>
