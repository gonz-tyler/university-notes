# Tutorial 06: Basic Authentication and User Authentication

**Instructions:**

- **[R]** = Review question (covered in lectures).
- **[C]** = Challenge question (harder).
- **[O]** = Open-ended question.
- **[M]** = Moderate.

---

## Part 1: General Questions

### Question 1 [R]

Explain the three main user authentication factors.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 2

A smart card is a small piece of electronic equipment that can be used to provide cryptographic authentication services. Iris recognition scans are a form of biometric authentication.

Which of the following are, or are not, examples of **two-factor authentication**?

- (a) The use of a password and a PIN (personal identification number).
- (b) The use of a password and a smart card.
- (c) The use of a smart card and a cryptographic key embedded in a corporate laptop (with an accompanying certificate).
- (d) The use of an iris scan and the use of a smart card.
- (e) The use of a fingerprint and iris recognition.
- (f) The use of a fingerprint and a password.

<details>
<summary>**Answer:**</summary>

> - (a)
> - (b)
> - (c)
> - (d)
> - (e)
> - (f)
</details>

### Question 3 [R]

Why is authentication important for accountability in an IT system?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 4

Users authenticate to log in to a computer or use some service. They may then leave their machine unlocked, or not actually use the service. This introduces a vulnerability in that there is a window of exposure where an attacker may use the authenticated session to misbehave.

What timing-related general security (and access control) concern is this an example of?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 5

What was the bootstrap mechanism used for getting you your University authentication details?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 6

**Scenario:** A company allowed users to use passwords that were no longer acceptable given its critical security needs. The company originally had a small staff handling credential recovery. Over time, they adopted policies requiring:

- More passwords
- More complicated passwords
- More frequent changes
- No re-use of passwords between systems

What do you think might have been the unintended consequences?

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 2: Passwords

### Question 1

Using a password authentication system alone, is there any way of telling the difference between a user who has legitimate access, and an attacker who has obtained a legitimate user's password?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 2

**Context:** In the ASCII character set there are 256 characters. However, only 128 of these are printable. Assume that on some system, passwords can be made up of precisely the printable ASCII characters.

**(a)** How many passwords are there of length exactly 6, 8, 10, 12 in the ASCII character set?
_Give your answer in decimal as well as an expression in powers of 2._

| Length | Decimal Size | Powers of 2 |
| :----- | :----------- | :---------- |
| 6      |              |             |
| 8      |              |             |
| 10     |              |             |
| 12     |              |             |

**(b)** Most users will never consider using most ASCII characters. They will instead use "easily accessible" characters ($a-z, A-Z, 0-9$, and maybe 30 punctuation symbols).

- How many easily accessible characters are there?
- How many passwords of length between 8 and 12 (inclusive) are there?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** Are all easily accessible characters equally likely to be used by users?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 3

It is sometimes proposed that users should use **passphrases** instead of passwords, where passwords are made by picking a few random words from a dictionary.
If the dictionary is large enough, only a very few words, say $m$ of them, generate more possible phrases than there are characters in a password with more characters.
Say the password is length $n$. So we will have $d^{m} > c^{n}$ where $d$ is the number of words in the dictionary and $c$ is the number of characters in the alphabet.

Pick a practical hole in this scheme regarding expected real use by users.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 4 [R]

Some distributed systems have a system of **single sign-on (SSO)**. The user authenticates once, and this allows them to access multiple resources without having to re-authenticate.

Discuss the trade-offs involved in single sign-on on some network domain, compared with:

- (a) A system where users are required to have separate passwords for different services on the domain.
- (b) A system where they have one set of credentials for the entire domain, but have to re-authenticate for each service they request.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 5

You are a vendor shipping WLAN access points. Access to these points is protected by password. Discuss the trade-off, for you, between shipping the kit with **default** or **individual** passwords.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 6 [O]

Passwords are entered by users and checked by computers. Thus there has to be some communication between users and computers. So far, we have taken the very abstract view of this channel and assumed that it exists and that it is adequately secure.

