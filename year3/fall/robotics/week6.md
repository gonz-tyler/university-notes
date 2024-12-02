# Week 6: Bayes Filters and Kalman Filters
## Notes
---

### Core Concepts in Localization

#### Map-Based Localization
- The robot estimates its position using:
  - **Map**: Can be prebuilt or created in real-time (SLAM).
  - **Sensor Models**: Capture environment perceptions.
  - **Motion Models**: Account for robot's movements.

#### Challenges
- Maps and sensor measurements are error-prone.
- Localization must handle uncertain information.

---

### Bayes Filter Framework

#### Definition
- A probabilistic method to calculate the robot's belief \( bel(x_t) \) (probability of being in state \( x_t \)) based on:
  - **Past Observations**: \( z_1, z_2, \dots, z_t \).
  - **Control Inputs**: \( u_1, u_2, \dots, u_t \).

#### Recursive Formula
$$
bel(x_t) = \eta P(z_t | x_t) \int P(x_t | u_t, x_{t-1}) bel(x_{t-1}) dx_{t-1}
$$

#### Prediction Step
$$
bel'(x_t) = \int P(x_t | u_t, x_{t-1}) bel(x_{t-1}) dx_{t-1}
$$

#### Correction Step
$$
bel(x_t) = \eta P(z_t | x_t) bel'(x_t)
$$

---

### Gaussian Distribution

#### Univariate Gaussian
$$
p(x) = \frac{1}{\sqrt{2\pi\sigma^2}} e^{-\frac{(x - \mu)^2}{2\sigma^2}}
$$

#### Multivariate Gaussian
$$
p(x) = \frac{1}{(2\pi)^{d/2} |\Sigma|^{1/2}} e^{-\frac{1}{2}(x - \mu)^T \Sigma^{-1} (x - \mu)}
$$

---

### Kalman Filter

#### Purpose
- Estimates the state \( x_t \) of a system governed by linear dynamics and Gaussian noise.

#### System Model
- State Transition
$$
x_t = A x_{t-1} + B u_t + \epsilon_t, \quad \epsilon_t \sim N(0, R_t)
$$

- Observation Model
$$
z_t = C x_t + \delta_t, \quad \delta_t \sim N(0, Q_t)
$$

#### Steps in Kalman Filter
- Prediction
1. Mean Update:
$$
\mu_t^- = A \mu_{t-1} + B u_t
$$
2. Covariance Update:
$$
\Sigma_t^- = A \Sigma_{t-1} A^T + R_t
$$

- Correction
1. Kalman Gain:
$$
K_t = \Sigma_t^- C^T (C \Sigma_t^- C^T + Q_t)^{-1}
$$
2. Mean Update:
$$
\mu_t = \mu_t^- + K_t (z_t - C \mu_t^-)
$$
3. Covariance Update:
$$
\Sigma_t = (I - K_t C) \Sigma_t^-
$$

---

### Extended Kalman Filter (EKF)

#### Handles Nonlinear Dynamics
- State Transition
$$
x_t = g(x_{t-1}, u_t) + \epsilon_t, \quad \epsilon_t \sim N(0, R_t)
$$

- Observation Model
$$
z_t = h(x_t) + \delta_t, \quad \delta_t \sim N(0, Q_t)
$$

#### Linearization
1. Jacobian of Motion Model:
$$
G_t = \frac{\partial g(x_{t-1}, u_t)}{\partial x_{t-1}}
$$
2. Jacobian of Observation Model:
$$
H_t = \frac{\partial h(x_t)}{\partial x_t}
$$

#### EKF Algorithm
- Prediction
1. Mean Update:
$$
\mu_t^- = g(\mu_{t-1}, u_t)
$$
2. Covariance Update:
$$
\Sigma_t^- = G_t \Sigma_{t-1} G_t^T + R_t
$$

- Correction
1. Kalman Gain:
$$
K_t = \Sigma_t^- H_t^T (H_t \Sigma_t^- H_t^T + Q_t)^{-1}
$$
2. Mean Update:
$$
\mu_t = \mu_t^- + K_t (z_t - h(\mu_t^-))
$$
3. Covariance Update:
$$
\Sigma_t = (I - K_t H_t) \Sigma_t^-
$$

---

### Prediction-Correction Cycle

1. **Prediction**:
   - Predict next state using motion model and control inputs.

2. **Correction**:
   - Incorporate new sensor measurements to refine state estimate.

---

### Summary

1. **Bayes Filters**:
   - General framework for probabilistic localization.
   - Accounts for uncertainty in measurements and actions.

2. **Kalman Filters**:
   - Optimal for linear Gaussian systems.
   - Recursive and computationally efficient.

3. **Extended Kalman Filters**:
   - Handles nonlinear systems by linearizing the models.

4. **Applications**:
   - Mobile robot localization.
   - Tracking objects in dynamic environments.

