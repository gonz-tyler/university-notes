# Week 7.1: Planning 3 - Hierarchical Planning (AIMA Ch 11.4, APTP 11.1-11.4)
## Notes
---
### **Key Concepts**

1. **Introduction to Hierarchical Planning**:
    - Hierarchical planning addresses the **complexity of large-scale problems** by decomposing them into smaller, more manageable subproblems.
    - Instead of planning a sequence of primitive actions (low-level actions), hierarchical planners plan **high-level tasks** that can be broken down into further subtasks or primitive actions.
    - **Hierarchy**: Organizing the planning problem into levels of abstraction. Higher levels involve broad goals, while lower levels involve specific actions needed to achieve those goals.
2. **Key Ideas in Hierarchical Planning**:
    - **Decomposition**: Higher-level tasks are decomposed into sub-tasks, which can further be decomposed, leading to a hierarchical structure.
    - **Abstract Actions**: Instead of planning individual actions, high-level abstract actions are used. These abstract actions represent a sequence of lower-level actions (or other abstract actions).
    - **Plan Refinement**: Hierarchical planning starts with high-level plans that are iteratively refined until they are decomposed into concrete sequences of actions.
3. **Methods of Hierarchical Planning**:
    - **Hierarchical Task Network (HTN) Planning**: A popular framework for hierarchical planning.
        - An **HTN** consists of:
            - **Tasks**: High-level operations that need to be accomplished.
            - **Methods**: Define how to decompose tasks into sub-tasks.
            - **Preconditions**: Conditions that must hold true before a task can be executed.
            - **Subtasks**: Lower-level tasks or actions resulting from task decomposition.
    - **HTN Planner**: The planning process in HTN involves the following steps:
        1. **Start with a top-level goal** (abstract task).
        2. **Apply methods** to decompose the top-level goal into sub-tasks.
        3. **Refine sub-tasks** by applying further decomposition until primitive actions are reached.
        4. **Search for a valid sequence of actions** that satisfies all the decomposed tasks.
4. **HTN Planning Example**:
Consider a goal of "making a sandwich" in an HTN planner. The decomposition might look like this:
    - **Top-level goal**: Make a sandwich.
        - Decompose into:
            - **Subtask 1**: Get bread.
            - **Subtask 2**: Get filling (e.g., cheese, ham).
            - **Subtask 3**: Assemble sandwich.
        - Each subtask can be further decomposed into smaller, primitive actions (e.g., "pick up bread," "slice cheese," "place cheese on bread").
5. **Methods in HTN**:
    - HTN methods provide a formal way to define task decomposition. A method may specify:
        - **Preconditions** for when the method can be applied.
        - **Subtasks** to be achieved at the next level of the hierarchy.
    - Methods can be applied in a **top-down** approach (decomposing tasks progressively) or **bottom-up** (refining specific actions into broader goals).
6. **HTN Planner Algorithm**:
    - **Goal**: Find a plan that satisfies the high-level goal.
    - **Procedure**:
        1. **Select the top-most goal**.
        2. **Apply applicable methods** to decompose the goal.
        3. **Repeat decomposition** recursively until primitive actions are obtained.
        4. **Search for a valid sequence of primitive actions** that leads to the goal.
    
    This recursive decomposition is handled with a combination of **search** (for finding applicable methods and subtasks) and **reasoning** (about preconditions and effects of actions).
    
7. **Hierarchical Planning in APTP**:
    - **Hierarchical Task Networks** (HTNs) are effective in reducing the search space for large and complex planning problems.
    - **Hierarchical problem decomposition** results in **more efficient planning**, as fewer details are handled at higher levels of abstraction.
    - **APTP (Automated Planning: Theory and Practice)** expands on this concept by incorporating complex **decomposition strategies** and analyzing their **computational efficiency** in large-scale problems.
8. **Advantages of Hierarchical Planning**:
    - **Improved Scalability**: By breaking down a problem into manageable subtasks, hierarchical planning reduces the complexity of the overall problem.
    - **Reusability**: High-level tasks and methods can be reused across different problems, making planning more modular.
    - **Flexibility**: Hierarchical planning allows for flexibility in how tasks are executed, providing more options to adjust plans based on available resources or changes in the environment.
9. **Challenges in Hierarchical Planning**:
    - **Task Decomposition**: Decomposing tasks effectively can be challenging and domain-specific. Defining appropriate methods for decomposition is critical for successful planning.
    - **Complexity in Search**: While hierarchical planning reduces the search space, the search within each level still needs to be efficient, especially when methods are not easily applicable or preconditions are hard to satisfy.
    - **Coordination of Subtasks**: Managing dependencies and interactions between subtasks requires careful coordination.

---

### **Key Insights**:

- **Hierarchical planning** offers a powerful way to manage complex problems by breaking them into smaller, more tractable subproblems.
- **HTN planning** provides a structured framework for decomposing high-level tasks into actionable sub-tasks, making it easier to handle large-scale problems.
- While hierarchical planning improves efficiency, it requires careful decomposition of tasks and efficient management of methods to ensure its success.

---

This chapter introduces hierarchical planning, which significantly improves the scalability and efficiency of planning in complex environments. By leveraging task decomposition and HTN methods, hierarchical planners can address large and dynamic problems with better flexibility and adaptability.
