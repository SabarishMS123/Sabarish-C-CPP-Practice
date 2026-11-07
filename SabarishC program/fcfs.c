#include <stdio.h>

// Define a process structure
struct Process {
    int pid;      // Process ID
    int arrival;  // Arrival time
    int burst;    // Burst time
};

int main() {
    int n, i;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
     int wait[n], turn[n]; // Wait and Turnaround times
    float total_wait = 0, total_turn = 0; // Total wait and turnaround times
    wait[0] = 0; // First process doesn't wait

    struct Process proc[n];
    for (i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", proc[i].pid);
        scanf("%d%d", &proc[i].arrival, &proc[i].burst);
    }

 /*   int wait[n], turn[n]; // Wait and Turnaround times
    float total_wait = 0, total_turn = 0; // Total wait and turnaround times
    wait[0] = 0; // First process doesn't wait */

    // Calculate waiting and turnaround times
    for (i = 1; i < n; i++) {
        wait[i] = (wait[i - 1] + proc[i - 1].burst) - proc[i].arrival;
        if (wait[i] < 0) 
		     wait[i] = 0; // Wait time can't be negative
    }

    for (i = 0; i < n; i++) {
        turn[i] = wait[i] + proc[i].burst;
        total_wait += wait[i];
        total_turn += turn[i];
    }

    // Calculate average waiting time and turnaround time
    float avg_wait = total_wait / n;
    float avg_turn = total_turn / n;

    // Display the results
    printf("\nProcess\t\tArrival Time \t\tBurst Time \t\tWaiting Time \t\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst, wait[i], turn[i]);
    }

    // Display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f s", avg_wait);
    printf("\nAverage Turnaround Time: %.2f s\n", avg_turn);

    return 0;
}

