#include<stdio.h>

void dessort(int a[],int n ){
	int i,j,temp;
	printf("\n------\nDESENDING SORT\n-----\n");
	for(i=0 ;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]<a[j])
			{ 
			   temp=a[i];
			   a[i]=a[j];
			   a[j]=temp;
			}
		}
	}
	printf("\nDESENDING order:");
    display(a,n);
}


void ascsort(int a[],int n){
	int i,j,temp;
	printf("\n------\nASCENDING SORT\n-----\n");
	for(i=0 ;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j])
			{ 
			   temp=a[i];
			   a[i]=a[j];
			   a[j]=temp;
			}
		}
	}
	printf("\nASCENDING  order:");
	display(a,n);
}

void display(int a[],int n){
	int i;
	for(i=0;i<n;i++)
	   printf("%d",a[i]);

}

void main(){
	int i,j,n,a[50],c,op;
	
	
	while(c!=0){
		printf("\n------------BUBBLE SORT----------\n");
		printf("\nEnter the  number of elements you want:");
		scanf("%d",&n);
		for(i=0 ;i<n;i++){
		   printf("\nElement[%d]",i+1);
		   scanf("%d",&a[i]);
               	}
        
        printf("#MENU \n\t1.Ascending sort\n\t 2.Descending sort\n\t Enter your choice:"); scanf("%d",&op);
        switch(op){
        	case 1:
        		ascsort(a,n);
        		
        		break;
        	case 2:
        		dessort(a,n);
        	
        		
        		break;
		}
		printf("\n\t Do you want to continue \n\t [1]YES\n\t [0]NO\n\t Enter your choice:"); scanf("%d",&c);
		
	
    }
}





