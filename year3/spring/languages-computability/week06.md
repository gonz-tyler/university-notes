# Week 06: The Church-Turing Thesis
## Notes
---

## 1. Introduction to Formal Models of Computation

- **Finite Automata (FA)**: small memory
- **Pushdown Automata (PDA)**: stack-based memory (LIFO)
- **Linear Bounded Automata (LBA)**: restricted memory use
- **Turing Machines (TM)**: most general and powerful

### Why TMs?
- Capture any computation a real computer can perform
- Introduced by **Alan Turing** (1936)

---

## 2. Turing Machines – Informal Description

- Infinite tape with read/write head
- Initially tape has input; rest is blank
- TM writes data to tape, moves head, and changes state

### Accept/Reject:
- Accept: reaches `q_accept` state
- Reject: reaches `q_reject` state
- May also **loop forever**

---

## 3. Example TM: Testing w#w

Language: B = {w#w | w ∈ {0,1}*}

### How TM M1 works:
1. Compare corresponding symbols across `#`
2. Mark matched symbols
3. Accept if all match, reject on mismatch

---

## 4. Formal Definition of a Turing Machine

M = (Q, Σ, Γ, δ, q₀, q_accept, q_reject)

- Q: finite set of states
- Σ: input alphabet
- Γ: tape alphabet (Σ ⊆ Γ, includes blank symbol)
- δ: transition function
  - δ: Q \\ {q_accept, q_reject} × Γ → Q × Γ × {L, R}
- q₀: start state
- q_accept: accept state
- q_reject: reject state

---

## 5. TM Configurations

- A **configuration** = (current state, tape content, head position)
- Notation: `u q v` = tape = `uv`, head over `v[0]`, current state `q`

---

## 6. TM Computation and Halting

- Computation = sequence of configurations
- TM **accepts** input w if it reaches `q_accept`
- **Halting**: either accepts, rejects, or **loops forever**

---

## 7. Recognisable vs Decidable Languages

| Term                 | Definition                                       |
|----------------------|--------------------------------------------------|
| Turing-recognisable  | TM halts on accept, may loop on others           |
| Decidable            | TM halts on all inputs                           |
| Decider              | TM that always halts                             |

---

## 8. Example TM M2 – Recognising {0^(2ⁿ)}

- Input: string of 0s
- Algorithm:
  1. Cross off every second 0
  2. If 1 zero remains → accept
  3. If odd number of zeros > 1 → reject
  4. Repeat

---

## 9. TM Variants (Same Power)

- **Multitape TMs**: Simulate multiple tapes on one
- **Nondeterministic TMs**: Try all computation paths
- **Enumerators**: TMs that print output

---

## 10. The Definition of Algorithms

- 20th-century need for precision
- **Hilbert’s 10th Problem**: Is there an algorithm to test if a polynomial has integer roots?
- Answer: **No algorithm exists** (proved by Matijasevič, 1970)

---

## 11. Church-Turing Thesis

> Every effectively computable function is Turing-computable.

- Proposed independently by:
  - **Church** (λ-calculus)
  - **Turing** (Turing Machines)

- Established equivalence of formal definitions of “algorithm”

---

## 12. Undecidability Example

D = {⟨p⟩ | p is a polynomial with an integer root}

- **Undecidable** but **Turing-recognisable**
- Example TM: test values x = 0, 1, −1, 2, −2, ...

---

## 13. Levels of TM Description

1. **Formal** – Full state machine with δ
2. **Implementation-level** – Describes head movement, tape use
3. **High-level** – Algorithmic steps, abstracted details

---

## 14. TM Input Representations

- All inputs must be strings
- Use encoding:
  - ⟨O⟩ = object encoded as string
  - ⟨O₁, O₂, ..., Oₖ⟩ = tuple of objects as string

---

## 15. TM Example: Connected Graph

Language A = {⟨G⟩ | G is a connected undirected graph}

### TM M:
1. Mark a start node
2. Iteratively mark nodes connected to already marked ones
3. Accept if all nodes are marked

---

## 16. TM Implementation Details for Graph Connectivity

- Use dot and underline marks
- Mark nodes and track reachability via edges
- Use multiple stages to simulate graph traversal

---

## Summary Table

| Concept                | Description                                         |
|------------------------|-----------------------------------------------------|
| Turing Machine         | Formal model of computation                         |
| Configuration          | State + tape + head                                 |
| Recogniser vs Decider  | Recogniser may loop; decider halts                  |
| Church-Turing Thesis   | All algorithms are Turing-computable                |
| Hilbert’s 10th Problem | First major undecidable problem                     |
| TM Input Encoding      | All data is processed as strings                    |
| Description Levels     | From low-level δ to high-level algorithms           |

---

## Further Reading

- [Wikipedia – Alan Turing](https://en.wikipedia.org/wiki/Alan_Turing)
- [Stanford – Turing Machines](https://plato.stanford.edu/entries/turing-machine/)
- [Turing Machine Simulator](https://turingmachinesimulator.com/)
- [Turing's Original Paper (1936)](https://www.cs.virginia.edu/~robins/Turing_Paper_1936.pdf)
