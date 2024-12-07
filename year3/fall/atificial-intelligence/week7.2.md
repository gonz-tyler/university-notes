# Week 7.2: Planning 4 - Stochastic Planning (AIMA Ch 17)
## Notes
---

### **Key Concepts**

1. **Introduction to Stochastic Planning**:
    - **Stochastic planning** involves planning in environments where the outcomes of actions are uncertain or probabilistic, rather than deterministic.
    - In these domains, the agent's actions don't always lead to predictable results, which introduces **uncertainty** into the planning process.
    - The environment is modeled probabilistically, where each action has a **probability distribution** over possible outcomes.
2. **Stochastic Domains**:
    - A **stochastic environment** is one in which the outcome of an action may depend on random factors or other uncertain conditions.
    - Examples include:
        - **Robotics**: Where sensors may provide noisy data, leading to uncertainty in positioning.
        - **Games**: Such as board games or video games, where the state of the game can evolve unpredictably.
        - **Resource Management**: In tasks where resources may fluctuate unpredictably (e.g., fluctuating demand in production).
3. **Markov Decision Processes (MDPs)**:
    - **MDPs** provide a formal framework for modeling decision-making in stochastic environments.
    - An **MDP** is defined by:
        - **States (S)**: The possible configurations of the system.
        - **Actions (A)**: The possible actions the agent can take.
        - **Transition Model (T)**: A probabilistic function that defines the likelihood of reaching a new state, given the current state and action. This is $T(s,a,s′)=P(s′∣s,a)$.
        - **Rewards (R)**: A function that gives a numeric reward based on the state and action taken, $R(s,a)$.
        - **Discount Factor (γ)**: A factor that represents the agent’s preference for receiving rewards sooner rather than later. It is a number between 0 and 1.
        - **Policy (π)**: A strategy that defines which action to take in each state. The goal is to find a policy that maximizes the expected sum of rewards over time.
4. **Markov Property**:
    - The **Markov Property** states that the future state depends only on the current state, not on the sequence of events that led to the current state. In other words, the environment has **no memory** beyond the present state.
    - Mathematically, $P(s_{t+1} | s_t, a_t) = P(s_{t+1} | s_t)$, meaning the next state depends only on the current state and action.
5. **Value Iteration**:
    - **Value iteration** is an algorithm used to compute the optimal policy for an MDP.
        - It works by iteratively improving the estimated value of each state (the expected reward starting from that state), using the Bellman equation:
            
            $$ V(s) = \max_a \left( R(s, a) + \gamma \sum_{s'} T(s, a, s') V(s') \right) $$
            
        - The algorithm continues until the values converge to the optimal solution.
        - **Bellman Equation**: Describes how the value of a state is related to the values of successor states, considering immediate rewards and future rewards discounted by $ \gamma $
6. **Policy Iteration**:
    - **Policy iteration** is another algorithm for solving MDPs, which alternates between:
        1. **Policy Evaluation**: Calculate the value of each state under the current policy.
        2. **Policy Improvement**: Update the policy to take the action that maximizes the expected reward, given the value of each state.
    - This process continues until the policy converges (i.e., it does not change between iterations).
7. **Q-Learning**:
    - **Q-learning** is a model-free reinforcement learning algorithm that learns the value of state-action pairs, called **Q-values**, without needing a model of the environment.
    - It is used to solve problems where the agent must learn the best actions to take through exploration and experience.
    - The **Q-value update** is given by:
    $$ Q(s, a) = Q(s, a) + \alpha \left( R(s, a) + \gamma \max_a Q(s', a) - Q(s, a) \right) $$
        - **α** is the learning rate, and $\max_a Q(s', a)$ is the estimate of the optimal future value of the next state.
8. **Partially Observable MDPs (POMDPs)**:
    - In some domains, the agent might not have complete information about the current state, leading to **Partially Observable Markov Decision Processes (POMDPs)**.
    - **POMDPs** are an extension of MDPs that account for partial observability by introducing a belief state that represents the agent’s uncertainty about the true state of the environment.
    - The agent must plan based on its belief about the current state rather than knowing the exact state.
9. **Stochastic Planning Algorithms**:
    - Several algorithms are specifically designed for stochastic planning problems:
        - **Monte Carlo Tree Search (MCTS)**: A search algorithm that uses random sampling to explore possible actions and states.
        - **Dynamic Programming (DP)**: Used in algorithms like **Value Iteration** and **Policy Iteration** to optimize decisions over time.

---

### **Key Insights**:

- **Stochastic planning** involves modeling decision-making in uncertain environments, where the outcomes of actions are probabilistic.
- **MDPs** provide a powerful mathematical framework for representing such environments, and the main goal is to find an optimal policy that maximizes the expected long-term reward.
- Algorithms like **value iteration**, **policy iteration**, and **Q-learning** are essential for solving MDPs and improving decision-making in stochastic domains.
- **POMDPs** extend MDPs by incorporating uncertainty in observation, making them applicable in real-world scenarios where the agent has incomplete information.

---

This chapter introduces the key concepts of stochastic planning and MDPs, which are crucial for planning in environments with uncertainty. The algorithms discussed provide foundational methods for solving complex planning problems in such domains, making them highly relevant in fields like robotics, autonomous systems, and reinforcement learning.
