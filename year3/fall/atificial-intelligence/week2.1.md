# Week 2.1: Search 1 - Uninformed Search (AIMA Ch 3.1-3.5)
## Notes
---
### **Key Concepts**

1. **Problem-Solving Agents**:
    - Use search to find a sequence of actions that lead to a goal.
    - Components of a problem:
        - **Initial state**: The starting point.
        - **Actions**: The set of possible actions available to the agent.
        - **Transition model**: The outcome of performing actions.
        - **Goal test**: Determines if a state is a goal state.
        - **Path cost**: The cost associated with a sequence of actions.
2. **Search Tree**:
    - Nodes represent states and paths to states.
    - **Root node**: Represents the initial state.
    - **Actions expand nodes** to generate successors.
    - Search involves exploring this tree for the goal.
3. **Uninformed Search Strategies**:
    - Do not use any domain-specific knowledge (only the problem definition).
4. **Key Search Strategies**:
    - **Breadth-First Search (BFS)**:
        - Expands the shallowest unexpanded node.
        - **Characteristics**:
            - Complete: Guaranteed to find a solution if one exists.
            - Optimal: Finds the shallowest (least-cost) solution if all step costs are equal.
            - Time/Space Complexity: $O(b^d)$, where $b$ is the branching factor and $d$ is the depth of the shallowest solution.
    - **Uniform-Cost Search (UCS)**:
        - Expands the node with the lowest path cost (uses a priority queue).
        - **Characteristics**:
            - Complete and optimal.
            - Time/Space Complexity: $O(b^{1+\lceil C^*/\epsilon \rceil})$, where $C^*$ is the cost of the optimal solution, and $\epsilon$ is the smallest step cost.
    - **Depth-First Search (DFS)**:
        - Expands the deepest unexpanded node (uses a stack).
        - **Characteristics**:
            - Not complete (can get stuck in infinite depth).
            - Not optimal.
            - Time Complexity: $O(b^m)$, where $m$ is the maximum depth of the search tree.
            - Space Complexity: $O(b^m)$.
    - **Depth-Limited Search (DLS)**:
        - DFS with a pre-defined depth limit.
        - **Characteristics**:
            - Addresses infinite depth issue but is incomplete if the goal is beyond the limit.
            - Not optimal.
    - **Iterative Deepening Search (IDS)**:
        - Repeatedly applies DLS with increasing depth limits.
        - **Characteristics**:
            - Combines benefits of BFS (completeness, optimality) and DFS (space efficiency).
            - Time Complexity: $O(b^d)$
            - Space Complexity: $O(b^d)$
5. **Comparison of Strategies**:
    - **Trade-offs** between completeness, optimality, time complexity, and space complexity.

### **Key Insights**:

- The choice of search strategy depends on the problem requirements (e.g., memory constraints, need for optimality).
- Uninformed search explores the search space blindly, relying only on the problem's structure.

---

This chapter introduces the foundational search methods necessary for problem-solving without heuristic guidance.
