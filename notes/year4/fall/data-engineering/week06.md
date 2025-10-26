# Week 06: Visual Interfaces & EDA

---

## 1. Automation in Data Science & Data Engineering

Data science involves several stages, including Data Engineering, Data Exploration (EDA), Model Building (CDA), and Exploitation. Automation can take different forms:

* **Mechanization**: End-to-end automation (e.g., AutoML for model building). Less feasible for Data Engineering (DE) because data issues can change with every batch.
* **Composition**: Using workflow platforms to connect steps (e.g., Apache Airflow).
* **Assistance**: Tools that help data scientists/engineers work more effectively.

### Assistance in Data Engineering

Assistance tools are crucial for DE and can be categorized as:

1.  **Backend Assistance**: Libraries and algorithms that automatically or semi-automatically preprocess data (e.g., `SimpleImputer` in Scikit-Learn for missing values, `drop_duplicates` in Pandas).
2.  **Frontend Assistance**: Tools that engage data engineers in the DE process, allowing them to make informed decisions. This heavily relies on **Information Visualization (InfoVis)**.

---

## 2. Information Visualization (InfoVis)

InfoVis is the process of **representing abstract data visually** to help users gain insights.

* **Goal**: Make underlying patterns, relationships, and structures in the data visible and comprehensible.
* **Design**: Involves mapping data attributes (e.g., army size, temperature) to visual attributes (e.g., line thickness, position, colour).
* **Technology**: Uses computer graphics to render the visual representations (e.g., SVG, OpenGL).

### Principles of Good InfoVis

* **Based on Understanding**: Requires understanding both the data structures and human perception/cognition.
* **Simplicity**: Pack large amounts of information into simple, clear graphics. Highlight important information.
* **Truthfulness**: Accurately represent the data without distortion.
* **Maximize Data-Ink Ratio** (Edward Tufte): Minimize non-essential visual elements ("chart junk") so that most of the "ink" is used to represent the actual data.
* **Interactivity**: Modern InfoVis is often interactive, allowing users to explore the data dynamically.

### Visual Information Seeking Mantra (Ben Shneiderman)

A guideline for designing interactive visualizations:
> **"Overview first, zoom and filter, then details-on-demand."**

This mantra is part of the **Task by Type Taxonomy (TTT)**, which categorizes visualizations based on 7 data types (1D, 2D, 3D, Multi-dimensional, Temporal, Tree, Network) and 7 user tasks (Overview, Zoom, Filter, Details-on-demand, Relate, History, Extract).

---

## 3. Exploratory Data Analysis (EDA)

EDA is an **approach** to data analysis that involves inspecting data, often visually, **without preconceived assumptions** to understand its main characteristics. It's a crucial first step before formal modeling. The insights gained from EDA help select appropriate analysis techniques and inform the data engineering process.

### Descriptive Statistics

These methods quantitatively describe data features.

* **Measures of Central Tendency**: Represent the "center" of the data.
    * **Mean**: The average value. Sensitive to outliers.
    * **Median**: The middle value when data is sorted. More robust to outliers and skewed distributions.
* **Measures of Variability**: Represent the "spread" of the data.
    * **Standard Deviation ($\sigma$)**: The typical deviation of data points from the mean.
    * **Quartiles**: Divide the sorted data into four equal parts.
        * **Q1 (Lower Quartile)**: 25th percentile.
        * **Q2 (Median)**: 50th percentile.
        * **Q3 (Upper Quartile)**: 75th percentile.
        * **Interquartile Range (IQR)**: Q3 - Q1. Represents the spread of the middle 50% of the data.

### EDA Visualization Techniques

* **Dot Diagram**: Simple plot showing individual data points along a number line.
* **Stem-and-Leaf Plot**: Organizes numeric data to show distribution while retaining individual values. Good for small datasets.
* **Box Plot (Box-and-Whisker Plot)**: Visualizes the five-number summary: minimum, Q1, median (Q2), Q3, maximum. Whiskers typically extend to 1.5 * IQR from the box edges; points beyond the whiskers are flagged as potential outliers.
* **Histogram / Bar Chart**: Shows the frequency distribution of data. Histograms are for numeric data (grouped into bins), while bar charts are for categorical data. Bin size in histograms is important.
* **Scatter Plot**: Shows the relationship between two numeric variables. Helps visualize strength, shape (linear/curved), direction, and outliers in the relationship.
* **Scatter Plot Matrix**: Displays scatter plots for all pairs of variables in a dataset, arranged in a matrix. Useful for quickly spotting relationships between multiple variables.

### Standardization (Z-Scores)

* **Purpose**: To compare values from different distributions or attributes measured on different scales.
* **Calculation**: Transforms a value `x` into a **z-score**, representing how many standard deviations it is away from the mean ($\mu$).
    $$
    z = \frac{x - \mu}{\sigma}
    $$
* **Use**: Essential for algorithms sensitive to feature scales (like KNN) and helps in interpreting feature importance in models like linear regression.

EDA techniques, especially visualizations, provide the necessary understanding to effectively guide the data engineering process and build robust frontend assistance tools.
