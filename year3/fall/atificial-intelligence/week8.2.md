# Week 8.2: Learning 2 - Regression (AIMA Ch 19.4-19.6)
## Notes
---
### **Key Concepts**

1. **Introduction to Regression**:
    - **Regression** is a type of supervised learning used to predict continuous outcomes based on input features.
    - Unlike classification, which predicts discrete labels, regression models predict **real-valued outputs**.
    - The goal is to find a function that **maps inputs to outputs** in such a way that the error (difference between the predicted and actual values) is minimized.
2. **Linear Regression**:
    - **Linear regression** is the simplest and most widely used regression technique.
    - The model assumes a **linear relationship** between the input variables and the output.
    - The equation for simple linear regression (with one feature) is: 
    $$ y = \beta_0 + \beta_1 x $$
        - $y$ is the predicted output (dependent variable).
        - $x$ is the input feature (independent variable).
        - $\beta_0$​ is the intercept (the value of $y$ when $x=0$).
        - $\beta_1$​ is the slope (the rate of change of $y$ with respect to $x$).
    - In **multiple linear regression**, there are multiple input features:
        
        $$y = \beta_0 + \beta_1 x_1 + \beta_2 x_2 + \dots + \beta_n x_n$$
        
        - Each $\beta_i$ corresponds to the weight of feature $x_i$​, which determines the effect of each feature on the predicted output.
3. **Objective of Linear Regression**:
    - The goal is to find the best-fitting line (or hyperplane in the case of multiple regression) that minimizes the **sum of squared errors** (SSE) or **residual sum of squares (RSS)** between the predicted and actual values:
    $$RSS = \sum_{i=1}^{n} (y_i - \hat{y}_i)^2$$
    where $y_i$​ are the actual values and $\hat{y}_​i$​ are the predicted values.
4. **Solving for the Parameters**:
    - The parameters $\beta_0, \beta_1, \dots, \beta_n$ are typically found using methods like:
        - **Ordinary Least Squares (OLS)**: A method that minimizes the sum of squared errors. The formula for the solution is:
        $$\beta = (X^T X)^{-1} X^T y$$
        where $X$ is the matrix of input features, and $y$ is the vector of actual values.
        - **Gradient Descent**: An iterative optimization method to minimize the error function by updating the parameters in the direction of the negative gradient of the error.
5. **Assumptions of Linear Regression**:
    - **Linearity**: The relationship between the independent variables and the dependent variable is linear.
    - **Independence**: The residuals (errors) should be independent of each other.
    - **Homoscedasticity**: The residuals should have constant variance across all levels of the independent variables.
    - **Normality of Errors**: The errors are assumed to be normally distributed (this is important for hypothesis testing).
6. **Polynomial Regression**:
    - **Polynomial regression** is an extension of linear regression where the relationship between the independent and dependent variables is modeled as an **nth-degree polynomial**:
    $$y = \beta_0 + \beta_1 x + \beta_2 x^2 + \dots + \beta_n x^n$$
    - Polynomial regression allows for fitting more complex, non-linear relationships, but it can also lead to **overfitting** if the degree of the polynomial is too high.
7. **Regularization**:
    - **Regularization** is a technique used to prevent **overfitting** in regression models, especially when the number of features is large or the model is very complex.
    - Common regularization methods include:
        - **Lasso Regression** (L1 regularization): Adds a penalty proportional to the sum of the absolute values of the coefficients, encouraging sparsity (some coefficients are driven to zero).
        - **Ridge Regression** (L2 regularization): Adds a penalty proportional to the sum of the squares of the coefficients, shrinking the coefficients but not necessarily to zero.
        - **Elastic Net**: Combines Lasso and Ridge regularization, providing a balance between sparsity and shrinkage.
8. **Model Evaluation for Regression**:
    - After training a regression model, its performance is evaluated using various metrics:
        - **Mean Absolute Error (MAE)**: The average absolute difference between predicted and actual values.
        $$MAE = \frac{1}{n} \sum_{i=1}^{n} |y_i - \hat{y}_i|$$
        - **Mean Squared Error (MSE)**: The average squared difference between predicted and actual values.
        $$MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2$$
        - **Root Mean Squared Error (RMSE)**: The square root of the MSE, providing an error metric in the same units as the target variable.
        - **R-squared ($R^2$**: A measure of how well the model explains the variance in the dependent variable. Ranges from 0 (no fit) to 1 (perfect fit).
        $$R^2 = 1 - \frac{\sum (y_i - \hat{y}_i)^2}{\sum (y_i - \bar{y})^2}$$
        - **Adjusted $R^2$**: A modified version of $R^2$ that adjusts for the number of predictors in the model, preventing overfitting by penalizing the addition of irrelevant variables.
9. **Limitations of Linear Regression**:
    - Linear regression models assume that the relationship between features and the target variable is linear. If this assumption is violated, the model will not perform well.
    - It can be sensitive to **outliers**, as they can disproportionately affect the line of best fit.
    - **Multicollinearity**: If there is a high correlation between two or more independent variables, it can lead to instability in the coefficient estimates.
10. **Applications of Regression**:
    - **Predictive Modeling**: Regression is widely used in fields like economics, finance, healthcare, and social sciences for predicting continuous values (e.g., stock prices, house prices, demand forecasting).
    - **Trend Analysis**: Used to model the relationship between variables and understand underlying trends over time.

---

### **Key Insights**:

- **Regression** is a fundamental technique in machine learning, enabling the prediction of continuous variables.
- **Linear regression** is simple and effective when the relationship between variables is linear, but more complex relationships may require **polynomial regression** or other models.
- **Regularization** is critical to prevent overfitting, especially in models with many features or complex relationships.
- Evaluation metrics like **MAE**, **MSE**, and **R-squared** help assess the accuracy of regression models and guide model selection and improvement.

---

This chapter covers the key concepts in **regression analysis**, a core method in supervised learning. By understanding the techniques, assumptions, and evaluation metrics associated with regression, you can build effective models for continuous prediction tasks in a variety of domains.
