#include<stdio.h>
void enque();
void deque();
void display();
int rear=-1,front=-1,x,i,n,queue[100],choice=0;
 
 int main()

 {
    printf("enter the size: ");
    scanf("%d",&n);
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
    printf("enter the element: ");
    scanf("%d",&x);
    if((rear+1)%n==front)
    {
        printf("queue is Full\n");

    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;

    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }

}

void deque()
{
  if(front==-1 && rear==-1)
  {
    printf("Empty");
  }
  else if(front==rear)
  {

     front=-1;
     rear=-1;
  }
  else
  {
    printf("element is deleted %d",queue[front]);
    front=(front+1)%n;
  }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%n)
        {
            printf("%d ",queue[i]);
        }
        printf("%d",queue[i]);

    }
}