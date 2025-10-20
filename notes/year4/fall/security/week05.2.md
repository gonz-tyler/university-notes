# Week 05.2: Authentication Revision Notes

---

## 1. Introduction to Authentication

User authentication is a fundamental security process that controls access to resources and holds users accountable for their actions. It consists of two distinct steps:

1.  **Identification**: The act of claiming an identity (e.g., entering your username). You are announcing who you are.
2.  **Authentication**: The act of proving that claim (e.g., entering your password). You are proving you are who you say you are.

### Authentication Factors

There are three main categories of factors used to prove an identity:

1.  **Something you know**: A secret piece of information like a password or a PIN.
2.  **Something you have**: A physical object like a key, a smart card, or a one-time password token.
3.  **Something you are (Biometrics)**: A unique physical or behavioral characteristic like a fingerprint, iris pattern, or voiceprint.

**Multi-Factor Authentication (MFA)** significantly enhances security by requiring proof from two or more of these different categories.

---

## 2. Authentication by "Something You Know": Passwords

Passwords are the most common form of authentication. They are easy to implement but come with significant security challenges.

### How Passwords Work

-   **Password Storage**: A system should **never** store passwords in plaintext. Instead, when a user creates a password, it is passed through a **one-way hash function**. The system stores the user's ID and the resulting hash.
-   **Login Process**: When the user logs in, the password they enter is hashed using the same function, and the result is compared to the stored hash. If they match, access is granted.

### Password Vulnerabilities and Attacks

* **Weak User Habits**: Users often choose easy-to-guess passwords, write them down, or reuse them across multiple services.
* **Brute-Force Attack**: The attacker tries every possible combination of characters until the correct password is found. The effectiveness of this is limited by password length and complexity.
* **Dictionary Attack**: A more targeted attack where the attacker tries a list of common words, names, and simple variations. This can be done:
    * **Offline**: If an attacker steals the password file, they can run a dictionary attack very quickly on their own machine.
    * **Online**: The attacker tries to log in directly, which is slower and risks account lockout.

### Countermeasure: Salting

**Salting** is a technique to make offline dictionary attacks much less effective.

1.  **Process**: Before hashing a user's password, a unique, random string called a **salt** is appended to it.
2.  **Storage**: The system stores the user's ID, their unique salt, and the hash of `(password + salt)`.
3.  **The Benefit**: Salting ensures that even if two users have the same password, their stored hashes will be different. This means an attacker cannot just compute the hash of a common password once and check it against the entire stolen password file. They must re-hash the password with each user's unique salt, making the attack **much slower**. It also defeats pre-computed "rainbow tables."

### Other Attacks

* **Spoofing / Phishing**: Tricking a user into entering their credentials on a fake login page that looks like the real one.
* **Shoulder-Surfing**: Directly observing someone typing their password.
* **Keyloggers**: Malicious software that records keystrokes.

---

## 3. Authentication by "Something You Have": Tokens

This method relies on the user possessing a physical object. A common example is a **time-based one-time password (TOTP) token**.

-   **How it Works**: The user has a physical device (or an app) that displays a short code (e.g., 6 digits). This code changes at regular intervals (e.g., every 60 seconds) and is synchronized with the server.
-   **Usage**: To log in, the user provides something they know (a PIN) plus the current code from their token. This combines two factors for stronger security.

---

## 4. Authentication by "What You Are": Biometrics

Biometrics uses the measurement and statistical analysis of unique biological or behavioral traits for authentication.

### Verification vs. Identification

Biometric systems operate in two modes:

1.  **Verification (1-to-1)**: The user claims an identity, and the system performs a one-to-one comparison to verify if the presented biometric matches the stored template for that identity. The question is: "Are you who you say you are?"
2.  **Identification (1-to-many)**: The system performs a one-to-many comparison, searching an entire database to find a match for the presented biometric. The question is: "Who are you?"

### Failure Rates and The Tolerance Threshold

Because biometric measurements are never perfectly identical, the system must use a **tolerance threshold** to decide if a new scan is a "match" to a stored template. This creates a trade-off between two types of errors:

* **False Rejection Rate (FRR) - Type I Error**: A legitimate, authorized user is incorrectly rejected. This is an inconvenience.
* **False Acceptance Rate (FAR) - Type II Error**: An unauthorized impostor is incorrectly accepted. This is a security breach.

The relationship between these errors is inverse:
-   A **high threshold** (very strict) reduces the FAR but increases the FRR, making the system more secure but less convenient.
-   A **low threshold** (very lenient) reduces the FRR but increases the FAR, making the system more convenient but less secure.

The **Equal Error Rate (EER)** is the point where the FAR and FRR are equal. It's a common metric used to compare the overall accuracy of different biometric systems.
