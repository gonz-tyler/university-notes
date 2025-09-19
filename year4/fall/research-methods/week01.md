# Week01: Introduction to Research Methods

## Notes
---

### The Scientific Method

Scientific research is a structured process for investigating phenomena.

#### Hypotheses and Testing

* **The Process**: The scientific method involves:
    1.  Proposing **hypotheses**.
    2.  Experimentally **testing** these hypotheses.
    3.  **Rejecting or refining** the hypotheses based on experimental results.
    4.  Repeating the process, acknowledging that no experiment is perfect.
* **Testable Hypotheses**: A core principle is that hypotheses must be testable. For example, the claim "the Moon is made of green cheese" can be tested by analysing moon rocks. However, a subjective statement like "Python is better than Java" is not directly testable. In such cases, researchers must find related, testable aspects, such as comparing job availability or developer productivity between the two languages.
* **Data over Opinion**: Conclusions must be based on experimental data, not expert opinion. We believe the speed of light is fixed because of repeated experimental measurements, not simply because Einstein said so.

#### Limitations of Experiments

* **Falsification vs. Proof**: Experiments can often **falsify** (disprove) a hypothesis, but they can rarely **prove** it with 100% certainty. We know the "green cheese" hypothesis is false because moon rocks are not cheese. However, we can't be absolutely certain the "speed of light is fixed" is true in every possible context, only that it has been true in every experiment conducted so far.
* **Honesty in Reporting**: It is an essential part of science to report results honestly, including **negative results** where an experiment fails to support the hypothesis or is inconclusive.

#### Theories and Models

Experimentally-supported hypotheses are used to build broader **theories and models** that generalise findings and explain how the world works. Examples include plate tectonics in geology and quantum theory in physics.

---

### Computing Science (CS) Research

CS research applies the scientific method to create and evaluate algorithms, models, systems, and methodologies.

#### Common Types of CS Hypotheses

* **Speed**: Algorithm X is faster than algorithm Y (e.g., Quicksort is faster than bubble sort).
* **Quality**: System X produces better output than system Y (e.g., Google Translate produces better translations than Bing Translate).
* **Acceptability**: Users prefer system X over system Y (e.g., users prefer a mouse over a touchscreen for desktop PCs).
* **Development Time**: Software is developed faster using method X than method Y (e.g., rapid prototyping is faster than the waterfall model).

#### The CS Research Process

Most CS research involves:
1.  Creating an algorithm, model, or system that is claimed to be **better** than an existing one in a specific context.
2.  Formulating a clear **hypothesis** that states how it is better.
3.  **Experimentally testing** this hypothesis.

Sometimes, research introduces something entirely novel, like the World Wide Web or public-key cryptography. In these cases, experiments focus on demonstrating the new creation's utility. The most impactful research often presents new theories or models, such as relational databases or large language models.

---

### Examples of CS Research Projects

#### Professor Reiter's Research

1.  **Safer Driving App**: An app was developed to monitor driving behaviour (e.g., speeding) and generate weekly feedback. The hypothesis was that using the app would lead to safer driving. Experiments showed a small but useful improvement.
2.  **Detecting Hallucinations in AI Text**: Neural language models sometimes generate incorrect "hallucinated" facts. A human-centric annotation protocol was developed to detect these errors. The hypothesis was that this protocol would be more accurate and replicable than existing methods, which was confirmed by experiments.
3.  **Using LLMs for Patient Communication**: This is an exploratory study to see if large language models can effectively communicate information to patients. Rather than testing a hypothesis, this work is focused on *generating* hypotheses. Early findings show challenges related to accuracy, lack of trust, and emotionally inappropriate text.

#### Adarsa Sivaprasad's Research

* **Explainable AI in IVF Treatment**: This project investigates how health prediction models communicate risk to patients. In the context of IVF, a model predicts the probability of having a baby. The research evaluates patient understanding and trust and explores what kinds of explanations users want. The methodology involves surveys, interviews, and analysis of user feedback.
