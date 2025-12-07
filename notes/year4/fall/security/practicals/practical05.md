# Tutorial 05: Digital Signatures, Zero Knowledge, and Certificates

**Instructions:**

- **R** = Review question (look it up in notes)
- **E** = Easy (simple application)
- **M** = Moderate (takes some thought)
- **H** = Harder (takes a lot of thought)
- **O** = Open-ended

---

## Part 1: RSA Signatures

### Question 1 [R, *]

Name five properties for which a (handwritten or digital) signature should provide assurance.

How do these relate to the following standard information security terminology:

- **Message integrity** (the message is not altered after signing)
- **Message origin** (the message was signed by the claimed signer)
- **Non-repudiation** (the message signer cannot claim that he/she did not sign the message)

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 2 [R, *]

Name the parts of a digital signature scheme.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 3 [R]

What is the verifiability property?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 4 [R]

Explain a typical protocol for the use of digital signatures in signing a document, and sending the document and signature to a receiver.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 5 [R, *]

**(a)** Are RSA and ElGamal signature schemes randomized or deterministic? What does this mean?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** Is ElGamal an appendix or message recovery scheme? Explain what this means.

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** Explain how RSA is fundamentally a message recovery scheme, but can also be used to make an appendix scheme.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 6 [R, *]

Prove that if you take a message and construct its RSA signature, then the scheme will in fact verify that it is the correct signature. (You may do this with or without hashing).
Comment on the similarity of this proof and the proof that RSA encryption-decryption successfully works.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 7 [M]

Consider an RSA digital signature scheme without hashing.
Alice tricks Bob into signing messages $m_{1}$ and $m_{2}$ such that $m = m_{1}m_{2} \pmod N$.

**(a)** Prove that Alice can forge Bob's signature on $m$.

<details>
<summary>**Proof:**</summary>

>
</details>

**(b)** Explain why using a signing protocol that involves hashing before signing disrupts this attack.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 8 [R]

Prove that if you take a message and construct its ElGamal signature, then the verification process will indeed accept the signature as correct.

<details>
<summary>**Proof:**</summary>

>
</details>

---

### Question 9 [H]

**Context:** In this exercise, we show that for ElGamal signatures, messages should not be signed without being hashed.
Suppose that there is a legitimate signer, $S$, with signing key $(p, g, y)$. We will show that an attacker can construct a message $m$ and a valid signature for it $(r, s)$ despite not knowing $S$'s private signing key $x$.

**Procedure:**

1.  Select any positive integers $u, v$.
2.  Compute $r = g^{u}y^{v} \pmod p$.
3.  Define $s$ by $sv + r \equiv 0 \pmod{p-1}$.
4.  Compute $m = su \pmod{p-1}$.

**(a)** Verify that $(r, s)$ is a valid signature for $m$.
_Hint: use the fact $g^{p-1} \equiv 1 \pmod p$._

<details>
<summary>**Verification:**</summary>

>
</details>

**(b)** Explain why this means there is an existential forgery attack. Why is using a hash likely to defeat such attacks?

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 2: Zero Knowledge Proofs

### Question 1 [R]

What are the properties that a Zero knowledge protocol should have?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 2 [R, *]

Describe in detail the simplified Feige-Fiat-Shamir accreditation scheme between Peggy (the Prover) and Victor (the Verifier).

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 3 [R, *]

Consider the simplified Feige-Fiat-Shamir scheme with parameters $n=15$, and random number $r=11$.
Trace with these values the contents of all the messages that Peggy and Victor will send/receive.

<details>
<summary>**Trace:**</summary>

>
</details>

---

### Question 4 [R, *]

Consider the Feige-Fiat-Shamir scheme with parameters $n=35$.

**(a)** Find all possible public keys $(v)$ and corresponding private keys $(s)$.

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** Choose a random key $(r)$ for Peggy and the random string for Victor yourself. Using these values, trace through the entire protocol by detailing the contents of all messages exchanged between Peggy and Victor.

