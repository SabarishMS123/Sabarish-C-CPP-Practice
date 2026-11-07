
#include <stdio.h>

int main() {
    int n, time_slot, total = 0, x, counter = 0;
    int wait_time = 0, ta_time = 0;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);
    x = n;
    int arr_time[n], burst_time[n], temp_burst_time[n];
    int i; // Define i outside the loop

    for(i = 0; i < n; i++) {
        printf("Enter Details of Process %d \n", i + 1);
        printf("Arrival Time:  ");
        scanf("%d", &arr_time[i]);
        printf("Burst Time:   ");
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    printf("Enter Time Slot: ");
    scanf("%d", &time_slot);

    printf("Process ID       Burst Time       Turnaround Time      Waiting Time\n");

    for(total = 0, i = 0; x != 0; total++) {
        if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0) {
            total += temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        }
        else if(temp_burst_time[i] > 0) {
            temp_burst_time[i] -= time_slot;
            total += time_slot;
        }
        
        if(temp_burst_time[i] == 0 && counter == 1) {
            x--; 
            printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arr_time[i], total - arr_time[i] - burst_time[i]);
            wait_time += total - arr_time[i] - burst_time[i];
            ta_time += total - arr_time[i];
            counter = 0;
        }

        if(i == n - 1) {
            i = 0;
        }
        else if(arr_time[i + 1] <= total) {
            i++;
        }
        else {
            i = 0;
        }
    }

    float average_wait_time = wait_time * 1.0 / (n);
    float average_turnaround_time = ta_time * 1.0 / (n);
    printf("\nAverage Waiting Time: %f", average_wait_time);
    printf("\nAvg Turnaround Time: %f", average_turnaround_time);

    return 0;
}

/*
Process	Arrival Time	Burst Time	
P1		0					4  					 2       0
 P2		1					5					3       1       0
P3		2					2					0
P4		3					1					0
P5		4					6					4        2       0
P6		6					3					1        0

*/
