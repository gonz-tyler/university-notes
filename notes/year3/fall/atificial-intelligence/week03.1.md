# Week 3: Search 3 - Local Search (AIMA Ch 4.1-4.4)
## Notes
---
### **Key Concepts**

1. **Local Search Algorithms**:
    - Operate using a single current state (instead of maintaining multiple paths).
    - Suitable for optimization problems where the goal is to find the best solution.
    - Focus on improving the current state rather than systematic exploration.
2. **Advantages of Local Search**:
    - Use constant memory.
    - Suitable for large or infinite state spaces.
    - Effective in problems with no explicit path requirements (e.g., traveling salesperson problem).
3. **Hill-Climbing (Greedy Local Search)**:
    - Iteratively moves to the neighboring state with the highest value (or lowest cost).
    - **Variants**:
        - **Simple hill-climbing**: Chooses the first neighbor that improves the current state.
        - **Steepest ascent hill-climbing**: Examines all neighbors and selects the best one.
        - **Stochastic hill-climbing**: Chooses a neighbor at random.
    - **Problems**:
        - **Local maxima**: Peaks that are lower than the global maximum.
        - **Plateaus**: Flat areas with no improvement.
        - **Ridges**: Narrow paths that are hard to climb.
4. **Simulated Annealing**:
    - Inspired by the annealing process in metallurgy.
    - Allows occasional "downhill" moves to escape local maxima.
    - **Key Parameters**:
        - Temperature ($T$): Controls the probability of accepting worse solutions.
        - Cooling schedule: Determines how $T$ decreases over time.
    - **Advantages**:
        - Can find global optimum if cooling is sufficiently slow.
    - **Applications**: Effective in problems like VLSI layout and scheduling.
5. **Local Beam Search**:
    - Keeps track of $k$ states instead of one.
    - At each step, generates successors of all $k$ states and selects the $k$ best ones.
    - **Stochastic Beam Search**:
        - Probabilistic selection of states based on their fitness.
    - **Advantages**:
        - Can share information between parallel searches.
    - **Limitation**:
        - Risk of all states converging to a single path (loss of diversity).
6. **Genetic Algorithms (GA)**:
    - Inspired by natural selection and evolution.
    - Represent states as **chromosomes** (strings or data structures).
    - **Key Operations**:
        - **Selection**: Choose the fittest individuals.
        - **Crossover**: Combine parts of two parent solutions.
        - **Mutation**: Randomly alter parts of a solution to introduce diversity.
    - **Applications**:
        - Optimization problems with large, complex search spaces.
    - **Advantages**:
        - Can escape local optima through diversity.

### **Comparison of Techniques**:

- **Hill-Climbing**: Simple but prone to local optima.
- **Simulated Annealing**: Balances exploration and exploitation over time.
- **Local Beam Search**: Adds parallelism but risks convergence.
- **Genetic Algorithms**: Encourage diversity but require parameter tuning.

### **Key Insights**:

- Local search methods are powerful for optimization tasks, especially when state space is large.
- Success depends on escaping local optima and balancing exploration with exploitation.

---

This chapter focuses on strategies for effectively navigating search spaces without exhaustive exploration.
