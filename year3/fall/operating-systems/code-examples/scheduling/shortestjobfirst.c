#include <stdio.h>
#include <stdbool.h> // For boolean values

// Structure to store process information
typedef struct {
    int id;               // Process ID
    int arrival_time;     // Time at which process arrives
    int burst_time;       // CPU burst time required
    int completion_time;  // Time at which process finishes execution
    int turnaround_time;  // Turnaround time (completion - arrival)
    int waiting_time;     // Waiting time (turnaround - burst)
    bool is_completed;    // Whether the process has finished execution
} Process;

void sjf(Process processes[], int n) {
    int current_time = 0; // Tracks current time in the simulation
    int completed = 0;    // Number of processes completed

    while (completed < n) {
        int idx = -1;        // Index of the process to execute
        int min_burst = 1e9; // Initialize to a very high value (simulate infinity)

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].is_completed && processes[i].arrival_time <= current_time) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    idx = i;
                }
            }
        }

        // If no process is ready, advance time
        if (idx == -1) {
            current_time++;
            continue;
        }

        // Update process attributes
        processes[idx].completion_time = current_time + processes[idx].burst_time;
        processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
        processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;

        current_time = processes[idx].completion_time; // Update current time
        processes[idx].is_completed = true;           // Mark the process as completed
        completed++;                                  // Increment the count of completed processes
    }
}

// Print process details in tabular format
void print_sjf(Process processes[], int n) {
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
        {1, 0, 6, 0, 0, 0, false}, {2, 1, 8, 0, 0, 0, false}, 
        {3, 2, 7, 0, 0, 0, false}, {4, 3, 3, 0, 0, 0, false}
    };
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes

    // Run SJF scheduling
    sjf(processes, n);

    // Print the results
    print_sjf(processes, n);

    return 0;
}
