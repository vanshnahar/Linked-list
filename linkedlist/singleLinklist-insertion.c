#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node* createlinkedlist(){
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data=3;

/* Connect nodes */
one->next = two;
two->next = three;
three->next = NULL;

/* Save address of first node in head */
head = one;
return head;
}
struct node* insertb(struct node* new)
{
    
    struct node* newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter the value in linked list:");
    scanf("%d",&newnode->data);
    newnode->next=new;
    new=newnode;
    return new;
}
struct node* insertend(struct node* new)
{
    int item ;
    struct node* newnode,* temp;
    newnode=malloc(sizeof(struct node));
    temp=new;
    while(temp->next!=0)
    temp=temp->next;

    printf("Enter the value in linked list:");
    scanf("%d",&newnode->data);
    temp->next=newnode;
    newnode->next=0;
    return new;
}
struct node* insertatp(struct node* new,int n)
{
    
    struct node* newnode,* temp;
    newnode=malloc(sizeof(struct node));
    temp=new;
    for(int i=1;i<n-1;i++)
    temp=temp->next;

    printf("Enter the value in linked list:");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next= newnode;
    return new;
}
void display(struct node* new){
    int i=1;
     struct node* temp;
     temp=new;
    while(temp)
     {
     printf("\ndata in linked list%d:%d",i,temp->data);
     temp=temp->next;
     i++;
     }
}
void main ()
{
    int s,i;
    struct node* head=0 ;
    head=createlinkedlist();
    printf("1:insertion in begin \n 2:insertion at end\n 3:insertion in between linked list\n 4:display linked list \n5: exit");
   
    while(1)
    {
         printf("\nenter your choice:");
    scanf("%d",&s);
        switch(s)
        {
        case 1:head=insertb(head);
               break;
        case 2:head=insertend(head);
               break;
        case 3:printf("enter the position you want to insert:");
               scanf("%d",&i);
               head=insertatp(head,i);
               break;
        case 4:display(head);
               break;
        case 5:exit(0);              
        }
    

    }
}
