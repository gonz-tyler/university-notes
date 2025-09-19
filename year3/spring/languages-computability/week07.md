# Week 07: Decidability and Countability

## Notes

---

### **1. Decision Problems and Decidability**

- **Decision Problem**: A yes-or-no question on some input(s).
- **Decision Procedure**: An algorithm that halts and returns yes/no correctly for every instance of a decision problem.
- **Decidable Problem**: A problem for which a decision procedure exists.
- **Semi-Decidable Problem**: A problem where an algorithm outputs "yes" if the answer is "yes" but may loop or not halt otherwise. Every decidable problem is also semi-decidable.

### **2. Examples of Decidable Problems**

- **ADFA**: Given a DFA D and string w, does D accept w?
    - **Proof**: A TM can simulate D on w and halt with accept/reject.
- **ANFA**: Given an NFA N and string w, does N accept w?
    - **Proof**: Convert N*N* to an equivalent DFA D*D* and use the TM for ADFA.
- **ACFG**: Given a CFG G and string w*w*, does G generate w*w*?
    - **Proof**: Convert G to Chomsky Normal Form and check derivations of length ≤2n−1.

### **3. Language Classes and Decidability**

- **Regular Languages**: All are decidable.
- **Context-Free Languages**: All are decidable.
- **Context-Sensitive Languages**: All are decidable.
- **Turing-Recognisable (Recursively Enumerable) Languages**: Includes all decidable languages and some undecidable ones.
- **Non-Turing-Recognisable Languages**: Exist due to uncountability of languages.

### **4. Theorems on Decidability**

- **Complement Theorem**: If L is decidable, then L‾ is also decidable.
- **Turing-Recognisability and Decidability**:
    
    L is decidable iff both L and L‾ are Turing-recognisable.
    

### **5. Countability**

- **Countable Set**: A set S is countable if there exists an injective function f:S→N.
    - Examples: N,Z,Q, all strings over a finite alphabet.
- **Uncountable Set**: No such injective function exists.
    - Examples: RR, all infinite-length binary strings, all languages over a finite alphabet.

### **6. Key Countability Results**

- **Turing Machines**: The set of all TMs is countable (can be enumerated as strings).
- **Turing-Recognisable Languages**: Countably infinite (each corresponds to a TM).
- **All Languages**: Uncountably infinite (bijection with infinite binary strings).
- **Implication**: There exist languages that are not Turing-recognisable.

### **7. Important Definitions**

- **ATM**: The language {⟨M,w⟩∣M is a TM that accepts w}.
    - **Question**: Is ATM decidable? (To be explored further in undecidability.)

## **Summary Diagram**

`Regular ⊂ Context-Free ⊂ Context-Sensitive ⊂ Decidable ⊂ Turing-Recognisable`

- **Decidable**: Halts on all inputs.
- **Turing-Recognisable**: Halts on "yes" inputs, may loop on others.

## **Key Takeaways**

- Decidability formalises the idea of a "definite procedure" using TMs.
- Many language classes (regular, CF, CS) are decidable.
- Countability arguments show limitations: not all languages are recognisable or decidable.
- Next: Undecidability and the Halting Problem.
