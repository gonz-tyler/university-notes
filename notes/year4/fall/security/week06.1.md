# Week 06.1: Access Control

---

## 1. Introduction: Security Policies and Mechanisms

* **Security Policy**: A statement defining what is allowed and what is not allowed within a system.
* **Security Mechanism**: A method, tool, or procedure used to enforce a security policy.

In real life, mechanisms like locks (requiring keys) and guards (checking identity) control access. Computer systems need analogous mechanisms to control:
* Who can use the system.
* Which programs a user can run.
* Which resources a process can access.
* How shared resources are protected between processes.

---

## 2. Fundamental Security Techniques

1.  **Authentication**: Verifying the identity of users ("who you are").
2.  **Access Control (Authorization)**: Limiting what an authenticated user can do ("what you are allowed to do"). This is the main focus here.
3.  **Audit**: Reviewing system records to check compliance, detect breaches, and ensure controls are adequate.
4.  **Information Flow Control**: Ensuring information moves through the system without security violations.

These often work together in an **AAA (Authentication, Authorization, Auditing)** framework.

---

## 3. Access Control Concepts

* **Definition**: Access control is the process by which a computer system controls interactions between users (or processes acting on their behalf) and system resources.
* **Goal**: To prevent unauthorized access and limit the actions of authorized users according to the security policy.

### Key Components

* **Subject**: An **active entity** that requests access (e.g., user, process, thread).
* **Object**: A **passive entity** or resource that is accessed (e.g., file, directory, printer, socket).
* **Access Operation**: The action the subject attempts to perform on the object (e.g., read, write, execute, print).

### The Reference Monitor

* An **abstract machine** or conceptual entity within the system that **mediates all access requests**.
* It checks the request against the defined security policy (often represented implicitly or explicitly) and decides whether to grant or deny access.

### Access Modes and Information Flow

* **Observe (Read)**: Looking at the content of an object. Information flows from the object to the subject.
* **Alter (Write)**: Changing the content of an object. Information flows from the subject to the object.

---

## 4. Access Control Models

An access control model provides an abstract way to represent system elements and security rules, typically describing a reference monitor. Models help in reasoning about security and designing implementations.

### Policy Classifications

1.  **Discretionary Access Control (DAC)**:
    * Access decisions are based on the **identity** of the user.
    * **Owners** of resources typically control who can access them.
    * Common in commercial systems like Unix/Linux file permissions.
2.  **Mandatory Access Control (MAC)**:
    * Access decisions are based on **security labels** (e.g., clearance levels, categories) attached to subjects and objects, independent of user identity.
    * Users cannot change access permissions at their discretion.
    * Common in military and government systems.

### Representing Access Rights

1.  **Access Control Matrix (ACM)**:
    * A conceptual matrix where rows represent subjects, columns represent objects, and each cell `M(s, o)` contains the set of operations that subject `s` is allowed to perform on object `o`.
    * A request `(s, o, a)` is granted if operation `a` is in `M(s, o)`.
    * **Disadvantage**: Impractical to implement directly for large, dynamic systems.

2.  **Access Control Lists (ACLs)**:
    * Corresponds to **columns** of the ACM. Each object has a list specifying which subjects have what permissions for that object.
    * Example: ACL for `fun.com` might be `[(Alice, {r,x}), (Bob, {r,w,x})]`.
    * Often implemented using **access masks** (bit patterns).
    * Common in operating systems like Windows NT.
    * **Disadvantage**: Determining all permissions for a specific subject requires checking the ACL of every object.

3.  **Capabilities**:
    * Corresponds to **rows** of the ACM. Each subject holds a list of **unforgeable tokens** (capabilities), where each token specifies an object and the allowed operations on it.
    * Example: Alice's capability list might be `[(edit.exe, {x}), (fun.com, {r,x})]`.
    * When accessing an object, the subject presents the relevant capability.
    * **Disadvantages**: Difficult to get an overview of who can access a specific object; revoking capabilities can be complex.

### Other Approaches

* **Role-Based Access Control (RBAC)**: Permissions are associated with **roles** (job functions), and users are assigned to roles. Access depends on the user's role, not their individual identity.
* **Rule-Based Access Control**: Access is determined by a list of rules (e.g., time of day, location).
* **Content-Dependent Access Control**: Access depends on the actual content of the object.
