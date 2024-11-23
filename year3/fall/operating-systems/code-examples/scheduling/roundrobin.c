#include <stdio.h>
#include <stdbool.h>

// Structure to store process information
typedef struct {
    int id;               // Process ID
    int arrival_time;     // Time at which process arrives
    int burst_time;       // Total burst time required
    int remaining_time;   // Remaining burst time (used for preemption)
    int completion_time;  // Time at which process finishes execution
    int turnaround_time;  // Turnaround time (completion - arrival)
    int waiting_time;     // Waiting time (turnaround - burst)
} Process;

void round_robin(Process processes[], int n, int quantum) {
    int current_time = 0; // Tracks current time in the simulation
    int completed = 0;    // Number of processes completed

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                if (processes[i].remaining_time > quantum) {
                    // Process executes for the quantum
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    // Process finishes within this time slice
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;

                    // Update completion time and other attributes
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed++;
                }
            }
        }
    }
}

// Print process details in tabular format
void print_round_robin(Process processes[], int n) {
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
        {1, 0, 6, 6, 0, 0, 0}, {2, 1, 8, 8, 0, 0, 0}, 
        {3, 2, 7, 7, 0, 0, 0}, {4, 3, 3, 3, 0, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes
    int quantum = 4;                                  // Time quantum for Round Robin

    // Run Round Robin scheduling
    round_robin(processes, n, quantum);

    // Print the results
    print_round_robin(processes, n);

    return 0;
}
