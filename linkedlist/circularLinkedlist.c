#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
void display(struct node* tail){
  int i=1;
   struct node* temp;
     temp=tail->next;
     if (tail==0){
      printf("empty ll");
     }
     else{
    do
     {
     printf("\n data in linked list%d:%d",i,temp->data);
     temp=temp->next;
     i++;
     }while(temp!=tail->next);
}
}
void main(){
    int ch;
    struct node* newnode, * tail=0;
    do{
    newnode=malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0){
    tail=newnode;
    newnode->next=tail;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    printf("again:");
    scanf("%d",&ch);
}while(ch);

 display(tail);
    // printf("\ndata in linked list%d:%d",i,temp->data);
}












