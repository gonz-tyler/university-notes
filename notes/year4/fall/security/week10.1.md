# Week 10.1: Introduction to Differential Privacy Revision Notes

---

## 1. Introduction: Databases and Queries

A database is a collection of records, where each record represents an individual's data (e.g., age, salary, medical status). We perform **queries** on these databases to extract useful information, like the average age or the count of people with a specific disease.

### Key Concepts

- **Record**: An element from a domain of values (e.g., `(John, 20)`).
- **Database (Dataset)**: A collection of $n$ records.
- **Adjacency**: Two databases $x_1$ and $x_2$ are **adjacent** ($x_1 \sim x_2$) if they differ by exactly one record (i.e., one individual's data is added, removed, or changed). This concept is central to differential privacy.
- **Query**: A function $f$ that takes a database as input and returns a value (e.g., the average salary).
- **Randomized Mechanism**: A function $\mathcal{K}$ that takes a database and returns a _probability distribution_ of possible answers, rather than a single deterministic answer. This adds "noise" to protect privacy.

---

## 2. Differential Privacy (DP) Overview

### Definition of $\epsilon$-Differential Privacy

A randomized mechanism $\mathcal{K}$ is **$\epsilon$-differentially private** if for any two adjacent databases $x_1$ and $x_2$ (differing by one person), and for any possible output $z$:

$$
P(\mathcal{K}(x_1) = z) \le e^{\epsilon} \cdot P(\mathcal{K}(x_2) = z)
$$

### Meaning

- The probability of getting a specific output $z$ should be almost the same whether an individual is in the database ($x_1$) or not ($x_2$).
- **Privacy Guarantee**: An attacker seeing the output cannot confidently determine if any specific individual's data was used. The presence or absence of a single person has a negligible effect on the outcome.
- **Privacy Parameter $\epsilon$ (Epsilon)**:
  - Controls the level of privacy.
  - **Smaller $\epsilon$**: Stronger privacy (the distributions are very close), but potentially less useful data (more noise).
  - **Larger $\epsilon$**: Weaker privacy, but more accurate data (less noise).

### Key Properties

1.  **Independence from Adversary's Knowledge**: DP guarantees privacy regardless of what external information an attacker already knows.
2.  **Compositionality**: If you combine two DP mechanisms, the result is still differentially private.
    - If $\mathcal{K}_1$ is $\epsilon_1$-DP and $\mathcal{K}_2$ is $\epsilon_2$-DP, their combination is $(\epsilon_1 + \epsilon_2)$-DP.
    - This introduces the concept of a **Privacy Budget**: Every query "consumes" a bit of the budget ($\epsilon$). Once the budget is exhausted, no more queries are allowed to prevent privacy leakage accumulation.

---

## 3. Mechanisms for Differential Privacy

To achieve DP, we add random **noise** to the true answer of a query. The amount of noise depends on the query's **sensitivity**.

### Sensitivity ($\Delta f$)

The sensitivity of a query $f$ measures the maximum amount the output can change if one record in the database is changed.

$$
\Delta f = \max_{x_1 \sim x_2} |f(x_1) - f(x_2)|
$$

- **Example**: For a "count" query (how many people?), adding one person changes the result by at most 1. So, $\Delta f = 1$.

### The Laplace Mechanism

For queries with numerical answers, we can achieve $\epsilon$-DP by adding noise drawn from a **Laplace distribution**.

- **Noise**: Sampled from $Lap(\frac{\Delta f}{\epsilon})$.
- **Mechanism**: Report $z = f(x) + \text{noise}$.
- **Trade-off**:
  - High sensitivity ($\Delta f$) $\rightarrow$ More noise needed.
  - Stronger privacy (small $\epsilon$) $\rightarrow$ More noise needed.

### The Gaussian Mechanism

Another way to add noise is using a **Gaussian (Normal) distribution**.

- **Limitation**: Gaussian noise does **not** strictly satisfy $\epsilon$-DP.
- **Relaxed DP**: It satisfies **$(\epsilon, \delta)$-Differential Privacy**.
  - The definition is relaxed by an additive term $\delta$:
    $$P(\mathcal{K}(x_1) = z) \le e^{\epsilon} \cdot P(\mathcal{K}(x_2) = z) + \delta$$
  - $\delta$ represents a small probability that the privacy guarantee might fail.
- **Why use it?**: It is often practically useful and arises naturally in some settings (e.g., sampling).
