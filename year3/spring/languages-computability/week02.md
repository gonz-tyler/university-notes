# Week 02: Non-deterministic Finite State Automata (NFSAs)
## Notes
---

### 1. Introduction to NFSAs

#### What is an NFSA?

- An **NFSA** is an extension of a **Deterministic Finite State Automaton (DFSA)**.
- Unlike DFSAs, NFSAs allow **multiple transitions** for the same input symbol from a given state.
- NFSAs can also have **ε-transitions** (transitions that do not consume any input symbol).

#### Key Differences Between DFSAs and NFSAs

- **DFSAs**:
    - For each state and input symbol, there is **exactly one transition**.
- **NFSAs**:
    - For each state and input symbol, there can be **zero, one, or multiple transitions**.
    - Can have **ε-transitions** (transitions that do not consume any input symbol).
![](Pasted%20image%2020250510205152.png)
#### Example NFSA

- Consider an NFSA that accepts all strings over `{0, 1}` that end with `01`.
- The NFSA can have multiple transitions for the same input symbol, allowing it to "guess" the correct path to acceptance.

---

### 2. Formal Definition of NFSAs

#### NFSA as a 5-tuple

- An **NFSA** is defined as a 5-tuple $N=(Q,\Sigma,\delta,q_0,F)$:
    - $Q$: Finite set of **states**
    - $\Sigma$: Input **alphabet**
    - $\delta$: **Transition function** $Q\times\Sigma_\varepsilon\mapsto P(Q)$, where $\Sigma_\varepsilon=\Sigma\cup\{\varepsilon\}$ and $P(Q) = \{\emptyset,\{a\},\{b\},\{a,b\}\}$
    - $q_0$​: **Start state**
    - $F\subseteq Q$: Set of **accept states**

#### Transition Function - NFSAs Key Idea

- The transition function δ returns a **set of states** rather than a single state.
- For example, δ(q1,0)={q2,q3} means that from state q1​, reading input symbol `0`, the NFSA can transition to either q2​ or q3.

---

### 3. Execution of NFSAs

#### How NFSAs Work

- When processing an input string, the NFSA can **split into multiple "copies"** and follow all possible transitions in parallel.
- **Acceptance**: The NFSA accepts a string if **at least one** of the parallel computations reaches an accept state.
- **Rejection**: The NFSA rejects a string if **none** of the parallel computations reach an accept state.

#### Example Execution

- NFSA M
	![[Pasted image 20250510212219.png]]

- Example is $010 \in L(M)$
- **step 0:** 010
	- we begin at the initial state $q_0$
	![](Pasted%20image%2020250510211141.png)
- **step 1:** **0**10
	- we read 0 and move to $q_1$ from $q_0$
	![](Pasted%20image%2020250510212014.png)
- **step 2:** 0**1**0
	- we read 1 and stay in $q_1$
	![](Pasted%20image%2020250510212104.png)
- **step 3:** 0**1**0
	- we move back to $q_0$ without consuming any characters
	![](Pasted%20image%2020250510212610.png)
- **step 4:** 01**0**
	- we read 0 and move to $q_1$
	![](Pasted%20image%2020250510212723.png)
- End of string
- Current state $q_1\in F$ so $010 \in L(M)$

- What happens if we make a wrong decision
![](Pasted%20image%2020250510212922.png)
- at step 1 (**0**10) we would be stuck in $q_0$ as there are no transitions labelled 1
	- in this situation we cannot state that $w\notin L(M)$
	- to establish that $w\notin L(M)$ we have to try **all** possibilities

#### Computing by Hand
- When you are simulating a NFSA, you can often do better  
	- Start from an accepting state and **work backwards**  
	- Consume the string from the **end** to the **start**  
	- Follow the transitions in their **reverse direction**  
		- For ϵ-transitions, follow the edge **without** consuming an input symbol  
	- If you can find a **reverse path** to the start state then string is **accepted**  

---

### 4. Equivalence of NFSAs and DFSAs

#### Theorem:

- Every **NFSA** has an equivalent **DFSA**.
- This means that NFSAs and DFSAs recognize the **same class of languages** (regular languages).

