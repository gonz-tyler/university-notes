# Week 5.1: Probabilistic Reasoning 1 - Bayesian Networks (AIMA Ch 12-13)
## Notes
---

### **Key Concepts**

1. **Introduction to Probabilistic Reasoning**:
    - Captures uncertainty using probability theory.
    - Uses a **joint probability distribution (JPD)** to represent probabilities for all variables.
2. **Bayesian Networks (Belief Networks)**:
    - Compact representation of the JPD using a directed acyclic graph (DAG).
    - **Nodes**: Represent random variables.
    - **Edges**: Represent direct probabilistic dependencies.
    - **Conditional Probability Table (CPT)**: Specifies the probability of a node given its parents.
3. **Independence and Conditional Independence**:
    - **Independence**: P(A,B)=P(A)P(B).
    - **Conditional Independence**: P(A,B∣C)=P(A∣C)P(B∣C).
    - Bayesian networks exploit these properties to simplify JPD.
4. **Constructing Bayesian Networks**:
    - Identify variables and relationships.
    - Define CPTs for each node based on domain knowledge or data.
    - Ensure consistency with independence assumptions.
5. **Inference in Bayesian Networks**:
    - Goal: Compute posterior probabilities of query variables given evidence (P(X∣E)).
    - **Exact Inference**:
        - **Enumeration**: Sum out irrelevant variables from the JPD.
        - **Variable Elimination**: A more efficient method using dynamic programming.
    - **Approximate Inference**:
        - Sampling methods such as **Monte Carlo** and **Gibbs sampling**.
        - Useful for large or complex networks.
6. **Explaining Away**:
    - Evidence about one cause can affect beliefs about other causes due to dependencies.
7. **Dynamic Bayesian Networks (DBNs)**:
    - Extension of Bayesian networks for temporal processes.
    - Represent state transitions over time (e.g., Hidden Markov Models).
8. **Applications of Bayesian Networks**:
    - Medical diagnosis (e.g., diseases and symptoms).
    - Fault detection in systems.
    - Decision support systems.

---

### **Key Insights**:

- Bayesian networks provide an efficient framework for probabilistic reasoning in complex domains.
- Independence assumptions enable scalability and tractability.
- Exact and approximate inference methods balance precision and computational efficiency.

---

This chapter builds a foundation for reasoning under uncertainty, a critical component of intelligent decision-making in real-world systems.
