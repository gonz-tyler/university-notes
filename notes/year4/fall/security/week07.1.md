# Week 07.1: Quantitative Information Flow Control I Revision Notes

---

## 1. Information Flow Control (IFC) Basics

### Basic Security Theorem

* A system's security can be defined by state transitions. If the initial state is secure, and every possible state transition preserves security, then all subsequent states will also be secure. This is the foundation of information flow security.

### Motivation for IFC

* Traditional Access Control (like ACLs or capabilities) focuses on securing the **container** of information (e.g., a file) rather than the information itself.
* Once access is granted, traditional controls cannot restrict how that information is propagated or leaked (e.g., via covert channels).
* **Solution**: Information Flow Control directly restricts the transmission of information from one "place" (or security level) to another.

### Confidentiality vs. Flow

* **Confidentiality Policy**: Specifies **what** is allowed (e.g., "Subject A can read Object B").
* **Information Flow**: Describes **how** the policy is enforced (e.g., ensuring data read from Object B doesn't leak to a public output).
* **Dependability View**: A system is secure for confidentiality if public outputs do not depend on secret inputs. For example, the time it takes to check a password should not depend on whether the password is correct or incorrect, otherwise, a timing channel exists.

---

## 2. Non-Interference (NI)

* **Definition**: Non-interference is a strict security property introduced by Goguen and Meseguer (1982). Ideally, actions performed by a high-security (confidential) user should have **no effect whatsoever** on what a low-security (public) user can see.
* **State Machine View**: Even if the internal state of the system changes due to high-security actions, the sequence of outputs observed by a low-security user must remain exactly the same as if those high-security actions had never happened.
* **Relational Characterization**:
    * If two program states $\sigma_1$ and $\sigma_2$ are "low-equivalent" (meaning all low-security variables have the same values), then running the program from either state must produce final states that are also low-equivalent.
    * Essentially: Low inputs $\rightarrow$ Low outputs. High inputs should not influence Low outputs.

### Limitation of Non-Interference

* NI is often **too restrictive** for real-world applications. Almost any useful system requires *some* flow of information (e.g., a login process must reveal *some* information, like "login failed").
* This leads to the need for **Quantitative Information Flow**: Instead of asking "Is there any flow?" (yes/no), we ask "How **much** information is leaked?"

---

## 3. Quantitative Information Flow: Entropy and Information

To measure information leakage, we use concepts from Information Theory (Claude Shannon).

### Uncertainty and Information

* **Information** is effectively a reduction in **uncertainty**.
* "Knowing" something means having zero uncertainty.
* The more unlikely an event is, the more "information" you gain when it occurs. (e.g., Learning a coin landed 'heads' gives 1 bit of information. Learning a specific number was rolled on a 1000-sided die gives much more information).

### Entropy ($\mathcal{H}$)

* Entropy measures the average amount of information (or uncertainty) inherent in a variable's possible outcomes.
* Formula for a set of events $A$:
    $$
    \mathcal{H}(A) = \sum_{a \in A} p(a) \log_2 \frac{1}{p(a)}
    $$
    Where $p(a)$ is the probability of event $a$.
* **Base 2 logarithms** are used to measure information in **bits**.
* **Maximum Entropy**: Occurs when all outcomes are equally likely (uniform distribution).

### Calculation Examples

* **Zero Entropy**: If an event is certain (probability 1), entropy is 0. No information is gained because the outcome was already known.
* **Example**:
    * If $P(A)=1/2$ and $P(B)=1/2$, Entropy = 1 bit.
    * If $P(A)=1/6, P(B)=1/4, P(C)=7/12$, Entropy $\approx$ 1.38 bits.

---

## 4. Measuring Leakage in Deterministic Programs

We model a program as a communication channel. The "Secret" is the input, and the "Observable Output" is the output.

### The Leakage Model

1.  **Input Space**: The set of all possible values for the secret (high) variable `h`. We assume a probability distribution for these values (often uniform).
2.  **Observations**: The low-security output `l` produced by the program.
3.  **Inverted Mapping**: We analyze the program to see which secret inputs `h` could have produced a specific observed output `l`. This partitions the input space.

### Calculating Leakage

* **Initial Uncertainty**: The entropy of the secret input `h` *before* running the program ($\mathcal{H}(H)$).
* **Remaining Uncertainty**: The conditional entropy of `h` *given* the observation `l` ($\mathcal{H}(H|L)$). This represents how uncertain the attacker still is after seeing the output.
* **Information Leakage**: The difference between the initial uncertainty and the remaining uncertainty.
    $$
    \text{Leakage} = \mathcal{H}(H) - \mathcal{H}(H|L)
    $$
    This value tells us how many bits of the secret key were effectively "revealed" by running the program.

### Example Walkthrough ($l := h \% 2$)

* If `h` is a 2-bit secret (values 0, 1, 2, 3) and `l` is `h % 2`:
    * **Observer sees `l=0`**: They know `h` must be 0 or 2.
    * **Observer sees `l=1`**: They know `h` must be 1 or 3.
    * The observation partitions the possible secret space into sets $\{0, 2\}$ and $\{1, 3\}$.
    * If `h` was uniformly distributed (2 bits of entropy initially), the observer now has narrowed it down to 2 choices (1 bit of entropy remaining).
    * **Leakage**: $2 - 1 = 1$ bit. The program leaked the parity of the secret.
