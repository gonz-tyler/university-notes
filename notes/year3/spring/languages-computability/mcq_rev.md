# MCQ Revision

### 1. Check if the Language Requires Counting

#### Why Counting Matters:

- **Regular languages** (recognized by FSAs) **cannot count**. They have no memory other than the current state.
- If a language requires counting (e.g., matching the number of `0`s and `1`s), it is **not regular**.

#### Example: {0n1n∣n≥0}{0*n*1*n*∣*n*≥0}

- This language requires matching the number of `0`s and `1`s.
- An FSA cannot "remember" how many `0`s it has seen to match the number of `1`s.
- **Conclusion**: This language is **not regular**.

---

### 2. What Does S→aSb∣Sb∣ϵ*S*→*aSb*∣*Sb*∣*ϵ* Mean?

#### Context-Free Grammar (CFG) Rules:

- S→aSb*S*→*aSb*: This rule generates strings where the number of `a`s and `b`s are equal.
    - For example:
        - Start with S*S*.
        - Apply S→aSb*S*→*aSb*: aSb*aSb*.
        - Apply S→aSb*S*→*aSb* again: aaSbb*aaSbb*.
        - Apply S→ϵ*S*→*ϵ*: aabb*aabb*.
- S→Sb*S*→*Sb*: This rule allows adding extra `b`s.
    - For example:
        - Start with S*S*.
        - Apply S→Sb*S*→*Sb*: Sb*Sb*.
        - Apply S→Sb*S*→*Sb* again: Sbb*Sbb*.
        - Apply S→ϵ*S*→*ϵ*: bb*bb*.
- S→ϵ*S*→*ϵ*: This rule terminates the derivation, producing the empty string.

#### Language Generated:

- The CFG S→aSb∣Sb∣ϵ*S*→*aSb*∣*Sb*∣*ϵ* generates the language {anbm∣n≤m}{*anbm*∣*n*≤*m*}.
    - aSb*aSb* ensures n≤m*n*≤*m*.
    - Sb*Sb* allows adding extra `b`s.

---

### **3. How to Come Up with the Pumping Lemmas**

### **Pumping Lemma for Regular Languages**:

- **Purpose**: To prove that a language is **not regular**.
- **Statement**: For any regular language L*L*, there exists a pumping length p*p* such that any string s∈L*s*∈*L* with ∣s∣≥p∣*s*∣≥*p* can be divided into s=xyz*s*=*xyz*, where:
    1. ∣xy∣≤p∣*xy*∣≤*p*.
    2. ∣y∣≥1∣*y*∣≥1.
    3. xyiz∈L*xyiz*∈*L* for all i≥0*i*≥0.

### **Steps to Apply the Pumping Lemma**:

1. **Assume** the language is regular.
2. **Choose** a string s*s* in the language with ∣s∣≥p∣*s*∣≥*p*.
3. **Divide** s*s* into xyz*xyz* such that ∣xy∣≤p∣*xy*∣≤*p* and ∣y∣≥1∣*y*∣≥1.
4. **Pump** y*y* (repeat it) to show that xyiz*xyiz* is **not** in the language for some i*i*.
5. **Conclude** that the language is not regular.

### **Example**:

- **Language**: {0n1n∣n≥0}{0*n*1*n*∣*n*≥0}.
- **Proof**:
    1. Assume the language is regular.
    2. Let p*p* be the pumping length.
    3. Choose s=0p1p*s*=0*p*1*p*.
    4. Divide s*s* into xyz*xyz*, where y*y* consists of only `0`s.
    5. Pump y*y*: xy2z=0p+k1p*xy*2*z*=0*p*+*k*1*p*, where k≥1*k*≥1.
    6. This string is **not** in the language because the number of `0`s and `1`s no longer match.
    7. **Conclusion**: The language is not regular.

---

### **4. How to Design PDAs**

### **Key Idea**:

- A **PDA** is an FSA with a **stack** for additional memory.
- The stack allows the PDA to recognize **context-free languages** (e.g., {0n1n∣n≥0}{0*n*1*n*∣*n*≥0}).

### **Steps to Design a PDA**:

1. **Identify the Language**:
    - Determine the pattern or structure of the language (e.g., matching symbols, counting).
2. **Use the Stack**:
    - Push symbols onto the stack to "remember" information.
    - Pop symbols from the stack to "match" or "count" symbols.
3. **Define States and Transitions**:
    - Create states to represent different stages of the computation.
    - Define transitions based on the input symbol and the top of the stack.
4. **Acceptance**:
    - Accept the string if the stack is empty and the input is fully read.

### **Example: PDA for {0n1n∣n≥0}{0*n*1*n*∣*n*≥0}**:

- **States**: `q0`, `q1`, `q2`.
- **Transitions**:
    - From `q0`, on `0`, push `0` onto the stack and stay in `q0`.
    - From `q0`, on `1`, pop `0` from the stack and move to `q1`.
    - From `q1`, on `1`, pop `0` from the stack and stay in `q1`.
    - From `q1`, on empty input and empty stack, move to `q2` (accepting state).
- **Execution Example**:
    - Input: `0011`
        - Start in `q0` with an empty stack.
        - Read `0`, push `0` onto the stack.
        - Read `0`, push another `0` onto the stack.
        - Read `1`, pop `0` from the stack and move to `q1`.
        - Read `1`, pop `0` from the stack and stay in `q1`.
        - Since the stack is empty and the input is fully read, move to `q2` (accepting state).

## **Bitesize Summary for Exam**

---

### **1. Finite State Automata (FSAs)**

- **What is it?** A computational model with states, transitions, and an input string.
- **Key Points**:
    - Recognizes **regular languages**.
    - No memory other than the current state.
    - **Deterministic (DFSA)**: One transition per input symbol.
    - **Non-deterministic (NFSA)**: Multiple transitions or ε-transitions allowed.
- **Example**: FSA for strings with an odd number of `1`s:
    - States: `q_even`, `q_odd`.
    - Transitions: On `1`, flip between `q_even` and `q_odd`.
    - Accept state: `q_odd`.

---

### **2. Regular Expressions (REs)**

- **What is it?** A pattern for matching strings in regular languages.
- **Key Operators**:
    - `∪` (union), `◦` (concatenation),  (Kleene star).
- **Examples**:
    - `0*10*`: Strings with exactly one `1`.
    - `(0 ∪ 1)*`: All strings over `{0, 1}`.
    - `0*1*`: Strings with `0`s followed by `1`s.
- **Equivalence**: REs and FSAs recognize the same languages (regular languages).

---

### **3. Non-deterministic Finite State Automata (NFSAs)**

- **What is it?** An FSA with multiple transitions or ε-transitions.
- **Key Points**:
    - Can "guess" the correct path to acceptance.
    - Accepts a string if **any** path leads to an accept state.
    - **Subset Construction**: Every NFSA can be converted to an equivalent DFSA.
- **Example**: NFSA for strings ending with `01`:
    - States: `q0`, `q1`, `q2`.
    - Transitions: On `0`, go to `q0` or `q1`; on `1`, go to `q2`.

---

### **4. Context-free Grammars (CFGs)**

- **What is it?** A set of rules to generate context-free languages.
- **Key Points**:
    - Rules: A→β*A*→*β*, where A*A* is a non-terminal and β*β* is a string of terminals/non-terminals.
    - **Example**: S→aSb∣ϵ*S*→*aSb*∣*ϵ* generates {anbn∣n≥0}{*anbn*∣*n*≥0}.
    - **Regular Grammars**: A subset of CFGs where rules are of the form A→tB*A*→*tB* or A→t*A*→*t*.

---

### **5. Pushdown Automata (PDAs)**

