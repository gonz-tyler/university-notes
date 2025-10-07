# Week03: Data Quality Revision Notes

---

## 1. What is Data Quality? 🤔

**Data quality** refers to the state of data and is a measure of how well a dataset meets specific criteria. High-quality data is considered "**fit for its intended uses**" in operations, planning, and decision-making. It correctly represents the real-world construct to which it refers.

Good data quality allows organizations to trust their data, leading to better decision-making and business strategies.

### Key Data Quality Metrics 📊

There are several dimensions or metrics used to assess data quality:

1.  **Completeness**: This measures the amount of usable data and the percentage of missing values. High levels of missing data can lead to biased or misleading analysis.
2.  **Uniqueness**: This accounts for the amount of duplicate data. For example, each customer in a database should have a unique ID.
3.  **Validity**: This measures how well the data conforms to required formats and business rules, such as data types, ranges, or patterns.
4.  **Timeliness**: This refers to the readiness and availability of data within an expected timeframe. For example, an order confirmation number should be generated immediately after a purchase.
5.  **Accuracy**: This refers to the correctness of data values when compared to an agreed-upon "source of truth." For instance, a patient's recorded address should match their actual physical address.
6.  **Consistency**: This evaluates if data records from different datasets are free of contradiction. For example, if a person's address is updated in one system, it should be consistently updated across all related systems (e.g., patient records, bank statements).
7.  **Fitness for Purpose**: This ensures that the data meets the specific business need it was collected for. For example, to study the energy consumption of Scottish houses, surveying only Aberdeen homes might not be fit for purpose.

---

## 2. Common Data Quality Issues and Solutions

Poor data quality manifests in several common issues.

### Canonicalization, Standardization, or Normalization

This is the process of converting data into a standard, or "canonical," format.

* **Cell Entity Normalization**: Resolving different representations of the same entity. For example, ensuring that `U.K.`, `UK`, and `United Kingdom` are all treated as the same entity. This also applies to feature names with typos or different capitalization (e.g., `Country` vs. `County`).
* **Canonicalization of Features**: Enforcing a standard format for an entire feature/column, such as representing all dates as `YYYY-MM-DD`.
* **Canonicalization of Units**: Transforming numerical values and their units into a standard representation, such as converting all height measurements to metres.
* **Canonicalization of Column Names**: Standardizing feature names to a consistent format, such as changing `package_for_weighting` to `Package_for_Weighting`.

### Missing Data

Missing data is a common problem that needs to be detected, understood, and handled.

* **Detection**: Missing values can be represented in many ways, including `Null`, `NaN`, `NA`, blank spaces, or even special codes like `-99`.
* **Understanding the Missingness**:
    1.  **MCAR (Missing Completely At Random)**: The missingness is random and doesn't depend on any other data. Analysis on the remaining data is unbiased but may have less statistical power.
    2.  **MAR (Missing At Random)**: The missingness depends only on other *observed* values, not the missing values themselves. The missing information can potentially be predicted from other variables.
    3.  **MNAR (Missing Not At Random)**: The missingness is systematic and depends on the unobserved (missing) values themselves.
* **Repair**:
    * **Deletion**: Removing any rows with missing entries (known as "complete case analysis").
    * **Imputation**: Substituting missing entries with other values, such as the mean or mode of the column.

### Anomalies (Outliers)

Anomalies are patterns that do not conform to expected normal behaviour. They can be caused by measurement errors, handling errors, or malicious activity like fraud.

* **Detection**: Finding anomalies is challenging. Methods include:
    * **Supervised**: Using labeled data to train a classification model (e.g., normal vs. abnormal tissue).
    * **Unsupervised**: Using clustering methods when no labels are available.
* **Repair**: Once detected, anomalies can either be removed completely or repaired by inserting sensible values.

### Non-Stationarity

This issue occurs when the statistical properties of data change over time or across different contexts.

* **Time Series Data**: This is often called **change point detection**, where the data distribution changes after a specific point in time (e.g., river flow changing after dam construction).
* **Tabular Data**: This is often called **dataset shift**, where the distribution of training data is different from the test data. It can also happen if data collection protocols change over time (e.g., units or labels are changed).

### Data Duplication

This is when a piece of data is repeated within the same data infrastructure.

* **Exact Duplicates**: Records where all fields and values are identical copies.
* **Near Duplicates**: Records that are highly similar but not identical, often due to different spellings or formatting (e.g., `John Smith` vs. `J. Smith`).
* **Integration Duplicates**: Duplicates that are introduced when combining data from different sources.
* **Transformation Duplicates**: Duplicates created when one record is a transformed version of another (e.g., a record with height in `cm` and another with the same height in `m`).
