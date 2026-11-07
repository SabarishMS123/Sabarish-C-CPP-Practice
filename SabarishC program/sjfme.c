#include<stdio.h>

struct process{
	int burst;
	int wait;
	int turn;
	
};


sortburst(struct process p[] , int n)
{
	struct process temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].burst > p[j].burst) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}


int main(){
	 int i,n,tot_tat=0,tot_wt=0;
	 printf("\nEnter number of process:");
	 scanf("%d",&n);
	 struct process p[n];
	 printf("Enter the Burst time of each process:");
	 for(i=0; i<n ;i++){
	 	   printf("\nEnter the Burst time of P%d: \t",i+1);
	 	   scanf("%d",&p[i].burst);
	 }
	 sortburst(p,n);
	 
	 //calculating the waiting time
	 p[0].wait=0;
	 for(i=1; i<n; i++){
	 	  p[i].wait=p[i-1].wait+p[i-1].burst;
	 	}
	 //calculating TAT
	 
	 for(i=0 ;i<n;i++){
	 	   p[i].turn=p[i].wait+p[i].burst;
	 	   tot_tat+=p[i].turn;
	 	   tot_wt+=p[i].wait;
	 	 
	 }
	 
	 float a_tot_tat=tot_tat/n;
	 float a_tot_wt=tot_wt/n;
	 printf("%2f %2f",a_tot_tat,a_tot_wt);
	
	 
	 
}
