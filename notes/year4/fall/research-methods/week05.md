# Week 05: Experimental Design Revision Notes

---

## 1. The Five Components of Experimental Design

When designing any experiment in computer science, whether for evaluation or exploration, you must carefully consider five key components. Getting these basics right is a crucial part of any research project.

The five components are:
1.  **Hypotheses**: What specific, testable questions are you trying to answer?
2.  **Subjects**: If the experiment involves people, who are they?
3.  **Material**: What data, scenarios, or inputs will you use?
4.  **Procedure**: What are the step-by-step instructions for the experiment?
5.  **Analysis**: How will you analyze and report the data you collect?

---

## 2. Hypotheses

A hypothesis is a precise, measurable statement that you can test. A vague goal like "my new search engine, SuperSearch, is better than Google" is not a hypothesis. It must be refined into something concrete.

### Types of Hypotheses

Evaluation hypotheses in CS usually fall into one of these categories:
* **User Satisfaction**: Users will prefer the new system or give it higher ratings (e.g., on a Likert scale).
* **Task Performance (Utility)**: Users will complete a task faster or with fewer mistakes using the new system.
* **Performance Metrics**: The system will achieve a better score on an objective metric (e.g., accuracy, precision, relevance of search results).
* **Compute Speed**: The system will run faster or use fewer resources.

### Baselines and the "Before" Rule

* **Compare to a Baseline**: Your hypothesis should almost always compare your system to a **baseline** (or "control"). This could be the market leader (e.g., Google), the best-performing academic system, or even a human expert. Be careful not to "cheat" by choosing a weak or inappropriate baseline.
* **Decide Before You Experiment**: You **must** define your hypotheses *before* you run the experiment and collect data. Changing your hypotheses after seeing the results to find something "significant" is a common but unethical practice.

---

## 3. Subjects (for Human-Based Experiments)

If your experiment involves users, you need to be systematic about who they are and how you find them.

* **Who are the subjects?**: They should be representative of the system's **potential users**. For example, don't test a specialized legal search tool on CS students. You should also report the characteristics of your subjects (e.g., age, gender, expertise).
* **How many subjects?**: While a statistical "power calculation" is ideal, this is often hard to do in practice. For student projects, **around 20 subjects** is a common number.
* **How to recruit subjects?**:
    * **Crowdsourcing** (e.g., Amazon Mechanical Turk): Good for getting many subjects for simple tasks, but they may not be representative or take the task seriously.
    * **Friends and Colleagues**: Convenient, but they may not be potential users and could be biased because they know you.
    * **Explicit Recruitment**: Targeting the exact user group you want. This is the best method but often takes the most time and effort.

---

## 4. Material

The "material" refers to the specific input data, scenarios, or tasks used in the experiment.

* **Standard Datasets**: In some fields like machine learning, standard, publicly available datasets are used for evaluation. This simplifies the process, as you don't have to create your own material.
* **Choosing Scenarios**: If you need to create your own, it's often best to use a mixture of different types:
    * **Common scenarios**: e.g., the most popular searches on Google Trends.
    * **Difficult scenarios**: e.g., technically challenging or complex search queries.
    * **Random scenarios**: e.g., letting users search for whatever they want.

---

## 5. Procedure

The procedure is the detailed, step-by-step plan for how the experiment will be conducted. It must be described in enough detail that someone else could replicate your experiment.

### Key Procedural Decisions

* **What software to use?**: Be specific. If you're testing an algorithm, which implementation and programming language? If you're using an LLM, which version, prompt, and temperature setting?
* **What to measure?**: Be precise. If measuring user satisfaction, is it a 5-point or 7-point Likert scale? If measuring speed, on what hardware?
* **Within-Subjects vs. Between-Subjects Design**:
    * **Within-Subjects**: Each subject tries **all** the systems being compared (e.g., every user tries both Google and SuperSearch). This is often preferred as it controls for individual differences between people.
    * **Between-Subjects**: Subjects are split into groups, and each group tries **only one** system (e.g., Group A uses Google, Group B uses SuperSearch).
* **Latin Square Design**: A common technique in within-subjects experiments to balance the order of tasks and systems, ensuring that learning effects or fatigue don't bias the results.

---

## 6. Analysis

Once you have your data, you need to analyze and report it.

* **Show Raw Data**: Present your findings clearly using graphs and tables.
* **Statistical Analysis**: Use statistical tests (e.g., binomial test, t-test) to determine if your results are **statistically significant** or if they could have occurred by chance.
* **Error Analysis**: This is a **qualitative** analysis where you look at a few specific cases where your system failed and try to understand *why*. This can provide valuable insights that numbers alone cannot. For example, "Face recognition failed in this case because of poor lighting."
