# Week 05: K-Nearest Neighbour (KNN)

---

## 1. The KNN Intuition

The K-Nearest Neighbour (KNN) algorithm is a simple yet powerful supervised learning method. The core idea is based on the saying, "Birds of a feather flock together."

> To classify a new, unknown data point, we look at the other data points that are most similar (i.e., "nearest") to it and assign the new point to the class that is most common among its neighbours.

KNN is a **non-parametric** method, meaning it makes no strong assumptions about the underlying distribution of the data. It's also called a "lazy learner" because it doesn't build a model during training; all the computation happens at prediction time.

---

## 2. The KNN Algorithm

The KNN algorithm can be used for both classification and regression tasks.

### KNN for Classification

The goal is to predict a discrete class label.

1.  **Given**: A training dataset of labeled examples `(xᵢ, yᵢ)` and a new, unlabeled point `x*` to classify.
2.  **Step 1: Compute Distances**: Calculate the distance from the new point `x*` to **every single point** `xᵢ` in the training data.
3.  **Step 2: Find Neighbours**: Select the `k` training examples that are closest to `x*`.
4.  **Step 3: Majority Vote**: Assign the class label to `x*` that is the **most frequent** among its `k` nearest neighbours.

The decision boundary created by 1-NN can be visualized as a **Voronoi partition**, where space is divided into regions, each belonging to a single training point. However, 1-NN is highly sensitive to outliers and mislabeled data. Using a larger `k` helps to smooth out the decision boundary and make the model more robust to noise.

### KNN for Regression

The goal is to predict a continuous numerical value. The algorithm is nearly identical, except for the final step.

1.  **Given**: A training dataset `(xᵢ, yᵢ)` (where `yᵢ` are continuous values) and a new point `x*`.
2.  **Step 1: Compute Distances**: Same as for classification.
3.  **Step 2: Find Neighbours**: Select the `k` closest training examples.
4.  **Step 3: Average Values**: The prediction for `x*` is the **average** of the `y` values of its `k` nearest neighbours.
    $$
    y_* = \frac{1}{k}\sum_{j=1}^{k}y_j
    $$

---

## 3. Practical Issues in KNN

Several practical considerations can significantly affect the performance of a KNN model.

### Choosing the Value of `k`

The choice of `k` is a critical hyperparameter.

-   **Small `k`** (e.g., k=1): The model is very flexible and can capture fine-grained patterns, but it's also highly sensitive to noise and outliers, leading to unstable decision boundaries.
-   **Large `k`**: The model is more robust to noise and produces smoother decision boundaries. However, if `k` is too large, the model might become too simple and fail to capture the local structure of the data.

The optimal value for `k` is typically found using **cross-validation**. You split your training data, train models with different values of `k`, and choose the `k` that gives the best performance on the validation set.

### Distance Measures

The concept of "nearness" is defined by a distance metric. The choice of metric is crucial.

-   **Numeric Attributes**: The most common metric is **Euclidean Distance**.
    $$
    D(x, x') = \sqrt{\sum_{d}(x_d - x'_d)^2}
    $$
-   **Categorical Attributes**: For non-numeric data, **Hamming Distance** is used. It simply counts the number of attributes for which the two points differ.
    -   Example: `D("tube", "cube") = 1`

### Other Practical Issues

-   **Resolving Ties**: In classification, if there's a tie in the majority vote (e.g., 2 red vs. 2 blue neighbours), you can break it randomly, pick the class with the higher overall frequency in the dataset, or use the 1-NN result. Using an odd `k` for binary classification avoids this problem.
-   **Missing Values**: KNN cannot compute distances if data is missing. A common strategy is to **impute** missing values by filling them with the mean or median of that feature across the entire dataset.

---

## 4. Why Feature Scaling is Essential for KNN

**You should almost always normalize or standardize your features before using KNN.**

-   **The Problem**: KNN is a distance-based algorithm. If your features are on different scales (e.g., house size in sq-ft `[1000-5000]` vs. number of bedrooms `[1-5]`), the feature with the larger scale will completely dominate the distance calculation. The number of bedrooms would have almost no effect.
-   **The Solution**: Rescale all features to a common range.
    -   **Normalization**: Scales features to a fixed range, typically [0, 1].
    -   **Standardization**: Rescales features to have a mean of 0 and a standard deviation of 1.

This ensures that all features contribute equally to the distance metric, leading to a much more meaningful and accurate model.

---

## 5. Strengths and Weaknesses of KNN

| Strengths | Weaknesses |
| :--- | :--- |
| Simple and intuitive to understand. | Computationally expensive at **prediction time**. |
| Non-parametric: makes few assumptions about data distribution. | Very sensitive to irrelevant features (curse of dimensionality). |
| Can learn complex, non-linear decision boundaries. | Sensitive to outliers and mislabeled data. |
| Easy to update with new data (just add it to the training set). | Requires a strategy for handling missing values. |
| Works for both classification and regression. | Performance depends heavily on choosing a good `k` and distance metric. |
