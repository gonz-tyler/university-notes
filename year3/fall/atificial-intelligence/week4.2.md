# Week 4.2: Reasoning 2 - Logic and Inference (AIMA Ch 7.1-7.5, Ch 9)
## Notes
---
### **Key Concepts**

---

### **Logical Agents**

1. **Knowledge-Based Agents**:
    - Use a knowledge base (KB) and a reasoning system to infer new knowledge.
    - Components:
        - **Knowledge Base (KB)**: A set of sentences in a formal language.
        - **Inference Engine**: Derives new sentences from the KB.
2. **Propositional Logic**:
    - **Syntax**: Defines the structure of logical sentences.
        - Atomic propositions: $P$, $Q$, $R$, $\dots$
        - Logical connectives: $\neg$ (NOT), $\land$ (AND), $\lor$ (OR), $\implies$ (IMPLIES), $\iff$ (IFF)
    - **Semantics**: Specifies how sentences are evaluated as true or false.
    - **Models**: Assignments of truth values to propositions.
        - A sentence is satisfiable if it has at least one model.
        - A sentence is valid if it is true in all models.
        - A sentence is inconsistent if it has no models.
3. **Inference in Propositional Logic**:
    - **Soundness**: All derived sentences are true.
    - **Completeness**: All true sentences can be derived.
    - **Entailment**: $KB \models \alpha$: Sentence $\alpha$ is true in all models of $KB$.
    - Inference Rules:
        - Modus Ponens: $P \land (P \implies Q) \models Q$
        - Resolution: A complete rule for propositional logic.

---

### **First-Order Logic (FOL)**

1. **Extension of Propositional Logic**:
    - **Objects**: Individuals in the domain.
    - **Predicates**: Properties or relationships (Loves(Alice,Bob)).
    - **Quantifiers**:
        - Universal ($ \forall x$): For all x, a statement holds.
        - Existential ($ \exists x $): There exists an x for which a statement holds.
2. **Inference in FOL**:
    - **Unification**: Finds a substitution of variables that makes expressions identical.
    - **Generalized Modus Ponens**: Applies to FOL for combining premises and inferring conclusions.
    - **Resolution in FOL**:
        - Converts sentences to conjunctive normal form (CNF).
        - Uses unification to resolve clauses.

---

### **Logic Programming (Ch 9)**

1. **Knowledge Representation**:
    - Uses declarative knowledge to encode facts and rules.
    - **Facts**: Parent(John,Mary).
        
        Parent(John,Mary)Parent(John, Mary)
        
    - **Rules**: Ancestor(x,y)←Parent(x,z)∧Ancestor(z,y).
2. **Inference in Logic Programming**:
    - **Forward Chaining**:
        - Starts with known facts and applies rules to derive new facts.
        - Suitable for **data-driven** reasoning.
    - **Backward Chaining**:
        - Starts with a goal and works backward to determine supporting facts.
        - Suitable for **goal-driven** reasoning.
3. **Prolog**:
    - A logic programming language for declarative problem-solving.
    - Uses backward chaining for inference.
4. **Applications**:
    - Expert systems, natural language processing, and decision support systems.

---

### **Key Insights**:

- Propositional logic provides a foundation for reasoning but lacks expressiveness for real-world domains.
- FOL introduces quantifiers and relations, enabling richer representations.
- Logic programming combines reasoning and computation effectively.

---

This chapter provides a deep dive into logical foundations for AI, focusing on formal representation and sound inference methods.
