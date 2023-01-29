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
int deletebegin(){
    struct node* temp;
    temp=head;
    if(head==0){
        printf("empty linked list");
        return 0;
    }
    else if(head==temp->next){
         head=0;
         return head->data;
         free(head);

    }
    else{
       head=temp->next;
       head->prev=tail;
       tail->next=head;
       return temp->data;
       free(temp);
    }

}
int deleteend(){
    struct node* temp;
    temp=tail;
    if(head==0){
        printf("empty linked list");
        return -1;
    }
     if(head==tail){
         head=0;
         return head->data;
         free(head);

    }
    else{
         tail=temp->prev;
         head->prev=temp->prev;
         tail->next=head;
         return temp->data;
         free(temp);
 }
}
int deleteatp(int pos)
{   
    int k,i=1;
    struct node* temp;
    temp=head;
    if(head==0){
        printf("empty linked list");
        return 0;
    }
    if(pos==1){
        k=deletebegin();
        return k;
    }
    else{
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        return temp->data;
        free(temp);

    }
}
void main ()
{
    int s,i,a,pos;

    printf("1:create doubly circulur linked list\n2:delete from begin \n3:delete from end\n4:delete from  linked list\n5:display linked list \n6:lenght of linked list\n7: exit");
   
    while(1)
    {
        printf("\n========================================================");
         printf("\nenter your choice:");
    scanf("%d",&s);
        switch(s)
        {
        case 1:createdc();
            break;
        case 2:a=deletebegin();
               printf("Deleted element from beginning is %d",a);
               break;
        case 3:a=deleteend();
               printf("Deleted element from beginning is %d",a);
               break;
        case 4 :
                printf("enter the position you want to delete:");
                scanf("%d",&pos);
                a=deleteatp(pos);
                printf("Deleted element from beginning is %d",a);
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