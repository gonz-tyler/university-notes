# Week 06: Decision Trees

---

## 1. Introduction: The Classification Task

* **Input**: A collection of data instances, each described by a set of attributes (`x`) and a special nominal class attribute (`y`).
* **Output**: A model (like a decision tree) that predicts the class `y` for new, unseen instances based on their attributes `x`.
* **Datasets**:
    * **Training Set**: Used to build the model.
    * **Test Set**: Used to evaluate the model's performance on unseen data.

---

## 2. Decision Tree Construction

A decision tree is built using a recursive procedure:

1.  **Select Root Attribute**: Choose an attribute to place at the root node of the tree.
2.  **Branch for Each Value**: Create a separate branch for each possible value of the selected attribute.
3.  **Distribute Instances**: Send the training instances down the appropriate branch based on their value for the root attribute.
4.  **Recurse**: Repeat steps 1-3 for each branch, using only the instances that reached that branch and considering only the remaining attributes.
5.  **Stopping Condition**: Stop developing a branch when all instances reaching that node belong to the **same class**. This node becomes a **leaf node** labeled with that class.

Different trees can be built from the same data depending on the order in which attributes are selected.

---

## 3. Occam's Razor and Choosing the Best Tree

* **Occam's Razor**: The principle states that simpler explanations (or models) are generally preferable to more complex ones.
* **Application**: For decision trees, this means **smaller trees are better** than larger, more complex ones, assuming they perform similarly.
* **Goal**: We want an attribute selection strategy that leads to the smallest, most efficient tree.

---

## 4. Attribute Selection for Splitting: Information Gain

How do we choose the "best" attribute to split on at each node? We want an attribute that divides the data into the "purest" possible subsets (i.e., subsets where most instances belong to a single class).

### Entropy: Measuring Impurity

* **Entropy** is a measure of impurity or uncertainty in a set of instances, expressed in bits.
* For a node containing instances from `n` classes with proportions $p_1, p_2, ..., p_n$, the entropy is calculated as:
    $$
    Entropy(p_1, ..., p_n) = -p_1 \log_2(p_1) - p_2 \log_2(p_2) - ... - p_n \log_2(p_n)
    $$
* **Interpretation**:
    * Entropy = 0 bits: The node is perfectly pure (all instances belong to the same class).
    * Entropy = 1 bit (for 2 classes): The node is maximally impure (equal numbers of instances from each class).

### Information Gain: Measuring Purity Improvement

* **Information Gain** measures the reduction in entropy achieved by splitting the data based on a particular attribute.
* **Calculation**:
    1.  Calculate the entropy of the current node (before splitting).
    2.  For the chosen attribute, calculate the weighted average entropy of the daughter nodes created by the split (weighted by the proportion of instances going down each branch).
    3.  Information Gain = Entropy(parent) - Weighted Average Entropy(children).
* **Attribute Selection**: At each step of tree construction, choose the attribute with the **highest Information Gain** to split on.

### Problem with Highly Branching Attributes (e.g., ID)

* Attributes with many unique values (like an ID number) will often have a very high Information Gain because they split the data into many tiny, pure subsets (often single instances).
* This creates a very wide, shallow tree that perfectly fits the training data but is useless for predicting new instances (overfitting).

---

## 5. Gain Ratio: Adjusting for Branching

To counteract the bias of Information Gain towards highly branching attributes, we use **Gain Ratio**.

* **Intrinsic Information**: This measures the "amount of splitting" done by an attribute, calculated using the entropy formula on the *proportions of instances* going down each branch, irrespective of their class labels.
    $$
    IntrinsicInfo(Attribute) = Entropy(\frac{N_1}{N}, \frac{N_2}{N}, ..., \frac{N_v}{N})
    $$
    (where $N_i$ is the number of instances in the $i$-th branch and N is the total number of instances).
* **Gain Ratio Calculation**:
    $$
    GainRatio(Attribute) = \frac{InformationGain(Attribute)}{IntrinsicInformation(Attribute)}
    $$
* **Effect**: It penalizes attributes that split the data into many small branches. Attributes with high gain *and* reasonable branching are preferred.

---

## 6. Handling Numeric Attributes and Missing Values

### Numeric Attributes

* **Problem**: Numeric attributes have many possible values, leading to excessive branching if treated like nominal attributes.
* **Solution**: Convert them into discrete attributes by finding a **split point**.
    1.  Sort the instances based on the numeric attribute's value.
    2.  Identify potential split points between adjacent values with different class labels.
    3.  Calculate the Information Gain (or Gain Ratio) for each potential split point (treating it as a binary split, e.g., `temp < 71.5` vs. `temp >= 71.5`).
    4.  Choose the split point that maximizes the chosen measure.

### Missing Values

* **Simple Approach**: Treat "missing" as a separate attribute value. Create a distinct branch for instances where the attribute value is unknown. This works well if the "missingness" itself is predictive.
* **Complex Approach (Fractional Instances)**: Distribute the instance with the missing value down *all* branches of that attribute, weighted by the proportion of known instances that went down each branch. Calculations (like entropy) then use these fractional weights.

---

## 7. Overfitting and Pruning

* **Overfitting**: When a decision tree grows too deep, it learns noise and specific details of the training data that do not generalize to unseen data. This leads to poor performance on the test set.
* **Solutions**:
    1.  **Pre-pruning (Early Stopping)**: Stop growing the tree before it becomes fully grown based on some criterion (e.g., if the information gain is below a threshold). Hard to get right.
    2.  **Post-pruning**: Grow the full tree first, then remove nodes/subtrees that do not improve (or even hurt) performance on a separate **validation set** (a portion of the training data held aside). This is generally more effective.
