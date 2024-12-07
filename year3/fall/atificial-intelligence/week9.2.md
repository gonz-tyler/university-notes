# Week 9.2: Learning 4 - Reinforcement Learning (AIMA Ch 22)
## Notes
---
### **Key Concepts**

1. **Introduction to Reinforcement Learning (RL)**:
    - **Reinforcement Learning (RL)** is a type of machine learning where an agent learns to make decisions by interacting with an environment to maximize a **cumulative reward**.
    - Unlike supervised learning, where a model learns from labeled data, in RL the agent learns by **trial and error**, receiving feedback in the form of rewards or punishments.
    - The learning process in RL involves taking actions based on the current state, receiving feedback (rewards), and then adjusting actions to improve performance over time.
2. **Key Components of RL**:
    - **Agent**: The entity that makes decisions and takes actions in the environment.
    - **Environment**: The external system with which the agent interacts. The environment provides feedback to the agent in the form of rewards and transitions between states.
    - **State (s)**: A representation of the current situation or configuration of the environment. The state provides all the information the agent needs to decide its next action.
    - **Action (a)**: The decision or move the agent makes in a given state. Actions are chosen based on a policy or strategy.
    - **Reward (r)**: The feedback signal received by the agent after taking an action. The reward can be positive or negative and helps guide the agent toward better behavior.
    - **Policy (π)**: A strategy or mapping from states to actions that defines the agent's behavior. The policy can be deterministic (always choosing the same action in a state) or stochastic (choosing actions based on probabilities).
    - **Value Function (V)**: A function that estimates the expected cumulative reward an agent can obtain from a given state, starting from that state and following a certain policy.
    - **Q-Function (Q)**: A function that estimates the expected cumulative reward of an agent taking a certain action in a certain state and then following a policy thereafter.
3. **Markov Decision Process (MDP)**:Gt​=rt+1​+γrt+2​+γ2rt+3​+…
    - RL problems are often formalized as **Markov Decision Processes (MDPs)**, which consist of the following components:
        - **States (S)**: The set of all possible states.
        - **Actions (A)**: The set of all possible actions the agent can take.
        - **Transition Function (P)**: A function $P(s′∣s,a)$ that defines the probability of transitioning from state $s$ to state $s′$ after taking action $a$.
        - **Reward Function (R)**: A function $R(s,a)$ that defines the immediate reward the agent receives after taking action $a$ in state $s$.
        - **Discount Factor ($\gamma$)**: A factor $0 \leq \gamma \leq 1$ that discounts future rewards, reflecting the idea that immediate rewards are more valuable than future rewards.
    
    The goal in RL is to find a policy $\pi(s)$ that maximizes the **expected cumulative reward** over time, typically expressed as the **return** $G_t$​:
    
    $$G_t = r_{t+1} + \gamma r_{t+2} + \gamma^2 r_{t+3} + \dots$$
    
4. **Exploration vs. Exploitation**:
    - One of the key challenges in RL is balancing **exploration** (trying new actions to discover better rewards) and **exploitation** (using known actions that give high rewards).
    - **Epsilon-Greedy Strategy**: A simple method where the agent usually selects the action with the highest expected reward (exploitation), but with a small probability $\epsilon$, it selects a random action (exploration).
    - **Softmax Action Selection**: A more advanced approach where the agent selects actions probabilistically, with the probability of selecting an action based on its estimated value.
5. **Value Iteration and Policy Iteration**:
    - **Value Iteration**: An algorithm for computing the optimal policy by iteratively updating the value function for each state until it converges.
    - **Policy Iteration**: An algorithm that alternates between improving the policy based on the current value function and evaluating the new policy.
    
    Both approaches rely on the Bellman Equation, which expresses the relationship between the value of a state and the values of its successor states:
    
    $$V(s) = \max_a \left[ R(s, a) + \gamma \sum_{s'} P(s'|s, a) V(s') \right]$$
    
6. **Temporal Difference (TD) Learning**:
    - **Temporal Difference Learning** is a type of learning where the agent updates its value estimates based on the difference between successive estimates of the same state. It combines ideas from **dynamic programming** and **Monte Carlo methods**.
    - The TD update rule for updating the value of state $s_t$​ is:
    $$V(s_t) \leftarrow V(s_t) + \alpha \left[ r_{t+1} + \gamma V(s_{t+1}) - V(s_t) \right]$$
    where $\alpha$ is the learning rate.
    
    TD learning is the basis of many RL algorithms, including **Q-learning**.
    
7. **Q-Learning**:
    - **Q-learning** is an off-policy RL algorithm where the agent learns the optimal policy without needing a model of the environment (i.e., it does not need to know the transition probabilities).
    - The goal is to learn an optimal **Q-function** $Q(s,a)$ that gives the expected cumulative reward for taking action $a$ in state $s$ and following the optimal policy thereafter.
    - The Q-value is updated using the following Bellman equation:
    $$Q(s_t, a_t) \leftarrow Q(s_t, a_t) + \alpha \left[ r_{t+1} + \gamma \max_{a'} Q(s_{t+1}, a') - Q(s_t, a_t) \right]$$
    - The agent chooses actions based on the **ε-greedy** policy, balancing exploration and exploitation.
8. **Deep Q Networks (DQN)**:
    - **Deep Q Networks (DQN)** combine **Q-learning** with **deep neural networks** to approximate the Q-values for large, high-dimensional state spaces.
    - In DQN, a deep neural network is used to estimate the Q-function, and **experience replay** and **target networks** are used to stabilize the learning process.
        - **Experience Replay**: A technique where the agent stores past experiences in a buffer and randomly samples from it to break the temporal correlations between consecutive samples.
        - **Target Network**: A copy of the Q-network that is periodically updated to improve stability during training.
9. **Policy Gradient Methods**:
    - **Policy Gradient Methods** are a family of algorithms that learn directly a **policy function** $\pi(a | s)$, which maps states to probabilities of taking each action.
    - Unlike Q-learning, which learns a value function and derives the policy from it, policy gradient methods optimize the policy directly.
    - The **Reinforce Algorithm** is one of the simplest policy gradient methods, updating the policy parameters in the direction that increases the expected reward.
10. **Applications of Reinforcement Learning**:
    - **Game Playing**: RL has been successfully applied to games like **AlphaGo**, where agents learn to play at a superhuman level by interacting with the game environment.
    - **Robotics**: Robots can use RL to learn tasks such as navigation, manipulation, and object recognition.
    - **Autonomous Vehicles**: RL can be used to train self-driving cars to make decisions in dynamic environments.
    - **Healthcare**: RL has been used to personalize medical treatments, optimize resource allocation, and assist in decision-making tasks.

---

### **Key Insights**:

- **Reinforcement Learning** focuses on training agents to learn behaviors through interactions with their environment, aiming to maximize cumulative rewards.
- The **Markov Decision Process (MDP)** framework provides a mathematical model for RL problems, including states, actions, rewards, and transitions.
- Algorithms like **Q-learning** and **Policy Gradients** offer different ways to learn optimal policies, with **Q-learning** learning value functions and **Policy Gradient** methods directly optimizing policies.
- **Deep Q Networks (DQN)** have been a breakthrough in applying RL to high-dimensional problems, particularly with the integration of deep learning.
- RL is widely applied in domains like **game playing**, **robotics**, and **autonomous systems**, where decision-making in dynamic environments is crucial.

---

This chapter delves into **Reinforcement Learning**, which is key for decision-making systems that learn from interaction rather than supervised signals. Understanding RL algorithms like **Q-learning** and **Policy Gradients** opens the door to designing systems capable of tackling complex, dynamic tasks across many industries.
