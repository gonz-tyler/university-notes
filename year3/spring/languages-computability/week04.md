# Week 4: Pushdown Automata (PDAs)
## Notes
---

### 1. Pushdown Automata
- **PDAs** are similar to NFSAs but with an **unbounded stack** as additional memory.
- PDAs are equivalent to CFGs in expressive power.
- **Transitions** are based on the current state, input symbol, and the top symbol on the stack.

#### Example PDA
- For the language \( \{0^n 1^n | n \geq 0\} \):
  - Push 0s onto the stack for each 0 in the input.
  - Pop 0s from the stack for each 1 in the input.
  - Accept if the stack is empty when the input ends.

### 2. Formal Definition of PDAs
- A **PDA** is a 6-tuple \( M = (Q, \Sigma, \Gamma, \delta, q_0, F) \):
  - \( Q \): Finite set of states.
  - \( \Sigma \): Input alphabet.
  - \( \Gamma \): Stack alphabet.
  - \( \delta \): Transition function \( Q \times \Sigma_\epsilon \times \Gamma_\epsilon \rightarrow P(Q \times \Gamma_\epsilon) \).
  - \( q_0 \): Start state.
  - \( F \): Set of accept states.

### 3. PDA Examples
- **Example 1**: PDA for \( \{0^n 1^n | n \geq 0\} \).
- **Example 2**: PDA for \( \{a^i b^j c^k | i = j \text{ or } i = k\} \).
- **Example 3**: PDA for \( \{ww^R | w \in \{0, 1\}^*\} \).

### 4. Equivalence of CFGs and PDAs
- **Theorem**: A language is context-free if and only if some PDA recognizes it.
- **Proof**:
  - **CFG to PDA**: Convert a CFG into an equivalent PDA.
  - **PDA to CFG**: Convert a PDA into an equivalent CFG.

### 5. Transforming CFGs into PDAs
- **Key Idea**: The transitions in the PDA "encode" the productions in the CFG.
- **Steps**:
  1. Define the stack alphabet \( \Gamma_p = N \cup T \cup \{\$\} \).
  2. Define the input alphabet \( \Sigma_p = T \).
  3. Set \( Q_p = \{q_p, q_{loop}, q_{accept}\} \cup E \).
  4. Add transitions for each production rule.

### 6. Transforming PDAs into CFGs
- **Key Idea**: Each non-terminal \( A_{pq} \) generates all strings that take the PDA from state \( p \) to state \( q \) with an empty stack.
- **Steps**:
  1. Convert the PDA into an equivalent PDA with a single accept state and empty stack.
  2. Define non-terminals \( A_{pq} \) for each pair of states \( p, q \).
  3. Add rules for transitions and stack operations.

### 7. Non-Context-Free Languages
- Some languages are **not context-free**, e.g., \( \{a^n b^n c^n | n \geq 0\} \).
- **Pumping Lemma for CFLs**: Every CFL has a pumping length \( p \). For any string \( s \) in the language with \( |s| \geq p \), \( s \) can be divided into 5 parts \( uvxyz \) such that:
  - \( |vxy| \leq p \)
  - \( |vy| \geq 1 \)
  - \( uv^i xy^i z \) is in the language for all \( i \geq 0 \).

### 8. Deterministic CFLs
- **Deterministic CFLs** are a subset of CFLs recognized by **deterministic PDAs**.
- **DPDAs** have a single transition from each state, making them suitable for parsing programming languages.
