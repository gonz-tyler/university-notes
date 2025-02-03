# Week 1: Finite State Automata and Regular Expressions
## Notes
---
## 1. Introduction

### Why Study Formal Languages and Computability?
- Defines the essence of computing.
- Defines what an algorithm is.
- Determines if there are problems unsolvable by computers.
- Establishes the limits of computing.
- Understanding unsolvable problems prevents wasted effort on faster computers.

### How Do We Study It?
- Using mathematical concepts (sets, functions, relations).
- Stripping computing to its fundamental principles.

## 2. Finite State Automata (FSA)

### Preliminaries
- Also known as **Finite State Machines (FSMs)** or simply **Automata**.
- A computational model used to check if a string follows a syntax.

### Terminology
- **Symbols**: Atomic components of a formal language (e.g., digits, letters, special characters).
- **Alphabet (Σ)**: A finite non-empty set of symbols (e.g., {0,1}, {a,b,...,z}).
- **String over Σ**: A finite sequence of symbols (e.g., 010, epsilon (ϵ) represents an empty string).

### Computational Model
- Input tape containing a string.
- Finite State Automaton (FSA).
- Output: **Accept** or **Reject**.

### Transition Graph
- **States**: Represented as circles.
- **Initial state**: Indicated by an unlabelled arrow.
- **Final/accepting state**: Represented by a double circle.
- **Transitions**: Labelled edges showing transitions between states.

### How FSAs Work
- **Head** reads input from left to right.
- **State transitions** occur based on input symbols.
- **End of string** reached:
  - If in an accepting state, **accept**.
  - Otherwise, **reject**.

### Formal Definition of FSA
A finite state automaton **M** is a tuple:
M = (Q, Σ, δ, q0, F), where:
- **Q**: Finite set of states.
- **Σ**: Finite alphabet.
- **δ**: Transition function (Q × Σ → Q).
- **q0**: Initial state.
- **F**: Set of accepting states.

### Language Recognised by an FSA
- **L(M) = A** where A is the set of all accepted strings.
- A machine may accept multiple strings but recognizes only **one** language.
- If M accepts no strings, L(M) = ∅ (empty language).

### Designing FSAs
1. Identify what information needs to be remembered.
2. Represent these as a finite list of states.
3. Define state transitions based on input.
4. Set the initial state.
5. Define accepting states based on desired conditions.

## 3. Regular Expressions (REs)

### Preliminaries
- A notation for representing **languages**.
- Used in pattern matching (e.g., **grep**, **Perl**).

### Formal Definition
A Regular Expression (RE) over an alphabet Σ is defined inductively:
1. Any symbol **a** ∈ Σ is an RE.
2. **ϵ** (empty string) is an RE.
3. **∅** (empty set) is an RE.
4. **(R1 ∪ R2)** (union) is an RE.
5. **(R1 ◦ R2)** (concatenation) is an RE.
6. **(R1\*)** (Kleene star) is an RE.

### Language Represented by REs
- **L(a) = {a}** for any symbol a.
- **L(ϵ) = {ϵ}**
- **L(∅) = ∅**
- **L(R1 ∪ R2) = L(R1) ∪ L(R2)**
- **L(R1 ◦ R2) = {w1 ◦ w2 | w1 ∈ L(R1), w2 ∈ L(R2)}**
- **L(R\*) = \⋃∞ i=0 L(R i)**

### Examples
1. **L(0*) = {ϵ, 0, 00, 000, ...}**
2. **L((0 ∪ 1) ◦ 1) = {01, 11}**
3. **L(0\*10\*) =** The set of strings with exactly one '1'.
4. **L(Σ\*1Σ\*) =** The set of strings with at least one '1'.

### Notation Variants
- Some books use **R1 + R2** instead of **R1 ∪ R2**.
- **Concatenation** may be written as juxtaposition (R1 R2).
- **R+** is shorthand for **RR*** (one or more occurrences).

### Interesting Properties
- **∅ ◦ R = R ◦ ∅ = ∅** (Concatenation with empty set results in empty set).
- **(R\*)\* = R\*** (Star is idempotent).
- **R ∪ ∅ = R** (Union with empty set is R).
- **R ◦ ϵ = R** (Concatenation with empty string is R).
- **R ∪ ϵ ≠ R** (Union with empty string is different if R ≠ ϵ).

## 4. Equivalence of REs and FSAs
- **Theorem**: A language is regular **if and only if** some RE describes it.
- **Proof outline**:
  1. Convert an RE **R** to an equivalent **FSA M**.
  2. Convert an **FSA M** to an equivalent **RE R**.
- **Conclusion**: FSAs and REs have the same expressive power.

## 5. Non-Regular Languages
- Some languages **cannot** be represented by FSAs or REs.
- Examples:
  - **L = {ϵ, 01, 0011, 000111, ...}** (not regular).
  - **L = {w | w has equal number of 0s and 1s}** (not regular).
  - **L = {ww | w ∈ Σ\*}** (not regular).

### Pumping Lemma
- A technique to prove that a language is **not** regular.
- **Regular languages** satisfy a property where **strings can be “pumped”**.
- If a language **fails** the pumping lemma, it is **not regular**.

## Summary
### What You Should Know
1. **Finite State Automata**
   - Understand how FSAs process strings.
   - Design FSAs for given languages.
   - Prove whether an FSA can recognize a language.
2. **Regular Expressions**
   - Compute the language of an RE.
   - Convert language descriptions to REs.
3. **Equivalence of FSAs and REs**
   - Convert between FSAs and REs.
4. **Non-Regular Languages**
   - Identify languages that cannot be recognized by FSAs.
   - Use the Pumping Lemma to prove non-regularity.

### Next Steps
- Exercises on FSAs and REs to reinforce concepts.
- Further studies in computability and complexity theory.
