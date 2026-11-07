#include <stdio.h> 
int n,i,b,c,d,e,flag=0,k,j; 
void insert(int c,int a[]) 
{  
  printf("\nEnter the element"); 
           scanf("%d",&b); 
           for( i=n-1;i>=c-1;i--) 
               a[i+1]=a[i]; 
            a[c-1]=b;     
           printf("\nThe array is:   "); 
           for( j=0;j<n+1;j++) 
               printf("  %d",a[j]); 
            
} 
void del(int d,int a[]) 
{ 
  for(i=d-1;i<=n-1;i++) 
               a[i]=a[i+1];  
           printf("\nThe array is:   "); 
           for( j=0;j<n-1;j++) 
           printf("  %d",a[j]); 
            
} 
void search(int e,int a[]) 
{ 
  for( i=0;i<n;i++) 
               if(e==a[i]) 
               { 
                   k=i; 
                   flag=1;break; 
                    
                } 
            if( flag==0) 
               printf("\n Searched element NOT found."); 
               else 
            printf("The position is: %d",k+1); 
             
} 
void main() 
{ 
   int f,p,h,g; 
  printf("Enter the number of elements:");  
  scanf("%d",&n); 
  int a[50]; 
  printf("\nEnter the elements of array:"); 
  for(i=0;i<n;i++) 
  scanf("%d",&a[i]); 
  printf("Choose your operation:\n1.Insertion\n2.Deletion\n3.Search"); 
  printf("\nEnter your choice:"); 
  scanf("%d",&f); 
   
  switch(f) 
  { 
    case 1: printf("\n\nINSERTION"); 
           printf("\nEnter the position:"); 
           scanf("%d",&p); 
           if(p>n+1) 
           printf("Invalid position..."); 
           else 
           { 
             insert(p,a); 
           } 
           break; 
            
    case 2: printf("\n\nDELETION"); 
           printf("\nEnter the position:"); 
           scanf("%d",&g);      
           if(g>n) 
           printf("Invalid position..."); 
           else 
           { 
           del(g,a); 
           } 
           break; 
            
    case 3:printf("\nEnter the element:"); 
           scanf("%d",&h); 
           search(h,a);break; 
            
             
    default: printf("\n\n\tINVALID CHOICE!!!"); 
     
  }; 
   
   
}
