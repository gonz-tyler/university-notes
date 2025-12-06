# Week 10.2: Privacy Issues in Machine Learning Revision Notes

---

## 1. Overview of Privacy Risks in Machine Learning

Machine learning models, when trained on sensitive data (e.g., medical records, financial data), can inadvertently leak information about that data. Two fundamental privacy risks are:

1.  **Membership Inference (MI)**: Determining whether a specific individual's record was part of the dataset used to train the model.
2.  **Feature Inference (Model Inversion)**: Inferring sensitive attributes or reconstructing the original data of a record, given partial information about it or simply access to the model.

---

## 2. Membership Inference (MI) Attacks

**Goal**: To determine if a specific record $x$ belongs to the training dataset $D$.

### Motivation

- **Direct Privacy Breach**: In sensitive contexts (e.g., a hospital dataset for a rare disease), knowing someone is in the database reveals sensitive information about them (e.g., they have that disease).
- **Establishing Wrongdoing**: It can prove that data was used illegally (e.g., the 2017 case where the NHS illegally shared patient data with Google DeepMind).
- **Gateway to Other Attacks**: Confirming membership can be a stepping stone for further attacks on the model.

### Attack Scenarios

- **Black-Box Attack**: The attacker can only query the model (send input $x$ and get prediction $\hat{y}$) but has no access to the model's internal parameters or architecture.
  - _Naive Approach_: Simply check the confidence score. Models are often more confident (overfitted) on training data than unseen data.
  - _Shadow Models_: The attacker trains their own "shadow models" on similar data to mimic the target model's behavior. They use these to train an inference model that learns to distinguish members from non-members based on the target model's output.
- **White-Box Attack**: The attacker has full access to the model's architecture, parameters (weights $W$), and gradients.
  - _Gradient Norm_: The gradient of the loss function is expected to be much lower for training members (since the model has already minimized loss for them) compared to non-members. This allows for more powerful attacks.

### Evaluation

- Attacks are evaluated using metrics like **accuracy** (fraction of correct membership predictions) and **ROC curves** (True Positive vs. False Positive rates).

---

## 3. Feature Inference (FI) / Model Inversion Attacks

**Goal**: To recover missing sensitive features of a record or reconstruct the record entirely.

### Attack Scenarios

- **Inferring Sensitive Features**: Given a model $F_W$ and partial knowledge of a record (e.g., name, age, symptoms), the attacker tries to infer a missing sensitive attribute (e.g., genome type or dosage).
  - _Method_: The attacker can use Maximum a Posteriori (MAP) estimation to find the value of the missing feature that maximizes the likelihood of the model's output.
- **Reconstruction Attack**: The attacker attempts to reconstruct a representative example of a class (e.g., generating an image of a person's face given only their name and access to a facial recognition system).
  - _Example_: Researchers demonstrated that it is possible to recover recognizable images of faces from a facial recognition model using only the person's name and the model's confidence scores. This works against various model types like Softmax classifiers, MLPs, and DAEs.

---

## 4. Differential Privacy vs. Membership Inference

It is important to distinguish between these concepts:

- **Differential Privacy (DP)**: A _defensive_ guarantee. It ensures that the model's output is statistically similar whether or not any single individual's record is in the dataset. It focuses on preventing sensitive information leakage.
- **Membership Inference**: An _offensive_ attack (or risk). It specifically targets the ability to determine membership.

Strong Differential Privacy is a robust defense against Membership Inference attacks because if the model's output doesn't change based on a record's presence, an attacker cannot infer membership.
