# Week 5: Planning and Navigation with Search Algorithms
## Notes
---
### Core Concepts in Mobile Robotics
- Key Questions:
  - Where am I?: Localization.
  - Where am I going?: Goal specification.
  - How do I get there?: Path planning and execution.
- Components of Navigation:
  - Sensing: Gathering environmental data using sensors.
  - Planning: Computing a path to the goal while avoiding obstacles.
  - Acting: Executing motion commands through actuators.

### The Navigation Problem
- Objective: Find a collision-free path from a start position to a goal position in the workspace.
- Key Steps:
  - Map Transformation: Converting the workspace into a configuration space (C-space).
  - Path Planning: Identifying a feasible path in the C-space.
  - Motion Execution: Sending control commands.

### Work Space vs. Configuration Space
- Work Space: The physical space where the robot operates.
- Configuration Space (C-space):
  - Represents all possible positions (configurations) of the robot.
  - Obstacles in the work space map to regions in the C-space.
  - Free space: Area in C-space without obstacles.

### Example:
- 2-Link Planar Robot:
  - Work space: Physical arm movement constrained by obstacles.
  - C-space: Represented by joint angles θ1,θ2.

### Graph-Based Path Planning
- Graphs:
  - Nodes: Represent configurations.
  - Edges: Connect adjacent configurations.
  - Obstacles: Excluded from connectivity.
- Graph Search Algorithms:
  - Uninformed: Breadth-first, Depth-first, Dijkstra.
  - Informed: A* (uses heuristics).

### Uninformed Search
#### Breadth-First Search (BFS)
- Explores all nodes at the current depth before moving to the next level.
- Guarantees the shortest path in terms of edge count (not cost).

#### Depth-First Search (DFS)
- Explores as far as possible along one branch before backtracking.
- Not guaranteed to find the shortest path.

#### Dijkstra's Algorithm
- Finds the shortest path based on path cost g(s), where:
- g(s)=Cost from start node to state s
- Operates without heuristic guidance.

### Informed Search: A*
- Heuristic Function (h(s)):
  - Estimates cost from state ss to goal sgoalsgoal​.
  - Must be:
    - Admissible: Never overestimates the cost to the goal.
    - Consistent: Satisfies the triangle inequality.
  - Example: Euclidean distance for planar navigation.
- Evaluation Function:
  - f(s)=g(s)+h(s)
  - Expands nodes based on f(s) values.
- Algorithm Steps:
  - Initialize: g(sstart)=0, f(sstart)=h(sstart).
  - Maintain two lists:
    - OPEN: Nodes to be expanded, sorted by f(s).
    - CLOSED: Nodes already expanded.
  - Expand the node in OPEN with the smallest f(s).
  - Update successors' g and f values and insert into OPEN.

### Mathematical Calculations
#### Cost Functions in Graph Search
- g(s):
- g(s)=(min⁡/s′∈Predecessors(s))[g(s′)+c(s′,s)]
- where c(s′,s) is the cost between states s′ and s.

#### A* Backtracking
- Optimal path reconstruction:
  - Start at sgoal​.
  - Backtrack to predecessor s′ such that:
  - s′=arg⁡(min/⁡s"∈Predecessors(s))[g(s")+c(s",s)]

#### Heuristic Examples:
- Euclidean Distance:
  - h(s)=sqrt((x−xgoal​)^2+(y−ygoal​)^2)
- Manhattan Distance (for grid-based maps):
  - h(s)=∣x−xgoal​∣+∣y−ygoal​∣

### Performance of A*
- Optimal if h is admissible.
- Minimal node expansions compared to uninformed algorithms if h is consistent.

### Applications
- Mobile Robots: Pathfinding in cluttered environments.
- Robotic Arms: Manipulator motion planning in constrained workspaces.
- Autonomous Vehicles: Real-time obstacle avoidance and navigation.
