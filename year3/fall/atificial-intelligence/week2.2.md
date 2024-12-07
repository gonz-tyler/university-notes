# Week 2.2: Search 2 - Heuristic Search (AIMA Ch 3.5-3.6)
## Notes
---
### **Key Concepts**

1. **Heuristic Search**:
    - Enhances search efficiency by incorporating problem-specific knowledge.
    - **Heuristic Function (h(n))**:
        - Estimates the cost from a node n to the goal.
        - A good heuristic reduces the search effort while maintaining accuracy.
2. **Greedy Best-First Search**:
    - Expands the node with the lowest heuristic value h(n).
    - **Characteristics**:
        - Focuses on the most "promising" path based on heuristic estimates.
        - **Complete**: No, can get stuck in loops.
        - **Optimal**: No, may find suboptimal solutions.
        - Time/Space Complexity: $O(b^m)$, where m is the maximum depth.
    - Works well when the heuristic is accurate but risks being misled by poor heuristics.
3. **A* Search**:
    - Combines actual cost to reach a node g(n) with the heuristic h(n).
    - **Evaluation Function**: $f(n) = g(n) + h(n)$.
    - **Characteristics**:
        - Complete and optimal if h(n) is admissible and consistent.
        - Admissibility: $h(n) ≤ h*(n)$, where $h*(n)$ is the true cost to the goal.
        - Consistency (Monotonicity): $h(n) ≤ c(n,a,n') + h(n')$, where $c(n,a,n')$ is the cost of reaching $n'$ from $n$.
        - Time/Space Complexity: Exponential in the worst case, $O(b^d)$.
4. **Heuristic Design**:
    - Derived from problem abstractions.
    - Examples:
        - **8-Puzzle**:
            - Misplaced tiles heuristic $(h_1)$: Counts the number of misplaced tiles.
            - Manhattan distance heuristic $(h_2)$: Sum of the distances of each tile from its goal position.
            - $(h_2)$ is more informed than $(h_1)$.
5. **Optimality of A***:
    - $h(n)$ impacts the search space explored:
        - $h(n) = 0$: Reduces $A^*$ to Uniform-Cost Search.
        - Overestimating $h(n)$: Leads to suboptimal solutions (violates admissibility).
6. **Memory-Bounded Heuristic Search**:
    - *Iterative Deepening A* (IDA*)*:
        - Repeatedly applies depth-first search using f(n) as a threshold.
        - Uses less memory than A*.
    - *Simplified Memory-Bounded A* (SMA*)*:
        - Discards least promising nodes when memory is full.
        - Balances space efficiency and optimality.
7. **Performance Metrics**:
    - Evaluating heuristics using **effective branching factor**:
        - The branching factor of a uniform search tree that matches the performance of the heuristic search.

### **Key Insights**:

- Heuristics improve efficiency by guiding the search process but must be carefully designed.
- A* is a powerful algorithm that balances exploration and exploitation when using effective heuristics.

---

This chapter focuses on heuristics as a critical tool for intelligent problem-solving and optimization in search algorithms.
