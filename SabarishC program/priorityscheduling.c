#include<stdio.h>
#define max 5
int main(){
	int i,j,n,t,p[max],bt[max],pr[max],wt[max],tat[max],tot_wt=0,tot_tat=0;
	float awt=0,atat=0;
	printf("\nEnter the number of process you wish to do:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process no");
		scanf("%d",&p[i]);
		printf("\nEnter the Burst time of the process :\n");
		scanf("%d",&bt[i]);
		printf("\nEnter the Priority of the process :\n");
		scanf("%d",&pr[i]);
		
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			if(pr[j]>pr[j+1])
			{
				t=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=t;
				
				t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
				
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				
				
				
				
			}
		}
	}


printf("\nProcess  \t   \t  BT \t\t\WTt\tTAT\n");
for(i=0;i<n;i++){
	wt[i]=0;
	tat[i]=0;
	for(j=0;j<i;j++){
		wt[j]=wt[i]+bt[j];
	}
	
	tat[i]=wt[i]+bt[i];
	tot_wt=tot_wt+wt[i];
	tot_tat=tot_tat+tat[i];
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
	
	
}
  printf("\nThe Average waiting time:")
	return 0;
}
