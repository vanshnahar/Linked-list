#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node* tail;
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
struct node* createcircularlinkedlist(){
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

 return tail;
    // printf("\ndata in linked list%d:%d",i,temp->data);
}
int length(){
    struct node* temp;
    temp=tail->next;
    int count=0;
    do{
        temp=temp->next;
        count++;

    }while(temp!=tail->next);
    return count;
}

void insertb(){
    struct node* newnode;
    newnode=malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    if(tail==0){
        tail=newnode;
        newnode->next=tail;
    }
    else{
      newnode->next=tail->next;
      tail->next=newnode;
    }
}
void insertend(){
    struct node* newnode;
    newnode=malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    if(tail==0){
        tail=newnode;
        newnode->next=tail;
    }
    else{
      newnode->next=tail->next;
      tail->next=newnode;
      tail=newnode;
    }
}
void insertatp(int pos){
    struct node* temp,* newnode;
    int i=1,l;
    l=length();
    if(pos<1&&pos>l){
        printf("invalid position");
    }
    else if(pos==1){
        insertb();
    }
    else{
        newnode=malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
        temp=tail->next;
        while(i<pos-1){
            
            temp=temp->next;
            i++;
        } 
        newnode->next=temp->next;
        temp->next=newnode;
    }

}

void main ()
{
    int s,i,a;
    // tail=createcircularlinkedlist();

    printf("\n1: create circular linked list \n2:insertion in begin \n 3:insertion at end\n 4:insertion in between linked list\n 5:display linked list \n6:lenght of linked list\n7: exit");
   
    while(1)
    {
        printf("========================================================");
         printf("\nenter your choice:");
    scanf("%d",&s);
        switch(s)
        {
            case 1: tail=createcircularlinkedlist();
            break;
        case 2:insertb();
               break;
        case 3:insertend();
               break;
        case 4:printf("enter the position you want to insert:");
               scanf("%d",&i);
               insertatp(i);
               break;
        case 5:display(tail);
               break;
        case 6:a=length();
          printf("length of linked list is %d",a);
               break;
        case 7:exit(0);              
        }
    }
}