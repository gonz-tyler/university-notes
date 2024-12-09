# Week 8.1: Learning 1 - Introduction to Machine Learning (Decision Trees) (AIMA Ch 19.1-19.3)
## Notes
---
### **Key Concepts**

1. **Introduction to Machine Learning**:
    - **Machine Learning (ML)** is the study of algorithms that allow computers to learn from data and improve over time without being explicitly programmed.
    - **Supervised Learning**: The learning algorithm is trained on labeled data (input-output pairs) to learn a mapping from inputs to outputs.
    - **Unsupervised Learning**: The algorithm finds patterns or structure in data without labeled outputs.
    - **Reinforcement Learning**: The algorithm learns by interacting with an environment and receiving feedback in the form of rewards or penalties.
2. **Decision Trees**:
    - A **decision tree** is a popular model used for classification and regression tasks in supervised learning.
    - The tree consists of:
        - **Nodes**: Each internal node represents a decision based on a specific feature.
        - **Edges**: Each edge represents a possible outcome of the decision.
        - **Leaves**: The terminal nodes represent the final output or prediction.
3. **Building a Decision Tree**:
    - A decision tree is constructed by recursively splitting the data into subsets based on the features that best separate the data.
    - The goal is to select the feature at each node that maximizes the separation between classes or minimizes variance.
    - **Greedy Algorithm**: Decision trees are typically constructed using a greedy approach, making locally optimal decisions at each step to grow the tree.
4. **Splitting Criteria**:
    - **Information Gain**: A common splitting criterion used in decision trees for classification tasks.
        - Information gain measures the reduction in entropy (uncertainty) after splitting the data on a specific feature.
        - The formula for **information gain** for a feature A is:
        $$\text{IG}(A) = \text{Entropy}(S) - \sum_{v \in A} \frac{|S_v|}{|S|} \text{Entropy}(S_v)$$
        where Sv​ is the subset of data for which the feature $A$ takes value $v$, and $∣S∣$ is the total number of instances in the dataset.
    - **Gini Impurity**: Another common splitting criterion used, particularly in decision trees like **CART (Classification and Regression Trees)**.
        - Gini impurity measures the **impurity** or **impurity** of a node and is used to select the best feature to split on.
        - The formula for **Gini impurity** is:
        $$Gini(t) = 1 - \sum_{i=1}^{k} p_i^2$$
        where $p_i​$ is the probability of choosing an element of class $i$ in the node $t$.
            
            
5. **Tree Construction**:
    - The decision tree is built using a **top-down, recursive** strategy. At each node:
        1. **Choose the best feature** (based on information gain or Gini impurity).
        2. **Split the dataset** based on the chosen feature into subsets.
        3. **Repeat** the process recursively for each subset until one of the stopping criteria is met:
            - All data points in the subset have the same class (pure node).
            - A predefined tree depth is reached.
            - The subset cannot be split further.
6. **Overfitting and Pruning**:
    - **Overfitting**: A decision tree can become overly complex by fitting noise or small variations in the training data, leading to poor generalization to new data.
        - **Overfitting occurs** when the tree becomes too large and captures details that do not generalize well.
    - **Pruning**: Pruning is the process of removing parts of the tree that do not contribute significantly to the accuracy of the model. This helps to reduce overfitting and improve generalization.
        - **Pre-pruning**: Stops tree growth early by setting a maximum depth or requiring a minimum number of samples per leaf.
        - **Post-pruning**: Removes nodes after the tree has been fully grown by evaluating the effect of removing branches.
7. **Handling Continuous Features**:
    - Decision trees can handle both **discrete** and **continuous** features. When dealing with continuous features:
        - The algorithm considers all possible split points and selects the one that best separates the data (e.g., split based on whether a feature value is greater than a threshold).
8. **Handling Missing Values**:
    - **Missing values** can be handled in decision trees by:
        - Assigning a probability distribution for missing values based on the known data.
        - **Surrogate splits**: Using alternative splits when the main feature is missing.
9. **Evaluation of Decision Trees**:
    - **Accuracy**: The proportion of correctly classified instances.
    - **Cross-validation**: A technique to assess the model's performance by splitting the dataset into multiple training and testing sets.
    - **Confusion Matrix**: A matrix that helps to evaluate the classification performance by showing the true positives, false positives, true negatives, and false negatives.
10. **Random Forests**:
    - **Random Forest** is an ensemble method that builds multiple decision trees and combines their results. It helps to improve the performance and reduce overfitting.
    - **Bagging**: A technique used in Random Forest where multiple decision trees are trained on different subsets of the data (with replacement).
    - The final prediction is made by aggregating the results of all individual trees (e.g., by voting for classification).

---

### **Key Insights**:

- **Decision Trees** are a powerful and interpretable model used in machine learning for both classification and regression tasks.
- The **splitting criteria** (e.g., Information Gain, Gini Impurity) play a crucial role in how the tree is constructed and how effective it is in making accurate predictions.
- **Pruning** is essential for preventing **overfitting** and ensuring that the decision tree generalizes well to unseen data.
- **Random Forests** build upon decision trees by combining multiple trees, reducing overfitting, and improving the model's robustness.

---

This chapter covers **Decision Trees**, one of the most commonly used models in machine learning, particularly for classification problems. Understanding how to build, evaluate, and optimize decision trees is fundamental to applying machine learning techniques effectively.
