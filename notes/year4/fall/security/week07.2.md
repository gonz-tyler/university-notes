# Week 07.2: Quantitative Information Flow Control II - Revision Notes

---

## 1. The Problem: Hidden Information Leakage

Standard security measures like **Access Control** and **Encryption** are often insufficient to fully protect sensitive data. Even if a system is theoretically secure, it can leak secret information through **correlated observables** (side channels).

* **Observables**: These are public outputs or behaviors of the system that an attacker can see or measure (e.g., error messages, execution time, power consumption).
* **The Goal**: Ideally, we want **Non-Interference**, where actions by a high-security user have absolutely no effect on what a low-security user sees.
* **The Reality**: In practice, almost all systems leak *some* information. Therefore, we need **Quantitative Information Flow (QIF)** to measure *how much* is leaking and determine if it is acceptable.

---

## 2. Examples of Information Flow

### A. Password Checking (Timing Leaks)
Consider two versions of a password checker:
1.  **Secure but Slow**: Checks every character of the input against the real password, even if a mismatch is found early. Returns result only after checking all characters.
2.  **Fast but Insecure**: Returns `FAIL` immediately upon finding the first mismatching character.
    * **The Leak**: The second version introduces a **timing channel**. An attacker can measure how long the program takes to reject a guess. Longer execution means more leading characters were correct, allowing the attacker to guess the password character by character.

### B. DC Nets (Dining Cryptographers)
A protocol designed to allow a source to broadcast a bit ($b$) anonymously.
* **Mechanism**: Nodes toss coins and share results. The protocol uses XOR operations (binary sums) to transmit the message.
* **Strong Anonymity**: If the coins are fair (50/50 probability), an external observer sees the output but learns nothing about *who* sent it (the *a posteriori* probability equals the *a priori* probability).
* **Leakage**: If the coins are **biased** (e.g., 2/3 probability of Heads), the protocol leaks information, and the observer can determine that certain nodes are more likely to be the source than others.

### C. Crowds
A protocol for anonymous web browsing.
* **Probable Innocence**: A guarantee that, from the perspective of an attacker, the probability that any specific user is the originator of a message is not greater than 0.5.

---

## 3. The Information-Theoretic View

QIF models a system as a **noisy channel** in information theory.

* **Input ($S$)**: The Secret information (e.g., the password).
* **Output ($O$)**: The Observables (e.g., pass/fail response, timing).
* **Channel Matrix**: A matrix of conditional probabilities $p(o|s)$, representing the probability of observing output $o$ given secret $s$.

### Bayesian Update
The attacker starts with a **Prior** probability distribution of the secret, $p(s)$. After observing an output $o$, they update this to a **Posterior** probability distribution, $p(s|o)$, using Bayes' theorem:

$$
p(s|o) = \frac{p(o|s) \cdot p(s)}{p(o)}
$$

If the posterior distribution is significantly different from the prior (i.e., the attacker has narrowed down the possibilities), **leakage** has occurred.

---

## 4. Measuring Leakage: Entropy

We use **Entropy** ($\mathcal{H}$) to quantify uncertainty.

### Shannon Entropy
The expected amount of information (in bits) required to describe the value of a random variable $S$. It represents the attacker's uncertainty about the secret.

$$
\mathcal{H}(S) = -\sum_{s} p(s) \log_2 p(s)
$$

* **Uniform Distribution**: Entropy is highest when all secrets are equally likely. For $n$ secrets, max entropy is $\log_2 n$.
* **Operational Interpretation**: Entropy roughly corresponds to the expected number of "Yes/No" questions an attacker needs to ask to find the secret (using an optimal binary search strategy).

### Mutual Information (Leakage)
Leakage is defined as the difference between the uncertainty before the observation and the uncertainty remaining after the observation.

$$
\text{Leakage} = \mathcal{I}(S;O) = \mathcal{H}(S) - \mathcal{H}(S|O)
$$

* **$\mathcal{H}(S)$**: Initial (Prior) Uncertainty.
* **$\mathcal{H}(S|O)$**: Conditional (Posterior) Entropy (Expected remaining uncertainty given the observation).
* **Shannon Capacity**: The worst-case leakage over all possible prior distributions.

---

## 5. Case Study: PIN Checking

Consider a program checking a 5-digit PIN.
* **Input**: User guess $x$.
* **Secret**: Actual PIN $s$ (Uniformly distributed, $10^5$ possibilities).
* **Output**: 1 if $x=s$ (Correct), 0 if $x \neq s$ (Wrong).

**Leakage Calculation**:
* **Prior Entropy**: $\log_2(10^5) \approx 16.61$ bits.
* **Observation**:
    * If Output = 1 (Correct): Uncertainty drops to 0. (Huge information gain, but extremely rare event).
    * If Output = 0 (Wrong): Uncertainty remains almost the same (reduced by a tiny fraction because we eliminated only 1 out of 100,000 options).
* **Result**: Because the "Wrong" output is overwhelmingly likely, the **average** remaining uncertainty $\mathcal{H}(S|O)$ is extremely close to the initial uncertainty.
* **Leakage**: $\approx 0.002$ bits.
* **Conclusion**: This specific program (without timing leaks) is statistically safe because the average leakage is negligible.
