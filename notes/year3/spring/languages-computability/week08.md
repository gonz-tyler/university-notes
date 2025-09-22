# Week 08: Undecidability and Reducibility

## Notes

---

### **1. The Universal Turing Machine (UTM)**

- **Definition**: A UTM U takes input ⟨M,w⟩ and simulates TM M on input w.
- **Behavior**:
    - If M accepts w*w*, U accepts.
    - If M rejects w*w*, U rejects.
    - If M loops on w*w*, U loops.
- **Proposition**: U recognizes ATM, proving ATM is Turing-recognizable.

### **2. Undecidability of ATM*ATM***

- **Theorem**: ATM={⟨M,w⟩∣M accepts w} is undecidable.
- **Proof by Contradiction**:
    1. Assume ATM is decidable with decider H.
    2. Construct TM X that inverts H's behavior on ⟨M,⟨M⟩⟩.
    3. Feeding X to itself leads to a contradiction: X accepts ⟨X⟩ iff it rejects ⟨X⟩.
- **Conclusion**: No such H exists; ATM is undecidable.

### **3. The Halting Problem (HALTTM)**

- **Definition**: HALTTM={⟨M,w⟩∣M halts on w}.
- **Theorem**: HALTTM is undecidable.
- **Proof via Reduction**:
    - Show ATM⪯HALTTM: Construct TM F that maps ⟨M,w⟩ to ⟨M′,w⟩, where M′ halts iff M accepts w.
    - Since ATM is undecidable, HALTTM must also be undecidable.

### **4. Reducibility**

- **Definition**: Problem A reduces to problem B (A⪯B) if a computable function f exists such that w∈A iff f(w)∈B.
- **Key Theorems**:
    - If A⪯B and B is decidable, then A is decidable.
    - If A⪯B and A is undecidable, then B is undecidable.
- **Applications**:
    - Prove undecidability by reducing known undecidable problems (e.g., ATM) to new problems.

### **5. Rice’s Theorem**

- **Statement**: Any non-trivial property of a TM's language is undecidable.
- **Conditions**:
    1. P contains only TM descriptions.
    2. P is non-trivial (neither empty nor all TMs).
    3. P depends only on the language of the TM.
- **Example**: ALLTM={⟨M⟩∣L(M)=Σ∗} is undecidable by Rice’s Theorem.

### **6. Turing-Unrecognizable Languages**

- **Example**: ATM‾={⟨M,w⟩∣M does not accept w}∪{invalid inputs}.
- **Theorem**: ATM‾ is not Turing-recognizable.
- **Proof**: If ATM‾ were recognizable, ATM would be decidable (contradiction).

### **7. Other Undecidable Problems**

- **ETM*ETM***: {⟨M⟩∣L(M)=∅} is undecidable but recognizable.
    - **Proof**: Reduce ATM to ETM.
- **Recognizability of ETM**:
    - Construct TM R2 that simulates M on all inputs for increasing steps, accepting if M accepts any input.

## **Summary Diagram**

`Regular ⊂ Context-Free ⊂ Context-Sensitive ⊂ Decidable ⊂ Turing-Recognizable`

- **Undecidable Examples**: ATM,HALTTM,ETM,ALLTM.
- **Non-Recognizable Example**: ATM‾.

## **Key Takeaways**

- **Universal TM**: Simulates any TM, showing ATM is recognizable.
- **Undecidability**: Proved via contradiction or reduction (e.g., ATM⪯HALTTM).
- **Reducibility**: A tool to transfer decidability/undecidability results between problems.
- **Rice’s Theorem**: A powerful tool to prove undecidability for language properties.
- **Limits of Computation**: Some problems (e.g., halting) have no algorithmic solution.
