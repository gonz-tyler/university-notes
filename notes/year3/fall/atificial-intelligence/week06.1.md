# Week 6.1: Planning 1 - Introduction and Formalism (AIMA Ch 11.1, IPDDL 2.1-2.2)
## Notes
---

### **Key Concepts**

1. **Introduction to Planning**:
    - **Planning** in AI involves generating a sequence of actions that will transition an agent from an initial state to a goal state.
    - Unlike search problems where the goal is to find a solution, planning must take into account the actions and their effects over time.
    - **Key challenges**:
        - **Complexity**: Planning problems can be computationally hard.
        - **Uncertainty**: Planning can be affected by incomplete information or unforeseen changes.
        - **Resource Constraints**: Actions might have limited resources (time, energy, etc.).
2. **Planning Problem Definition**:
    - A **planning problem** consists of:
        - **Initial State**: The state from which the agent starts.
        - **Actions**: A set of operators that transform one state into another.
        - **Goal State**: The desired state the agent aims to achieve.
        - **Plan**: A sequence of actions that transforms the initial state to the goal state.
3. **Planning as Search**:
    - Planning can be viewed as a search problem, where:
        - The **state space** consists of all possible states that the agent can be in.
        - The **operators** define transitions between states.
        - The **goal test** checks if the current state matches the goal state.
        - The search process involves finding a sequence of actions (a plan) that leads to the goal state.
4. **Planning Domain Definition Language (PDDL)**:
    - **PDDL** is a standard language used for defining planning problems.
    - PDDL describes:
        - **Objects**: Entities in the domain (e.g., locations, vehicles).
        - **Predicates**: Properties or relations among objects (e.g., at(location, object)).
        - **Actions**: Operators that modify the state.
            - Each action is defined by:
                - **Preconditions**: Conditions that must hold true for the action to be applied.
                - **Effects**: Conditions that will be true after the action is applied.
        - **Initial State**: Describes the initial conditions in the domain.
        - **Goal**: Specifies the conditions that must be true in the goal state.
5. **PDDL Syntax**:
    - **Objects**: Defined using the `:objects` keyword.
    - **Initial State**: Represented using `:init` with a list of predicates.
    - **Goal**: Described using `:goal` and logical conjunctions of predicates.
    - **Actions**: Defined with `:action`, followed by the name, parameters, preconditions, and effects.
    
    Example (simple PDDL problem):
    
    ```lisp
    (define (problem example-problem)
      (:domain example-domain)
      (:objects location1 location2)
      (:init (at location1))
      (:goal (at location2)))
    ```
    
6. **Action Representation**:
    - **Preconditions**: A list of conditions that must be true to apply an action.
    - **Effects**: The resulting state after the action is applied.
        - **Add effects**: Facts that become true after the action.
        - **Delete effects**: Facts that become false after the action.
    
    Example (action in PDDL):
    
    ```lisp
    (:action move
      :parameters (?from ?to)
      :precondition (at ?from)
      :effect (and (not (at ?from)) (at ?to)))
    ```
    
7. **Planning with PDDL**:
    - **Classical Planning**: Assumes complete information, deterministic outcomes, and no resource limitations.
    - **Real-world Planning**: Often involves incomplete information, stochastic outcomes, and resource constraints.
    - **Planning Algorithms**:
        - **Forward search**: Start from the initial state and search forward towards the goal.
        - **Backward search**: Start from the goal state and search backward to find the initial state.

---

### **Key Insights**:

- Planning formalizes the process of determining how to achieve a goal by specifying actions, preconditions, and effects.
- PDDL serves as a formal language to express planning problems, making it easier to model and solve them.
- Planning problems can vary from simple to very complex depending on the domain, requiring efficient search algorithms and heuristics.

---

This chapter introduces the formalism and structures for planning, focusing on PDDL as the standard representation language for planning problems. Planning is key to intelligent agents operating autonomously in dynamic environments.
