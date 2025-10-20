# Week 05: Apache Airflow in Practice

---

## Building a Data Pipeline: A Practical Example

This lecture demonstrates how to build a real data pipeline using Airflow.

* **The Goal**: Create a workflow that fetches data about upcoming rocket launches, downloads the associated images, and notifies us of the result.
* **The Data Source**: The Launch Library 2 API, which provides free JSON data on rocket launches.
* **The ETL Process (Extract, Transform, Load)**:
    1.  **Extract**: Download the JSON data from the API.
    2.  **Transform**: Parse the JSON to find the URLs of the rocket images and download them.
    3.  **Load**: Save the images to a local directory and send a notification about how many were downloaded.

This entire process can be mapped to an Airflow **DAG (Directed Acyclic Graph)** with three main tasks: `download_launches`, `get_pictures`, and `notify`.

---

## Anatomy of an Airflow DAG File

An Airflow DAG is defined in a Python script. Let's break down the code for our rocket launch pipeline.

### Step 1: Imports

First, we import the necessary libraries, including `DAG` and the specific **Operators** we'll need.

```python
import json
import pathlib
import airflow
import requests
from airflow import DAG
from airflow.operators.bash import BashOperator
from airflow.operators.python import PythonOperator
```

### Step 2: Instantiate the DAG
Every workflow starts by creating a DAG object. All tasks will be associated with this object.

```python
dag = DAG(
    dag_id="rocket_launch",
    start_date=airflow.utils.dates.days_ago(14),
    schedule_interval=None,
)
```

- `dag_id`: A unique identifier for the DAG.

- `start_date`: The date from which the DAG can start running.

- `schedule_interval`: How often the DAG should run automatically. Setting it to None means the DAG will only run when triggered manually.

### Step 3: Define the Tasks with Operators
Tasks are instances of Operators. An operator defines a single unit of work.

- Task 1: Download Launches (BashOperator) The BashOperator is used to execute a shell command. Here, we use curl to download the JSON data.

```python
download_launches = BashOperator(
    task_id="download_launches",
    bash_command="curl -o /path/to/launches.json -L '[https://ll.thespacedevs.com/2.0.0/launch/upcoming/](https://ll.thespacedevs.com/2.0.0/launch/upcoming/)'",
    dag=dag,
)
```

- Task 2: Get Pictures (PythonOperator) The PythonOperator is used to execute a Python function. We first define the function that will parse the JSON and download the images.

```python
def _get_pictures():
    # Ensure image directory exists
    pathlib.Path("/path/to/images").mkdir(parents=True, exist_ok=True)

    # Read the JSON file and download images
    with open("/path/to/launches.json") as f:
        launches = json.load(f)
        image_urls = [launch["image"] for launch in launches["results"]]
        for url in image_urls:
            response = requests.get(url)
            # ... save the image content to a file ...

get_pictures = PythonOperator(
    task_id="get_pictures",
    python_callable=_get_pictures,
    dag=dag,
)
```
- Task 3: Notify (BashOperator) Another BashOperator is used to count the downloaded images and print a message.

```python

notify = BashOperator(
    task_id="notify",
    bash_command='echo "There are now $(ls /path/to/images/ | wc -l) images."',
    dag=dag,
)
```
- Step 4: Set Task Dependencies
Finally, we define the order of execution using the bitshift operators (>> for downstream, << for upstream).

```python
download_launches >> get_pictures >> notify
```

This simple line creates a linear dependency: download_launches must complete successfully before get_pictures can run, which in turn must complete before notify can run.

## Running Airflow and Handling Failures
- Running Airflow: A common way to run Airflow locally is with Docker, which provides an isolated and pre-configured environment. You can start all the necessary services (scheduler, worker, webserver) with a docker-compose.yaml file and the docker-compose up command.
- The Airflow UI: Once running, the UI is accessible (usually at http://localhost:8080). It allows you to see all your DAGs, trigger them manually, and monitor their progress.
- Handling Failures: When a task fails, its status in the UI will turn red. To debug, you can inspect the log files for that specific task run. The logs provide detailed information, including stack traces for Python errors or output from Bash commands, helping you diagnose and fix the issue.

## Advanced DAG Patterns
- Airflow's dependency management allows for more complex workflows than just a simple linear chain.

Fan-in / Fan-out Dependencies
Fan-out: One task triggers multiple downstream tasks that can run in parallel.

```python
# 'start' triggers both fetching tasks at the same time
start >> [fetch_weather, fetch_sales]
```
Fan-in: A task that only runs after multiple upstream tasks have all completed.
```python
# 'join_datasets' only runs after both cleaning tasks are done
[clean_weather, clean_sales] >> join_datasets
```
### Branching
You can create conditional paths in your DAG using the BranchPythonOperator.

1. Define the Branching Task: The BranchPythonOperator executes a Python function that must return the task_id of the next task to run. All other downstream paths will be skipped.

```python
def _pick_erp_system(**context):
    if context["execution_date"] < ERP_SWITCH_DATE:
        return "fetch_sales_old"
    else:
        return "fetch_sales_new"
pick_erp = BranchPythonOperator(
    task_id="pick_erp_system",
    python_callable=_pick_erp_system,
)
```
2. The Joining Problem: A task downstream from the branches (e.g., join_datasets) will not run by default, because it expects all its parent tasks to succeed. Since branching skips one path, this condition is never met.

3. The Solution (trigger_rule): To fix this, you set the trigger_rule on the joining task. The default rule is all_success. For joining branches, you use none_failed. This rule means the task will run as long as all its parents have either succeeded or been skipped.

```python
join_datasets = PythonOperator(
    task_id="join_datasets",
    python_callable=_join_datasets,
    trigger_rule="none_failed",
)
```
