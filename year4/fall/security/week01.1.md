# Week 01.1: Introduction to Information Security

## Notes
---

### **1. Introduction to Information Security**

Information security is the process of preventing and detecting the unauthorised use of your information and the science of guarding information systems and assets against the malicious behaviours of intelligent adversaries.

- **Security vs. Reliability**: Security deals with intentional faults from intelligent adversaries, whereas reliability deals with accidental faults or failures.
- **Malicious Behaviours**: These can include:
    - **Fraud**: Deceiving someone to get money, goods, or services.
    - **Theft**: Stealing something from a person or place.
    - **Terrorism**: Causing damage, disruption, and intimidation.
    - **Vandalism**: Damaging or destroying something deliberately.
    - **Espionage**: Stealing information or commercial secrets.
    - **Sabotage**: Causing damage or destruction to gain an advantage.

---

### **2. Applications of Security**

Security and cryptography have many application examples across different sectors:

- **Home and Business**: mobile phones, DVD players, game consoles, prepayment electricity meters, Internet protocols (SSL, S/MIME, PGP, SSH), software license numbers, and door access cards.
- **Banking**: ATM (automatic teller machines) were the first large-scale commercial use of crypto. Other uses include card authentication codes, PIN verification, funds transfers, online banking, electronic purses, and cryptocurrencies.
- **Military**: Identify friend/foe systems, jamming resistant radios, weapon-system unlock codes, permissive action links for nuclear warheads, and navigation signals like GPS.

---

### **3. The Core Security Goals: The CIA Triad**

In 1973, James Anderson identified three types of security violations in computer systems:
1.  Unauthorised information release.
2.  Unauthorised information modification.
3.  Unauthorised denial of use.

These violations are countered by the three main goals for computer security, known as the CIA triad.

#### **3.1. Confidentiality**
* **Goal**: The prevention of unauthorised information release. It means information is accessible only to authorised users.
* **Violation Example**: An unauthorised user reads and copies encrypted passwords from a password file and then decrypts them offline using brute force.
* **Variants**: Variants of confidentiality include anonymity, copy protection, information flow control, unlinkability, and unobservability.

#### **3.2. Integrity**
* **Goal**: The prevention of unauthorised information modification. In computing, this means preventing unauthorised users from writing information they are not entitled to. In data communication, it involves the detection of modifications to transmitted data.
* **Violation Example**: An unauthorised user changes the password file, perhaps by inserting a new entry (a "backdoor") or by changing the root password.

#### **3.3. Availability**
* **Goal**: Ensuring that authorised users are not prevented from accessing information and associated assets when required.
* **Violation Example**: An internet 'flooding' attack, where attackers overwhelm a server by sending it large numbers of connection requests, causing a denial of service.

---

### **4. Additional Security Goals**

* **Authentication**: The process of verifying an identity claimed by or for a system entity.
* **Access control (Authorisation)**: The protection of system resources against unauthorised access.
* **Non-repudiation**: Protection against the false denial of involvement in a communication.

---

### **5. Security Analysis: Vulnerabilities, Threats, and Assets**

* **Assets**: What we want to protect, such as Hardware, Software, Data, and Users.
* **Vulnerability**: A flaw in the design or implementation of a computer system that could lead to a security violation. Examples include program bugs, configuration errors, and poor choice of passwords.
* **Threat**: A set of circumstances that could cause harm. An attack is performed by exploiting a vulnerability of the system.
* **Countermeasure**: An action, device, procedure, or technique that removes or reduces a vulnerability.

| Security Threat | Linked Goal   | Description                                           |
| :-------------- | :------------ | :---------------------------------------------------- |
| Interception    | Confidentiality | Unauthorized party gains access to data or services. |
| Interruption    | Integrity     | Service or data becomes unavailable or unusable.    |
| Modification    | Availability  | Unauthorized tampering of data or services.       |
| Fabrication     |               | Generation of additional data or activity.        |

---

### **6. How to Practice Security**

There are three intuitive strategies for security:

1.  **Prevention**: Take measures that prevent your assets from being damaged. For example, encrypting e-commerce orders.
2.  **Detection**: Take measures so that you can detect when, how, and by whom an asset has been damaged. For example, noticing an unauthorised transaction on your credit card statement.
3.  **Reaction**: Take measures so that you can recover your assets or recover from damage. For example, complaining about a fraudulent charge and asking for a new card number.

---

### **7. A 3-Step Method for Information Protection**

A method for tackling an information protection problem involves three steps:

#### **Step 1: Drawing up a threat model via security requirement analysis**
* Identify assets to be protected and their value.
* Identify vulnerabilities, threats, and risk priorities.
* Identify legal and contractual requirements.

#### **Step 2: Formulating a suitable security policy**
* The policy models what ought to be protected.
* It defines which activities are or are not authorised and which information flows are or are not prohibited.
* The policy should be precise, well-documented, and followed.

#### **Step 3: Implementing specific protection mechanisms to enforce the policy**
* Examples include:
    * Hardware protection mechanisms.
    * Secure operating systems.
    * Secure coding.
    * Capabilities and access control lists.
    * End user security training.
    * Response to breaches.