<details>
<summary>**Trace:**</summary>

>
</details>

---

### Question 5 [M]

Zero-knowledge protocols can also be used to construct signature schemes.
Construct a signature scheme from the Feige-Fiat-Shamir identification protocol by replacing the challenge $(b_{1},...,b_{k})$ with a hash value $h(m, x)$.

Specify the signing and the verification algorithm.

<details>
<summary>**Signing Algorithms:**</summary>

>
</details>

<details>
<summary>**Verification Algorithm:**</summary>

>
</details>

---

## Part 3: Certificates

### Question 1 [R, *]

What is the purpose of a public key certificate? What three components do they contain?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 2 [R, *]

Explain why chains of certificates are often needed, and where and how they terminate furthest from the end user.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 3 [R, *]

Is possession of a public key certificate sufficient to identify an entity as the owner of the corresponding private key?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 4 [R, *]

**(a)** Explain how a signature can be used in a challenge-response authentication mechanism.

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** How does this rely upon the authenticity of keys? How might this be assured?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 5 [R]

Explain how two parties, A and B who both trust a certificate authority (CA), can use it as a key certification centre to set up communications with a shared symmetric key.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 6 [O]

**Activity:** Fire up a web browser. Find the 'preferences' or 'settings'. See if you can find the certificates for ordinary servers and for certificate authorities. Try to view information about them.

How does this match the information that you were given in lectures?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 7 [H]

Suppose that A and B wish to do a Diffie-Hellman key exchange. Suppose that they each have separate public-private key pairs (say for RSA), and that each knows the correct public-key for the other.

**(a)** Set up a protocol that sends signed versions of the Diffie-Hellman data in order to defeat the basic man-in-the-middle attack.

<details>
<summary>**Protocol:**</summary>

>
</details>

**(b)** Suppose that the signature keys might be unreliable. Explain how a new attack could now take place.

<details>
<summary>**Attack Scenario:**</summary>

>
</details>

**(c)** Suppose that there is a trusted third party that can reliably sign certificates for the signature keys. Explain how to modify your protocol messages to include these signatures so that the new attack fails.

<details>
<summary>**Modified Protocl:**</summary>

>
</details>

---

### Question 8 [M]

Certificates are sometimes revoked (e.g., when keys are lost, expired, or untrusted) using Certificate Revocation Lists (CRLs).
Consider a guard entity, G, for a system, S, that uses certificates in the authentication process, but which is temporarily unable to read any certificate revocation list.

**(a)** If preventing undesired access to a system resource is critical to S, what might G be designed to do?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** If availability of the resource is critical for S, then what might G do?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** If both are important, then what does this tell us about CRLs and their security?

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 4: PKI, PKIX

### Question 1 [R, *]

What is a PKI? Give at least two different examples of use.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 2 [R, *]

Explain (briefly) how the signature field on an X.509 (v3) certificate depends upon the fields preceding it.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 3 [R, *]

Outline, at a high level, how an X.509 public key certificate is verified.
_(Complete technical details are not required; assume the certificate has not been revoked and external keys are trusted)._

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 4 [E, *]

What problems might occur for an end user if they install either an OS or a browser with fake root certificates (certificates purporting to be for genuine root entities, that are really for different entities)?

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 5 [R]

Explain how the need to verify one certificate can result in a whole chain of certificates being verified. (You can assume your answer to Question 3 is already in place).

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 6 [R, E]

Explain why the CA critical extension field is essential for the X.509 system not to be easily compromised.

<details>
<summary>**Answer:**</summary>

>
</details>

---

### Question 7 [E]

Outline one possible application of the **shell model** and one possible outline for the **chain model** for handling certificate expiry.

<details>
<summary>**Shell Model Application:**</summary>

>
</details>
<details>
<summary>**Chain Model Outline:**</summary>

>
</details>
