# Week01: Introduction to Data Engineering

## Notes
---


### Foundational Concepts: Data Engineering vs. Data Science

This summary introduces the core concepts of data engineering, its role in the broader data landscape, and its relationship with data science.

#### What is Data Engineering?

**Data engineering** is the practice of designing and building systems for collecting, storing, and processing data. The primary goal is to make large volumes of data usable for downstream applications, such as data analysis and machine learning. This process requires significant computational and storage resources.

A **data engineer** is a specialized software engineer responsible for creating and managing big data pipelines. They handle the flow of data through an organization, focusing on the production-readiness of data, including its format, resilience, scalability, and security. Typically, data engineers have a strong software engineering background, with proficiency in languages like Java, Python, and Scala, and are knowledgeable about databases, cloud computing, and agile development.

---

#### What is Data Science?

**Data science** is an interdisciplinary field that uses scientific methods, algorithms, and statistics to extract knowledge and insights from structured or unstructured data.

A **data scientist**, in contrast to a data engineer, is more focused on the *analysis* of data. They possess deep expertise in mathematics, statistics, algorithms, and machine learning.

---

#### The Relationship Between Engineering and Science

Data engineering is considered **upstream** from data science. Data engineers prepare the raw data, making it clean and accessible, while data scientists (the **downstream** users) extract knowledge from this prepared data.

This relationship is often visualized using the **Data Science Hierarchy of Needs**. This model shows that advanced applications like AI and machine learning (at the top) rely on a solid foundation of data collection, storage, and transformation (the bottom layers), which are the core responsibilities of data engineering.

In practice, data scientists often spend **70-80% of their time on data engineering tasks**—gathering, cleaning, and preprocessing data—and only 20-30% on actual analysis and model building. This highlights the critical, foundational role of data engineering.

---

### The Data Engineering Lifecycle

The data engineering lifecycle is a process that transforms raw data into a useful data product. It consists of five key components, often referred to as an **ETL (Extract, Transform, Load)** or **Ingestion-Transform-Serving** process.

1.  **Generation**: The origin of the data from various sources.
2.  **Ingestion/Extract**: Pulling data from its source systems.
3.  **Storage**: Persisting the data at various stages of the pipeline.
4.  **Transform**: Cleaning, structuring, and enriching the data.
5.  **Serving/Load**: Making the processed data available to end-users and systems.

---

#### 1. Generation: Understanding Data Sources

The first step is to understand the source systems where data is generated. Sources can include:
* **Transactional databases** from applications.
* **IoT devices** generating sensor data (e.g., smart home temperatures).
* **Messaging systems** like email or social media platforms.

Data engineers must understand the data's characteristics at its source, including its **frequency, volume, type (numeric, text), and structure (structured tables vs. unstructured text)**. They also need to understand the **schema**, which is the blueprint defining how the data is organized, its elements, and their relationships.

---

#### 2. Ingestion: Extracting the Data

Ingestion involves extracting data from its source. This can be one of the most challenging parts of the lifecycle because source systems are often outside the engineer's control and can be unresponsive, provide poor-quality data, or experience interruptions.

Key questions during ingestion include:
* What is the use case for this data?
* How often will it be accessed?
* What volume and format will it arrive in?

---

#### 3. Storage: Persisting the Data

Data needs to be stored at various points throughout the lifecycle. A data engineer must choose appropriate storage systems (e.g., data warehouses, databases) by considering:
* **Compatibility** with the data pipeline.
* **Read and write speeds**.
* **Scalability** to meet future demands.
* **Support for queries** and downstream tasks.
* **Security and regulatory compliance**.

---

#### 4. Transform: Preparing the Data

Transformation is the process of converting ingested data into the required format and structure for its final use case. This is a critical step driven by the needs of downstream tasks.

Common transformations include:
* Handling missing values.
* Normalizing data.
* Restructuring data to fit a new schema.

It's important to note that this is different from the preprocessing done for machine learning, which is a more specific type of feature engineering.

---

#### 5. Serving/Load: Delivering Value

The final stage is serving the transformed data to its consumers to generate value. The primary consumers are:

* **Machine Learning (ML)**: ML is a core technology in AI that extracts knowledge from data. Data engineers should be familiar with ML to better engineer data for model training and may even assist in the ML engineering process.
* **Analytics**: This involves generating reports, dashboards, and visualizations. Analytics can be:
    * **Business Intelligence (BI)**: Extracting key information to inform business strategy.
    * **Operational Analytics**: Consuming real-time data to take immediate action.
    * **Customer-Facing Analytics**: Providing data access to thousands of external customers, requiring high security and controlled access.
* **Reverse ETL**: This process takes processed data and feeds it *back into* source operational systems (e.g., a CRM), often to support real-time marketing and sales activities.

---

### The Role and Skills of a Data Engineer

A successful data engineer requires a blend of technical expertise and business acumen.

#### Technical Skills

* **Core Competencies**: Data management, architecture, security, and software engineering.
* **Programming Languages**: Proficiency in languages like Python, Java, SQL, and Bash.
* **Powerful Tools**: Knowledge of key data engineering tools, such as:
    * **Apache Kafka**: For real-time data ingestion and streaming.
    * **Apache Airflow**: For orchestrating and managing complex data workflows.
    * **TensorFlow Extended (TFX)** and **Scikit-learn**: For building ML pipelines.

#### Business Responsibilities

* **Communication**: Effectively communicating with both technical and non-technical stakeholders.
* **Requirements Gathering**: Understanding stakeholder needs and the business impact of data projects.
* **Agile Methodologies**: Applying principles from Agile, DevOps, and DataOps.
* **Cost Management**: Controlling costs while maximizing the value derived from data.
* **Continuous Learning**: Staying current in a rapidly evolving field.

In an organization, the data engineer acts as a central hub, collaborating with software engineers, database administrators, data scientists, ML developers, and business stakeholders.

---

### Data Engineering Pipeline Tools

A **data engineering pipeline** encapsulates all the steps required to process data from source to destination. These pipelines can be classified based on their primary function:

1.  **ETL Data Pipelines**: Tools focused on extracting, transforming, and loading data.
    * **Apache Spark**: An open-source engine for large-scale data processing.
    * **AWS Glue**: A serverless, managed ETL service on AWS.
2.  **Integration, Ingestion, and Transformation Pipelines**: Solutions for handling data from multiple, heterogeneous sources.
    * **Apache Kafka**: A distributed system for ingesting multiple data streams and enabling real-time transformations.
3.  **Pipeline Orchestration & Workflow Management**: Tools that automate, monitor, and manage end-to-end data workflows.
    * **Apache Airflow**: An open-source tool for programmatically authoring, scheduling, and monitoring workflows.
4.  **Machine Learning and Model Deployment Pipelines**: Frameworks for building automated ML models and integrating them with data pipelines.
    * **TensorFlow Extended (TFX)**: An end-to-end platform for deploying production ML pipelines.
    * **Scikit-learn Pipeline**: A library for creating chains of transformations and estimators for ML modelling.
