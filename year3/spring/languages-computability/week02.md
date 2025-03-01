# Week 2: Non-deterministic Finite State Automata (NFSAs)
## Notes
---

### 1. Non-deterministic Finite State Automata
- **NFSAs** allow multiple transitions for the same input symbol from a given state.
- **Key Idea**: The transition function returns a **set of states** rather than a single state.
- **Advantages**: NFSAs can be more compact than DFSAs for the same language.

#### Example NFSA
- For the language \( \{w \in \{0, 1\}^* | w \text{ has } 1 \text{ in the 3rd position from the end\} \).

### 2. Formal Definition of NFSAs
- An **NFSA** is a 5-tuple \( N = (Q, \Sigma, \delta, q_0, F) \):
  - \( Q \): Finite set of states.
  - \( \Sigma \): Input alphabet.
  - \( \delta \): Transition function \( Q \times \Sigma_\epsilon \rightarrow P(Q) \).
  - \( q_0 \): Start state.
  - \( F \): Set of accept states.

### 3. Execution of NFSAs
- **Computation**: For each input symbol, the NFSA splits into multiple "copies" and follows all possible transitions in parallel.
- **Acceptance**: The NFSA accepts a string if at least one copy reaches an accept state.

### 4. Equivalence of NFSAs and DFSAs
- **Theorem**: Every NFSA has an equivalent DFSA.
- **Proof**: Use **subset construction** to convert an NFSA into a DFSA.

### 5. Closure Properties of Regular Languages
- **Theorem**: The class of regular languages is closed under:
  - **Union**: \( L_1 \cup L_2 \)
  - **Concatenation**: \( L_1 \circ L_2 \)
  - **Star**: \( L^* \)
  - **Intersection**: \( L_1 \cap L_2 \)
  - **Complement**: \( \overline{L} \)
