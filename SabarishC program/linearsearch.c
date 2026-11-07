#include<stdio.h>

void main(){
	
	int a[50],i,j,key,found=0,c,n;
	printf("\n----LINEAR SEARCH ----\n");
	printf("\n");
	printf("\n:Enter the number of elements you want:");
	scanf("%d",&n);
	
	for(i=0 ;i<n;i++)
	{
		   printf("\nElement[%d]",i+1);
		   scanf("%d",&a[i]);
    }
    
    printf("\nEnter the key value:");
    scanf("%d",&key);
    
    for(i=0;i<n;i++){
    	if(a[i]==key)
    	{
    		found++;
    		printf("\nElement found!!");
		}
	}
	
	 if(found==0)
		printf("\nElement not found!!");
	
	printf("\nDo you want to continue:\n[1]yes\n[0]No");
	scanf("%d",&c);
	if(c!=0)
	    exit(0);
	else
	   main();
	
}
