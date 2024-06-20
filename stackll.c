//Stack with linked list

#include<stdio.h>
#include<stdlib.h>


void push();
void pop();
void display();
int choice;

struct node
{
    int data;
    struct node *next;
}*top,*new,*ptr;

int main()
{
    
    printf("1.enque\n 2.deque\n 3.display\n 4.exit\n");
   while(choice!=4)
   { 
    printf("enter your choice");
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
     default:printf("invalid");
     }
     }
     }

void push()
{
  new=(struct node*)malloc(sizeof(struct node));
  printf("enter the data: ");
  scanf("%d",&new->data);
  new->next=top;
  top=new;
}

void pop() 
{

    if(top==NULL)
    {
        printf("stack is empty");
    }
    else
    {
      ptr=top;
      top=ptr->next;
      free(ptr);
    }
    }

void display()
{
 if(top==NULL)
 {
    printf("stack is empty");
 }
 else
 {
  printf("list of items\n");
  ptr=top;
  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
 }
}

