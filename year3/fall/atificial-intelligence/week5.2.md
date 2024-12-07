# Week 5.2: Probabilistic Reasoning 2 - Hidden Markov Models (AIMA Ch 14.1-14.3)
## Notes
---
### **Key Concepts**

1. **Introduction to Hidden Markov Models (HMMs)**:
    - **HMMs** are used for modeling sequential data where the system's state is partially observable.
    - **Components**:
        - **States**: Hidden (unobservable) variables that evolve over time.
        - **Observations**: Observable variables that depend on the state.
        - **Transition Probabilities**: The probability of moving from one state to another.
        - **Emission Probabilities**: The probability of an observation given a state.
        - **Initial State Probabilities**: The probability distribution of the initial state.
2. **HMM as a Probabilistic Model**:
    - A sequence of observations is modeled as a sequence of hidden states and observations, where:
    $ P(O_1, O_2, \dots, O_T | \lambda) = \sum_{S_1, S_2, \dots, S_T} P(O_1, O_2, \dots, O_T, S_1, S_2, \dots, S_T | \lambda) $
    where Oi represents the observation at time i, Si represents the hidden state at time i, and λ represents the model parameters (transition, emission, and initial probabilities).
3. **The Three Fundamental Problems of HMMs**:
    - **1. Evaluation Problem**:
        - Given a sequence of observations, compute the probability of the sequence given the model parameters $P(O_1, O_2, \dots, O_T | \lambda)$
        - **Forward Algorithm**: A dynamic programming algorithm to efficiently compute this probability by breaking it down recursively.
    - **2. Decoding Problem**:
        - Given a sequence of observations, find the most likely sequence of hidden states ($S_1, S_2, \dots, S_T$)
        - **Viterbi Algorithm**: A dynamic programming algorithm that computes the most likely sequence of states by finding the path with the highest probability.
    - **3. Learning Problem**:
        - Given a sequence of observations, learn the parameters of the HMM (transition probabilities, emission probabilities, and initial state probabilities).
        - **Baum-Welch Algorithm**: A special case of the Expectation-Maximization (EM) algorithm that iteratively estimates the model parameters to maximize the likelihood of the observed sequence.
4. **Applications of HMMs**:
    - **Speech Recognition**: Modeling the sequential nature of speech signals where the observed signals (audio features) depend on hidden phonetic states.
    - **Biological Sequence Analysis**: Used for gene prediction or protein structure analysis, where the observed data are DNA or protein sequences, and the hidden states represent biological states (e.g., exon, intron).
    - **Time Series Forecasting**: Predicting future states based on historical observations in fields like finance, robotics, or weather prediction.
5. **Limitations of HMMs**:
    - **Markov Assumption**: Assumes that the future state depends only on the current state and not on previous states, which may not be valid in some applications.
    - **Stationary Transitions**: Assumes that transition probabilities are constant over time, which may not always hold in dynamic environments.

---

### **Key Insights**:

- HMMs are powerful models for handling sequential data where the underlying states are hidden and inferred based on observable evidence.
- The forward, Viterbi, and Baum-Welch algorithms are central to HMM operations, enabling efficient computation and learning.
- Despite their success, HMMs make assumptions (like the Markov property) that can limit their applicability in some contexts.

---

This chapter introduces Hidden Markov Models, a cornerstone technique for sequential probabilistic modeling, widely used in fields such as speech recognition, natural language processing, and bioinformatics.
