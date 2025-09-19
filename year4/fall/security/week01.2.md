# Week01.2: Introduction to Cryptography

## Notes
---

### Overview of Cryptography

Cryptography is defined as "the science and study of secret writing," a term derived from the Greek words **crypto** (hidden/secret) and **grafia** (writing). The fundamental purpose of cryptography is to protect data by converting it into an unreadable form. This ensures that the data cannot be accessed for unauthorized use, its content is hidden, its authenticity can be verified, undetected modification is prevented, and it cannot be disowned by its originator. It is essential for passing secret information through potentially insecure channels, with applications in military campaigns, online banking, and diplomatic communications.

---

### The Four Fundamental Goals of Cryptography

Cryptography aims to achieve four primary security goals in the face of adversaries:

1.  **Confidentiality**: This goal ensures that information is not accessed by unauthorized individuals. It comprises two aspects: preventing observers from accessing the message content and preventing them from identifying the sender and receiver. This is also referred to as privacy or secrecy.
2.  **Integrity**: This ensures that the message has not been tampered with. The recipient must be able to verify that the message was not changed, lost, prevented from being delivered, or delivered more than once during transmission.
3.  **Authentication**: This goal is about verifying the identity of entities or the origin of data. The sender needs to be sure the message reaches only the intended recipient, and the recipient must be sure the message is from the claimed sender and not an imposter. Sending a message as an imposter is known as "spoofing."
4.  **Non-repudiation**: This prevents the sender or receiver from denying their actions. It ensures the sender cannot deny sending the message, and the recipient cannot deny receiving it.

---

### Core Terminology in Cryptography

Understanding the following terms is essential for studying cryptography:

* **Plaintext** (or clear text): The original, readable message.
* **Encryption**: The process of transforming plaintext into an unreadable format.
* **Ciphertext** (or encrypted text): The encrypted, unreadable message.
* **Decryption**: The process of transforming ciphertext back into plaintext.
* **Cipher**: The secret method or algorithm used for encryption and decryption.
* **Key**: A word, number, or phrase used by the cipher to perform encryption and decryption.

The **conventional encryption model** works as follows: a sender uses an encryption algorithm and a secret key to convert plaintext into ciphertext. This ciphertext is then transmitted. The recipient uses a decryption algorithm and the same secret key to convert the ciphertext back into the original plaintext.

---

### Main Cryptography Techniques

Cryptography is broadly divided into two main categories based on key management:

#### Symmetric Encryption

* Also known as **secret key cryptography**.
* It uses a **single, shared key** for both encryption and decryption.
* The functions are represented as:
    * Encryption: $\mathcal{E}_{k}(PT)=CT$
    * Decryption: $\mathcal{D}_{k}(CT)=PT$
* The main challenge is the secure distribution of the shared secret key between the sender and receiver.
* Common algorithms include **DES, 3DES, and AES**.

#### Asymmetric (Non-symmetric) Encryption

* Also known as **public key cryptography**.
* It uses a **pair of keys**: a public key for encryption and a private (secret) key for decryption.
* The functions are represented as:
    * Encryption: $\mathcal{E}_{k_{1}}(PT)=CT$
    * Decryption: $\mathcal{D}_{k_{2}}(CT)=PT$
* A message encrypted with a public key can only be decrypted with the corresponding private key.
* A widely used algorithm is **RSA**.

---

### Classical (Traditional) Cryptographic Techniques

Classical ciphers form the foundation of modern cryptography and are based on two main operations: substitution and transposition. These ciphers can be **monoalphabetic** (using a single alphabet/system) or **polyalphabetic** (using multiple alphabets/systems). A combination of several ciphers is called a **product cipher**.

#### Substitution Ciphers

In these ciphers, letters of the plaintext are replaced by other letters, numbers, or symbols.

* **Caesar Cipher**: A monoalphabetic cipher where each letter is shifted by a fixed number of positions, $k$, in the alphabet.
    * Encryption: $\mathcal{E}_{k}:i\rightarrow i+k \pmod{26}$
    * Decryption: $\mathcal{D}_{k}:i\rightarrow i-k \pmod{26}$
