#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* link;
};

void main()
{
    struct node* newnode,* head,* temp,* tra;
    int choice;
   head=0;
   do
    {
    newnode=malloc(sizeof(*newnode));
    printf("enter the data:");
    scanf("%d",&(newnode->data));
    newnode->link=0;
    if(head==NULL)
    temp=head=newnode;
    else
    {
        temp->link=newnode;
        temp=newnode;
    }
    printf("enter 0 or 1 if you want to store more values:");
    scanf("%d",&choice);
    
    }while(choice);
    temp  =head;
    printf("elements linked list is:  ");
    while(temp!=0){
    printf("%d\t",temp->data);
    temp=temp->link;
    } 
    

}