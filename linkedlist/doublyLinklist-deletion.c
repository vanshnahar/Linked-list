#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* prev;
  struct node *next;
};
struct node* head=0 ,*tail=0,*third;
struct node* createdoublelinkedlist(){
    struct node* first, *second;
    first=malloc(sizeof(struct node));
    second=malloc(sizeof(struct node));
    third=malloc(sizeof(struct node));
   
    first->next=0;
    first->prev=0;

    second->next=0;
    second->prev=0;

    third->next=0;
    third->prev=0;

    first->data=1;
    second->data=2;
    third->data=3;
 
    first->next=second;
    
    second->prev=first;
    second->next=third;

    third->prev=second;

    head=first;
    tail=third;
    return head;
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
void deleteb(){
    struct node* temp;
    temp=head;
    if(head==0){
        printf("empty linked list");
    }
    else{
        head=temp->next;
        head->prev=0;
        free(temp);
    }

}
struct node* deleteend(){
     struct node* temp;
    temp=tail;
    if(tail==0){
        printf("empty linked list");
    }
    else if(tail==head){
        tail=head=0;
        free(temp);

    }
    else{
        tail=temp->prev;
        tail->next=0;
        free(temp);
    }
   return head;
}
void deleteatp(int pos){
    struct node* temp=head;
    int i=1,l;
    l=length();
    if(pos<1&&pos>l){
        printf("out of range");

    }
    else if(pos=1){
        deleteb();

    }
    else{
          while(i<pos){
            temp=temp->next;
            i++;
          }
          temp->prev->next=temp->next;
          temp->next->prev=temp->prev;
          free(temp);
    }
}
void display(struct node* head){
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

void reverse(){
    struct node* current ,* nextnode;
    if(head==0){
        printf("empty set");
    }
    else{
        current=head;
        while(current){
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
        }
        head=tail;
        
        display(head);
}

void main ()
{
    int a,s,i;
   
    head=createdoublelinkedlist();
    tail=third;
    
    printf("1:delete from begin \n 2:delete from  at end\n 3:delete in between linked list\n 4:display linked list \n5:length \n  6:reverse linked list \n 7:exit\n");
   
    while(1)
    {
        printf("\n=====================================================");
         printf("\nenter your choice:");
    scanf("%d",&s);
        switch(s)
        {
        case 1:deleteb();
               break;
        case 2:head=deleteend();
               break;
        case 3:printf("enter the position you want to delete:");
               scanf("%d",&i);
               deleteatp(i);
               break;
        case 4:display(head);
               break;
        case 5: a=length();
               printf("lenght of linked list is %d",a);
               break;
        case 6:reverse();
               break;
        case 7:exit(0);              
        }
    

    }
}