When is this assumption justified? When is it not?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 7 [R]

Why do complete passwords often not need to be stored on systems to which users are authenticating (even when passwords are the only means of authentication)? What advantages are there in not storing passwords?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 8 [R]

What are the differences between a dictionary attack and a brute force attack?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 9

Much of cryptanalysis is about search. There is a time-memory trade-off in many search algorithms. Explain why **brute-force guessing** lies at one extreme end of a cryptanalytic trade-off, whilst use of a **complete lookup table** of all possible passwords lies at the other.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 10

In modern Windows (NT through Windows 10), passwords are stored in the Security Account Manager (SAM). Below is an abridged excerpt from an old SAM. It shows usernames $u$ together with their password hashes $h$ and salts $s$, separated by colons in the format $u:h:s$.

```text
testuser1:"":0F20048EFC645D0A179B4D5D6690BDF3:1120ACB74670C7DD46F1D3F5038A5CE8:::
remote:"":E52CAC67419A9A224A3B108F3FA6CB6D:8846F7EAEE8FB117AD06BDD830B7586C:::
joeuser:"":E52CAC67419A9A224A3B108F3FA6CB6D:8846F7EAEE8FB117AD06BDD830B7586C:::
averageguy:"":299CCF964D9A359BAAD3B435B51404EE:A5C07214487C87B584E8877DE72DCA0B:::
```

**(a)** What do you observe?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** What would you first guess would be the reason?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** What standard technique could have solved this problem?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 11

In a **pass-the-hash attack**, an attacker obtains a hash of authentication data (e.g., a password from a password file). They then find systems that accept the hash of the authentication data, rather than the original data.

If a system only possesses password hashes (and not a copy of the original password), explain why possession of the hash (say by an attacker) is functionally equivalent to, and therefore as good as, possession of the password.

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 3: Alternative Authentication Methods

### Question 1

Biometric authentication systems use biometric data for identification. This usually involves turning detailed analogue data into less informative digital data.

**(a)** What are the implications of failure to enroll or situations where a user's biometrics change?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** When would it be better to err on the side of reducing **false negatives**, and when might it be better to err on the side of reducing **false positives**?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** If your password is stolen you can change it. What is a related fundamental problem with biometric authentication data?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 2

Smart cards are often used to provide user authentication. They communicate with a Card Authentication Device (CAD).

**(a)** What does the CAD rely upon regarding possession of the card?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** In the challenge-response phase, various protocols can be used. Sometimes symmetric schemes have been used. What difficulty can you see in this?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c) [C]** A more common alternative is to use a public-key scheme. The card has a private key pre-installed. It 'signs' the challenge by encrypting with the private key, and the CAD can verify with the public key.

Explain the contents of the diagram/protocol described above. Make sure to explain the need for, and the role of, the **certificate**, and suggest how it might be verified.

<details>
<summary>**Answer:**</summary>

>
</details>

**(d) [C]** Some smart card uses also require the user to input a PIN on the CAD. The PIN is passed from the CAD to the smart card. The card compares the PIN to a reference number stored in its memory.

**i.** Why does recording the PIN on the smart card introduce a vulnerability?

<details>
<summary>**Answer:**</summary>

>
</details>

**ii.** How do you think this risk is often mitigated?

<details>
<summary>**Answer:**</summary>

>
</details>

**iii.** Given the answer to part (ii), suppose that the same message is sent every time from the CAD to the smart card. Why is this potentially vulnerable?

<details>
<summary>**Answer:**</summary>

>
</details>

**iv.** Biometrics can also be used with smart cards. If the biometric data is _not_ stored on the card, the smart card is simply notified that the biometric authentication (via a Biometric Reading Device) has been successful. In both cases, the CAD should then have to authenticate to the smart card (mutual authentication). What vulnerability does this address?

<details>
<summary>**Answer:**</summary>

>
</details>
