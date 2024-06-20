#include<stdio.h>
#include<stdlib.h>

void traverse();
void insertion();
void reverse();
int choice;

struct node
{
    int data;
    struct node *link;
}*header,*ptr,*prev,*next,*new;

void main()
{
     header=NULL;
     ptr=header;
    printf("-------THIS IS A MENU----\n");
   printf("1.Insertion\n 2.Reverse\n 3.traverse\n 4.exit\n");
   while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertion();
            break;
            case 2:reverse();
            break;
            case 3:traverse();
            break;
            case 4:exit(0);
            break;
            default:printf("Invalid choice\n");
        }
    }
}

void insertion()
{
   new=(struct node*)malloc(sizeof(struct node));
   printf("\nenter the item to be inserted: ");
   scanf("%d",&new->data);
   if(header==NULL)
   {
    new->link=NULL;
    header=ptr=new;
}
else
{
    ptr->link=new;
    ptr=new;
}
     
 }

void reverse()
{
    prev=NULL;
    ptr=header;
    next=header;
    while(next!=NULL)
    {
        next=next->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;

    }
    header=prev;
}

void traverse()
{
    ptr=header;
    if(header==NULL)
    {
        printf("list is empty");

    }
    else
    {
       while(ptr!=NULL)
       {
        printf("%d ",ptr->data);
        ptr=ptr->link;
       }
    }
}