- **What is it?** An FSA with a **stack** for additional memory.
- **Key Points**:
    - Recognizes **context-free languages**.
    - Transitions depend on the current state, input symbol, and top of the stack.
    - **Example**: PDA for {0n1n∣n≥0}{0*n*1*n*∣*n*≥0}:
        - Push `0`s onto the stack for each `0`.
        - Pop `0`s from the stack for each `1`.
        - Accept if the stack is empty at the end.
- **Non-deterministic PDAs**: More powerful than deterministic PDAs.

---

### **6. Equivalence of CFGs and PDAs**

- **Key Theorem**: A language is context-free if and only if some PDA recognizes it.
- **Proof**:
    - **CFG to PDA**: Convert a CFG into a PDA.
    - **PDA to CFG**: Convert a PDA into a CFG.

---

### **7. Non-Context-Free Languages**

- **What is it?** Languages that cannot be recognized by PDAs or generated by CFGs.
- **Examples**:
    - {anbncn∣n≥0}{*anbncn*∣*n*≥0}.
    - {ww∣w∈{0,1}∗}{*ww*∣*w*∈{0,1}∗}.
- **Pumping Lemma for CFLs**:
    - If a language is context-free, any sufficiently long string can be "pumped".
    - Used to prove a language is **not** context-free.

---

### **8. Deterministic Context-Free Languages (DCFLs)**

- **What is it?** A subset of context-free languages recognized by **deterministic PDAs**.
- **Key Points**:
    - **DPDAs**: Have a single transition for each input symbol.
    - **Example**: {anbn∣n≥0}{*anbn*∣*n*≥0} is a DCFL.
    - Important for parsing programming languages.

---

### **9. Key Differences Between Models**

- **FSAs**:
    - Recognize **regular languages**.
    - No stack.
- **PDAs**:
    - Recognize **context-free languages**.
    - Use a stack for memory.
- **Turing Machines**:
    - Recognize **recursively enumerable languages**.
    - Use an infinite tape for memory.

---

### **10. Key Theorems**

1. **Kleene’s Theorem**: Regular languages = languages recognized by FSAs = languages described by REs.
2. **Equivalence of CFGs and PDAs**: Context-free languages = languages recognized by PDAs.
3. **Pumping Lemma**:
    - Regular languages: Used to prove a language is **not** regular.
    - Context-free languages: Used to prove a language is **not** context-free.

---

### **11. Common Mistakes to Avoid**

- **FSAs**:
    - Don’t assume FSAs can count (e.g., {0n1n∣n≥0}{0*n*1*n*∣*n*≥0} is not regular).
- **CFGs**:
    - Don’t confuse regular grammars with general CFGs.
- **PDAs**:
    - Remember that PDAs use a stack, but only the **top symbol** is accessible.

---

### **12. Quick Tips for the Exam**

- **FSAs**:
    - Draw the state diagram if you’re stuck.
    - Check if the language requires counting (if yes, it’s not regular).
- **CFGs**:
    - Look for patterns like anbn*anbn* or nested structures.
- **PDAs**:
    - Use the stack to count or match symbols (e.g., push for `0`, pop for `1`).
- **Pumping Lemma**:
    - Use it to prove a language is **not** regular or context-free.

---

### **13. Example Problems to Review**

1. **FSA**: Design an FSA for strings with an even number of `0`s.
2. **RE**: Write a regular expression for strings with at least two `1`s.
3. **CFG**: Write a CFG for {anbm∣n≤m}{*anbm*∣*n*≤*m*}.
4. **PDA**: Design a PDA for {anb2n∣n≥0}{*anb*2*n*∣*n*≥0}.
5. **Pumping Lemma**: Prove {anbncn∣n≥0}{*anbncn*∣*n*≥0} is not context-free.

---

### **14. Final Reminders**

- **FSAs**: No memory, only states.
- **CFGs**: Recursive rules, can generate nested structures.
- **PDAs**: Use a stack, can recognize context-free languages.
- **Pumping Lemma**: Use it to disprove regularity or context-freeness.
