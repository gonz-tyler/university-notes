# Week04: Shrinkage Methods & Logistic Regression

---

## 1. Motivation: Beyond Least Squares

Standard **Least Squares Estimation (LSE)** in linear regression finds the parameters ($\beta$) that minimize the error. However, LSE often produces models that are difficult to interpret, especially with a large number of predictors, because every predictor is assigned a non-zero coefficient.

We often want to answer: **Which predictors are most important?** To achieve this, we need methods that can identify a smaller subset of important predictors or reduce the influence of less important ones. This is where shrinkage methods come in.

---

## 2. Best-Subset Selection

One way to find the most important predictors is to try every possible combination.

-   **Process**: For a model with `p` predictors, you would fit separate models for all possible subset sizes (from 0 to `p`).
-   **Example**: For 2 predictors (`location`, `size`), you would test four models: one with no predictors (just the intercept), one with `location` only, one with `size` only, and one with both.
-   **Drawback**: This method is computationally intensive and discrete. The number of possible models is $2^p$, which becomes infeasible very quickly.

---

## 3. Shrinkage Methods

Shrinkage methods provide a more efficient, continuous alternative to best-subset selection. They work by adding a **penalty term** to the standard SSE loss function. This penalty "shrinks" the estimated coefficients towards zero.

The two main types are Ridge Regression and LASSO.

### Ridge Regression (L2 Regularization)

Ridge regression adds a penalty proportional to the **sum of the squares of the coefficients**.

-   **Loss Function**:
    $$
    \text{loss}(\beta) = \sum_{i=1}^{N}(y_i - \sum_{j=1}^{p}x_{ij}\beta_j)^2 + \lambda\sum_{j=1}^{p}\beta_j^2
    $$
    The second term, $\lambda\sum\beta_j^2$, is the L2 penalty.

-   **Effect**:
    -   It shrinks all coefficients towards zero, reducing the impact of less important predictors.
    -   It **does not** set any coefficient exactly to zero. All predictors remain in the model, but with reduced influence.
    -   It's particularly useful when many predictors have small or moderate effects.

-   **The Tuning Parameter ($\lambda$)**:
    -   $\lambda \ge 0$ controls the amount of shrinkage.
    -   If $\lambda=0$, Ridge Regression is identical to standard LSE.
    -   As $\lambda \to \infty$, all coefficients shrink to zero.
    -   In deep learning, this technique is often called **weight decay**.

!
### LASSO Regression (L1 Regularization)

LASSO (Least Absolute Shrinkage and Selection Operator) adds a penalty proportional to the **sum of the absolute values of the coefficients**.

-   **Loss Function**:
    $$
    \text{loss}(\beta) = \sum_{i=1}^{N}(y_i - \sum_{j=1}^{p}x_{ij}\beta_j)^2 + \lambda\sum_{j=1}^{p}|\beta_j|
    $$
    The second term, $\lambda\sum|\beta_j|$, is the L1 penalty.

-   **Effect**:
    -   Like Ridge, it shrinks coefficients towards zero.
    -   Crucially, the L1 penalty **can force some coefficients to be exactly zero**.
    -   This means LASSO performs **automatic feature selection**, creating a simpler, more interpretable "sparse" model.

-   **The Tuning Parameter ($\lambda$)**:
    -   Controls the amount of shrinkage and feature selection.
    -   If $\lambda=0$, LASSO is identical to standard LSE.
    -   As $\lambda$ increases, more coefficients are forced to zero.

!
### How to Choose $\lambda$?

The tuning parameter $\lambda$ is a hyperparameter that must be selected. The best value is typically found using a model selection technique like **Cross-Validation**, where you test a range of $\lambda$ values and choose the one that performs best on unseen data.

## 4. Introduction to Classification

While linear regression is used to predict continuous values, **classification** is the task of predicting a discrete class label.

-   **Goal**: Learn a classifier function $f: X \to Y$, where `X` is the set of input features and `Y` is a set of discrete classes (e.g., $\{0, 1\}$ or $\{\text{Cat}, \text{Dog}\}$).

Instead of predicting a label directly, it's more powerful to predict the **probability** of each class given the input features: $P(Y=y | X=x)$.

-   **Bayes Classifier**: The optimal decision rule is to choose the class with the highest probability.
    $$
    y^* = \text{argmax}_y P(Y=y | X=x)
    $$

---

## 5. Generative vs. Discriminative Classifiers

There are two main approaches to estimating $P(Y|X)$:

1.  **Generative Classifiers (e.g., Naïve Bayes)**:
    -   These models learn the joint probability distribution $P(X, Y)$ by modeling the class conditional probability $P(X|Y)$ and the prior probability $P(Y)$.
    -   They use **Bayes' rule** to calculate the desired posterior probability $P(Y|X)$.
    -   They are called "generative" because you can use them to generate new data samples.

2.  **Discriminative Classifiers (e.g., Logistic Regression)**:
    -   These models learn the conditional probability $P(Y|X)$ **directly**.
    -   They focus on finding the decision boundary that separates the classes.
    -   They cannot be used to generate new data samples.
    -   **Neural networks** and **deep learning models** are also discriminative classifiers.

---

## 6. The Logistic Regression Model

Logistic Regression is a discriminative classifier used for binary classification problems ($Y \in \{0, 1\}$). It's considered the simplest form of a neural network.

### The Sigmoid Function

The core of Logistic Regression is the **sigmoid (or logistic) function**. This function takes any real-valued number and maps it to a value between 0 and 1, which is perfect for representing probability.

$$
S(z) = \frac{1}{1 + e^{-z}}
$$

!
### Model Formulation

1.  **Linear Combination**: First, a linear function of the input features `X` and weights `w` is calculated, just like in linear regression:
    $$
    z = w^TX = w_1x_1 + w_2x_2 + \dots + w_nx_n
    $$
2.  **Probability Calculation**: The result `z` is passed through the sigmoid function to get the probability of the positive class (Y=1):
    $$
    P(Y=1 | X) = S(z) = \frac{1}{1 + e^{-w^TX}}
    $$
    The probability of the negative class (Y=0) is simply $1 - P(Y=1|X)$.

### Training the Model

The goal is to find the optimal weights `w` that best fit the training data. This is done by defining a **loss function** that measures how well the model's predictions match the true labels.

-   **Loss Function**: The loss is typically based on maximizing the **log-likelihood** of the data. We want to find the weights `w` that make the observed data most probable.
-   **Optimization**: Unlike linear regression, there is no closed-form solution. The optimal weights are found iteratively using an optimization algorithm like **Gradient Descent**.

---

## 7. Regularization

Just like in linear regression, logistic regression can suffer from **overfitting**, especially with high-dimensional data. To combat this, we use **regularization**.

-   A penalty term is added to the loss function to penalize large weight values.
-   The most common form is L2 regularization (the same as in Ridge Regression).
-   The new objective becomes finding the weights `w` that maximize the penalized loss:
    $$
    w^* = \text{argmax}_w \left( \text{loss}(w) - \frac{\lambda}{2} ||w||^2 \right)
    $$
-   This also requires an iterative optimization algorithm like Gradient Descent to solve.
