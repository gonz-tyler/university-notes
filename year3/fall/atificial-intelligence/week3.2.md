# Week 3.2: Search 4 - Adversarial Search (AIMA Ch 5)
## Notes
---
### **Key Concepts**

1. **Adversarial Search**:
    - Used for competitive environments where multiple agents (players) interact.
    - One agent’s gain is often another’s loss, e.g., games like chess or tic-tac-toe.
2. **Game Definitions**:
    - **Zero-sum games**: The utility values of all players sum to zero.
    - **Deterministic games**: No randomness (e.g., chess).
    - **Stochastic games**: Involve randomness (e.g., backgammon).
3. **Game Trees**:
    - Represent the possible moves and outcomes.
    - Nodes are game states; edges are player moves.
4. **Minimax Algorithm**:
    - Determines the optimal strategy assuming both players act rationally.
    - **Key Idea**:
        - **Maximizing player (MAX)**: Chooses moves to maximize utility.
        - **Minimizing player (MIN)**: Chooses moves to minimize utility.
    - **Algorithm**:
        - Recursively calculate values of game tree nodes using minimax values:
            - At MAX nodes: value(n) = $\max(\text{value}(\text{children}))$
            - At MIN nodes: value(n) = $\min(\text{value}(\text{children}))$
    - **Properties**:
        - Complete if the game tree is finite.
        - Optimal if both players play optimally.
        - Time Complexity: $O(b^m)$, where $b$ is the branching factor and $m$ is the depth.
        - Space Complexity: $O(bm)$ (with depth-first exploration).
5. **Alpha-Beta Pruning**:
    - Optimizes the minimax algorithm by pruning branches that cannot affect the outcome.
    - **Key Idea**:
        - Maintain two bounds during search:
            - **Alpha ($\alpha$)**: Best value for MAX along the path.
            - **Beta ($\beta$)**: Best value for MIN along the path.
        - Prune subtrees when:
            - $value(n) \geq \beta$ at MIN nodes.
            - $value(n) \leq \alpha$ at MAX nodes.
    - **Advantages**:
        - Reduces the number of nodes explored, improving efficiency.
        - Best-case time complexity: $O(b^{m/2})$.
6. **Evaluation Functions**:
    - Estimate the utility of a game state without fully expanding the tree.
    - **Heuristics**:
        - Must correlate with the likelihood of winning.
    - Examples:
        - Piece-count advantage in chess.
        - Mobility advantage in board games.
7. **Cutoff Search**:
    - In complex games, the tree is too large for exhaustive exploration.
    - **Cutoff depth**: Use a heuristic evaluation at a certain depth.
    - Risk of **horizon effect**: Missing long-term strategies due to fixed-depth limitation.
8. **Stochastic Games**:
    - Introduce randomness in the environment (e.g., dice rolls).
    - Use **expectiminimax**:
        - Expectation nodes calculate the average value over possible outcomes.
        - Computationally expensive: Incorporates probabilities into the tree.

### **Key Insights**:

- Adversarial search formalizes decision-making in competitive environments.
- Alpha-beta pruning and heuristic evaluations make these techniques practical for real-world games like chess and Go.

---

This chapter introduces the foundation for competitive decision-making and optimization in multi-agent environments.
