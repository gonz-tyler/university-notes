# Week 1: Lecture 2 Agents

## Notes

---

### Ubiquity

- Continuous reduction of cost of computing
- processing power in contexts/devices which once were uneconomic
- processing capability increases and spreads
- sophistication and “intelligence” become ubiquitous (everywhere)

### Interconnection

- computer systems no longer stand-alone
- systems-of-systems networked as very large distributed systems
- distributed and concurrent systems have become the norm
    - researchers and practitioners developing (theoretical) models of computing as interaction among many distributed systems

### Intelligence

- complexity of tasks automated and delegated has grown

### Delegation

- computers are more autonomous
- computers have control even in safety critical tasks

### Human-Orientation

- computing moving away from machine oriented views of programming
- heading towards the way humans understand the world
- programmers conceptualise and implement software in higher level abstractions

### Programming Progression

- machine code → assembly → machine independent → abstract data types → objects → …agents

### Agent

- an agent is a computer system that is capable of independent action on behalf of its user or owner (figuring out what needs to be done to satisfy design objectives, rather than constantly being told), exhibiting control over their internal state

### Multiagent Systems

- multiagent system consists of number of agents which interact with one another
- agents act on behalf of users with different goals and motivations
- require ability to cooperate, coordinate, and negotiate with each other

### Agent Design

- designing agents capable of independent autonomous action to successfully carry out delegated tasks

### Society Design

- designing agents capable of interacting (cooperating, coordinating, negotiating) with other agents in order to successfully carry out delegated tasks, especially when other agents cannot be assumed to share same interests/goals

### Intelligent Agents

- computer system capable of flexible autonomous action in some environment
- 3 types of behaviours
    - reactive
        - if program environment is guaranteed to be fixed program can just execute blindly (e.g. compiler)
        - most environments are dynamic (real world)
        - reactive system is one that maintains ongoing interaction with its environment and responds to changes that occur in time for response to be useful i.e. real time
    - proactive
        - generally want agents to do things for us
        - goal-directed behaviour
        - proactiveness
            - generating and attempting to achieve goals
            - not driven solely by events
            - taking initiative
            - recognising opportunities
    - social
      - real world is multi-agent environment - we must consider others when planning for goals
      - some goals can only be achieved with cooperation
      - social ability - ability to interact with other agents via some kind of agent communication language, perhaps cooperating

### Agents and Environments
- Agent: An entity that perceives its environment through sensors and acts upon it using actuators.
- Environment: The external world that the agent interacts with.

#### Key components of an agent:
- Percepts: The agent's perceptions at any given time.
- Percept Sequence: The complete history of everything the agent has perceived so far.
- Agent Function: Maps the percept sequence to an action. This function is often described as a mathematical function, but in practice, it's implemented via programs.

#### Agent = Sensors + Actuators + Agent Function (Program)
### Good Behavior: The Concept of Rationality
- Rational Agent: An agent that acts to maximize its performance measure based on:
  - The performance measure that defines success.
  - The agent's prior knowledge of the environment.
  - The actions that the agent can perform.
  - The percept sequence observed so far.
- Perfect Rationality: An agent is rational if, given all available information, it selects actions that maximize its expected performance.
- Autonomy: An agent is autonomous if it can operate on its own, using only its percepts, without needing prior built-in knowledge.

### The Nature of Environments
- Different types of environments require different approaches to agent design. Environments can be described by the following properties:
  - Fully Observable vs. Partially Observable:
    - Fully observable: The agent has complete access to the environment's state.
    - Partially observable: The agent only has limited information.
  - Deterministic vs. Stochastic:
    - Deterministic: The next state of the environment is fully determined by the current state and the agent's actions.
    - Stochastic: There is some randomness or uncertainty in the environment's state transitions.
  - Episodic vs. Sequential:
    - Episodic: Each action is independent of previous actions (e.g., classification tasks).
    - Sequential: Future actions depend on past actions (e.g., chess, driving).
  - Static vs. Dynamic:
    - Static: The environment doesn't change while the agent is deliberating.
    - Dynamic: The environment changes over time, even while the agent is thinking.
  - Discrete vs. Continuous:
    - Discrete: The environment has a limited number of distinct states and actions.
    - Continuous: The environment has an infinite number of states or actions.
  - Single-agent vs. Multi-agent:
    - Single-agent: The agent is the only decision-maker.
    - Multi-agent: There are other agents (competitors or collaborators) affecting the environment.

### The Structure of Agents
- Agents can be designed with different architectures, ranging from simple to complex:
  - Simple Reflex Agents:
    - Act only based on the current percept, ignoring the rest of the percept history.
    - Implement condition-action rules (if-then rules).
    - Effective in fully observable, static environments but fail in more complex ones.
  - Model-Based Reflex Agents:
    - Maintain an internal state that depends on the percept history and the agent's knowledge of how the world evolves.
    - The agent updates its state using information about how the environment works.
  - Goal-Based Agents:
    - Use goals to decide what actions to take.
    - Goals describe desired outcomes, and the agent seeks actions that achieve these goals.
  - Utility-Based Agents:
    - Have a utility function that ranks possible states based on how "happy" or "successful" the agent is in each state.
    - More flexible than goal-based agents, as they measure the desirability of different outcomes.
  - Learning Agents:
    - Can improve their behavior over time through experience.
    - Consist of four components:
      - Learning element: Responsible for making improvements.
      - Performance element: Chooses actions based on what it has learned.
      - Critic: Gives feedback about the performance (e.g., reward/punishment).
      - Problem generator: Suggests exploratory actions to improve future performance.
### Summary
- Agents are entities that perceive and act upon an environment to maximize their performance according to a specific measure of success.
- The rationality of an agent depends on how well it performs relative to its environment, knowledge, and percepts.
- Environment types (fully observable, deterministic, episodic, etc.) influence agent design.
- Agent architectures can range from simple reflexes to more sophisticated learning systems that incorporate knowledge of the environment and utility maximization.
