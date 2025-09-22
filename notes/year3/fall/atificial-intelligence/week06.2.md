# Week 6.2: Planning 2 - Algorithms and Heuristics (AIMA Ch 11.2-11.3, APTP 9.1-9.3)
## Notes
---

### **Key Concepts**

1. **Planning Algorithms**:
    - **Forward Search**: Starts at the initial state and searches forward through the state space until the goal is reached.
        - Useful for **factoring in actions** and understanding how each transition leads closer to the goal state.
        - May require handling a large state space and redundant exploration.
    - **Backward Search**: Starts at the goal state and searches backward to find the initial state.
        - Effective when the goal state is known, as it helps in reasoning about which actions could lead to that state.
    - **State-Space Search**: A **graph-based** search where nodes represent states, and edges represent actions that transition from one state to another.
        - Can be done with **breadth-first search (BFS)**, **depth-first search (DFS)**, or other search strategies.
2. **Heuristic Search for Planning**:
    - **Heuristic**: A function $h(s)$ used to estimate the cost from a given state $s$ to the goal state.        
        - A heuristic guides the search towards more promising states, allowing more efficient exploration.
    - **Greedy Search**: Chooses actions based on the heuristic evaluation that estimates the closest state to the goal.
    - **A* Search**: Combines the actual cost to reach a state $g(s)$ and the estimated cost to reach the goal from that state $h(s)$.
        - The **evaluation function**: $f(s)=g(s)+h(s)$.
        - Ensures optimality if the heuristic is admissible (never overestimates the cost).
3. **Partial Order Planning**:
    - In **partial order planning**, actions are planned without specifying their exact order, allowing flexibility in execution.
    - The plan consists of a set of **ordered actions**, with constraints that define the order in which they must occur.
    - Advantages:
        - More general than totally ordered plans, as it allows greater flexibility in action execution.
        - Reduces the size of the search space.
    - Example:
        - A sequence of actions might allow certain actions to be performed concurrently.
4. **Planning as Satisfiability (SAT)**:
    - Planning can be converted to a **Boolean satisfiability problem** by encoding the planning problem as a propositional logic formula.
    - This method enables the use of **SAT solvers** to find a solution, allowing planners to take advantage of efficient SAT-solving techniques.
    - **PDDL as SAT**: Actions, states, and goals are represented in a Boolean format, and the SAT solver finds assignments of truth values that satisfy the formula.
5. **Heuristic Search Methods for Planning** (from APTP):
    - **Heuristic Search** involves selecting actions based on the evaluation of states. The heuristic can be used to estimate the cost of reaching the goal from a given state.
        - **Relaxed Planning Graph**: A heuristic based on the construction of a relaxed planning graph that ignores mutual exclusions between actions.
        - **Landmark Heuristics**: Based on identifying essential actions (landmarks) that must occur on the path to the goal. The more landmarks are satisfied, the closer the solution is.
6. **GraphPlan**:
    - **GraphPlan** is a planning algorithm that constructs a planning graph incrementally.
    - **Planning Graph**: A layered structure consisting of:
        - **Propositional layer**: Represents facts.
        - **Action layer**: Represents actions.
    - The algorithm alternates between the two layers, and the search is guided by the structure of the graph.
    - **GraphPlan Algorithm**:
        1. Construct the planning graph incrementally.
        2. Check if the goal can be satisfied at the current level.
        3. If not, expand the graph further.
        4. Use the graph to extract a valid plan.
7. **Heuristic Functions**:
    - A **heuristic function** estimates the "distance" between the current state and the goal. A good heuristic improves search efficiency by guiding the search in promising directions.
        - **Goal Distance**: How far the current state is from achieving the goal.
        - **Action Cost**: How costly it is to perform an action.
8. **Criticism of Heuristic Methods**:
    - **Heuristic Design**: Crafting good heuristics is crucial for making search algorithms efficient. Poor heuristics can lead to ineffective planning or excessive search.
    - **Incompleteness**: Heuristic search algorithms do not always guarantee a solution, especially in non-deterministic or complex environments.

---

### **Key Insights**:

- **Heuristic search** plays a crucial role in scaling planning systems by guiding the search process toward optimal or near-optimal solutions.
- **A* search** is a prominent example of an optimal heuristic search algorithm in planning.
- **Partial order planning** and **GraphPlan** offer flexible and efficient approaches to solving complex planning problems, providing more robust solutions than traditional total order planning.

---

This chapter focuses on enhancing planning through algorithms and heuristics, balancing efficiency with the ability to solve complex problems. Heuristic search methods and planning as satisfiability offer powerful approaches for dealing with real-world planning challenges.
