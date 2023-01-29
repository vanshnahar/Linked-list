#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* prev;
  struct node* next;
};
struct node* tail,*head;

void createdc()
{
   
   struct node*newnode;
   
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
void insertb(){
   struct node* newnode;
  newnode=malloc(sizeof(struct node));
   printf("enter the you want to insert data:");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   if (head==0){
    tail=head=newnode;
    newnode->next=head;
    newnode->next=head;

   }
   else{
         newnode->prev=head->prev;
         tail->next=newnode;
         newnode->next=head;
         head->prev=newnode;
         head=newnode;
}
}
void display(){
     struct node* temp;
 temp=head;
 if (head==0){
    printf("No element in linked list");

 }
 else{
 do{
 printf("%d\t",temp->data);
 temp=temp->next;
 }while(temp!=head);
 }
}
int length(){
    int count=0;
    struct node* temp;
    temp=head;
    while(temp!=tail){
        temp=temp->next;
        count++;

    }
    count++;
    return count;
}
void insertend(){
 struct node* newnode;
  newnode=malloc(sizeof(struct node));
   printf("enter the you want to insert data:");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   if (head==0){
    tail=head=newnode;
    newnode->next=head;
    newnode->next=head;

   }
   else{
         newnode->next=tail->next;
         head->prev=newnode;
         tail->next=newnode;
         newnode->prev=tail;
         tail=newnode; 
}
}
void insertatp(){
int i, pos,l;
l=length();
printf("enter the pos you want to insert:");
scanf("%d",&pos);
if (pos<0&&pos>l)
{
    printf("this position is out of range");

}
else if(pos==1)
{
    insertb();
}
else{
    struct node* temp,*newnode;
    temp=head;
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
     newnode=malloc(sizeof(struct node));
   printf("enter the data:");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   newnode->next=temp->next;
   temp->next->prev=newnode;
   temp->next=newnode;
   newnode->prev=temp;
}
}
void main ()
{
    int s,i,a;

    printf("1:create doubly circulur linked list\n2:Insertion in begin \n3:Insertion at end\n4:Insertion in betwee n linked list\n5:display linked list \n6:lenght of linked list\n7: exit");
   
    while(1)
    {
        printf("\n========================================================");
         printf("\nenter your choice:");
    scanf("%d",&s);
        switch(s)
        {
        case 1:createdc();
            break;
        case 2:insertb();
               break;
        case 3:insertend();
               break;
        case 4:insertatp();
               break;
        case 5:display();
               break;
        case 6:a=length();
               printf("length of linked list is %d",a);
               break;
        case 7:exit(0);              
        }
    }
}


















