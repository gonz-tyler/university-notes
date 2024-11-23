#include <stdio.h>

// Structure to store process information
typedef struct {
    int id;               // Process ID
    int arrival_time;     // Time at which process arrives
    int burst_time;       // CPU burst time required
    int completion_time;  // Time at which process finishes execution
    int turnaround_time;  // Turnaround time (completion - arrival)
    int waiting_time;     // Waiting time (turnaround - burst)
} Process;

void fcfs(Process processes[], int n) {
    int current_time = 0; // Tracks the current time in simulation

    for (int i = 0; i < n; i++) {
        // If the CPU is idle and the next process hasn't arrived, jump time forward
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        // Compute the completion time of the current process
        processes[i].completion_time = current_time + processes[i].burst_time;
        
        // Update current time to reflect process completion
        current_time = processes[i].completion_time;

        // Turnaround Time = Completion Time - Arrival Time
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;

        // Waiting Time = Turnaround Time - Burst Time
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

// Print process details in tabular format
void print_fcfs(Process processes[], int n) {
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time,
               processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    // Array of processes with arrival and burst times
    Process processes[] = {
        {1, 0, 5}, {2, 1, 3}, {3, 2, 8}, {4, 3, 6}
    };
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes

    // Run FCFS scheduling
    fcfs(processes, n);

    // Print the results
    print_fcfs(processes, n);

    return 0;
}
