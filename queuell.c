//queue with linked list

#include<stdio.h>
#include<stdlib.h>
void enque();
void deque();
void display();
int choice;

struct node
{
    int data;
    struct node *next;
}*front=0,*rear=0,*ptr,*new;

int main()
{
    printf("--This is menu--\n");
    printf("1.enque\n 2.deque\n 3.display\n 4.exit\n");
    while(choice!=4)
    {
       printf("\nenter your choice: ");   
       scanf("%d",&choice);
       switch(choice)
       {
         case 1:enque();
         break;
         case 2:deque();
         break;
         case 3:display();
         break;
         case 4:printf("exit");
         break;
         deafult:printf("invalid choice");
}
    }
}

void enque()
{
  new=(struct node*)malloc(sizeof(struct node));
  printf("enter the data: ");
  scanf("%d",&new->data);
  new->next=NULL;
  if(front==0 && rear==0)
  {
     front=new;
     rear=new;
  }
  else
 {
    rear->next=new;
    rear=new;
 }


}

void deque()
{
    ptr=front;
    if(front==0 && rear==0)
    {
        printf("queue is empty\n");
    }
    else if(rear==front)
    {
      front=0;
      rear=0;
      free(ptr);

    }
    else
    {
        front=front->next;
        free(ptr);
    }
    


}

void display()
{
    ptr=front;
    if(front==0 && rear==0)
    {
        printf("queue is empty\n");

    }
    else
    {
        
      printf("List of items\n");
       while(ptr!=NULL)
       {
        printf("%d ",ptr->data);
       ptr=ptr->next;
       }
    }
}