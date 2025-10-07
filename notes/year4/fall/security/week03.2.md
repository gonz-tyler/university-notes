# Week03.2: Gradient Descent Revision Notes

---

## 1. Introduction to Gradient Descent

**Gradient Descent (GD)** is the primary optimization algorithm used in machine learning. Its purpose is to find the minimum value of a function by iteratively moving in the direction of steepest descent. In machine learning, we use it to minimize a **loss function**, thereby finding the optimal parameters (weights) for a model.

### The Core Concept 🏔️

-   **Function**: Imagine a function as a landscape with hills and valleys. Our goal is to find the lowest point in a valley (a minimum).
-   **Gradient**: The gradient (or derivative) of the function at any point tells us the direction of the steepest *ascent* (uphill).
-   **The Algorithm**: To find the minimum, we start at a random point and repeatedly take a small step in the **opposite direction of the gradient** (downhill).

### The Update Rule

The algorithm iteratively updates the model's parameters ($\theta$) using the following rule:

$$
\theta_{\text{new}} = \theta_{\text{old}} - \alpha \nabla_{\theta}f(\theta)
$$

-   $\theta$ represents the parameters of the model (e.g., the weights `w` in linear regression).
-   $f(\theta)$ is the loss function we want to minimize.
-   $\nabla_{\theta}f(\theta)$ is the gradient of the loss function with respect to the parameters.
-   $\alpha$ is the **learning rate**, a small positive number that controls the size of each step. Choosing a good learning rate is crucial:
    -   Too small: Convergence will be very slow.
    -   Too large: The algorithm might overshoot the minimum and fail to converge.

### Convex vs. Non-Convex Functions

-   **Convex Functions**: These are bowl-shaped functions with a single global minimum (e.g., the SSE loss function for linear regression). GD is guaranteed to find this global minimum.
-   **Non-Convex Functions**: These functions have multiple local minima (valleys). GD is only guaranteed to find a local minimum, not necessarily the global one. The loss landscapes of deep learning models are highly non-convex.

---

## 2. Stochastic Gradient Descent (SGD)

Standard Gradient Descent (also called **Batch GD**) has a major drawback: it is computationally expensive. For every single update step, it must calculate the gradient using the **entire training dataset**. This becomes impractical for large datasets.

**Stochastic Gradient Descent (SGD)** solves this by estimating the gradient using a smaller, random subset of the data.

### Variants of SGD

1.  **Standard SGD**: At each step, the gradient is calculated using only **one** randomly selected data sample. This is very fast but produces a "noisy" gradient, causing the loss to fluctuate significantly.
2.  **Mini-Batch SGD**: This is a compromise between Batch GD and standard SGD. At each step, the gradient is calculated using a small, random subset of the data called a **mini-batch** (e.g., 32, 64, or 128 samples). This is the most common approach used in modern machine learning and deep learning.

### The SGD Update Rule (Mini-Batch)

The update rule is similar, but the gradient is an average over the mini-batch $I_t$:

$$
\theta^{t+1} = \theta^{t} - \alpha_t \frac{1}{|I_t|} \sum_{i \in I_t} \nabla_{\theta}f(\theta, x_i)
$$

### Trade-offs and Benefits of SGD

-   **Computational Cost**: SGD is far more efficient. If the full dataset has `N` samples and the mini-batch has `d` samples, the cost per step is reduced from $O(N \cdot p)$ to $O(d \cdot p)$, where `p` is the number of features.
-   **Convergence Speed**: SGD converges much faster in terms of wall-clock time. While the loss may bounce around more, it makes progress much more quickly.
-   **Optimization**: The noisy updates in SGD can help the algorithm escape from shallow local minima, which can sometimes lead to a better overall solution in non-convex problems.
