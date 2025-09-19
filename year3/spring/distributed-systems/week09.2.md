# Week 09.2: Security Cryptology

## Notes
---

### What is Cryptology?

Cryptology = Cryptography + Cryptanalysis

- **Cryptography**: Art and science of securing communication.
- **Cryptanalysis**: Art and science of breaking cryptographic systems.

---

### Why Use Cryptography?

- Protect messages from being read or tampered with by third parties.
- Typical scenario: **Alice and Bob** communicating, while **Eve** (an eavesdropper) tries to intercept.

---

### Basic Terminology

- **Plaintext**: Original message.
- **Ciphertext**: Encrypted message.
- **Encryption algorithm**: Transforms plaintext → ciphertext.
- **Decryption algorithm**: Transforms ciphertext → plaintext.
- **Key**: Controls the transformation.

> No cipher should rely on the secrecy of the algorithm – only the key.
> 

---

### Cipher Types

#### Transposition Ciphers

- Reorders characters based on a scheme.
- **Columnar Transposition**:
    - Text arranged in rows, columns scrambled using a key.
    - Decryption: recreate matrix, reverse column order.

#### Substitution Ciphers

- Replace plaintext symbols with other symbols.
- **Mono-alphabetic**: Fixed mapping throughout the message.
    - **Caesar Cipher**: Shifts alphabet by a fixed number.
    - **Keyed substitution**: Based on keyword.
    - **Random substitution**: Random alphabet mapping.

---

### Example: Columnar Transposition

Key: `SECRET` = 6 letters → 6 columns

Plaintext: `MESSAGE FROM MARY STUART KILL THE QUEEN`

Readout order (alphabetical order of key): `5 2 1 4 3 6`

Resulting Ciphertext:

`SRYTHNEFRRTEAMTIQSOSKEMEAALEGMULU`

---

### Decrypting Columnar Transposition

Steps:

- Determine number of rows = ceil(len(ciphertext) / key length)
- Account for empty spaces in the last row.
- Fill columns based on key order.
- Read row by row to get original message.

---

### Substitution Cipher Types

#### Caesar Cipher

- Shifts alphabet letters by a fixed amount.
- Example:
Key = 3 → `A → D`, `B → E`, ...

#### Key Phrase Substitution

- Uses keyword to generate cipher alphabet (no duplicates).
- Followed by unused letters in alphabetical order.

#### Random Substitution

- Completely randomized mapping of alphabet.
- 26! possible combinations.

---

### Cryptanalysis: Frequency Analysis

- English has predictable letter frequencies (E, T, A... most common).
- Breaks mono-alphabetic substitution ciphers easily.

Techniques:

- Analyze frequencies of single letters, digraphs, trigraphs.
- Guess likely mappings.
- Use context and word structure.

---

### Advanced Substitution

#### Polygram Substitution

- Replace **n-grams** (e.g., digrams, trigrams)

#### Homophonic Substitution

- One plaintext letter maps to **multiple ciphertext symbols**

---

### Poly-alphabetic Substitution

- Use **multiple mono-alphabetic ciphers**
- Example: **Vigenère Cipher**
    - Keyword determines which alphabet to use
    - Cipher is periodic based on key length

---

### Vigenère Cipher

- Each letter in the plaintext is encrypted using a shifted alphabet
- Keyword repeated to match plaintext length
Example:

```
Plaintext:  MESSAGE FROM MARY STUART KILL THE QUEEN
Key:        WHITEWH ITEWHITEWHITEWHITEWHITEWHITEWH
```

### Breaking Vigenère Cipher

Steps:

- Look for repeating digraphs.
- Measure distance between repeats → key length.
- Use frequency analysis on each substring encrypted with same alphabet.

---

### One-Time Pad

- Perfect encryption:
    - Key is as long as the message
    - Completely random
    - Never reused

➡ Guarantees **unbreakable** encryption.

---

### Cryptographic Strength & Attacks

#### Attack Models:

1. **Ciphertext-only attack**
2. **Known-plaintext attack**
3. **Chosen-plaintext attack**

---

### Modern Cryptography

- Uses binary operations (e.g., XOR)
    - `0 ⊕ 0 = 0`, `1 ⊕ 0 = 1`, `0 ⊕ 1 = 1`, `1 ⊕ 1 = 0`

Example:

```
Plaintext:  DEAD (1101111010101101)
Key:        BEEF (1011111011101111)
Ciphertext:        0110000001000010 = 6042
```

---

### Symmetric Key Encryption

- Same key for **encryption and decryption**
- Must be shared securely
- Still widely used in secure communications (e.g., AES)

---

### Secure Key Exchange Challenges

- One-time pads are impractical for general use
- Symmetric keys must be distributed safely
- Public-key infrastructure (PKI) often used for secure exchange

---

### Summary Table

| Topic | Description |
| --- | --- |
| Cryptology | Cryptography + Cryptanalysis |
| Transposition Cipher | Reorders plaintext using a key-based scheme |
| Substitution Cipher | Replaces letters with other symbols |
| Frequency Analysis | Exploits letter frequency in language |
| Vigenère Cipher | Poly-alphabetic substitution |
| One-Time Pad | Unbreakable encryption with random long key |
| Symmetric Key Encryption | Same key for encrypt/decrypt |
| XOR Operation | Common in bitwise cryptography |
