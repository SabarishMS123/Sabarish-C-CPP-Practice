#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	  	int coef,power;
	  	struct node *next;
};
       struct node *p1,*head1,*head2,*p2,*new1,*new2;

 void createpoly1(){
 	    int ch=1;
 	    printf("\n1st poly:\n");
		head1=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the coefficient and power of the first variable:\n") 	;
		scanf("%d %d",&head1->coef,&head1->power);
		head1->next=0;
		p1=head1;
		while(ch==1){
			       new1=(struct node*)malloc(sizeof(struct node));
			       printf("\nEnter the Coefficient and power of next variable:\n");
				   scanf("%d %d",&new1->coef,&new1->power);
				   new1->next=0;
				   p1->next=new1;
				   p1=p1->next;
				   printf("\nDo you want to continue?\n");
				   scanf("%d",&ch);
			      }
       
	    }
void createpoly2(){
 	    int ch=1;
 	    printf("\n2nd poly:\n");
		head2=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the coefficient and power of the first variable:\n") 	;
		scanf("%d %d",&head2->coef,&head2->power);
		head2->next=0;
		p2=head2;
		while(ch==1){
			       new2=(struct node*)malloc(sizeof(struct node));
			       printf("\nEnter the Coefficient and power of next variable:\n");
				   scanf("%d %d",&new2->coef,&new2->power);
				   new2->next=0;
				   p2->next=new2;
				   p2=p2->next;
				   printf("\nDo you want to continue?\n");
				   scanf("%d",&ch);
			      }
       
	    }

void display1(){
	    p1=head1;
	    printf("\nThe polynomial is:\n");
     	while(p1!=0){
     	
			 
		         printf("%dX^%d\t",p1->coef,p1->power);
		         p1=p1->next;
		   
		    
		         if(p1!=0)
				 {
		            	printf("+");
			         	
				}
               
		
		
	}
	 printf("\n");
}

void display2(){
	    p2=head2;
	    printf("\nThe polynomial is:\n");
     	while(p2!=0){
     		
		         printf("%dX^%d\t",p2->coef,p2->power);
		         p2=p2->next;
		         if(p2!=0)
				 {
		            	printf("+");
			         	
				}
             
		
		
	}
	  printf("\n");
}


void poly(){
	
	p1=head1;
	p2=head2;
	while(p1!=0 && p2!=0)
	{
					if(p1->power == p2->power){
					   printf("%dX^%d", p1->coef+p2->coef,p1->power);
					   p1=p1->next;
					   p2=p2->next;
					
					}
					
					else if(p1->power >p2->power)
					{
						printf("%dX^%d",p1->coef,p1->power);
						p1=p1->next;
					}
					else 
					{
						printf("%dX^%d",p2->coef,p2->power);
						p2=p2->next;
					}
					
					if(p1!=0 || p2!=0)
					{
						printf("+\t");
					
		            }
		            while(p1!=0){
		            	printf("%dX^%d",p1->coef,p1->power);
						p1=p1->next;
						if(p1!=0){
							printf("\t+");
						}
										
			  }  
			  while(p2!=0){
		            	printf("%dX^%d",p2->coef,p2->power);
						p2=p2->next;
						if(p2!=0){
							printf("\t+");
						}
										
			}
			       
		
		}

}
	   
void main(){
	//clrscr();
	printf("\n----------------------POLYNOMIAL ADDITION------------------------------");
	createpoly1();
	display1();
	createpoly2();
	display2();
	poly();
	
}	   





	   
	   
	   
