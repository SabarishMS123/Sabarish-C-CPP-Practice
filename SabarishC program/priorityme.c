#include<stdio.h>

struct process{
	int priority;
	int burst;
	int turn;
	int wait;
};

void sortBypriority(struct process proc[],int n)
{
	int i,j;
	struct process temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			  if(proc[i].priority>proc[j].priority){
			  	temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
			  }
		}
	}
}

void  main(){
	 int i,j,n;
	 float tot_turn=0,tot_wait=0;
	printf("\n------------------\nPRIORITY SCHEDULING\n-------------------\n");
	printf("\n*****************************************************************\n");
	printf("\nEnter the number of Process:");
	scanf("%d",&n);
	
	struct process proc[n];
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter the Priority and the burst time of the process[%d]:",i+1);
		scanf("%d %d",&proc[i].priority,&proc[i].burst);
		
	}
	sortBypriority(proc,n);
	
	//wait[0]=0;
	//Calculate waiting time
	proc[0].wait=0;
	for(i=1;i<n;i++)
	{
		    proc[i].wait=proc[i-1].wait+proc[i-1].burst;
		    
		  
	}
	for(i=0;i<n;i++)
	{
		proc[i].turn=proc[i].wait+proc[i].burst;
		tot_turn+=proc[i].turn;
		tot_wait+=proc[i].wait;
	}
	
	printf("\n*********************************REPORT*******************************\n");
	printf("\nPROCESS \t PRIORITY \tBURST TIME \t TAT\t WT\n");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",i+1,proc[i].priority,proc[i].burst,proc[i].turn,proc[i].wait);
	}
	float average_tot_turn=tot_turn/n;
	float average_tot_wait=tot_wait/n;
	printf("\n");
	for(i=0;i<100;i++)
	  printf("*");
	printf("\n");
	printf("\nATAT=%2fms",average_tot_turn);
	printf("\nAWT=%2fms",average_tot_wait);
	getch();
	
}
