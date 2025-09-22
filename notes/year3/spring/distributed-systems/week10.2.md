# Week10.2: Security - Keys, Digital Signatures and Certificates II
## Notes
---
### Asymmetric Key Cryptography

- Involves two distinct keys: a **public key** (shared openly) and a **private key** (kept secret).
    
- Solves the problem of securely transmitting a shared secret in symmetric cryptography.
    
- Properties:
    
    - A message encrypted with a **public key** can only be decrypted with the corresponding **private key**.
        
    - A message encrypted with a **private key** can only be decrypted using the **public key**.
        
- Ensures:
    
    - **Confidentiality** (public key encryption).
        
    - **Authentication** (private key signing).
        

---

### Public Key Usage in Communication

- The **receiver** generates a key pair and publishes the **public key**.
    
- The **sender** uses the receiver's **public key** to encrypt the message.
    
- Only the receiver can decrypt it with their **private key**.
    
- Used for secure data exchange over **unsecure channels**.
    

---

### Applications of Asymmetric Cryptography

- **Encrypted Communication**: Ensures message privacy by encrypting with the receiver’s public key.
    
- **Authentication / Digital Signature**:
    
    - The sender uses their **private key** to create a digital signature.
        
    - The receiver uses the sender's **public key** to verify authenticity.
        
- **Key Exchange**:
    
    - Asymmetric encryption is used to share symmetric keys securely.
        

---

### Requirements for Asymmetric Key Systems

- Easy to generate a **key pair**.
    
- Efficient encryption/decryption processes.
    
- Hard to compute the **private key** from the **public key**.
    
- Infeasible to recover plaintext from ciphertext without the private key.
    
- Either key can encrypt; the other must decrypt (duality).
    

---

### RSA Public-Key Cryptosystem

#### Overview

- Developed by **Rivest, Shamir, and Adleman** in 1977.
    
- Widely used for:
    
    - **Encryption**
        
    - **Digital signatures**
        
    - **Key exchange**
        
- A **block cipher** using modular arithmetic.
    

#### RSA Encryption and Decryption

- **Public Key**: e,n{e, n}e,n
    
- **Private Key**: ddd
    
- **Encryption**: C=Memod  nC = M^e \mod nC=Memodn
    
- **Decryption**: M=Cdmod  nM = C^d \mod nM=Cdmodn
    
- Works with integers: plaintext and ciphertext are numbers in range [0, n−1].
    

---

### RSA Key Generation

#### Steps

1. **Select two large prime numbers**, ppp and qqq
    
2. Compute n=p×qn = p \times qn=p×q
    
3. Compute Euler’s Totient Function:
    
    - ϕ(n)=(p−1)(q−1)\phi(n) = (p - 1)(q - 1)ϕ(n)=(p−1)(q−1)
        
4. Choose encryption exponent eee:
    
    - 1<e<ϕ(n)1 < e < \phi(n)1<e<ϕ(n)
        
    - eee must be **relatively prime** to ϕ(n)\phi(n)ϕ(n) (i.e., gcd(e,ϕ(n))=1gcd(e, \phi(n)) = 1gcd(e,ϕ(n))=1)
        
5. Compute decryption exponent ddd:
    
    - d≡e−1mod  ϕ(n)d \equiv e^{-1} \mod \phi(n)d≡e−1modϕ(n) (i.e., demod  ϕ(n)=1de \mod \phi(n) = 1demodϕ(n)=1)
        

#### Result

- **Public key**: e,n{e, n}e,n
    
- **Private key**: ddd
    

#### RSA Example

- p=11p = 11p=11, q=3q = 3q=3 ⇒ n=33n = 33n=33
    
- ϕ(n)=(11−1)(3−1)=10×2=20\phi(n) = (11 - 1)(3 - 1) = 10 \times 2 = 20ϕ(n)=(11−1)(3−1)=10×2=20
    
