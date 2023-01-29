#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node* head=0 ;
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
void deleteb(){
struct node* temp;
temp=head;
head=temp->next;
free(temp);
}
struct node* deleteend(){
struct node* temp,*prev=0;
temp=head;
while(temp->next!=0)
{
    prev=temp;
    temp=temp->next;
    
}
if(temp==head){
    head=0;
    free(temp);
}
else{
prev->next=0;
printf("%d is deleted from linked list",temp->data);
free(temp);
}
return head;
}
struct node* deleteatp(int pos){
struct node* temp,*prev=0;
temp=head;
if(pos>0&&pos<=3){
int i=1;
while(i<pos){
    prev=temp;
    temp=temp->next;
    i++;
}
if (temp==head){
    deleteb();
}
prev->next=temp->next;
free(temp);
}
return head;
}
void display(){
    int i=1;
     struct node* temp;
     temp=head;
    while(temp)
     {
     printf("\ndata in linked list%d:%d",i,temp->data);
     temp=temp->next;
     i++;
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
void reverse(){
    struct node *prev,*current, *nextnode;
    prev=0;
    nextnode=current=head;
    while (nextnode!=0)
    {
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev;
    // return head;
display(head);

}
void main ()
{
    int a,s,i;
   
    head=createlinkedlist();
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
