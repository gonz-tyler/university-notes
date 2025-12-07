# Tutorial 03: Symmetric Cryptography and Hashing

**Instructions:**

- **R** = Review question (look it up in notes)
- **E** = Easy (simple application)
- **M** = Moderate (takes some thought)
- **H** = Harder (takes a lot of thought)
- **O** = Open-ended

---

## Part 1: Symmetric Cryptography

### Question 1 [M, *]

**i)** Explain how exclusive-or (XOR, $\oplus$) can be used to encipher and decipher a single bit, as in a one-time pad. Prove that encryption followed by decryption returns the original plaintext bit.

> **Answer:**
> XOR acts as a reversible toggle. To encypher plaintext p into ciphertext c $c = p \oplus k$ and to decypher $p = c \oplus k$.
> Proof
> 1. substitute encryption formula into decryption step: $p = (p \oplus k) \oplus k$
> 2. any bit XORed with itself is 0 equation becomes $p \oplus 0$ as $a \oplus (b \oplus c) = (a \oplus b) \oplus c$
> 3. any bit XORed with $0$ remains unchanged, returning original $p$
> eg.
> $0 \oplus 1 = 1$
> $1 \oplus 1 = 0$

**ii)** Explain why this provides secrecy (compared to other logical operations e.g. OR, AND).

> **Answer:**
> XOR provides secrecy because it is invertible and statistically unbiased, whereas AND and OR are lossy and biased.
> 1. The Failure of AND / OR (Information Leakage)
> The main problem with AND and OR is that they destroy information. They tend to "force" the output to a specific value, making it impossible to reverse the process reliably.
> eg using AND ($\land$)Rule: Output is 1 only if BOTH inputs are 1.
> The Flaw: If the key bit is 0, the output is forced to 0 regardless of the plaintext. The receiver cannot decrypt this because the information about $p$ was destroyed.
> The Leak: Conversely, if an attacker sees a ciphertext of 1, they know with 100% certainty that the plaintext was 1 (because $1 \land 1$ is the only way to get 1). That is zero secrecy.
> eg using OR ($\lor$)Rule: Output is 1 if EITHER input is 1.
> The Flaw: If the key bit is 1, the output is forced to 1 regardless of the plaintext.The Leak: If an attacker sees a ciphertext of 0, they know with 100% certainty that the plaintext was 0.

**iii)** Suppose that one-bit messages $m_{1}$ and $m_{2}$ are enciphered with the same key.

- Show how an attacker with access to the ciphertext can use this to compare messages $m_{1}$ and $m_{2}$.
- Suppose that message $m_{1}$ is known to the attacker. Show how the attacker can use this to work out $m_{2}$ and $k$.

> **Answer:**
> $c_{1} = m_{1} \oplus k$
> $c_{2} = m_{2} \oplus k$
> $c_{1} \oplus c_{2} = (m_{1} \oplus k) \oplus (m_{2} \oplus k)$
> $c_{1} \oplus c_{2} = m_{1} \oplus m_{2} \oplus (k \oplus k)$
> $c_{1} \oplus c_{2} = m_{1} \oplus m_{2} \oplus 0$
> $c_{1} \oplus c_{2} = m_{1} \oplus m_{2}$
> if $c_{1} \oplus c_{2} = 0$ attacker knows $m_{1}$ and $m_{2}$ are identical
> if $c_{1} \oplus c_{2} = 1$ attacker knows $m_{1}$ and $m_{2}$ are opposite
> If $m_1$ is known and so are $c_1$ and $c_2$
> $k = c_1 \oplus m_1$
> $m_2 = c_2 \oplus k$

---

### Question 2 [R, *]

Explain how a one-time pad (Vernam cipher) works. What is the essential protocol regarding keys? What problems of key management does this pose?

> **Answer:**
> one time pad pairs plaintext with a key of equal length
> text is converted to binary and XORed with corresponding bit of key
> to be secure the key must be truly random it must be at least as long as the message must be secured between sender and receiver and only used once and never reused
> the key must be exchanged physically as if there is a secure channel to transfer the key then the message itself could just be transferred
> the key forces the data to be doubled as the message and key must at least be equal in size
> if the sender and receiver get out of sync even one bit the remainder of the message is corrupted

---

### Question 3 [R, *]

What are the two key classes of operations used to build symmetric ciphers? As well as naming them, explain how each works.

> **Answer:**
> Substitution: replaces a piece of data with a completely different value based on a specific rule or key
> eg. ABC -> shift forward 1 -> BCD
> Transposition: scrambles the order of the data - bits stay the same just different order
> eg. ABC -> reverse -> CBA

---

### Question 4 [M, *]

