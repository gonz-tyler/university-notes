# Week 2.2: Hash Functions & MACs Revision Notes

---

## 1. Introduction to Hash Functions

A **hash function** `h` is a mathematical function with two basic properties:

1.  **Ease of Computation**: Given an input `x`, it is easy to compute its hash value `h(x)`.
2.  **Compression**: The function takes a variable-length input and maps it to a fixed-length output.
    -   $h: \{0,1\}^* \rightarrow \{0,1\}^L$, where `L` is the fixed output length in bits.

Hash functions are widely used in computer science for tasks like creating data structures. For security, however, they must have additional, stronger properties.

### Types of Hash Functions

Hash functions can be categorized as **keyed** or **unkeyed**.

-   **Unkeyed Hash Functions**: These do not require a secret key. They are primarily used to create a **Modification Detection Code (MDC)**, also known as a message digest or checksum, which serves as a digital fingerprint to verify file integrity.
-   **Keyed Hash Functions**: These functions require a secret key as an additional input. They are used to generate a **Message Authentication Code (MAC)**, which provides both integrity and authenticity.

---

## 2. Properties of Cryptographic Hash Functions

For a hash function to be cryptographically secure, it must satisfy several key properties.

### 1. Pre-image Resistance (One-Way)

A hash function is **pre-image resistant** if, given a hash value `y`, it is computationally infeasible to find any input `x` such that `h(x) = y`.

-   This property makes the function **one-way**. You can easily go from `x` to `h(x)`, but not the other way around.
-   A hash function that has this property is called a **One-Way Hash Function (OWHF)**.

### 2. Second Pre-image Resistance

A hash function is **second pre-image resistant** if, given an input `x`, it is computationally infeasible to find a *different* input $x'$ such that $h(x) = h(x')$.

-   This is crucial for preventing an attacker, who knows both a message and its hash, from creating a fraudulent message with the same hash.

### 3. Collision Resistance

A **collision** occurs when two different inputs, `x` and $x'$, produce the same hash output: $h(x) = h(x')$.

-   By the **pigeonhole principle**, collisions are guaranteed to exist because the set of possible inputs is infinite while the set of possible outputs is finite.
-   A hash function is **collision-resistant** if it is computationally infeasible to find *any* pair of inputs `(x, x')` that result in a collision.

**Relationships between properties:**
-   **Collision resistance implies second pre-image resistance**. If you can't find *any* collision pair, you certainly can't find one for a *specific* input `x`.
-   A function that is not pre-image resistant is unlikely to be collision resistant.

### 4. Avalanche Effect

A small change in the input message should cause a significant and unpredictable change in the output hash.

-   Ideally, changing a single bit in the input should, on average, change about **half of the bits** in the output hash.
-   This prevents attackers from deducing information about the input by analyzing the output or from predicting how to change the input to get a desired output.

### Applications of OWHFs

-   **Integrity Checks**: Distributing a file along with its hash value allows anyone to verify that the file has not been altered.
-   **Authentication**: To verify someone has a file `x`, you can ask them for `h(x)` instead of the file itself. This is useful if the file is large or secret.
-   **Password Storage**: Storing hashes of passwords (`h(password)`) instead of the plaintext passwords themselves is much more secure. If the password database is stolen, the actual passwords are not immediately compromised.

---

## 3. Attacks on Hash Functions

The most significant attack against the collision resistance of a hash function is the **Birthday Attack**.

### The Birthday Paradox

The "paradox" is that in a group of just **23 people**, there is a greater than 50% probability that at least two people share the same birthday. This is counter-intuitive because it takes 366 people to *guarantee* a shared birthday.

-   The key is that we are looking for *any* pair, not a pair matching a *specific* date.

### The Birthday Attack

This principle applies directly to hash functions. Finding a collision (any two messages with the same hash) is much easier than finding a pre-image (a message for a specific hash).

-   For a hash function with an `L`-bit output, there are $2^L$ possible hash values.
-   A brute-force attack to find a **pre-image** would require, on average, $2^{L-1}$ hash computations.
-   However, a brute-force attack to find a **collision** only requires approximately $\mathbf{2^{L/2}}$ computations.

