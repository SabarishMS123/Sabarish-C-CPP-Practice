#include <stdio.h>


struct Process {
    int pid;       
    int burst;    
    int priority;  
    int wait;      
    int turn;      
};


void sortPriority(struct Process proc[], int n) {
    struct Process temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (i = 0; i < n; i++) 
	{
        proc[i].pid = i + 1;
        printf("Enter priority and burst time for process %d: ", proc[i].pid);
        scanf("%d %d", &proc[i].priority, &proc[i].burst);
    }

    sortPriority(proc, n);

    proc[0].wait = 0; // First process doesn't wait
    for (i = 1; i < n; i++) 
	{
        proc[i].wait = proc[i - 1].wait + proc[i - 1].burst;
    }

    float total_wait = 0, total_turn = 0;
    for (i = 0; i < n; i++) 
	{
        proc[i].turn = proc[i].wait + proc[i].burst;
        total_wait += proc[i].wait;
        total_turn += proc[i].turn;
    }

    // Calculate average waiting time and turnaround time
    float avg_wait = total_wait / n;
    float avg_turn = total_turn / n;

    // Display the results
    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) 
	{
        printf("P%d\t%d\t%d\t\t%d\t%d\n", proc[i].pid, proc[i].burst, proc[i].priority, proc[i].wait, proc[i].turn);
    }

    // Display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", avg_wait);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turn);

    return 0;
}

