# Week 1.1: Introduction to Information Security

## Notes
---

Markdown

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
- **Banking**: ATM (automatic teller machines) were the first large-scale commercial use of crypto. Other uses include card authentication codes, PIN verification, funds transfers, online banking, electronic purses, and cryptocurrencies[cite: 76].
- **Military**: Identify friend/foe systems, jamming resistant radios, weapon-system unlock codes, permissive action links for nuclear warheads, and navigation signals like GPS.

---

### **3. The Core Security Goals: The CIA Triad**

[cite_start]In 1973, James Anderson identified three types of security violations in computer systems[cite: 93]:
1.  [cite_start]Unauthorised information release[cite: 94].
2.  [cite_start]Unauthorised information modification[cite: 95].
3.  [cite_start]Unauthorised denial of use[cite: 96].

[cite_start]These violations are countered by the three main goals for computer security, known as the CIA triad[cite: 128].

#### **3.1. Confidentiality**
* [cite_start]**Goal**: The prevention of unauthorised information release[cite: 129]. [cite_start]It means information is accessible only to authorised users[cite: 129].
* [cite_start]**Violation Example**: An unauthorised user reads and copies encrypted passwords from a password file and then decrypts them offline using brute force[cite: 115, 116].
* [cite_start]**Variants**: Variants of confidentiality include anonymity, copy protection, information flow control, unlinkability, and unobservability[cite: 141].

#### **3.2. Integrity**
* [cite_start]**Goal**: The prevention of unauthorised information modification[cite: 130]. [cite_start]In computing, this means preventing unauthorised users from writing information they are not entitled to[cite: 146]. [cite_start]In data communication, it involves the detection of modifications to transmitted data[cite: 148].
* [cite_start]**Violation Example**: An unauthorised user changes the password file, perhaps by inserting a new entry (a "backdoor") or by changing the root password[cite: 122, 123, 124].

#### **3.3. Availability**
* [cite_start]**Goal**: Ensuring that authorised users are not prevented from accessing information and associated assets when required[cite: 131].
* [cite_start]**Violation Example**: An internet 'flooding' attack, where attackers overwhelm a server by sending it large numbers of connection requests, causing a denial of service[cite: 157].

---

### **4. Additional Security Goals**

* [cite_start]**Authentication**: The process of verifying an identity claimed by or for a system entity[cite: 163].
* [cite_start]**Access control (Authorisation)**: The protection of system resources against unauthorised access[cite: 166].
* [cite_start]**Non-repudiation**: Protection against the false denial of involvement in a communication[cite: 168].

---

### **5. Security Analysis: Vulnerabilities, Threats, and Assets**

* [cite_start]**Assets**: What we want to protect, such as Hardware, Software, Data, and Users[cite: 186, 187].
* [cite_start]**Vulnerability**: A flaw in the design or implementation of a computer system that could lead to a security violation[cite: 174]. [cite_start]Examples include program bugs [cite: 176][cite_start], configuration errors [cite: 177][cite_start], and poor choice of passwords[cite: 178].
* [cite_start]**Threat**: A set of circumstances that could cause harm[cite: 189]. [cite_start]An attack is performed by exploiting a vulnerability of the system[cite: 190].
* [cite_start]**Countermeasure**: An action, device, procedure, or technique that removes or reduces a vulnerability[cite: 191].

| Security Threat | Linked Goal   | Description                                           |
| :-------------- | :------------ | :---------------------------------------------------- |
| Interception    | Confidentiality | [cite_start]Unauthorized party gains access to data or services[cite: 195]. |
| Interruption    | Integrity     | [cite_start]Service or data becomes unavailable or unusable[cite: 195].    |
| Modification    | Availability  | [cite_start]Unauthorized tampering of data or services[cite: 195].       |
| Fabrication     |               | [cite_start]Generation of additional data or activity[cite: 195].        |

---

### **6. How to Practice Security**

[cite_start]There are three intuitive strategies for security[cite: 244]:

1.  [cite_start]**Prevention**: Take measures that prevent your assets from being damaged[cite: 245]. [cite_start]For example, encrypting e-commerce orders[cite: 246].
2.  [cite_start]**Detection**: Take measures so that you can detect when, how, and by whom an asset has been damaged[cite: 247]. [cite_start]For example, noticing an unauthorised transaction on your credit card statement[cite: 248].
3.  [cite_start]**Reaction**: Take measures so that you can recover your assets or recover from damage[cite: 249]. [cite_start]For example, complaining about a fraudulent charge and asking for a new card number[cite: 250].

---

### **7. A 3-Step Method for Information Protection**

[cite_start]A method for tackling an information protection problem involves three steps[cite: 274]:

#### [cite_start]**Step 1: Drawing up a threat model via security requirement analysis** [cite: 275]
* [cite_start]Identify assets to be protected and their value[cite: 282].
* [cite_start]Identify vulnerabilities, threats, and risk priorities[cite: 282].
* [cite_start]Identify legal and contractual requirements[cite: 282].

#### [cite_start]**Step 2: Formulating a suitable security policy** [cite: 276]
* [cite_start]The policy models what ought to be protected[cite: 276].
* [cite_start]It defines which activities are or are not authorised and which information flows are or are not prohibited[cite: 287].
* [cite_start]The policy should be precise, well-documented, and followed[cite: 288, 289].

#### [cite_start]**Step 3: Implementing specific protection mechanisms to enforce the policy** [cite: 277]
* Examples include:
    * [cite_start]Hardware protection mechanisms[cite: 295].
    * [cite_start]Secure operating systems[cite: 296].
    * [cite_start]Secure coding[cite: 297].
    * [cite_start]Capabilities and access control lists[cite: 298].
    * [cite_start]End user security training[cite: 299].
    * [cite_start]Response to breaches[cite: 300].