- Choose e=3e = 3e=3, d=7d = 7d=7 since 3×7=21≡1mod  203 \times 7 = 21 \equiv 1 \mod 203×7=21≡1mod20
    
- Encrypt: M=5M = 5M=5, C=53mod  33=26C = 5^3 \mod 33 = 26C=53mod33=26
    
- Decrypt: C=26C = 26C=26, M=267mod  33=5M = 26^7 \mod 33 = 5M=267mod33=5
    

---

### RSA Cryptanalysis

#### Threats

1. **Brute Force**:
    
    - Try every possible private key.
        
    - Defense: use large key sizes (e.g., 2048 bits).
        
2. **Factoring Attack**:
    
    - RSA security relies on difficulty of factoring large nnn.
        
    - If ppp and qqq are discovered, private key can be derived.
        
    - 512-bit RSA can be broken with enough computing power (NSA level).
        
    - 1024-bit RSA is still currently secure.
        

---

### Digital Signatures

#### Purpose

- Ensure:
    
    - **Authentication**: identity of the sender.
        
    - **Integrity**: message not tampered with.
        
    - **Non-repudiation**: sender cannot deny authorship.
        

#### Basic Process

- Sender encrypts message or message digest using **private key**.
    
- Receiver decrypts using **public key** to verify authenticity.
    

---

### Digital Signatures and Message Digest

#### Why Use a Digest?

- Encrypting large messages is inefficient.
    
- Solution:
    
    - Create a **message digest** (hash) using a cryptographic hash function.
        
    - Encrypt digest with private key to create a **signature**.
        

#### Signature Creation

1. Compute D=hash(M)D = hash(M)D=hash(M)
    
2. Create signature S=encrypt(D,KPRIV)S = encrypt(D, K_{PRIV})S=encrypt(D,KPRIV​)
    
3. Send ⟨M,S⟩\langle M, S \rangle⟨M,S⟩
    

#### Signature Verification

1. Receiver computes D′=hash(M)D' = hash(M)D′=hash(M)
    
2. Decrypt SSS using sender’s public key: D=decrypt(S,KPUB)D = decrypt(S, K_{PUB})D=decrypt(S,KPUB​)
    
3. Compare DDD and D′D'D′. If equal, signature is valid.
    

---

### Message Authentication and Integrity

#### Authentication

- Sender signs the digest with their **private key**.
    
- Ensures message authenticity.
    

#### Integrity

- Receiver:
    
    - Computes digest from received message.
        
    - Compares it to the decrypted digest from the signature.
        
- If they match, the message has not been altered.
    

---

### MD5 Hash Function

#### Properties

- Produces a **128-bit** hash (32 hex digits).
    
- Designed by **Ronald Rivest (1991)**.
    
- Used for:
    
    - Data integrity checks
        
    - Digital signature support (deprecated)
        

#### Flaws

- **Not collision resistant**:
    
    - 1996: flaws discovered.
        
    - 2004: collisions demonstrated.
        
    - 2012: used in **Flame malware** to fake Microsoft signatures.
        
- **No longer suitable** for cryptographic use (replaced by SHA-2/SHA-3).
    

---

### Collision Resistance in Hash Functions

#### Definition

- A hash function is **collision resistant** if it's hard to find two inputs x1x_1x1​, x2x_2x2​ such that:
    
    - hash(x1)=hash(x2)hash(x_1) = hash(x_2)hash(x1​)=hash(x2​)
        

#### Practical Concern

- **SHA-256**: 256-bit output, but infinite input possibilities ⇒ collisions must exist.
    
- Good cryptographic hash functions make finding collisions computationally infeasible.
    

---

### Summary: Benefits of Digital Signatures

- Provide:
    
    - **Integrity** – Message content remains unchanged.
        
    - **Confidentiality** – Achieved when combined with encryption.
        
    - **Authentication** – Confirms sender’s identity.
        
    - **Non-repudiation** – Sender cannot deny sending the message.
        
- Signature is unique to both:
    
    - The sender (private key use)
        
    - The specific message (digest)