//Stack with an Array

#include<stdio.h>
void push();
void pop();
void display();
    int n,stack[100],x,i,choice=0,top=-1;

int main()
{
    printf("enter the size: ");
    scanf("%d",&n);
    printf("1.push\n 2.pop\n 3.disply\n 4.exit\n ");
    while(choice!=4)
    {
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:printf("exit");
            break;
            default:printf("invalid choice");
        }
    }

}

void push()
    {
  
      if(top==n-1)
      {
        printf("stack is full\n");
      }
      else
      {
        printf("enter the element: ");
        scanf("%d",&x);
        top=top+1;
        stack[top]=x;
      }
      
    }

    void pop()
    {
        if(top==-1)
        {
            printf("stack is empty\n");
        }
        else
    {
        printf("item deleted from the stack is %d\n",stack[top]);
        top=top-1;

    }
    }

    void display()
    {
      if(top==-1)
      {
        printf("stack is empty");
      }
      else
      {
        
        for(i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
      }
    }
