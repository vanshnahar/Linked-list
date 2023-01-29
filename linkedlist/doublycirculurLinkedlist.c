#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* prev;
  struct node *next;
};
void main()
{
   struct node* head=0  ;
   struct node* tail,* newnode;
   
   int ch;
   do{ 
   newnode=malloc(sizeof(struct node));
   printf("enter the data:");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   if (head==0){
    tail=head=newnode;
    newnode->next=head;
    newnode->next=head;

   }
   else{
    tail->next=newnode;
    newnode->next=head;
    newnode->prev=tail;
    head->prev=newnode;
    tail=newnode;
   }
   printf("you want to insert more element : ");
   scanf("%d",&ch);
}while(ch);

 struct node* temp;
 temp=head;
 do{
 printf("%d\t",temp->data);
 temp=temp->next;
 }while(temp!=head);


}






























