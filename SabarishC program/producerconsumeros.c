#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0,i=1;
int wait(int s)
{
	return(--s);
 }
int signal(int s)
{
   return(++s);
  }
void producer()
{
  mutex=wait(mutex);
  full=signal(full);
  empty=wait(empty);
  x++;
  printf("\nproducer produces the item %d",x);
  
	mutex=signal(mutex);
	consumer();
}
void consumer()
{	
	mutex= wait(mutex);
	while(i<=x)
	{
		printf("\n consumer consumes item %d",i);
		i++;
		full=wait(full);
		empty=signal(empty);
	}
	
	mutex=signal(mutex);
}
void main()
{	
	 
int n;
printf("\n1.producer\n2.consumer\n3.exit\n");
while(1)
{
	printf("\n your choice:\n");
	scanf("%d",&n);
	switch(n)
	{
		  case 1:
		  	if((mutex==1)&&(empty!=0))
		  	 	producer();
		  	 	else
		  	 	printf("buffer is full!!");
		  	 	break;
		  	case 2:
		  		if((mutex==1)&&(full!=0))
		  		consumer();
		  		else
		  		printf("buffer is empty!!");
		  		break;
		  	case 3:
		  		exit(0);
		  		break;
	}
  }
}