An adversary wants to break ciphertexts and retrieve corresponding plaintext messages. Rank the following attacks according to which is **hardest** to successfully execute (put the hardest first and the easiest last).

- **Ciphertext-only attacks:** Attacker has access to encrypted data only.
- **Chosen plaintext attacks:** Attacker can play with encryption device, choose plaintext to encrypt, and examine the result.
- **Known plaintext attacks:** Attacker has at least one pair $(m, c)$ for which they know that $D(k,c)=m$.

_(Note: Assume the necessary data is already obtained for each attack; do not consider the difficulty of obtaining the data itself.)_

> **Answer:**
>
> 1. Ciphertext only - zero context brute force
> 2. Known plaintext - you have some information but it might not be useful
> 3. Chosen plaintext - you can generate your own data to target weak points

---

### Question 5 [M]

In this exercise we consider known plaintext attacks. Try to determine the type of cipher and the key for the following $(M, C)$ pairs:

**(a)**
$M =$ `cryptographyisgreatfun` l=22
$C =$ `UVAGXHYVCGLRAWIIITLJWE` l=22

> **Answer:**
> letters different so substitution
> U(20) - c(2) = 18(s)
> V(21) - r(17) = 4(e)
> A(0) - y(24) = -24 = 2(c)
> G(6) - p(15) = -9 = 17(r)
> X(23) - t(19) = 4(e)
> H(7) - o(14) = -7 = 19(t)
> vigenere
> key is SECRET repeated

**(b)**
$C =$ `GVCTXSKVETLCMWKVIEXJYR` l=22

> **Answer:**
> G(6) - c(2) = 4(e)
> V(21) - r(17) = 4(e)
> C(2) - y(24) = -22 = 4(e)
> T(19) - p(15) = 4(e)
> caesar
> key is 4

**(c)**
$C =$ `PRCRGHYAOTPGTYIANSFERU` l=22

> **Answer:**
> 012345678910
> cryptograph - PRCRGHYAOTP
> 012345678910
> yisgreatfun - GTYIANSFERU
> indexes
> (3/9, 1/7, 0, 1/7, 6, 10, 2, 8, 5, 4, 3/9)
> (3, 7, 0, 1, 6, 10, 2, 8, 5, 4, 9)
> this is the final permutation sequence

---

### Question 6 [M]

Using Kerckhoffs’ principle (assuming the adversary knows the type of system used), you can perform a **Chosen Plaintext Attack**. Which choice of plaintext would you make, and how would you use the ciphertext to determine the key if the system is:

**(a) A shift cipher**

> **Answer:**
> Choose ABCDEF repeating and it should come out cycled through

**(b) A Vigenère cipher**

> **Answer:**
> Choose long repeating sequence of a single character eg. AAAAAAAAAAAAA this will encrypt to the key

**(c) A simple substitution cipher**

> **Answer:**
> input alphabet and view difference

**(d) A transposition cipher**

> **Answer:**
> try plaintext of repeating cycles of various lengths ABABABAB, ABCABCABCABC

---

### Question 7 [R, *]

**(a)** What is the difference between a stream cipher and a block cipher?

> **Answer:**
> A stream cipher encrypts data continuously one bit or byte at a time (like a video stream), whereas a block cipher breaks data into fixed-size chunks (e.g., 64 or 128 bits) and encrypts each chunk as a complete unit.
> 1. Stream Cipher (The "Conveyor Belt")
> Imagine a factory conveyor belt.
> How it works: Items (bits) flow past a robot one by one. As each item passes, the robot stamps it individually.
> Key Feature: It is continuous and fast. You don't need to wait for a pile of items to accumulate; you process them the instant they arrive.
> 2. Block Cipher (The "Shipping Container")
> Imagine filling a shipping container.
> How it works: You cannot ship just one item. You must wait until you have enough items to fill the entire container (the block). Once it is full, you lock the whole container at once.
> Key Feature: If you don't have enough items to fill the container, you must add "packing peanuts" (padding) to fill the empty space before you can lock it.

**(b)** At a high level, explain the operation of a typical, modern block cipher in enciphering a stream of bits. (Your answer should involve blocks, rounds, keys, substitutions, and permutations).

> **Answer:**
> incoming stream is chopped into fixed size chunks called blocks - if last block is not full then padded with extra bits
> main secret key provided by user is expanded into series of distinct round keys (subkeys) - a different subkey is used for each stage of the process to prevent patterns
> cipherr processes the block through cycle of operations called a round - the round is repeated multiple times to ensure security
> inside each round three things happen
> 1. key mixing - current round key is combined with the block (usually XOR)
> 2. substitution - segments of block are replaced with different values using fixed lookup table called S-Box breaking linear relationship between key and message
> 3. permutation - bits within block are shuffle (transposition) spreading influence of a single bit across entire block ensuring changing one bit of message changes entire block
> after all rounds complete final result is cipher text block and is repeated for every block in stream 

