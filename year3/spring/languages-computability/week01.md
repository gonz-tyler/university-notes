# Week 01: Finite State Automata (FSAs) and Regular Expressions (REs)
## Notes
---

### 1. Introduction

#### Why Study Formal Languages and Computability?

- **Purpose**: Formal languages and computability help us understand the **limits of computation** and what problems can or cannot be solved by computers.
- **Key Questions**:
    - What is an algorithm?
    - Are there problems that computers **cannot solve**?
    - What are the **limits of computing**?
- **Example**: The **Halting Problem** is a classic example of a problem that cannot be solved by any computer algorithm.

#### How Do We Study It?

- We use **mathematical tools** like sets, functions, and relations to model computation.
- We strip down computing to its **basic principles** to understand what is possible and what is not.

---

### 2. Finite State Automata (FSAs)

#### What is an FSA?

- An FSA is a **computational model** used to recognize patterns in strings.
- It consists of:
    - **States**: Represented as circles.
    - **Transitions**: Arrows between states, labeled with input symbols.
    - **Start State**: Where the computation begins.
    - **Accept States**: If the FSA ends in one of these states after reading the input, the string is accepted.

#### Terminology

- **Symbols**: The basic building blocks of strings (e.g., `0`, `1`, `a`, `b`).
- **Alphabet (Σ)**: A finite set of symbols (e.g., `Σ = {0, 1}`).
- **String**: A sequence of symbols (e.g., `010`, `111`).
- **Empty String (ε)**: A string with no symbols.

#### How FSAs Work

- The FSA reads the input string **one symbol at a time**.
- It transitions between states based on the current symbol.
- If the FSA ends in an **accept state** after reading the entire string, the string is **accepted**; otherwise, it is **rejected**.

#### Transition Graph

![](Pasted%20image%2020250510183921.png)
- Graphic Representation of FSAs
- Each node/vertex (**circle**) is a **state**
	- **initial state** - q1 (indicated by an **unlabelled arrow**)
	- **final/accepting state** - q2 (indicated by **double circle**)
- States connected by labelled transitions (**edges**)
- Labels of transitions compared against characters from input tape

#### Formal Definition of FSA

- Finite state automaton M is a tuple $M = (Q,\Sigma, \delta, q_0, F)$ where
	- $Q$ is a finite set of **states**
	- $\Sigma$ is a finite set of symbols, our **alphabet**
	- $\delta : Q \times \Sigma \mapsto Q$ is the **transition function**
	- $q_0 \in Q$ is the **initial/start state**
	- $F \subseteq Q$ is the set of **accept states**
- FSAs may have many accepting states: F can be empty (no accepting states) and F can have more than one state
- There must be a transition for all symbols in every state: $\delta$ is a function defined for all values of $Q$ and $\Sigma$ 
#### Example: FSA for Strings with an Odd Number of `1`s

- **Alphabet**: `Σ = {0, 1}`
- **States**:
    - `q_even`: Even number of `1`s.
    - `q_odd`: Odd number of `1`s.
- **Transitions**:
    - From `q_even`, on `0`, stay in `q_even`.
    - From `q_even`, on `1`, move to `q_odd`.
    - From `q_odd`, on `0`, stay in `q_odd`.
    - From `q_odd`, on `1`, move back to `q_even`.
- **Accept State**: `q_odd`.
- **Example Input**: `101`
    - Start in `q_even`.
    - Read `1`, move to `q_odd`.
    - Read `0`, stay in `q_odd`.
    - Read `1`, move back to `q_even`.
    - Final state: `q_even` (not accepting). So, `101` is **rejected**.
![](Pasted%20image%2020250510191308.png)

#### Language Recognised by a FSA
- If $A$ is set of all strings $M$ accepts then
	- $A$ is the **language** of $M$
	- $L(M)=A$
	- We say $M$ **recognises** $A$ or that $M$ **accepts** $A$
- A machine (FSA) may accept several (infinite) strings
- A machine recognises only one language
- If $M$ accepts no strings it still recognises the empty language $L(M)=\emptyset$ ($\emptyset$ is the empty set)
- A language is called **regular** if some FSA recognises it
---

### 3. Regular Expressions (REs)

#### What is a Regular Expression?

- A **regular expression** is a sequence of characters that defines a **pattern** for matching strings.
- REs are used to describe **regular languages**, which are languages that can be recognized by FSAs.

#### Formal Definition of REs

- A regular expression is defined inductively:
    1. **Symbols**: Any symbol $\alpha$ in the alphabet $\Sigma$ is an RE (e.g., $0$, $1$).
    2. **Empty String**: $\varepsilon$ is an RE.
    3. **Empty Set**: $\emptyset$ is an RE (matches nothing).
    4. **Union**: $(R_1 \cup R_2)$ matches strings in $R_1$ or $R_2$.
    5. **Concatenation**: $(R_1 \circ R_2)$ matches strings formed by concatenating a string from $R_1$ with a string from $R_2$.
    6. **Kleene Star**: $(R^*)$ matches zero or more repetitions of $R$.

