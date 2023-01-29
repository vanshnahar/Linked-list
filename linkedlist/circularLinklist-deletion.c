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
void deleteb(){
    struct node* temp;
    temp=tail->next;
    if(tail==0){
        printf("empty linked list");
    }
    if(temp==tail)
    {
        tail=0;
        free(temp);
    }
    else{
        tail->next=temp->next;
        free(temp);
    
    }
}
void deleteend(){
   struct node* current,* prev;
    current=tail->next;
    if(tail==0){  
        printf("empty linked list");
    }
    else if(current==tail){
         tail=0;
         free(current);

    }
    else{
        while(current!=tail)
{
        prev=current;
        current=current->next;
    }
    prev->next=tail->next;
    tail=prev;
    free(current);
    }

}
void deleteatp(int pos){
    struct node* current ,* prev;
    current=tail->next;
    int l,i=1;
    l=length();
    if(pos<1&&pos>l){
        printf("invalid position ");
    }
     else if(current==tail){
         tail=0;
         free(current);

    }
    else if(pos=1){
        deleteb();

    }
    else{
         while(i<pos)
         {
            prev=current;
            current=current->next;
         }
         prev->next=current->next;
         free(current);
         }

}
void reverse (){
struct node* current ,* prev,* nextnode;
    current=tail->next;
    nextnode=current->next;
    if(tail==0){
        printf("empty list");

    }
    else{
       while(current!=tail){
        prev=current;
        current=nextnode;
        nextnode=current->next;
        current->next=prev;
       }
       nextnode->next=tail;
       tail=nextnode;
    }
    display(tail);
}

void main ()
{
    int s,i,a;
    // tail=createcircularlinkedlist();

    printf("\n1:create circular linked list \n2:delete from begin \n3:delete from end \n4:delete from between linked list \n5:reverse \n6:display linked list \n7:lenght of linked list \n8:exit");
   
    while(1)
    {
        printf("\n========================================================");
         printf("\nenter your choice:");
    scanf("%d",&s);
        switch(s)
        {
        case 1: tail=createcircularlinkedlist();
            break;
        case 2:deleteb();
               break;
        case 3:deleteend();
               break;
        case 4:printf("enter the position you want to insert:");
               scanf("%d",&i);
               deleteatp(i);
               break;
        case 5:reverse();
               break;       
        case 6:display(tail);
               break;
        case 7:a=length();
          printf("length of linked list is %d",a);
               break;
        case 8:exit(0);              
        }
    }
}