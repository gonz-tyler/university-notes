# Week 2: Non-deterministic Finite State Automata (NFSAs)
## Notes
---

### 1. Introduction to NFSAs
- **NFSAs** are an extension of **Deterministic Finite State Automata (DFSAs)**.
- Unlike DFSAs, NFSAs allow **multiple transitions** for the same input symbol from a given state.
- NFSAs can also have **ε-transitions** (transitions that do not consume any input symbol).

#### Key Differences Between DFSAs and NFSAs
- **DFSAs**: 
  - For each state and input symbol, there is exactly one transition.
- **NFSAs**:
  - For each state and input symbol, there can be zero, one, or multiple transitions.
  - Can have ε-transitions.

#### Example NFSA
- Consider an NFSA that accepts all strings over \(\{0, 1\}\) that end with "01".
- The NFSA can have multiple transitions for the same input symbol, allowing it to "guess" the correct path to acceptance.

### 2. Formal Definition of NFSAs
- An **NFSA** is a 5-tuple \( N = (Q, \Sigma, \delta, q_0, F) \):
  - \( Q \): Finite set of states.
  - \( \Sigma \): Input alphabet.
  - \( \delta \): Transition function \( Q \times \Sigma_\epsilon \rightarrow P(Q) \), where \( \Sigma_\epsilon = \Sigma \cup \{\epsilon\} \).
  - \( q_0 \): Start state (\( q_0 \in Q \)).
  - \( F \): Set of accept states (\( F \subseteq Q \)).

#### Transition Function
- The transition function \( \delta \) returns a **set of states** rather than a single state.
- For example, \( \delta(q_1, 0) = \{q_2, q_3\} \) means that from state \( q_1 \), reading input symbol "0", the NFSA can transition to either \( q_2 \) or \( q_3 \).

### 3. Execution of NFSAs
- **Computation**: When processing an input string, the NFSA can split into multiple "copies" and follow all possible transitions in parallel.
- **Acceptance**: The NFSA accepts a string if **at least one** of the parallel computations reaches an accept state.
- **Rejection**: The NFSA rejects a string if **none** of the parallel computations reach an accept state.

#### Example Execution
- Consider an NFSA that accepts strings with "1" in the third position from the end.
- For the input "0101", the NFSA will explore multiple paths, and if at least one path leads to an accept state, the string is accepted.

### 4. Equivalence of NFSAs and DFSAs
- **Theorem**: Every NFSA has an equivalent DFSA.
- **Proof**: The proof uses **subset construction**, where each state in the DFSA corresponds to a **set of states** in the NFSA.
- **Subset Construction**:
  - The states of the DFSA are all possible subsets of the states of the NFSA.
  - The transition function of the DFSA is defined based on the transitions of the NFSA.

#### Example of Subset Construction
- Given an NFSA with states \( \{q_1, q_2\} \), the corresponding DFSA will have states \( \{\emptyset, \{q_1\}, \{q_2\}, \{q_1, q_2\}\} \).

### 5. Closure Properties of Regular Languages
- **Regular languages** are closed under the following operations:
  - **Union**: If \( L_1 \) and \( L_2 \) are regular, then \( L_1 \cup L_2 \) is regular.
  - **Concatenation**: If \( L_1 \) and \( L_2 \) are regular, then \( L_1 \circ L_2 \) is regular.
  - **Star**: If \( L \) is regular, then \( L^* \) is regular.
  - **Intersection**: If \( L_1 \) and \( L_2 \) are regular, then \( L_1 \cap L_2 \) is regular.
  - **Complement**: If \( L \) is regular, then \( \overline{L} \) is regular.

#### Proof of Closure Under Union
- Given two NFSAs \( N_1 \) and \( N_2 \), we can construct an NFSA \( N \) that accepts \( L(N_1) \cup L(N_2) \).
- The new NFSA \( N \) has a new start state with ε-transitions to the start states of \( N_1 \) and \( N_2 \).

## Summary
Non-deterministic Finite State Automata (NFSAs):
- What is it? An NFSA is similar to an FSA, but it can have multiple transitions for the same input symbol from a given state. This means that the NFSA can be in multiple states at once, and it accepts a string if any of the possible paths leads to an accepting state.

- Example: Consider an NFSA that recognizes strings ending with `01` over the alphabet `{0, 1}`.

  - States: Three states: `q0`, `q1`, and `q2`.

  - Transitions:

    - From `q0`, on `0`, go to `q0` or `q1`.

    - From `q0`, on `1`, go to `q0`.

    - From `q1`, on `1`, go to `q2`.

  - Accept State: `q2`.

  If the input string is `001`, the NFSA can:

  - Start in `q0`.

  - Read `0`, stay in `q0` or move to `q1`.

  - Read `0`, stay in `q0` or move to `q1`.

  - Read `1`, move to `q2` (if in `q1`).

  - Since one path leads to `q2` (accepting state), the string `001` is accepted.
