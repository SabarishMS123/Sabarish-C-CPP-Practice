#include<stdio.h>

struct process {

	int at;
	int bt;
};

int main(){
	int i,n,tot_wt,tot_tat;
	printf("---FIRST COME FIRST SERVE CPU SCHEDULING ALGORITHM---\n");
	printf("\nEnter number of processes:");
	scanf("%d",&n);
	
	int wait[n],turn[n],proc[n];
	struct process p[n];
	
	for(i=0 ;i<n;i++)
	 {
	 	 printf("\nEnter the arrival time and burst time of the P%d:",i+1);
	 	 scanf("%d %d",&p[i].at,&p[i].bt);
	 }
	 
	 for(i=0;i<n;i++){
	 	  wait[i]=(wait[i-1]+p[i-1].bt)-p[i].at;
	 	  
	 }
	 for(i=0;i<n;i++){
	 	  turn[i]=wait[i]+p[i].bt;
	 	   tot_wt+=wait[i];
	 	   tot_tat+=turn[i];
	 }
	 float a_tot_wt=tot_wt/n;
	 float a_tot_tat=tot_tat/n;
	 printf("\nProcess\t\tArrival Time \t\tBurst Time \t\tWaiting Time \t\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", i+1, p[i].at, p[i].bt, wait[i], turn[i]);
    }
	 
	 printf("%2f %2f",a_tot_wt,a_tot_tat);
	 return 0;
}