**Example (Yuval's Attack)**:
Mallory wants to trick Alice into signing a fraudulent contract.
1.  He prepares a legitimate contract and a fraudulent one.
2.  He creates $2^{32}$ (for a 64-bit hash) tiny, semantically invisible variations of *each* document (e.g., adding spaces, control characters).
3.  Due to the birthday paradox, he is highly likely to find one version of the legitimate contract and one version of the fraudulent contract that produce the **same hash value**.
4.  He gets Alice to sign the hash of the legitimate version.
5.  He can then attach her signature to the fraudulent contract, and the hash will still match.

This attack highlights why a hash length of 64 bits is insufficient. A good hash function must have a sufficiently large output `L` to make the $2^{L/2}$ work factor infeasible.

---

## 4. Well-Known Hash Functions

### MD5 (Message Digest 5)

-   **Output Size**: 128 bits.
-   **Status**: **Broken**. Collisions can be found in seconds. It should **not** be used for any security purposes, especially not for digital signatures or integrity checks where collision resistance is required.

### SHA-1 (Secure Hash Algorithm 1)

-   **Output Size**: 160 bits.
-   **Status**: **Insecure**. While stronger than MD5, practical collision attacks have been demonstrated. It is deprecated and should be phased out in favor of SHA-2.

### SHA-2 Family

This is a family of hash functions with different output sizes. They are currently considered secure.

| Characteristic | SHA-224 | SHA-256 | SHA-384 | SHA-512 |
| :--- | :---: | :---: | :---: | :---: |
| **Message Digest Size** | 224 bits | 256 bits | 384 bits | 512 bits |
| **Block Size** | 512 bits | 512 bits | 1024 bits | 1024 bits |
| **Max Message Size** | $2^{64}-1$ | $2^{64}-1$ | $2^{128}-1$ | $2^{128}-1$ |
| **Word Size** | 32 bits | 32 bits | 64 bits | 64 bits |

### General SHA Structure (e.g., SHA-512)

Most modern hash functions, including SHA, follow an iterative structure:

1.  **Padding**: The input message is padded so its length is a multiple of the block size (e.g., 1024 bits for SHA-512). Padding is always added, even if the message is already the right length.
2.  **Append Length**: A block representing the length of the original message is appended.
3.  **Process Blocks**: The algorithm processes the message block-by-block.
    -   It starts with a fixed **initial value** (IV).
    -   For each message block, a **compression function** takes the output of the previous stage and the current message block as input, producing a new intermediate hash value.
    -   The output from the final block is the message digest.

---

## 5. Message Authentication Codes (MACs)

While hash functions (MDCs) provide **integrity**, they do not provide **authenticity**. Anyone can compute the hash of a message, so an MDC cannot prove who the message came from.

A **Message Authentication Code (MAC)** is a cryptographic checksum that provides both integrity and authenticity.

-   **Definition**: A MAC is a function of a message `M` and a **secret key `K`** that produces a fixed-length authenticator tag.
    -   $MAC = C(K, M)$
-   **Process**:
    1.  The sender computes the MAC using the message and a shared secret key and appends it to the message.
    2.  The receiver, who also knows the secret key, re-computes the MAC on the received message.
    3.  If the computed MAC matches the received MAC, the receiver can be confident that:
        -   The message has **not been altered** (integrity).
        -   The message came from the party that holds the secret key (authenticity).

### HMAC: Hash-based MAC

It is desirable to create a MAC from a standard hash function like SHA-256. However, simple constructions like `Hash(Key || Message)` are insecure.

**HMAC** is a standard, secure method for constructing a MAC from a hash function.

-   **Formula**:
    $HMAC(K, M) = Hash((K^+ \oplus opad) \ || \ Hash((K^+ \oplus ipad) \ || \ M))$
-   **Components**:
    -   `K+`: The secret key `K`, padded to the block size of the hash function.
    -   `ipad`: An inner padding constant (`0x36` repeated).
    -   `opad`: An outer padding constant (`0x5C` repeated).
    -   `||`: Concatenation.
-   **Process**: HMAC uses the hash function twice in a nested manner, effectively mixing the key with the message in a way that is resistant to known attacks.
