# Week 05: Context-sensitive Languages (CSLs)
## Notes
---

### 1. Introduction to Context-sensitive Languages
- **Context-sensitive Languages (CSLs)** are a class of languages more expressive than **context-free languages (CFLs)**.
- CSLs are recognized by **Linear-bounded Automata (LBAs)**.
- **Context-sensitive Grammars (CSGs)** are used to generate CSLs.

#### Key Features of CSLs
- **Non-contracting Rules**: In CSGs, the length of the right-hand side of a production must be at least as long as the left-hand side (\( |\alpha| \leq |\beta| \)).
- **Context-sensitive**: The application of a rule depends on the context (surrounding symbols) of the non-terminal being replaced.

### 2. Formal Definition of Context-sensitive Grammars
- A **CSG** is a 4-tuple \( G = (V, \Sigma, R, S) \):
  - \( V \): Finite set of variables (non-terminals).
  - \( \Sigma \): Finite set of terminals.
  - \( R \): Finite set of production rules of the form \( \alpha \rightarrow \beta \), where \( \alpha = XAY \), \( \beta = XZY \), \( X, Y \in (V \cup \Sigma)^* \), \( A \in V \), \( Z \in (V \cup \Sigma)^+ \).
  - \( S \): Start symbol (\( S \in V \)).

#### Example CSG
- For the language \( \{a^n b^n c^n | n \geq 0\} \):
  - \( S \rightarrow aSBC \), \( CB \rightarrow HB \), \( HB \rightarrow HC \), \( HC \rightarrow BC \), \( aB \rightarrow ab \), \( bB \rightarrow bb \), \( bC \rightarrow bc \), \( cC \rightarrow cc \).

### 3. Linear-bounded Automata (LBAs)
- **LBAs** are a type of Turing machine with a tape bounded by the length of the input.
- **Formal Definition**: An LBA is a 6-tuple \( M = (Q, \Sigma, \Gamma, \delta, q_0, F) \):
  - \( Q \): Finite set of states.
  - \( \Sigma \): Input alphabet.
  - \( \Gamma \): Tape alphabet (\( \Gamma \supseteq \Sigma \)).
  - \( \delta \): Transition function \( Q \times \Gamma \rightarrow Q \times \Gamma \times \{L, R, 0\} \).
  - \( q_0 \): Start state (\( q_0 \in Q \)).
  - \( F \): Set of accept states (\( F \subseteq Q \)).

#### Example LBA
- Consider an LBA that recognizes the language \( \{a^n b^n c^n | n \geq 0\} \).
- The LBA scans the input, ensuring that the number of "a"s, "b"s, and "c"s are equal.

### 4. Chomsky Hierarchy
- The **Chomsky hierarchy** classifies languages based on their generative power and the type of automaton required to recognize them.
- **Levels**:
  1. **Type 3: Regular Languages** - Recognized by DFSAs/NFSAs.
  2. **Type 2: Context-free Languages** - Recognized by PDAs.
  3. **Type 1: Context-sensitive Languages** - Recognized by LBAs.
  4. **Type 0: Recursively Enumerable Languages** - Recognized by Turing Machines.

#### Relationships Between Language Classes
- **Regular Languages** ⊂ **Context-free Languages** ⊂ **Context-sensitive Languages** ⊂ **Recursively Enumerable Languages**.
- **Example**: The language \( \{a^n b^n | n \geq 0\} \) is context-free but not regular. The language \( \{a^n b^n c^n | n \geq 0\} \) is context-sensitive but not context-free.

### 5. Applications of Context-sensitive Languages
- **Programming Languages**: Some features of programming languages, such as type checking and variable scoping, cannot be expressed using context-free grammars.
- **Natural Language Processing**: Some natural languages have features that are not context-free, such as Swiss German.