#### Proof: Subset Construction

- The proof uses **subset construction**, where each state in the DFSA corresponds to a **set of states** in the NFSA.
- **Steps**:
    1. The states of the DFSA are all possible subsets of the states of the NFSA.
    2. The transition function of the DFSA is defined based on the transitions of the NFSA.

#### Example of Subset Construction

- Given an NFSA with states {q1,q2}{*q*1​,*q*2​}, the corresponding DFSA will have states:
    - $\emptyset$ (empty set)
    - $\{q_1\}$
    - $\{q_2\}$
    - $\{q_1,q_2\}$
- The transitions in the DFSA are defined based on the transitions of the NFSA. For example:
    - If $\delta(q_1,0)=\{q_2\}$ and $\delta(q_2,0)=\{q_1\}$, then in the DFSA:
        - From $\{q_1,q_2\}$, on input $0$, the DFSA transitions to $\{q_1,q_2\}$

---

### 5. Closure Properties of Regular Languages

#### What are Closure Properties?

- Regular languages are **closed** under certain operations, meaning that applying these operations to regular languages results in another regular language.

#### Closure Under Union

- If $L_1$​ and $L_2$​ are regular languages, then $L_1\cup L_2$ is also regular.
- **Proof Idea**:
    - Given two NFSAs $N_1$​ and $N_2$, we can construct a new NFSA $N$ that accepts $L(N_1)\cup L(N_2)$
    - The new NFSA $N$ has a new start state with **ε-transitions** to the start states of $N_1$​ and $N_2$.
    ![](Pasted%20image%2020250510214753.png)

#### Closure Under Intersection

- If $L_1$​ and $L_2$​ are regular languages, then $L_1\cap L_2$ is also regular.
- **Proof Idea**:
    - Given two NFSAs $N_1$​ and $N_2$, we can construct a new NFSA $N$ that accepts $L(N_1)\cap L(N_2)$
    - The new NFSA $N$ has a new start state with **ε-transitions** to the start states of $N_1$​ and $N_2$.
	
#### Closure Under Complement

- If $L_1$​​ is a regular language, then $L_1^C$ is also regular.

#### Closure Under Concatenation

- If L1​ and L2​ are regular languages, then L1∘L2 (concatenation) is also regular.
- **Proof Idea**:
    - The NFSA for L1∘L2 connects the accept states of N1*N*1​ to the start state of N2*N*2​ using ε-transitions.
	![](Pasted%20image%2020250510214835.png)
	
#### Closure Under Star

- If L is a regular language, then L* (Kleene star) is also regular.
- **Proof Idea**:
    - The NFSA for L* adds ε-transitions from the accept states back to the start state, allowing for zero or more repetitions of L.
	![](Pasted%20image%2020250510214930.png)
---

### Example: NFSA for Strings Ending with `01`

#### NFSA Definition

- **States**: Three states: `q0`, `q1`, and `q2`.
- **Transitions**:
    - From `q0`, on `0`, go to `q0` or `q1`.
    - From `q0`, on `1`, go to `q0`.
    - From `q1`, on `1`, go to `q2`.
- **Accept State**: `q2`.

#### Execution Example

- **Input String**: `001`
    - Start in `q0`.
    - Read `0`, stay in `q0` or move to `q1`.
    - Read `0`, stay in `q0` or move to `q1`.
    - Read `1`, move to `q2` (if in `q1`).
    - Since one path leads to `q2` (accepting state), the string `001` is **accepted**.

---

### Summary

#### Non-deterministic Finite State Automata (NFSAs):

- **What is it?** An NFSA is similar to an FSA, but it can have multiple transitions for the same input symbol from a given state. This means that the NFSA can be in multiple states at once, and it accepts a string if **any** of the possible paths leads to an accepting state.
- **Example**: An NFSA that recognizes strings ending with `01` over the alphabet `{0, 1}`.

#### Equivalence of NFSAs and DFSAs:

- Every NFSA can be converted into an equivalent DFSA using **subset construction**.

#### Closure Properties:

- Regular languages are closed under **union**, **concatenation**, and **star**.