---

### Question 8 [M, *]

**Context:** A two-round Feistel cipher.

- **Plaintext ($P$):** `10110110` (binary)
- **Function F1:** "Add 5 modulo 16"
- **Function F2:** "Add 3 modulo 16"
- **Structure:** The input is split into Left (`1011`) and Right (`0110`) halves.

Calculate the resulting ciphertext.

> **Workings:**
> $L_0 = 1011$ (Decimal 11)
> $R_0 = 0110$ (Decimal 6)
> $F_1(R_0)=(6+5) (mod 16) = 11$ (Binary 1011)
> $R_1 = L_0 \oplus F_1(R_0) = 11 \oplus 11 = 0$ (Binary 0000)
> $L_1 = R_0 = 6$ (Binary 0110)
> $F_2(R_1) = (0+3) (mod 16) = 3$ (Binary 0011)
> $R_2 = L_1 \oplus F_2(R_1) = 6 \oplus 3 = 0110 \oplus 0011 = 0101$ (Decimal 5)
> $L_2 = R_1 = 0$ (Binary 0000)
> $L_3 = R_2 = 0101$
> $R_3 = L_2 = 0000$
> Final Ciphertext $01010000$
> **Final Ciphertext:**
> 01010000

---

### Question 9 [M, *]

Reverse the Feistel cipher in the above question (Question 8) to demonstrate that the ciphertext can be decrypted into the original plaintext. (Remember: swap F1 and F2, and use the ciphertext as input).

> **Workings:**
> $L_0 = 0101$ (Decimal 5)
> $R_0 = 0000$ (Decimal 0)
> $F_2(0)=(0+3) (mod 16) = 3$ (Binary 0011)
> $R_1 = L_0 \oplus F_2(R_0) = 5 \oplus 3 = 6$ (Binary 0110)
> $L_1 = R_0 = 0$ (Binary 0110)
> $F_1(R_1) = (6+5) (mod 16) = 11$ (Binary 1011)
> $R_2 = L_1 \oplus F_1(R_1) = 0 \oplus 11 = 0000 \oplus 1011 = 1011$ (Decimal 11)
> $L_2 = R_1 = 6$ (Binary 0110)
> $L_3 = R_2 = 1011$
> $R_3 = L_2 = 0110$
> Final Ciphertext $10110110$
> **Result:**
> 10110110
---

### Question 10 [M]

**(Meet-in-the-middle attack on double encryption)**
Consider a toy cipher that takes a pair of n-bit keys $(k_{1},k_{2})$ and encrypts messages $m$ as follows: $C=E_{k_{1}}(E_{k_{2}}(m))$.
You know that single encryption can be broken by brute force in time $O(2^{n})$.

Show that the double encryption can also be broken in $O(2^{n})$ using a known-plaintext attack.
_Hint: Combine brute-force searches using decryption and encryption._

How much storage space is required for this attack?

