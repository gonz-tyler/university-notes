# Week 05.1: Certificates and PKI Revision Notes

---

## 1. The Problem: Binding Keys to Identities 

Asymmetric cryptography relies on public keys, but a major challenge is ensuring that a public key truly belongs to the person or entity you think it does.

-   **The Attack**: An attacker could substitute their own public key for a legitimate one. For example, they could alter a public key published on a website. Anyone using this fake key to encrypt messages would unknowingly allow the attacker to decrypt them.
-   **The Solution**: We need a secure way to **bind** an identity (like a person's name or a website's domain) to a public key. This is achieved using **digital certificates**.

---

## 2. Digital Certificates

A **public key certificate** is a digital document that serves as a proof of identity. Think of it as a digital passport for the online world.

### What's in a Certificate?

A certificate contains three key pieces of information:
1.  The **identity** of the entity (the "subject," e.g., `www.abdn.ac.uk`).
2.  The **public key** belonging to that entity.
3.  A **digital signature** from a trusted third party, which vouches for the authenticity of the information.

### Certificate Authorities (CAs)

The trusted third party that signs and issues certificates is called a **Certificate Authority (CA)**.

-   **Role of a CA**: A CA's job is to verify an entity's identity *before* issuing a certificate. By signing the certificate with its own private key, the CA is making a verifiable statement: "We have checked the identity of this subject, and we certify that this public key belongs to them."
-   **The Trust Problem**: This system works only if you trust the CA. We've shifted the problem from trusting millions of individual public keys to trusting a smaller number of reputable CAs.

### The Chain of Trust

How do you trust the CA's public key? It is certified by another, higher-level CA. This creates a **certificate chain**.

-   An end-entity certificate (like for a website) is signed by an intermediate CA.
-   That intermediate CA's certificate is signed by a higher-level CA.
-   This chain continues until it reaches a **Root CA**.

A **Root CA** is a top-level authority that is implicitly trusted. The public keys of major root CAs are pre-installed in your operating system and web browser, forming the foundation of the trust model.

---

## 3. Public Key Infrastructure (PKI)

A **Public Key Infrastructure (PKI)** is the entire system of hardware, software, people, policies, and procedures needed to create, manage, distribute, use, store, and revoke digital certificates.

### Key Components of a PKI

1.  **Certificate Authority (CA)**: The core component that issues and revokes certificates.
2.  **Registration Authority (RA)**: An entity that acts as a front-end for the CA. The RA's job is to verify the identity of a certificate applicant before the CA issues the certificate.
3.  **Validation Authority (VA)**: A service that a user can query to check the current status of a certificate (i.e., whether it has been revoked). This is often more efficient than downloading large revocation lists.
4.  **Certificate Owner/Subject**: The person or organization to whom the certificate is issued.
5.  **Relying Party**: The person or application that uses a certificate to verify a signature or establish a secure connection.

### Certificate Revocation

Certificates have a set validity period (e.g., one year). However, sometimes a certificate must be invalidated before its expiration date, for example, if the associated private key has been compromised.

-   This is done via a **Certificate Revocation List (CRL)**. A CRL is a digitally signed list, published by a CA, containing the serial numbers of all certificates it has revoked. Browsers and applications can check this list to ensure a certificate is still valid.

---

## 4. X.509 and PKI Trust Models

**X.509** is the most widely used standard that defines the format of public key certificates.

### X.509 Certificate Format

An X.509 certificate contains several standard fields, including:
-   **Version**: The X.509 version (usually v3).
-   **Serial Number**: A unique number assigned by the CA.
-   **Signature Algorithm**: The algorithm used by the CA to sign the certificate.
-   **Issuer Name**: The identity of the CA that issued the certificate.
-   **Validity Period**: The start and end dates for which the certificate is valid.
-   **Subject Name**: The identity of the certificate owner.
-   **Subject Public Key**: The public key being certified.
-   **CA's Signature**: The digital signature of the CA, covering all the fields above.

### PKI Trust Models

There are different ways to structure the relationships between CAs.

1.  **Strict Hierarchy**: A single Root CA sits at the top of a tree structure. It certifies a set of intermediate CAs, which in turn can certify other CAs or end-entities. This is the primary model used for the web (SSL/TLS).
2.  **Mesh Model**: In this model, there are multiple Root CAs. These roots trust each other through **cross-certification**, where each root CA issues a certificate for every other root CA. This creates a "web of trust" rather than a strict hierarchy.
