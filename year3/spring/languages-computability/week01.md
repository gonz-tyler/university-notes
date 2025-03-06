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
1. **L(0\*) = {ϵ, 0, 00, 000, ...}**
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
Finite State Automata (FSAs):
- What is it? An FSA is a computational model used to recognize patterns in strings. It consists of states, transitions between states, and an input string. The FSA reads the input string one symbol at a time and transitions between states based on the current symbol.

- Example: Consider an FSA that recognizes strings with an odd number of `1`s over the alphabet `{0, 1}`.

  - States: Two states: `q_even` (even number of `1`s) and `q_odd` (odd number of `1`s).

  - Transitions:

    - From `q_even`, if you read `0`, stay in `q_even`.

    - From `q_even`, if you read `1`, move to `q_odd`.

    - From `q_odd`, if you read `0`, stay in `q_odd`.

    - From `q_odd`, if you read `1`, move back to `q_even`.

  - Accept State: `q_odd` is the accepting state.

  If the input string is `101`, the FSA will:

  - Start in `q_even`.

  - Read `1`, move to `q_odd`.

  - Read `0`, stay in `q_odd`.

  - Read `1`, move back to `q_even`.

  - Since the final state is `q_even` (not accepting), the string `101` is not accepted.

Regular Expressions (REs):
- What is it? A regular expression is a sequence of characters that defines a search pattern, typically used for string matching. REs are used to describe regular languages, which are languages that can be recognized by FSAs.

- Example: The regular expression `(0 ∪ 1)*1(0 ∪ 1)*` describes all strings over `{0, 1}` that contain at least one `1`.

  - `(0 ∪ 1)*` means any combination of `0`s and `1`s (including none).

  - `1` means the string must contain at least one `1`.

  - `(0 ∪ 1)*` again means any combination of `0`s and `1`s after the `1`.

  So, strings like `010`, `111`, and `1001` are accepted, but `000` is not.
