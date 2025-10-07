# Week02: Research Literature Revision Notes

---

## 1. The Importance of Research Literature

In science and computing, progress is made by building upon previous work. As Isaac Newton said, "If I have seen further it is by standing on the shoulders of giants." It's essential to know what has already been done in your field to build upon it and to ensure your own ideas are novel.

A **literature review** is a survey of the research literature on your topic. It involves:
-   **Synthesizing and summarizing** key papers.
-   **Critically analyzing** the information to understand limitations and identify gaps.
-   Presenting these findings in an organized fashion.

Your project report must include a **Related Work** section that summarizes the most relevant existing research and explains how your work differs.

---

## 2. Types of Research Literature

There are many kinds of research literature, each with its own characteristics.

### Peer Review

-   **Peer-reviewed** content (most academic papers) has been assessed by experts in the field for correctness and value. It serves as a quality assurance mechanism.
-   **Non-peer-reviewed** content (like preprints, some web pages) should be read with caution as it hasn't been formally vetted.

### Common Literature Types

* **Conference and Workshop Papers**:
    -   Short (4-12 pages), dense, and timely papers presenting recent research.
    -   Highly respected in Computer Science, but less so in other fields like Medicine.
    -   Usually peer-reviewed.

* **Journal Articles**:
    -   Longer (10-25 pages), more detailed articles presenting major research findings.
    -   Often include introductory material, making them easier for newcomers to understand.
    -   Reputable journals have an "impact factor" to indicate their influence.

* **Books and Theses**:
    -   **Textbooks**: Explain a topic.
    -   **Monographs**: Detail an author's research.
    -   **Edited Collections**: A book of chapters by different authors on a related topic.
    -   **PhD Theses**: In-depth research projects.

* **Preprints (e.g., Arxiv)**:
    -   An archive where anyone can upload a paper **without peer review**.
    -   Popular in CS, containing both groundbreaking and low-quality work. It's important to assess the credibility of the authors.

* **Other Sources**:
    -   **Patents**: Formally reviewed by patent examiners but often written in dense "legalese."
    -   **Web Pages**: Quality is highly variable. Wikipedia articles in CS are generally good, but always be critical.
    -   **Commercial State of the Art**: Citing commercial products can be useful, but be wary of marketing hype.

### Assessing Paper Quality

-   **Citations**: Use Google Scholar to see how often a paper has been cited by others.
    -   **100+ citations**: Influential research.
    -   **10-100 citations**: Respected research.
    -   **0-10 citations**: Be cautious (unless the paper is very recent).

---

## 3. Finding Related Work

With vast archives (e.g., over 100k papers in NLP), finding the 10-20 most relevant papers is a key skill.

* **Ask People**: Your supervisor, lecturers, and PhD students are the best starting point.
* **Review Articles and Textbooks**: These sources summarize key research and point to important papers.
* **Search Engines**: Use **Google Scholar** and **Semantic Scholar**, which are designed specifically for academic literature.
* **Follow Citations**: If you find a key paper, use Google Scholar to find more recent papers that have cited it. Also, look for more recent work by the same authors.
* **Generative AI (e.g., ChatGPT)**: Can be a useful starting point for suggestions, but **you must read the papers yourself**. Be extremely careful, as these tools can "hallucinate" (invent) fake papers or make false claims about real ones.

---

## 4. How to Read a Research Paper

Reading academic papers is a skill that improves with practice.

1.  **Step 1: Read the Abstract**: Start with the abstract (and perhaps the introduction and conclusion) to quickly decide if the paper is relevant, interesting, and believable.
2.  **Step 2: Skim the Paper**: Read through quickly to get a general sense of the work. Is it understandable? Does it seem trustworthy (e.g., uses sensible statistics)?
3.  **Step 3: Read Carefully**: If the paper is worth a deep dive, read it carefully, focusing on its relationship to your work. Take notes on its contributions, strengths, and weaknesses.
4.  **Step 4: Contact the Author**: If you have questions, consider emailing the author. Most researchers are happy to discuss their work.

---

## 5. Citing Related Work

Properly citing sources is a critical academic requirement.

* **In-text citations** and a **Reference list** at the end of your report are both required.
* **LaTeX** and its **BibTeX** subsystem are the standard for managing citations and references in Computer Science.
* A **`.bib` file** stores reference information (title, author, year, etc.) for each paper, identified by a unique key.
* You cite papers in your main `.tex` document using commands like `\citet{key}` and `\citep{key}`.
    -   `\citet{reiter2018bleu}` produces a textual citation: "Reiter (2018) showed that..."
    -   `\citep{reiter2018bleu}` produces a parenthetical citation: "...is not always reliable (Reiter, 2018)."
