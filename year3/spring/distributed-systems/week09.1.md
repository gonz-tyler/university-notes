
# Week 09.1:Security Threat Analysis
## Notes
---

### Introduction to Security

**Security** ensures that *just the right agents* have access to *just the right resources* at *just the right time*.

Key elements:
- **Agents**: Legal entities (people, organizations, computers)
- **Resources**: Information, services, or devices
- **Time**: Specific durations when access is allowed

---

### Core Security Concepts

- **Confidentiality**: Visibility control (e.g., file permissions, encryption)
- **Integrity**: Correctness of data (e.g., backup systems, checksums)
- **Availability**: Accessibility and uptime (e.g., redundant systems, load balancing)

---

### Additional Concepts

- **Authenticity**: Confidence in source identity (e.g., digital signatures)
- **Accountability**: Actions are traceable to users
- **Non-repudiation**: Sender can't deny sending data

---

### Security Engineering Framework

- **Policy**: Defines who can do what
- **Mechanism**: Tools used to enforce policies (e.g., passwords, encryption)
- **Assurance**: Trustworthiness of mechanisms
- **Incentive**: Motivation to maintain security

---

### Threats, Vulnerabilities, and Attacks

- **Vulnerability**: Weakness in a system
- **Exploit**: Method used to take advantage of a vulnerability
- **Attack**: Execution of an exploit
- **Attack vector**: Method of delivery
- **Attack surface**: Total exposure of a system to attacks

---

### Security-Critical Examples: Banking

- **Bank Staff**: Internal threats → monitored via dual authorization and transaction logging
- **ATM**: External + internal threats → PINs, cards, cryptography
- **Phishing**: Targets users, not systems → needs multifactor authentication, psychology, and economic decisions

---

### Threat Analysis

- Understand what can go wrong
- Understand where and how attacks may occur
- Use the model to guide defensive decisions

---

### Threat Trees / Attack Trees

- Root = attack goal
- Nodes = sub-goals or attack methods
- Leaves = specific attack actions
- Node Types:
  - **OR**: Any child node suffices
  - **AND**: All child nodes must be true

---

### Threat Tree Example: Opening a Safe

```markdown
Goal: Open Safe
├── Pick Lock
├── Learn Combination (OR)
│   ├── Find Written Combo
│   └── Get From Person (OR)
│       ├── Threaten
│       ├── Blackmail
│       └── Eavesdrop (AND)
│           ├── Listen
│           └── Prompt Verbal Combo
├── Bribe
├── Cut Open
└── Exploit Installation
```

---

### Using Threat Trees

- Label attacks: **possible**, **impossible**
- Aggregate via AND/OR logic
- Optional annotations: cost, ease, legality, equipment
- Helps decide **where to invest** security resources

---

### Annotated Threat Trees

- **OR Node** is possible if **any** child is possible
- **AND Node** is possible only if **all** children are possible
- Use dotted lines to highlight feasible attack paths

---

### Assigning Costs

- Cost of OR node: **min(child cost)**
- Cost of AND node: **sum(child costs)**
- Useful for calculating ROI on defence strategies

---

### Threat Tree Workflow

1. Identify top-level attack goals
2. Break into sub-goals and concrete actions
3. Label leaves with feasibility/cost
4. Aggregate annotations up the tree
5. Update tree to explore "what-if" scenarios

---

### Choosing Defences

- Choose which attacks are most likely or cost-effective
- Profile attackers (skills, access)
- Compare cost of defence vs Annual Loss Expectancy (ALE)

---

### Annual Loss Expectancy (ALE)

**ALE = Damage × Likelihood**

- Prioritize defences based on ALE
- Useful for economic justification of security measures

---

### Defence: Security Protocols

Security protocols govern safe communication.

#### Types:
- **Human-human** (e.g., caller verification via known contact)
- **Human-computer** (e.g., passwords, biometrics)
- **Computer-computer** (e.g., encrypted remote key exchange)

---

### Secure Identification

#### Problems with passwords:
- Guessable
- Reused
- Not changeable in critical systems

#### Better options:
- Hardware tokens
- Biometric checks

---

### Secure Devices: Car Remote Example

#### Insecure:
- Sends plain password
- Vulnerable to replay attacks

#### Secure version:
- Uses encryption and **nonce** (number used once)
- **Challenge-response** model preferred

---

### Weaknesses in Protocols

- Replay attacks
- Signal jamming
- "Man in the middle" (MitM)

---

### People Are the Weak Link

- Social engineering
- Dumpster diving
- Insider threats
- Phishing

---

### Summary

| Topic                  | Key Points                                      |
|------------------------|-------------------------------------------------|
| Core Security Goals    | Confidentiality, Integrity, Availability        |
| Supporting Concepts    | Authenticity, Accountability, Non-repudiation   |
| Threat Trees           | Visual model of potential attacks               |
| ALE                    | Prioritize defences economically                |
| Identification         | Hard problem – biometrics & crypto help         |
| Protocol Types         | Human ↔ Human, Human ↔ Machine, Machine ↔ Machine |
| Human Weakness         | Biggest factor in many real-world attacks       |

---
