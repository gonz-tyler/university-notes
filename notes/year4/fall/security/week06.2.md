# Week 06.2: Security Models

---

## 1. Recap: Security Policies, Mechanisms, and Models

* **Security Policy**: A statement defining what is allowed (secure states) and what is not allowed (non-secure states) within a system. Policies can sometimes be incomplete or ambiguous.
* **Security Mechanism**: A method or tool used to enforce a security policy (e.g., access control lists).
* **Security Model**: An abstract representation of a particular security policy or set of policies. Formal models help ensure policies are clear, complete, and correctly implemented.

---

## 2. Information Flow Policy

Accessing computer resources involves information flowing between entities.

* **Read Access**: Information flows **from** an object **to** a subject.
* **Write Access**: Information flows **from** a subject **to** an object.

An **information flow policy** aims to control how information propagates through a system based on security levels.

* **Core Idea**: Assign **security labels** (e.g., `low`, `medium`, `high`, or `unclassified`, `secret`, `top secret`) to both subjects and objects. These labels form a partially ordered set (a **lattice**).
* **Fundamental Rule (for Confidentiality)**: Information is only allowed to flow from a lower security level to a higher security level (or stay at the same level). Information cannot flow "downhill" from high to low.
    * This prevents a subject with low clearance from reading high-sensitivity data.
    * This prevents high-sensitivity data from being written to a low-sensitivity object (like printing a `top secret` document to an `unclassified` printer).

---

## 3. Formal Security Models

Formal models provide a precise way to define and reason about security policies.

### The Bell-LaPadula (BLP) Model (1973)

* **Focus**: **Confidentiality**. It's the most famous model, designed primarily for military/government systems.
* **Goal**: Prevent information from flowing from higher security levels to lower security levels.
* **Components**:
    * Subjects (S), Objects (O).
    * Security Levels (L) forming a lattice (e.g., `unclassified < secret < top secret`).
    * Each subject `s` and object `o` has a security level, `λ(s)` and `λ(o)`.
    * An access control matrix `M` specifying permissions.
    * A system state includes the current permissions `M`, the security levels `λ`, and the set of currently active accesses `B`.
* **Key Properties**:
    1.  **Simple Security Property (No Read Up)**: A subject `s` can only read an object `o` if `λ(s) ≥ λ(o)`. (You need sufficient clearance to read).
    2.  **\*-Property (Star Property - No Write Down)**: A subject `s` can only write to an object `o` if `λ(s) ≤ λ(o)`. (You can't write secrets into an unclassified document).
    3.  **Discretionary Security Property**: Any access must also be explicitly allowed by the access control matrix `M`.
* **Limitations**: Primarily focuses on confidentiality, not integrity. Less flexible for commercial environments.

### The Biba Model (1977)

* **Focus**: **Integrity**. It aims to prevent corruption or unauthorized modification of data.
* **Goal**: Prevent information from flowing from lower integrity levels to higher integrity levels. High-integrity subjects should not be contaminated by low-integrity data.
* **Components**: Similar to BLP, but uses **integrity levels** instead of confidentiality levels.
* **Key Properties (Duals of BLP)**:
    1.  **Simple Integrity Property (No Read Down)**: A subject `s` can only read an object `o` if `λ(s) ≤ λ(o)`. (You can't read less trustworthy data).
    2.  **\*-Integrity Property (No Write Up)**: A subject `s` can only write to an object `o` if `λ(s) ≥ λ(o)`. (You can't write untrustworthy data into a high-integrity object).
* **Relation to BLP**: The Biba rules are essentially the opposite of the BLP rules, focusing on preventing "upward" flow for writing and "downward" flow for reading in terms of integrity.

### The Chinese Wall Model (1989)

* **Focus**: Preventing **conflicts of interest**, primarily in commercial settings (e.g., consultancies working with competing clients).
* **Goal**: Ensure that a subject (e.g., a consultant) who accesses data belonging to one company cannot access data belonging to a direct competitor. Access rights change dynamically based on past actions.
* **Components**:
    * Subjects (S).
    * Objects (O) organized hierarchically:
        * Basic Information Items (Files).
        * Company Datasets (Groups of files belonging to one company).
        * Conflict-of-Interest Classes (Groups of datasets for competing companies, e.g., all banks).
* **Key Rules**:
    1.  **Simple Security Rule (Read Rule)**: A subject `s` can read an object `o` **if and only if**:
        * `o` is in the same Company Dataset as an object already accessed by `s`, OR
        * `o` belongs to a Conflict-of-Interest Class from which `s` has not yet accessed any information. (Once you read from Bank A, you cannot read from Bank B).
    2.  **\*-Property (Write Rule)**: A subject `s` can write to an object `o` **if and only if**:
        * `s` is permitted to read `o` according to the read rule, AND
        * All objects that `s` has previously read belong to the **same Company Dataset** as `o`. (This prevents indirect leaks where information read from Company A is written into a file accessible by someone working for Company B).
* **Nature**: Combines discretionary choice (the first access) with mandatory control (subsequent accesses are restricted based on the first choice). The write rule is very restrictive.
