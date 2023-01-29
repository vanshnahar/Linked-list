#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* prev;
  struct node *next;
};
struct node* head=0 ;
void createdd()
{
   struct node* temp,* newnode;
   temp=head;
   int ch;
   do{ 
   newnode=malloc(sizeof(struct node));
   printf("enter the data");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   if (head=0){
    temp=head=newnode;
   }
   else{
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
   }
   printf("you want to insert more element : ");
   scanf("%d",ch);
}while(ch);
}
void insertb(){
    struct node* newnode;
    newnode=malloc(sizeof(struct node));
   printf("enter the data");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   if(head==0){
    head=newnode;
   }
   else{
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
   }
}
void insertend(){
    struct node* newnode,* temp;
    temp=head;
    newnode=malloc(sizeof(struct node));
   printf("enter the data");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   while (temp->next!=0)
   {
    temp=temp->next;

   }
   
   if(head==0){
    head=newnode;
   }
   else{
    temp->next=newnode;
    newnode->prev=temp;

}
}
int length(){
    int count=0;
    struct node* temp;
    temp=head;
    while(temp!=0){
        temp=temp->next;
        count++;

    }
    return count;
}
void insertatp(int pos){
   struct node* newnode,* temp;
    temp=head; 
    int i=1;
   int l=length();
   if((pos<=0) &&(pos>l)){
    printf("invalid position");
   }
   if(pos=1){
    insertb();
   }
   else{

    while (i<pos-1)
    {
      temp=temp->next;
      i++;
    }
      newnode=malloc(sizeof(struct node));
   printf("enter the data");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
   }
}
void display(){
    int i=1;
     struct node* temp;
     temp=head;
    while(temp)
     {
     printf("\ndata in doudly linked list%d:%d",i,temp->data);
     temp=temp->next;
     i++;
     }
}


void main ()
{
    int s,i;

    printf("1: create doubly linked list \n2:insertion in begin \n 3:insertion at end\n 4:insertion in between linked list\n 5:display linked list \n6:lenght of linked list\n7: exit");
   
    while(1)
    {
        printf("\n========================================================");
         printf("\nenter your choice:");
    scanf("%d",&s);
        switch(s)
        {
            case 1:createdd();
            break;
        case 2:insertb();
               break;
        case 3:insertend();
               break;
        case 4:printf("enter the position you want to insert:");
               scanf("%d",&i);
               insertatp(i);
               break;
        case 5:display(head);
               break;
               case 6:length();
               break;
        case 7:exit(0);              
        }
    }
}