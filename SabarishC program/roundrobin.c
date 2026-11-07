#include <stdio.h>

// Define a process structure
struct Process {
    int pid;       // Process ID
    int burst;     // Burst time
    int remaining; // Remaining time
    int wait;      // Waiting time
    int turn;      // Turnaround time
};

int main() {
    int n, i, quantum, time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);


    struct Process proc[n];
    for (i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for process %d: ", proc[i].pid);
        scanf("%d", &proc[i].burst);
        proc[i].remaining = proc[i].burst; // Initialize remaining time
        proc[i].wait = 0; // Initialize waiting time
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int done;
    do {
        done = 1; // Assume all processes are done

        for (i = 0; i < n; i++) {
            if (proc[i].remaining > 0) {
                done = 0; // At least one process is not done

                if (proc[i].remaining > quantum) {
                    time += quantum;
                    proc[i].remaining -= quantum;
                } else {
                    time += proc[i].remaining;
                    proc[i].wait = time - proc[i].burst;
                    proc[i].remaining = 0;
                }
            }
        }
    } while (!done);

    float total_wait = 0, total_turn = 0;
    for (i = 0; i < n; i++) {
        proc[i].turn = proc[i].burst + proc[i].wait;
        total_wait += proc[i].wait;
        total_turn += proc[i].turn;
    }

    // Calculate average waiting time and turnaround time
    float avg_wait = total_wait / n;
    float avg_turn = total_turn / n;

    // Display the results
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].burst, proc[i].wait, proc[i].turn);
    }

    // Display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", avg_wait);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turn);

    return 0;
}