#### Notation

- Parentheses can be omitted if resulting RE is unambiguous
	- Evaluation precedence: star, concatenation, union
		- $((1^*)\circ 0)$ can be written as $1^*\circ0$
		- $(1\circ0)^*$ parentheses cannot be removed
- For convenience we define $R^+=RR^*$
	- $R^*$: 0 or more concatenations of strings from $R$ (**includes** $\varepsilon$)
	- $R^+$: 1 or more concatenations of strings from $R$ (**excludes** $\varepsilon$)
	- $R^+\cup \varepsilon = R^*$ ($R^+$ and the empty string $\varepsilon$ = $R^*$)

#### Language Represented by RE

- $L(R)$ is the language (strings) represented by $R$:
	- $L(a)=\{a\}$ for any symbol $a \in \Sigma$
	- $L(\varepsilon) = \{\varepsilon\}$
	- $L(\emptyset) = \{\emptyset\}$
	- $L(R_1\cup R_2) = L(R_1)\cup L(R_2)$
	- $L(R_1\circ R_2) = \{ w_1 \circ w_2 | w_1 \in L(R_1), w_2\in L(R_2)\}$ 
	- $L(R^*) = U^\infty _{i=0} L(R^i)$ where
		- $L(R^0) = \{\varepsilon\}$
		- $L(R^1) = L(R)$
		- $L(R^{i+1}) = L(R^i \circ R) = \{w \circ v | w \in L(R^i), v \in L(R)\}$ 
	- The short hand $\Sigma^*$ where $\Sigma + \{a_1,a_2,...,a_n\}$ is often used to mean $L((a_1\cup a_2\cup ... \cup a_n)^*)$

#### Examples of REs

1. **RE for Strings with Exactly One `1`**:
    - $L(0^*\circ1\circ0^*)$
    - Matches: $\{1, 01, 10, 010,...\}$
    - Does not match: `11`, `000`, `1010`.
2. **RE for Strings with At Least One `1`**:
    - $L(\Sigma^*\circ1\circ\Sigma^*$ (where $\Sigma = \{0, 1\}$)
    - Matches: $\{1, 01, 10, 111, 0101,...\}$ 
    - Does not match: `000`.
3. **RE for Strings with Even Length**:
    - `(00 ∪ 01 ∪ 10 ∪ 11)*`
    - Matches: `00`, `01`, `10`, `11`, `0000`, `0101`, etc.
    - Does not match: `0`, `1`, `000`.

- $\emptyset \circ R = R \circ \emptyset = \emptyset$ ($\emptyset$ concatenated with any $R$ is $\emptyset$)
- $(R^*)^* = R^*$ (star is idempotent)
- $\emptyset^* = \varepsilon$ (since $L(\emptyset^0) = \{\varepsilon\}$ and $L(\emptyset^1)=\{\}$)
- $R\cup\emptyset = \emptyset \cup R = R$ 
- $R\circ \varepsilon = \varepsilon \circ R= R$ 

---

### 4. Equivalence of REs and FSAs

#### Theorem:

- A language is **regular** if and only if it can be described by a **regular expression**.
- This means that **FSAs** and **REs** have the same expressive power.

#### Proof Outline:

1. **RE to FSA**: Given a regular expression, we can construct an FSA that recognizes the same language.
2. **FSA to RE**: Given an FSA, we can construct a regular expression that describes the same language.

#### Example:

- **RE**: `(0 ∪ 1)*1(0 ∪ 1)*`
- **FSA**: An FSA that accepts any string containing at least one `1`.

---

### 5. Non-Regular Languages

#### What is a Non-Regular Language?

- Some languages **cannot** be recognized by any FSA or described by any RE.
- These languages require more powerful computational models, like **Pushdown Automata (PDAs)**.

#### Examples of Non-Regular Languages:

1. **Language with Equal Number of `0`s and `1`s**:
    - `L = {0^n 1^n | n ≥ 0}`
    - This language cannot be recognized by an FSA because an FSA cannot "count" the number of `0`s and `1`s.
2. **Language with Repeated Substrings**:
    - `L = {ww | w ∈ Σ*}`
    - This language cannot be recognized by an FSA because it requires remembering the first half of the string to compare it with the second half.

#### Pumping Lemma:

- A tool used to prove that a language is **not regular**.
- **Idea**: If a language is regular, then any sufficiently long string in the language can be "pumped" (repeated) to generate new strings that are also in the language.
- If a language **fails** the pumping lemma, it is **not regular**.

---

### Summary

#### Finite State Automata (FSAs):

- **What is it?** An FSA is a computational model used to recognize patterns in strings. It consists of states, transitions, and an input string.
- **Example**: An FSA that recognizes strings with an odd number of `1`s.

#### Regular Expressions (REs):

- **What is it?** A regular expression is a sequence of characters that defines a search pattern, typically used for string matching.
- **Example**: The regular expression `(0 ∪ 1)*1(0 ∪ 1)*` describes all strings over `{0, 1}` that contain at least one `1`.