* **Monalphabetic Substitution (Keyword)**: A more general form where a keyword (with no repeated characters) is written first, followed by the remaining letters of the alphabet, to create a substitution alphabet. The security of this cipher is weak, as it is susceptible to letter frequency analysis.
* **Porta Cipher**: A polygraphic cipher that substitutes blocks of two letters. It uses a keyword to select different substitution rules from a matrix, making it more complex than simple monoalphabetic ciphers.
* **Vigenère Cipher**: A polyalphabetic cipher that uses a keyword to shift letters by different amounts. The keyword is repeated over the plaintext, and each letter is encrypted using the corresponding key letter as an index into a Vigenère square (a table of 26 Caesar ciphers).

#### Transposition Ciphers

These ciphers rearrange the order of the letters in the plaintext without changing the letters themselves.

* **Turning Grille**: This method uses a template (a square sheet with holes) placed over a grid. The plaintext is written into the holes. The grille is then rotated (typically by 90 degrees) and the next part of the message is written. This is repeated until the grid is full. The ciphertext is formed by reading the letters off the grid, usually row by row.

#### Product Ciphers

These ciphers increase security by combining multiple cryptographic operations, such as both substitution and transposition.

* **Feistel Cipher**: A foundational structure for many modern block ciphers, including the Data Encryption Standard (DES). It uses permutation boxes (**P-boxes**) for transposition and substitution boxes (**S-boxes**) for confusion, applying them in multiple rounds.

---

### Block Ciphers vs. Stream Ciphers

#### Block Ciphers

* A type of symmetric-key encryption.
* They operate on **fixed-length blocks** of plaintext (e.g., 64 bits).
* Each block is transformed into a ciphertext block of the same length.
* A key feature is that the same plaintext block encrypted with the same key will always produce the same ciphertext block.

#### Stream Ciphers

* A type of symmetric-key encryption.
* They encrypt smaller units of plaintext, usually bits.
* They generate a **keystream** (a sequence of bits), which is then combined with the plaintext, typically using the XOR operation.
* Keystream generation can be **synchronous** (independent of plaintext/ciphertext) or **self-synchronising** (dependent on the data).
* Stream ciphers are typically designed to be exceptionally fast.
* **Vernam Cipher**: A stream cipher where plaintext is XORed with a random or pseudorandom stream.
* **One-Time Pad**: A type of Vernam cipher that is theoretically unbreakable. It requires the keystream to be truly random, at least as long as the message, and used only once. The primary difficulty lies in generating and securely distributing these long, single-use keys.

---

### Cryptographic Modes of Operation

When using a block cipher to encrypt messages longer than a single block, different modes of operation can be used.

#### Electronic Codebook (ECB)

* The message is divided into blocks, and each block is encrypted separately with the same key: $c_{j}=E_{k}(m_{j})$.
* It is the simplest mode but is insecure for many applications because identical plaintext blocks result in identical ciphertext blocks, revealing patterns in the data.

#### Cipher-Block Chaining (CBC)

* This mode introduces dependency between blocks. Each plaintext block is XORed with the *previous ciphertext block* before encryption.
* An **Initializing Vector (IV)** is used to XOR with the first plaintext block.
* Formulas: $c_{1}=E_{k}(m_{1}\oplus IV)$ and $c_{j}=E_{k}(m_{j}\oplus c_{j-1})$.

#### Cipher Feedback (CFB)

* This mode allows a block cipher to act like a stream cipher, encrypting smaller units of data (e.g., $r$ bits, where $r < n$, the block size).
* It encrypts the previous ciphertext block (or IV for the first step), and the result is XORed with the current plaintext block to produce the current ciphertext.
* Formula: $C_{i}=E_{k}(C_{i-1})\oplus P_{i}$, with $C_{0}=IV$.

#### Output Feedback (OFB)

* This mode also turns a block cipher into a stream cipher. It generates a keystream by repeatedly encrypting an initial value (the IV).
* The keystream is generated independently of the plaintext and ciphertext. The plaintext is then XORed with this keystream.
* Formulas: $O_{i}=E_{k}(O_{i-1})$ with $O_{0}=IV$, and then $C_{i}=P_{i}\oplus O_{i}$.
