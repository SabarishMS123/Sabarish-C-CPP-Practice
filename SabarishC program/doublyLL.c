#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *prev;
  struct node *next;
};

struct node *head,*tail;

void create(){
    printf("\n---------------------------DOUBLY  LINKED LIST OPERATION BOX-----------------------------------------------\n");
    struct node *newnode;
    int i,n;
    printf("\nEnter the no of nodes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data:");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
            head = tail = newnode;
        else {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
}

void display(){
    struct node *temp;
    temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void inatbeg(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert at beginning:");
    scanf("%d",&newnode->data);
    head->prev=newnode;
    newnode->next=head;
    newnode->prev=0;
    head=newnode;
}

void inatend(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert at end:");
    scanf("%d",&newnode->data);
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=0;
    tail=newnode;
}

void inatpos(){
    struct node *newnode,*temp;
    int pos,i=1;
    printf("\nEnter position:");
    scanf("%d",&pos);
    temp = head;
    while(i < pos-1){
        temp=temp->next;
        i++;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert at position:");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next != 0){
        temp->next->prev=newnode;
    }
    temp->next=newnode;
}

void delbeg(){
    struct node *temp;
    if(head==0){
        printf("\nList is empty!!!!!");
    } else {
        temp=head;
        head=head->next;
        if(head != 0) {
            head->prev=0;
        }
        free(temp);
        temp=0;
    }
}

void delend(){
    struct node *temp;
    temp=tail;
    tail=tail->prev;
    if(tail != 0) {
        tail->next=0;
    }
    free(temp);
    temp=0;
}

void delpos(){
    struct node *temp;
    int pos,i=1;
    printf("\nEnter position:");
    scanf("%d",&pos);
    temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    if(temp->next != 0){
        temp->next->prev=temp->prev;
    }
    free(temp);
}

void main(){
    int choice=1,opt;
    create();
    while(choice!=0){
        printf("\n--------------MENU CARD------\n");
        printf("\n1.Insertion at Beginning \n2.Insertion at End\n3.Insertion at Middle\n4.Deletion at Beginning\n5.Deletion at Middle\n6.Deletion at End\n");
        scanf("%d",&opt);
        switch(opt){
            case 1: inatbeg(); display(); printf("\n*********************************************************************************************\n"); break;
            case 2: inatend(); display(); printf("\n*********************************************************************************************\n"); break;
            case 3: inatpos(); display(); printf("\n*********************************************************************************************\n"); break;
            case 4: delbeg(); display(); printf("\n*********************************************************************************************\n"); break;
            case 5: delpos(); display(); printf("\n*********************************************************************************************\n"); break;
            case 6: delend(); display(); printf("\n*********************************************************************************************\n"); break;
            default: printf("\n---------Wrong choice---\n");
        }
        printf("\nIf you wish to continue press 1 or press 0 to exit from this Linked List operation:\n");
        scanf("%d",&choice);
    }
}

