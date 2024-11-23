# Week 2:
## Lecture 3: Solving Problems by Searching

### Problem-Solving Agents
- Problem-solving agents use search to find solutions to problems.
- Problem-solving agents work by:
  1. Formulating a goal: Define what it wants to achieve.
  2. Formulating the problem: Describe the possible actions and states that lead to the goal.
  3. Searching for a solution: Use a search algorithm to find a sequence of actions that leads to the goal state.

- Problem formulation includes:
  - Initial state: The state from where the agent starts.
  - Actions: The possible moves the agent can take from any state.
  - Transition model: Describes the result of applying an action to a state (i.e., what the new state will be).
  - Goal test: A way to determine if a given state is a goal state.
  - Path cost: The cost of a sequence of actions.

- Search problem: The agent needs to find a solution path from the initial state to a goal state.

### Example Problem Types

- Common search problems include:
  - Route-finding problems: Finding a path from one location to another (e.g., GPS systems).
  - Maze-solving problems: Navigating through a grid to reach a target.
  - 8-puzzle: Rearranging tiles to match a goal configuration.
  - Robot navigation: Finding a path through a physical space.

### Searching for Solutions
- Search algorithms explore the state space, which is the set of all states reachable from the initial state via the available actions.
  - Search tree: A tree where each node represents a state, and edges represent actions.
  - Node: Represents a state in the search tree. It contains:
    - State: The particular configuration at the node.
    - Parent: The node that generated this node.
    - Action: The action taken to generate this node.
    - Path cost: The cost of reaching this node from the start.

- The key steps in a search process:
  1. Expand nodes: Generate successor states from the current state.
  2. Explore the search space: Visit nodes systematically.
  3. Select nodes: Use different strategies to determine which node to expand next (based on the search strategy).

### Uninformed Search Strategies
- Uninformed (or blind) search strategies do not have any additional information about the problem beyond what is provided in the problem definition. They explore the search space without guidance from heuristics.

- Types of uninformed search strategies:
1. Breadth-First Search (BFS):
  - Explores all nodes at the present depth level before moving to nodes at the next depth level.
  - Uses a FIFO (First In, First Out) queue to store nodes.
  - Properties:
    - Complete: Guaranteed to find a solution if one exists.
    - Optimal: Finds the shallowest (shortest) solution if all step costs are equal.
    - Time complexity: O(bd)O(bd), where bb is the branching factor and dd is the depth of the shallowest solution.
    - Space complexity: O(bd)O(bd) due to storing all nodes at each level.
2. Uniform-Cost Search:
  - A version of BFS that accounts for varying step costs.
  - Expands the node with the lowest path cost first (not the shallowest).
  - Uses a priority queue ordered by path cost.
  - Properties:
    - Complete and optimal if step costs are non-negative.
    - Time and space complexity: O(b^(1+⌊C∗/ϵ⌋)), where C∗ is the cost of the optimal solution, and ϵϵ is the smallest step cost.
3. Depth-First Search (DFS):
  - Explores as far as possible along each branch before backtracking.
  - Uses a LIFO (Last In, First Out) stack to store nodes.
  - Properties:
    - Incomplete: May fail in infinite-depth or cyclic state spaces.
    - Not optimal: May find a suboptimal solution.
    - Time complexity: O(b^m), where mm is the maximum depth of the search tree.
    - Space complexity: O(bm), much better than BFS since it only stores the current path.
4. Depth-Limited Search (DLS):
  - DFS with a predefined depth limit to avoid infinite loops.
  - Properties:
    - Incomplete if the solution is deeper than the limit.
    - Not optimal.
    - Time complexity: O(b^l), where ll is the depth limit.
    - Space complexity: O(bl).
5. Iterative Deepening Search (IDS):
  - A combination of DFS and BFS: Repeatedly applies DFS with increasing depth limits until the goal is found.
  - Properties:
    - Complete: Finds a solution if one exists.
    - Optimal: Finds the shallowest solution if all step costs are equal.
    - Time complexity: O(bd)O(bd) (similar to BFS).
    - Space complexity: O(bd)O(bd) (like DFS).
### Comparing Uninformed Search Strategies
- Uninformed search strategies can be compared based on four key criteria:
  - Completeness: Will the algorithm find a solution if one exists?
  - Optimality: Will it find the least-cost or shallowest solution?
  - Time Complexity: How long does it take to find a solution? Measured in terms of the number of nodes generated.
  - Space Complexity: How much memory is needed to perform the search? Measured in terms of the maximum number of nodes stored in memory at any point.

- The table below summarizes the performance of the uninformed search strategies:
| Algorithm | Complete? | Optimal? | Time Complexity | Space Complexity |
|-----------|-----------|----------|-----------------|------------------|
|Breadth-First | Yes | Yes (if all step costs are equal) | O(b^d) | O(b^d) |
|Uniform-Cost | Yes | Yes | O(b^(1+⌊C∗/ϵ⌋)) | O(b^(1+⌊C∗/ϵ⌋)) |
|Depth-First | No | No | O(b^m) | O(bm) |
|Depth-Limited | No | No | O(b^l) | O(bl) |
|Iterative Deepening | Yes | Yes | O(b^d) | O(bd) |
- Summary
  - Uninformed search explores the search space without using domain-specific knowledge (heuristics).
  - Different uninformed strategies like BFS, DFS, UCS, and IDS have varying trade-offs in terms of time, space, completeness, and optimality.
  - Breadth-first search is complete and optimal for equal-cost problems but has high memory costs. Iterative deepening search combines the benefits of BFS and DFS, making it a popular uninformed search strategy.

