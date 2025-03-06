# **Week 2: Non-deterministic Finite State Automata (NFSAs)**
## Notes
---

### **1. Introduction to NFSAs**

### **What is an NFSA?**

- An **NFSA** is an extension of a **Deterministic Finite State Automaton (DFSA)**.
- Unlike DFSAs, NFSAs allow **multiple transitions** for the same input symbol from a given state.
- NFSAs can also have **ε-transitions** (transitions that do not consume any input symbol).

### **Key Differences Between DFSAs and NFSAs**

- **DFSAs**:
    - For each state and input symbol, there is **exactly one transition**.
- **NFSAs**:
    - For each state and input symbol, there can be **zero, one, or multiple transitions**.
    - Can have **ε-transitions** (transitions that do not consume any input symbol).

### **Example NFSA**

- Consider an NFSA that accepts all strings over `{0, 1}` that end with `01`.
- The NFSA can have multiple transitions for the same input symbol, allowing it to "guess" the correct path to acceptance.

---

### **2. Formal Definition of NFSAs**

### **NFSA as a 5-tuple**

- An **NFSA** is defined as a 5-tuple N=(Q,Σ,δ,q0,F):
    - Q: Finite set of states.
    - Σ: Input alphabet.
    - δ: Transition function Q×Σϵ→P(Q), where Σϵ=Σ∪{ϵ}.
    - q0​: Start state (q0∈Q).
    - F: Set of accept states (F⊆Q).

### **Transition Function**

- The transition function δ returns a **set of states** rather than a single state.
- For example, δ(q1,0)={q2,q3} means that from state q1​, reading input symbol `0`, the NFSA can transition to either q2​ or q3.

---

### **3. Execution of NFSAs**

### **How NFSAs Work**

- When processing an input string, the NFSA can **split into multiple "copies"** and follow all possible transitions in parallel.
- **Acceptance**: The NFSA accepts a string if **at least one** of the parallel computations reaches an accept state.
- **Rejection**: The NFSA rejects a string if **none** of the parallel computations reach an accept state.

### **Example Execution**

- Consider an NFSA that accepts strings with `1` in the **third position from the end**.
- For the input `0101`, the NFSA will explore multiple paths:
    - One path might guess that the third symbol from the end is `1` and accept the string.
    - Another path might guess incorrectly and reject the string.
- If **at least one path** leads to an accept state, the string is accepted.

---

### **4. Equivalence of NFSAs and DFSAs**

### **Theorem**:

- Every **NFSA** has an equivalent **DFSA**.
- This means that NFSAs and DFSAs recognize the **same class of languages** (regular languages).

### **Proof: Subset Construction**

- The proof uses **subset construction**, where each state in the DFSA corresponds to a **set of states** in the NFSA.
- **Steps**:
    1. The states of the DFSA are all possible subsets of the states of the NFSA.
    2. The transition function of the DFSA is defined based on the transitions of the NFSA.

### **Example of Subset Construction**

- Given an NFSA with states {q1,q2}{*q*1​,*q*2​}, the corresponding DFSA will have states:
    - ∅∅ (empty set).
    - {q1}.
    - {q2}.
    - {q1,q2}.
- The transitions in the DFSA are defined based on the transitions of the NFSA. For example:
    - If δ(q1,0)={q2} and δ(q2,0)={q1}, then in the DFSA:
        - From {q1,q2}, on input `0`, the DFSA transitions to {q1,q2}.

---

### **5. Closure Properties of Regular Languages**

### **What are Closure Properties?**

- Regular languages are **closed** under certain operations, meaning that applying these operations to regular languages results in another regular language.

### **Closure Under Union**

- If L1​ and L2​ are regular languages, then L1∪L2 is also regular.
- **Proof Idea**:
    - Given two NFSAs N1​ and N2, we can construct a new NFSA N that accepts L(N1)∪L(N2).
    - The new NFSA N has a new start state with **ε-transitions** to the start states of N1​ and N2​.

### **Closure Under Concatenation**

- If L1​ and L2​ are regular languages, then L1∘L2 (concatenation) is also regular.
- **Proof Idea**:
    - The NFSA for L1∘L2 connects the accept states of N1*N*1​ to the start state of N2*N*2​ using ε-transitions.

### **Closure Under Star**

- If L is a regular language, then L* (Kleene star) is also regular.
- **Proof Idea**:
    - The NFSA for L* adds ε-transitions from the accept states back to the start state, allowing for zero or more repetitions of L.

---

### **Example: NFSA for Strings Ending with `01`**

### **NFSA Definition**

- **States**: Three states: `q0`, `q1`, and `q2`.
- **Transitions**:
    - From `q0`, on `0`, go to `q0` or `q1`.
    - From `q0`, on `1`, go to `q0`.
    - From `q1`, on `1`, go to `q2`.
- **Accept State**: `q2`.

### **Execution Example**

- **Input String**: `001`
    - Start in `q0`.
    - Read `0`, stay in `q0` or move to `q1`.
    - Read `0`, stay in `q0` or move to `q1`.
    - Read `1`, move to `q2` (if in `q1`).
    - Since one path leads to `q2` (accepting state), the string `001` is **accepted**.

---

### **Summary**

### **Non-deterministic Finite State Automata (NFSAs)**:

- **What is it?** An NFSA is similar to an FSA, but it can have multiple transitions for the same input symbol from a given state. This means that the NFSA can be in multiple states at once, and it accepts a string if **any** of the possible paths leads to an accepting state.
- **Example**: An NFSA that recognizes strings ending with `01` over the alphabet `{0, 1}`.

### **Equivalence of NFSAs and DFSAs**:

- Every NFSA can be converted into an equivalent DFSA using **subset construction**.

### **Closure Properties**:

- Regular languages are closed under **union**, **concatenation**, and **star**.
