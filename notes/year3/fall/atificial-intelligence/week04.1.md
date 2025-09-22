# Week 4.1: Reasoning 1 - Constraint Satisfaction Problems (AIMA Ch 6)
## Notes
---
### **Key Concepts**

1. **Constraint Satisfaction Problems (CSPs)**:
    - Problems defined by:
        - **Variables**: $X_1, X_2, \dots, X_n$
        - **Domains**: Possible values for each variable.
        - **Constraints**: Restrictions on allowable combinations of variable values.
    - Goal: Assign values to variables such that all constraints are satisfied.
2. **Examples of CSPs**:
    - **Map Coloring**: Assign colors to regions such that adjacent regions have different colors.
    - **Sudoku**: Assign numbers to a grid while satisfying row, column, and sub-grid constraints.
    - **Scheduling**: Allocate resources without conflicts.
3. **Types of CSPs**:
    - **Discrete** vs. **Continuous**:
        - Discrete: Finite set of values (e.g., colors, integers).
        - Continuous: Infinite or real-valued domains.
    - **Binary** vs. **Non-binary**:
        - Binary: Constraints involve pairs of variables.
        - Non-binary: Constraints involve three or more variables.
    - **Hard** vs. **Soft**:
        - Hard: Constraints must be satisfied.
        - Soft: Preferences can be violated with penalties.
4. **Constraint Graph**:
    - Representation of CSPs where:
        - Nodes are variables.
        - Edges represent constraints between variables.
5. **Solving CSPs**:
    - **Backtracking Search**:
        - Depth-first search that assigns values to one variable at a time.
        - **Failure**: When a variable cannot be assigned a value that satisfies constraints.
    - **Improved Backtracking**:
        - **Variable Ordering Heuristics**:
            - **MRV (Minimum Remaining Values)**: Select the variable with the fewest legal values.
            - **Degree Heuristic**: Select the variable involved in the most constraints.
        - **Value Ordering Heuristics**:
            - **Least Constraining Value**: Choose the value that rules out the fewest options for other variables.
        - **Constraint Propagation**:
            - Enforce constraints as variables are assigned.
            - **Forward Checking**: Eliminate values inconsistent with current assignments.
            - **Arc Consistency (AC-3)**: Remove values that cannot satisfy constraints between variables.
6. **Local Search for CSPs**:
    - **Min-conflicts Heuristic**:
        - Iteratively assigns values to minimize the number of violated constraints.
        - Effective for large-scale problems (e.g., scheduling).
7. **Global Constraints**:
    - Apply to a set of variables (e.g., **AllDifferent**: All variables must have unique values).
8. **Applications of CSPs**:
    - Map coloring, scheduling, timetabling, resource allocation, and puzzles.

### **Key Insights**:

- CSPs are a structured framework for many real-world problems.
- Efficient solving requires combining search strategies with heuristics and constraint propagation.

---

This chapter highlights systematic approaches to solving problems that can be expressed as constraints over variables.