---

## Lecture 4: Adversarial Search
### Informed Search Strategies
- Informed search strategies, also called heuristic search strategies, use additional information (heuristics) to guide the search towards the goal more efficiently than uninformed strategies. A heuristic is a function that estimates the cost of reaching the goal from a given state.
  - Heuristic function (h(n)): A function that estimates the cost of the cheapest path from node nn to the goal state.
    - Example: In a route-finding problem, h(n)h(n) might represent the straight-line distance (Euclidean distance) from the current location to the goal.
- Heuristic search algorithms aim to reduce the number of explored nodes, improving time and space efficiency while still finding a solution (and sometimes optimizing it).
### Greedy Best-First Search
- Greedy Best-First Search uses the heuristic function h(n)h(n) to guide the search.
- It selects the node that appears to be closest to the goal according to h(n)h(n).
- The algorithm uses a priority queue, where nodes are prioritized by the value of the heuristic function h(n)h(n).
#### Algorithm:
- Start with the initial state.
- Expand the node with the lowest heuristic value h(n)h(n).
- If the node is a goal, return the solution. Otherwise, add the node’s successors to the priority queue.
- Repeat until the goal is found or no nodes remain.
#### Properties:
- Incomplete: Greedy best-first search is incomplete, meaning it may fail to find a solution, especially in infinite state spaces.
- Not optimal: It is not guaranteed to find the least-cost solution; it can lead to suboptimal paths because it only considers the heuristic value, ignoring actual path costs.
- Time complexity: Can vary widely depending on the heuristic used. In the worst case, it can explore a large number of nodes.
- Space complexity: Requires storing all nodes in memory (same as time complexity).
#### Example:
- If using straight-line distance as a heuristic in a map search, the greedy best-first search will always pick the city that is geographically closest to the goal, even if that does not necessarily lead to the shortest path.
### A Search (A-star)*
- A* Search is one of the most popular and widely used informed search strategies. It combines both the path cost and heuristic to make decisions.
- A* evaluates nodes by a function:
```latex
  f(n)=g(n)+h(n)
```
- where:
  - g(n)g(n) is the cost to reach node nn from the start (actual path cost).
  - h(n)h(n) is the estimated cost from nn to the goal (heuristic).
- A* selects the node with the smallest f(n)f(n), considering both the cost to reach a node and the estimated cost to complete the path.
#### Algorithm:
- Initialize the search with the start node.
- Expand the node with the lowest f(n)f(n).
- If the node is a goal, return the solution. If not, add its successors to the priority queue with their updated f(n)f(n) values.
- Repeat until the goal is reached or the search space is exhausted.
#### Properties:
- Complete: A* is complete and will always find a solution if one exists, provided that the branching factor is finite, and step costs are positive.
- Optimal: A* is optimal (it finds the least-cost solution) if the heuristic h(n)h(n) is admissible, meaning h(n)h(n) never overestimates the cost to reach the goal (i.e., h(n)≤h∗(n)h(n)≤h∗(n), where h∗(n)h∗(n) is the true cost to reach the goal).
- Time complexity: Exponential in the worst case, as A* may explore many nodes.
- Space complexity: Requires significant memory to store all explored nodes (also exponential in the worst case).
#### Heuristic properties for A*:
- Admissibility: Ensures that the heuristic never overestimates the true cost. This guarantees that A* finds an optimal solution.
- Consistency (Monotonicity): 
  - A heuristic is consistent if for every node _n_, and successor _n′_, the estimated cost from _n_ to the goal is less than or equal to the cost from _n_ to _n′_ plus the cost from _n′_ to the goal:
  ```latex
  h(n) \lt c(n,n′)+h(n′)
  ```
  - where c(n,n′) is the cost of reaching node _n′_ from node _n_. Consistency ensures that A* never revisits nodes and leads to more efficient search.
#### Example: 
- In a pathfinding problem, if g(n)g(n) represents the distance traveled so far and h(n)h(n) is the straight-line distance to the goal, A* will consider both the distance already covered and the estimated remaining distance to select the next node.
### Optimality of A*
- Proof of optimality: A* is optimal if the heuristic function is admissible. The reasoning is that A* explores nodes based on the sum of actual costs and estimated costs. If h(n)h(n) is admissible, it never overestimates, ensuring that when a goal node is selected, it is the least-cost solution.
- Summary of Heuristic Search
  - Greedy Best-First Search: Focuses on nodes that appear to be closest to the goal, but may not find an optimal path.
  - A* Search: Balances both the cost so far and the estimated cost to the goal, providing both completeness and optimality when using an admissible heuristic.
  - The efficiency and effectiveness of these search algorithms depend heavily on the quality of the heuristic h(n)h(n). A good heuristic can dramatically improve search performance.
### Summary
- Heuristic search strategies use domain-specific knowledge to guide the search process, aiming to improve efficiency over uninformed search.
- Greedy Best-First Search uses the heuristic alone to choose the next node, which can be fast but is not guaranteed to find the optimal solution.
- A* combines the actual cost to reach a node and the heuristic estimate of the remaining cost, providing a balance between exploration and exploitation.
- Admissible and consistent heuristics are crucial for ensuring the optimality and efficiency of A*.



