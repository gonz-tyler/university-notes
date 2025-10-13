# Week04: Apache Airflow

---

## 1. What is Apache Airflow? 

**Apache Airflow** is an open-source platform used for orchestrating and managing data pipelines. It's a **batch-oriented framework** that allows you to programmatically author, schedule, and monitor workflows.

-   **Workflow Management**: It helps "glue together" various technologies and coordinate tasks across different systems.
-   **Python-Based**: Workflows are defined as Python scripts, which gives developers immense flexibility.
-   **Orchestration**: It manages the execution, scheduling, and dependencies of tasks within a data pipeline.

---

## 2. Data Pipelines as Directed Acyclic Graphs (DAGs)

A **data pipeline** is a set of tasks that are executed to process data. A simple example is a weather dashboard pipeline:
1.  **Fetch** weather data from an API.
2.  **Clean** and transform the data (e.g., convert Fahrenheit to Celsius).
3.  **Push** the transformed data to the dashboard.

In Airflow, these pipelines are represented as **Directed Acyclic Graphs (DAGs)**.

### What is a DAG?

A DAG is a graph with nodes and directed edges, with one crucial rule: it has **no cycles** or loops.

-   **Nodes**: Represent the **tasks** in your pipeline (e.g., "Fetch weather forecast").
-   **Directed Edges**: Represent the **dependencies** between tasks, defining the order of execution. An edge from Task 1 to Task 2 means Task 1 must complete successfully before Task 2 can begin.
-   **Acyclic**: The "no cycles" rule is critical. A cyclic graph would create an infinite loop where a task could never run because its dependencies could never be met.

!
### Advantages of DAGs over Sequential Scripts

While a simple pipeline could be a sequential script, using a DAG structure provides significant advantages, especially for complex workflows:

1.  **Parallelism**: Independent tasks can be run in parallel, significantly speeding up the overall pipeline. For example, fetching sales data and weather data can happen at the same time.
2.  **Modularity**: DAGs encourage breaking down a large process into small, incremental, and reusable tasks. This makes the pipeline easier to understand, maintain, and debug.
3.  **Failure Handling**: If a single task fails, Airflow makes it easy to retry just that task (and its downstream dependencies) without re-running the entire pipeline from the beginning.

---

## 3. The Airflow Architecture

Airflow consists of several main components that work together to run your data pipelines.

1.  **Scheduler**: This is the heart of Airflow. It periodically scans your DAG files, checks their `schedule_interval`, and if it's time for a DAG to run, it sends the tasks to the execution queue. It also checks task dependencies to ensure tasks run in the correct order.
2.  **Workers**: These are the processes that actually do the work. They pick up tasks from the queue and execute the Python code defined for that task.
3.  **Webserver**: This provides a user interface (UI) for monitoring and managing your pipelines. You can visualize your DAGs, check the status of runs, view logs, and manually trigger or retry tasks.
4.  **Metastore**: This is a database where Airflow stores the state of everything: DAG structures, task statuses (queued, running, success, failed), historical runs, and other metadata.

### The Execution Flow

1.  A user writes a data workflow as a Python script in a **DAG file**.
2.  The **Scheduler** reads the DAG file, understands its tasks and dependencies, and stores this information in the **Metastore**.
3.  When a DAG is scheduled to run, the Scheduler places the first tasks (those with no dependencies) into a **Queue**.
4.  A **Worker** picks up a task from the queue and executes it.
5.  Upon completion, the Worker updates the task's status in the Metastore.
6.  The Scheduler sees that the task is complete and queues the next set of tasks whose dependencies are now met.
7.  The user can monitor this entire process through the **Webserver UI**.

---

## 4. Key Features and Concepts

* **Python as Code**: Defining pipelines in Python allows for dynamic generation of tasks, complex logic, and integration with virtually any other system.
* **Scheduling**: Airflow has a rich scheduling system (using cron expressions or presets) to run pipelines at regular intervals (e.g., `@daily`, `@hourly`).
* **Incremental Loading**: By using the schedule interval, pipelines can be designed to process data incrementally, meaning each run only processes the data for its specific time window, avoiding expensive re-computation of the entire dataset.
* **Backfilling**: Airflow allows you to easily run a DAG for historical dates. This is incredibly useful for reprocessing data after fixing a bug or changing the logic in your pipeline.
* **Web UI**: The interface provides powerful tools for monitoring and debugging, including:
    -   **Graph View**: Shows the structure of your DAG and the status of tasks for a single run.
    -   **Tree View**: Shows the status of tasks across multiple historical runs.

---

## 5. When to Use (and Not Use) Airflow

### Reasons TO Choose Airflow

-   Your pipelines are **batch-oriented** and run on a regular schedule.
-   You need the **flexibility of Python** to create complex, dynamic workflows.
-   You need to **integrate with a wide variety of external systems** (databases, cloud services, etc.).
-   You need features like **backfilling** to reprocess historical data easily.
-   You want a rich **UI for monitoring and debugging**.

### Reasons NOT to Choose Airflow

-   You need to handle **streaming data**. Airflow is designed for batches, not real-time streams.
-   Your pipelines are **highly dynamic**, changing their structure on every run. While possible, the UI is not optimized for this.
-   Your team has **little or no Python programming experience**. A tool with a graphical interface might be a better fit.