> **Answer:**
> Instead of brute-forcing the key pair ($2^{2n}$), we find the intermediate value $X$ where the two encryptions meet.
> 1. Forward (Store): Encrypt the known plaintext $m$ with all $2^n$ possible values of $k_2$. Store every result $X = E_{k_2}(m)$ in a lookup table (e.g., a hash map).
> 2. Backward (Match): Decrypt the ciphertext $C$ with all $2^n$ possible values of $k_1$. For each result $X' = D_{k_1}(C)$, check if it exists in the stored table.
> 3. Result: If a match is found ($X = X'$), the corresponding $(k_1, k_2)$ is the likely key pair.
> Time Complexity:$2^n$ operations to build the table + $2^n$ operations to check it $= O(2^n)$.
> Storage Space:The table must store $2^n$ intermediate values, so space complexity is $O(2^n)$.

---

### Question 11 [M, *]

What are ECB and CBC? Describe encryption and decryption in ECB mode and CBC mode, and describe/draw diagrams that explain them.

**(a) Descriptions:**

> **Answer:**
> ECB (Electronic Codebook) Mode:
> The simplest mode where each block of plaintext is encrypted independently using the same key.
> - Encryption: The plaintext is divided into blocks $P_1, P_2, \dots$. Each block is encrypted directly:
> $C_i = E_K(P_i)$
> - Decryption: Each ciphertext block is decrypted independently:$$P_i = D_K(C_i)$$
> CBC (Cipher Block Chaining) Mode:
> A mode where each block of plaintext is XORed with the previous ciphertext block before being encrypted. This links all blocks together.
> - Encryption: The first block uses an Initialization Vector ($IV$). Subsequent blocks use the previous output:
> $C_1 = E_K(P_1 \oplus IV)$
> $C_i = E_K(P_i \oplus C_{i-1}) \quad \text{for } i > 1$
> - Decryption: The process is reversed. You decrypt the current block and XOR it with the previous ciphertext block:
> $P_1 = D_K(C_1) \oplus IV$
> $P_i = D_K(C_i) \oplus C_{i-1} \quad \text{for } i > 1$

**(b) What advantage does CBC have over ECB for larger inputs?**

> **Answer:**
> CBC provides better diffusion and hides data patterns.
> In ECB, identical plaintext blocks produce identical ciphertext blocks. For large inputs (like images), this preserves the structure of the original data (e.g., you can still see the outline of a penguin in an ECB-encrypted image).
> CBC ensures that even if $P_1 = P_2$, the resulting $C_1 \neq C_2$ because the input to the second encryption is randomized by the first block's output.

**(c) What difficulties are there with CBC arising from potential errors?**

> **Answer:**
> Error Propagation.
> If a single bit is corrupted in a ciphertext block $C_i$ during transmission:
> 1. The decryption of that specific block ($P_i$) is completely garbled (random noise).
> 2. The decryption of the next block ($P_{i+1}$) will have a bit error in the exact same position (because $P_{i+1} = D_K(C_{i+1}) \oplus C_i$).
> However, CBC is self-synchronizing; the error does not propagate beyond these two blocks. If a bit is lost (shifting boundaries), the entire remainder of the message is corrupted.

---

## Part 2: Hashes

### Question 1 [R, *]

Give an example to explain how a secure hash can be used to assure integrity against malicious corruption of files.

> **Answer:**
> a person can generate a hash for a file
> the hash will always be the same for the same file
> so users can generate a hash with the file and check it with the original publicly available hash
> this provides users with a fingerprint to ensure a file has not been modified or corrupted

---

### Question 2 [R, *]

Explain two key properties of true cryptographic hash functions.

> **Answer:**
> Pre-image resistance - computationally infeasable to reverse a hash function
> collision resistance - it is computationally infeasible to find any pair of distinct messages $(m_1, m_2)$ such that they produce the same hash

---

### Question 3 [E, *]

Is the identity function (which outputs the same value as the input) a good one-way hash function? Why?

> **Answer:**
> No
> it is not one way as the hash is the message
> it does not compress the input
> it fails the avalanche effect as changing one bit in the input just changes one input in the output

---

### Question 4 [E, *]

Is the identically zero function (which maps any input into a 128-bit block of zeros) a good hash function? Why, or why not?

> **Answer:**
> No
> it completely fails collision resistance as all messages provide the same exact hash
> it fails pre-image resistance as any message can produce the same hash
> it fails avalanche completely because no matter what the output is the same

---

### Question 5 [M, *]

The `sum` function produces a byte (eight bits) of output and operates as follows:

1.  Takes a stream of bits (or bytes) as input.
2.  Divides it into contiguous bytes.
3.  For $1 \le i \le 8$, it takes the XOR of all the bits at position $i$ of each byte.
4.  Outputs the result at position $i$ of the output.

Is this a good one-way hash function? Give a reason.

> **Answer:**
> No
> it fails pre-image resistance - attacker can produce any desired hash value easily
> it fails collision resistance - AB XORs the same as BA

---

### Question 6 [M, *]

Suppose that a One-Way Hash Function (OWHF) has an output of 128 bits. What should be the approximate probability of a message hashing to any given hash value?
_Hint: The hash chosen should give as little information away about the input as possible._

> **Answer:**

---

### Question 7 [M]

Using the same 128-bit hash as in Question 6: You now choose two messages at random and hash them. Assume that the hash function is cryptographically strong. What is the approximate probability of a collision of the two values (i.e., that they are equal)?

> **Answer:**
> $\frac{1}{2^{128}}$ (or $2^{-128}$)
> secure hash function must produce a uniform distribution meaning all outputs are equally possible

---

### Question 8 [R, *]

Suppose that a message $m$ is hashed to produce $h(m)$. Suppose that we change one bit of $m$ to give a new message $m'$ and hash this to give $h(m')$.

Comparing bitwise, approximately how many bits should differ between $h(m)$ and $h(m')$? Assume the hash function is very strong.

> **Answer:**
> 50%
> if bits change 100% it is predictable
> if bits change 0% it is also predicatble
> 50% represents maximum randomness (entropy)
