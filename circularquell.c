//Circular queue with linked list

#include<stdio.h>
#include<malloc.h>
void enque();
void deque();
void display();
struct node
{
    int data;
    struct node *next;
}*front=0,*rear=0,*new,*ptr;
int choice=0;
 
 int main()

 {
    printf("This is Menu\n");
    printf("1.push\n 2.pop\n 3.disply\n 4.exit\n");
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
            default:printf("invalid choice");
        }
    }
 }


 void enque()
 {
    new=(struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA: ");
    scanf("%d",&new->data);
    new->next=NULL;
    if(rear==NULL)
    {
        front=new;
        rear=new;
        rear->next=front;
    }
    else
    {
        rear->next=new;
        rear=new;
        rear->next=front;
    }

 }

 void deque()
 {
    ptr=front;
    if(front==0 && rear==0)
    {
        printf("empty");

    
    }
    else if(front==rear)
    {
        front=0;
        rear=0;
        free(ptr);

    }
    else
    { 
       front=front->next;
       rear->next=front;
       free(ptr);

    }
 }

 void display()
  {
    ptr=front;
    if(front==0 && rear==0)
    {
        printf("empty\n");

    }
    else
    {
        while(ptr->next!=front)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d ",ptr->data);
    }
  }