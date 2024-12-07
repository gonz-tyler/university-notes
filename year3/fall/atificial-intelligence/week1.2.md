# Week 1.2: Intelligent Agents (AIMA Ch 2)
## Notes
---
### **Key Concepts**

1. **Definition of an Agent**:
    - **Agent**: An entity that perceives its environment through sensors and acts upon it with actuators to achieve goals.
    - **Agent Function**: Maps a sequence of percepts to actions.
    - **Agent Program**: Implementation of the agent function in software or hardware.
2. **Structure of Agents**:
    - **Percept**: Information from the environment at a given time.
    - **Percept Sequence**: The complete history of all percepts received.
    - **Action**: The decisions made by the agent based on percepts.
3. **Properties of Agents**:
    - **Rationality**: The agent acts to maximize expected performance measure, given its knowledge and capabilities.
    - **Autonomy**: The extent to which the agent's behavior depends on its own experience versus external input.
4. **Types of Agents**:
    - **Simple Reflex Agents**:
        - Use condition-action rules.
        - Work well in fully observable environments.
    - **Model-based Reflex Agents**:
        - Maintain internal state to handle partially observable environments.
    - **Goal-based Agents**:
        - Use goals to guide decision-making.
    - **Utility-based Agents**:
        - Optimize a utility function for preferences over outcomes.
    - **Learning Agents**:
        - Improve performance over time through learning.
5. **Environment Types**:
    - **Fully Observable vs. Partially Observable**:
        - Can perceive all relevant aspects vs. limited or noisy data.
    - **Deterministic vs. Stochastic**:
        - Outcomes of actions are predictable vs. uncertain.
    - **Episodic vs. Sequential**:
        - Each decision is independent vs. dependent on previous ones.
    - **Static vs. Dynamic**:
        - Environment remains constant vs. changes during agent decisions.
    - **Discrete vs. Continuous**:
        - Finite set of actions/states vs. infinite possibilities.
    - **Single-agent vs. Multi-agent**:
        - One agent acting vs. interaction with others (cooperative or competitive).
6. **Agent Design and PEAS**:
    - **PEAS Framework**:
        - **P**erformance Measure: Criteria for success.
        - **E**nvironment: External conditions.
        - **A**ctuators: Tools for action.
        - **S**ensors: Tools for perception.

### **Agent Evaluation**:

- Rationality depends on:
    - The performance measure.
    - The agent’s prior knowledge.
    - The environment and available percepts.
    - The agent’s ability to act.

---

This chapter emphasizes designing agents that interact effectively and rationally within diverse environments.
