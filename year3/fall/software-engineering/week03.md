# Week 3: Team Collaboration

## Notes
---

### Git Basics
- Distributed Version Control System (DVCS):
  - Maintains a full clone of the repository locally, providing a backup and faster operations compared to server-based systems.
- Key Git Features:
  - Version Tracking: Tracks changes in files and maintains snapshots of the repository's state.
  - Branches: Enables experimentation without affecting the main branch (now referred to as "main").
  - Rolling Back Changes: Use reset or checkout for undoing commits or changes.

### Repository Management
- Single Repository Per Project: Each project gets its own Git repository.
- Commit Workflow:
  - Untracked/Unmodified/Modified/Staged: Tracks file states for effective commits.
  - Regularly push code to remote repositories to safeguard against local data loss.

### Collaborative Practices
- Use Issues (in GitHub) and tools like Trello for task tracking.
- Minimize overlapping work by clearly assigning tasks.
- Follow workflows:
  - Pull remote changes before starting.
  - Run tests locally to avoid breaking the build.
  - Push only after passing all tests.

### Code Reviews
- Use Pull Requests to review code before merging.
- Alternatives like pair programming and mob programming allow real-time collaborative reviews.

### Trunk-Based Development
- Short-lived branches (less than a day) reduce integration conflicts.
- Merge work into the main branch daily for shared visibility.

### DevOps Principles
- Everyone is Responsible: All team members handle development, deployment, and support.
- Automation:
  - Test, deploy, and support processes should be automated to reduce manual errors.
  - Infrastructure as Code (IaC): Use tools like Puppet or Chef for consistent environments.

### Benefits of DevOps
- Faster deployment cycles with reduced communication delays.
- Reduced risk via smaller, incremental releases.
- Faster issue resolution by eliminating inter-team bottlenecks.
- Improved team productivity and morale.

### Continuous Integration (CI)
- Automatically build and test the system with each commit.
- Immediate feedback for errors reduces debugging time.
- Avoid "breaking the build" by testing locally before pushing.

### Continuous Delivery (CD)
- Ensure code is always ready for production by testing in environments replicating production conditions.

### Continuous Deployment
- Automates deployment to production after passing tests.
- Benefits:
  - Faster customer feedback for iterative improvements.
  - Cost savings from automated pipelines.
  - Enables A/B testing for feature validation.

### Infrastructure as Code (IaC)
- Characteristics:
  - Visibility: Defined infrastructure models can be reviewed by all.
  - Reproducibility: Consistent environments through automation.
  - Reliability: Reduces errors caused by manual configuration.
  - Recovery: Easily revert to previous working configurations.
- Business Benefits:
  - Lower costs and risks by aligning test and production environments.

### Measuring and Improving DevOps
- Metrics to Track:
  - Deployment frequency.
  - Mean time to recovery (MTTR).
  - Change failure rate.
  - Customer satisfaction metrics.
  - Tools: Use logging, monitoring systems, and DORA metrics to benchmark performance.
