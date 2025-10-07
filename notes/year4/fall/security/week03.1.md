# Week03.1: Regression Models Revision Notes

---

## 1. Introduction to Regression

Regression models are a fundamental tool in statistics and supervised machine learning. Their primary goal is to model the relationship between a set of input variables (**features**) and a continuous output variable (**target**). A common task is prediction, such as predicting the price of a house based on its features.

### Terminology

| Machine Learning Term | Statistics Term | Description |
| :--- | :--- | :--- |
| **Target** (`y`) | Response | The continuous value we want to predict. |
| **Feature(s)** (`x`) | Predictor(s) | The input variables used for prediction. |
| **Weights** (`w`) | Parameters (`β`) | The coefficients the model learns. |
| **Bias** (`w₀`) | Intercept | A special weight that is independent of any feature. |
| Model Training | Parameter Estimation| The process of learning the weights. |

---

## 2. Simple Linear Regression

Simple linear regression models the relationship between a single feature `x` and a target `y` by fitting a straight line to the data.

### The Model

The relationship is expressed by the equation:

$$
\hat{y} = w_0 + w_1x
$$

-   $\hat{y}$ is the predicted value.
-   $x$ is the input feature.
-   $w_1$ is the **weight** (or slope), which determines how much $\hat{y}$ changes for a one-unit change in `x`.
-   $w_0$ is the **bias** (or intercept), which is the value of $\hat{y}$ when `x` is zero.

The true relationship includes an error term, $\epsilon$ (epsilon), representing noise or un-modelled factors: $y = w_0 + w_1x + \epsilon$.

### Finding the Best Fit Line

To find the "best" line, we need to minimize the total error between our model's predictions ($\hat{y}_n$) and the actual data points ($y_n$).

-   **Error (Residual)**: For each data point `n`, the error is $\epsilon_n = y_n - \hat{y}_n$.
-   **Loss Function**: We use the **Sum of Squared Errors (SSE)** (also called Residual Sum of Squares, RSS) as our loss function. This penalizes larger errors more heavily.

$$
E(w_0, w_1) = \sum_{n=1}^{N}(y_n - \hat{y}_n)^2 = \sum_{n=1}^{N}(y_n - (w_0 + w_1x_n))^2
$$

-   **Least Squares Estimation (LSE)**: The method of finding the weights ($w_0, w_1$) that minimize the SSE is called LSE. This can be solved analytically by taking the partial derivatives of the SSE with respect to each weight, setting them to zero, and solving the resulting system of equations.

---

## 3. Multiple Linear Regression

Multiple linear regression extends the simple model to handle multiple input features.

### The Model

The model now includes a weight for each of the `D` features:

$$
\hat{y} = w_0 + w_1x_1 + w_2x_2 + \dots + w_Dx_D
$$

This can be written more compactly using vector notation. By adding a dummy feature $x_0=1$, we can include the bias $w_0$ in the weight vector `w`:

-   **Weight Vector `w`**: $[w_0, w_1, \dots, w_D]^T$
-   **Feature Vector `x`**: $[1, x_1, \dots, x_D]^T$

The model becomes: $\hat{y} = w^Tx$.

For the entire dataset, we can use matrix form: $\hat{y} = Xw$, where `X` is the design matrix (each row is a feature vector) and `y` is the vector of all target values. The LSE solution for the optimal weights is:

$$
\hat{w} = (X^T X)^{-1}X^T y
$$

### Handling Categorical Features

Categorical features (like "Party: Rep/Dem/Ind") must be converted into a numerical format. The standard method is **one-hot encoding** (or 1-of-K coding scheme), where a feature with `K` categories is converted into `K` binary columns.

---

## 4. Generalized Linear Models (Linear Basis Function Models)

Linear regression can be extended to model non-linear relationships by using **basis functions**. The model remains linear with respect to the *weights*, but can be non-linear with respect to the *input features*.

The general form is:
$$
\hat{y}(x) = w^T\phi(x)
$$
-   $\phi(x)$ is a vector of basis functions that transform the input `x`.

**Example: Polynomial Regression**
To fit a cubic curve to data with one feature `x`, the basis functions would be:
$$
\phi(x) = [1, x, x^2, x^3]^T
$$
The model is $\hat{y} = w_0 \cdot 1 + w_1 \cdot x + w_2 \cdot x^2 + w_3 \cdot x^3$, which is a non-linear function of `x` but still a linear combination of the weights `w`.

---

## 5. Evaluating Regression Models

To assess how well a model performs, especially on new, unseen data, we use evaluation metrics on a **test set** (data that was not used for training).

-   **Mean Squared Error (MSE)**: The average of the squared errors. It's sensitive to large errors (outliers).
    $$
    MSE = \frac{1}{M}\sum_{i=1}^{M}(y_i - \hat{y_i})^2
    $$
-   **Mean Absolute Error (MAE)**: The average of the absolute errors. It's less sensitive to outliers than MSE.
    $$
    MAE = \frac{1}{M}\sum_{i=1}^{M}|y_i - \hat{y_i}|
    $$
For both metrics, a smaller value indicates a better model fit.
