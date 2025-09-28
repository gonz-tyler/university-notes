# Week 2: Data Organization Revision Notes

Data organization is the foundational task for any data scientist, involving a series of steps to prepare raw data for analysis. This process can be broken down into four main stages: Data Parsing, creating a Data Dictionary, Data Integration, and Data Transformation.

---

## 1. Data Parsing

**Data parsing** is the initial process of identifying the structure within a raw data source so that it can be correctly read and loaded for processing. The tools and methods used depend heavily on the data's format.

### Data Formats

Data sources can be broadly classified into three categories:

* **Structured Data**: Highly organized data, typically in a tabular format. This includes flat files like CSV, Excel, and TXT, as well as databases like SQL.
* **Semi-structured Data**: Data that doesn't fit into a formal database structure but contains tags or markers to separate semantic elements. Common examples are XML and JSON files.
* **Unstructured Data**: Data with no predefined model or organization. This includes text documents, log files, social media content, images, and real-time data streams from sensors.

### Parsing Challenges

Even with structured data, parsing can present challenges:

* **Proprietary Software**: Some file formats can only be read using specific, non-open-source software.
* **Ambiguous CSVs**: CSV files can be tricky. They allow for a wide variety of delimiters (e.g., comma, semicolon), quote characters, and escape characters, which must be correctly identified. A common issue is when a data field, like an address, contains the same character used as the delimiter.
    * **Solutions**:
        1.  Use a different, less common delimiter (like a semicolon or pipe `|`).
        2.  Wrap the problematic data fields in quotes.

### Parsing XML and JSON

* **XML (eXtensible Markup Language)**: In Python, there are three primary models for parsing XML files:
    1.  **DOM (Document Object Model)**: Easy to use but can consume significant memory and time, making it suitable for smaller files.
    2.  **SAX (Simple API for XML)**: Uses less memory than DOM and can handle arbitrarily large files, making it great for single-pass processing. However, it's more difficult to use.
    3.  **StAX (Streaming API for XML)**: Built on SAX, it offers more control over the parsing process and better state management.

* **JSON (JavaScript Object Notation)**: A lightweight, text-based format that uses a dictionary-like structure of **key-value pairs**. The key is a string, and the value can be a string, number, boolean, array, or another object. Python's `json` package is typically used to load and parse these files.

---

## 2. Data Dictionary (Metadata)

A **data dictionary**, or **metadata**, involves understanding the contents of a dataset and defining information about the meaning and type of each attribute. This information is crucial for analysis and is often provided by data collectors or domain experts in documents or file headers. However, this metadata can sometimes be missing or out-of-date.

The process involves three levels of understanding:

1.  **Table Understanding**: Getting a high-level overview of the dataset. This includes finding out how many tables, features, and records exist, and whether the data is relational or time-series.
2.  **Feature Understanding**: A crucial step where data scientists must understand the meaning of each feature (column) before analysis. If feature names are missing or unclear, a domain expert may be needed.
3.  **Value Understanding**: Analyzing the actual data within each feature. This involves determining if the data is categorical, numerical, or text, and identifying any outliers or anomalies (values outside the expected range).

---

## 3. Data Integration

**Data integration** is the process of combining related information from multiple sources into a single, unified data structure. This is often necessary when data is collected in installments or when different pieces of information (e.g., patient demographics and medical tests) are stored in separate tables.

### Methods of Integration

* **Joining (Record Linkage)**: This involves identifying records across multiple tables that correspond to the **same entity** and combining them to add new features (columns). For example, using a `patient_id` to join demographic and medical test tables. Difficulties arise if primary keys are missing or change across tables.
* **Unioning**: This refers to aggregating tables that contain **different entities** but the same type of information. The tables are stacked on top of each other to add new records (rows). Obstacles include tables having different structures, feature names changing, or columns being in different orders.
* **Heterogeneous Integration**: A more complex task of aggregating data from varied sources, such as relational tables, websites, and different physical locations, into a single format.

---

## 4. Data Transformation

**Data transformation** involves manipulating the data to change its "shape" or structure to meet the requirements of analytical models. Often, the goal is to create a standard **N x D table**, where N is the number of records and D is the number of features.

### Types of Transformation

* **Table Transformation**: This includes any manipulation that changes the shape of the data table, such as removing irrelevant rows or features. For instance, one might remove records where the year of observation was not recorded.
* **Information Extraction**: This refers to extracting structured data from unstructured or semi-structured sources. A key example is from Natural Language Processing (NLP), where **Named Entity Recognition (NER)** is used to identify and extract names of people and places from raw text to create a structured table.
