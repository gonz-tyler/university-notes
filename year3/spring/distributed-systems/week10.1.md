# Week 10.1: Security - Keys, Digital Signatures and Certificates I
## Notes
---

### Introduction to Security Services

- **Security Services** are mechanisms that ensure the protection of data and communication systems from unauthorized access or modification.
    
- Key goals include:
    
    - **Confidentiality:** Ensuring that information is not disclosed to unauthorized individuals.
        
    - **Integrity:** Assuring that information has not been altered during transmission.
        
    - **Authentication:** Verifying the identity of the sender and/or receiver.
        
    - **Non-repudiation:** Ensuring that a sender cannot deny sending a message.
        
    - **Access Control:** Restricting access to resources only to authorized users.
        

---

### Symmetric Key Cryptography

- **Definition:** Both sender and receiver use the same secret key for encryption and decryption.
    
- **Key Characteristics:**
    
    - Fast and efficient.
        
    - Key must be shared securely beforehand.
        
    - Vulnerable if the key is intercepted.
        
- **Challenges:**
    
    - **Key distribution problem:** How to share the key securely without interception.
        
    - **Scalability:** With ‘n’ users, n(n−1)2\frac{n(n-1)}{2}2n(n−1)​ unique keys are needed for full pairwise communication.
        

---

### Asymmetric Key Cryptography (Public Key Cryptography)

- **Definition:** Uses a pair of keys – a public key (shared) and a private key (kept secret).
    
- **How It Works:**
    
    - Data encrypted with a public key can only be decrypted with the corresponding private key and vice versa.
        
- **Benefits:**
    
    - Solves the key distribution problem.
        
    - More scalable than symmetric systems.
        
- **Drawbacks:**
    
    - Computationally more intensive than symmetric cryptography.
        

---

### Public and Private Keys

- **Public Key:**
    
    - Widely distributed.
        
    - Used to encrypt data or verify digital signatures.
        
- **Private Key:**
    
    - Kept secret.
        
    - Used to decrypt data or create digital signatures.
        
- **Applications:**
    
    - Secure web communication (HTTPS).
        
    - Digital signatures.
        
    - Secure email.
        

---

### Digital Signatures

- **Purpose:** Provide authentication, data integrity, and non-repudiation.
    
- **How It Works:**
    
    1. Sender creates a hash of the message.
        
    2. The hash is encrypted with the sender's private key – this becomes the digital signature.
        
    3. Message and signature are sent together.
        
    4. Receiver decrypts the signature using the sender’s public key to retrieve the original hash.
        
    5. Receiver hashes the received message and compares it with the decrypted hash.
        
    6. If they match, the signature is valid.
        
- **Properties:**
    
    - Only the sender with the private key could have created the signature.
        
    - Ensures that the message was not altered.
        

---

### Hash Functions in Digital Signatures

- **Definition:** A hash function takes input data and produces a fixed-size string of characters (hash value).
    
- **Desirable Properties:**
    
    - **Deterministic:** Same input always produces the same output.
        
    - **Fast computation.**
        
    - **Pre-image resistance:** Difficult to reverse-engineer input from hash.
        
    - **Collision resistance:** Difficult to find two different inputs with the same hash.
        
    - **Avalanche effect:** A small change in input results in a significantly different hash.
        
- **Common Hash Algorithms:**
    
    - MD5 (deprecated due to vulnerabilities)
        
    - SHA-1 (also deprecated)
        
    - SHA-2 family (SHA-256, SHA-512 – widely used)
        
    - SHA-3 (newer standard)
        

---

### Message Authentication Code (MAC) vs Digital Signatures

- **MAC:**
    
    - Uses symmetric key cryptography.
        
    - Both sender and receiver share a secret key.
        
    - Provides data integrity and authentication.
        
    - Does **not** provide non-repudiation (since both share the same key).
        
- **Digital Signature:**
    
    - Uses asymmetric key cryptography.
        
    - Only sender signs with their private key.
        
    - Receiver verifies using sender’s public key.
        
    - Provides authentication, integrity, and **non-repudiation**.
        

---

### Applications of Digital Signatures

- **Email Security:** Sign emails to prove authenticity and integrity.
    
- **Software Distribution:** Verify that software hasn’t been tampered with.
    
- **Legal Documents:** Sign contracts digitally.
    
- **SSL/TLS Certificates:** Authenticate websites and secure communications.
    

---

### Summary

- Symmetric key encryption is fast but struggles with key distribution.
    
- Asymmetric encryption solves the key sharing problem but is slower.
    
- Digital signatures authenticate the source, ensure data integrity, and provide non-repudiation.
    
- Hash functions are crucial in digital signature schemes.
    
- MACs and digital signatures serve similar purposes but differ in their cryptographic foundations and properties.

