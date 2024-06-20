
#include<stdio.h>
#include<stdlib.h>

void traverse();
void deletion();
void insertion();
int i,choice,pos;

struct node
{
    int data;
    struct node *link;
}*header,*ptr,*ptr1,*new;

void main()
{
    header=NULL;
    ptr=header;
    printf("-------THIS IS A MENU----\n");
   printf("1.Insertion\n 2.Deletion\n 3.Traverse\n 4.exit\n");
   while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertion();
            break;
            case 2:deletion();
            break;
            case 3:traverse();
            break;
            case 4:exit(0);
            break;
            default:
            printf("Invalid Choice\n");
       
        }

    }
}
void insertion()
{

   new=malloc(sizeof(struct node));
   printf("\nenter the item to be inserted: ");
   scanf("%d",&new->data);

   if(header==NULL)
   {
    new->link=NULL;
    header=new;
   }
}

 void deletion()
 {
 
   ptr=header;
   if(header==NULL)
   {
   printf("list is empty\n");
   }
   else
   {
   
   printf("enter the place to delete an elemeent\n");
   printf("1.begin\n 2.pos\n 3.end\n");
   scanf("%d",&choice);
   
   if(choice==1)
   {
   printf("the deleted item from a list : %d\n",ptr->data);
   header=header->link;
   }
   if(choice==2)
   {
    printf("enter the position to delete an item: ");
    scanf("%d",&pos);
    for(i=0;i<pos-1;i++)
    {
      ptr1=ptr;
      ptr=ptr->link;
      }
      printf("the deleted item is: %d\n",ptr->data);
      ptr1->link=ptr->link;
      }
      if(choice==3)
      {
      while(ptr->link!=NULL)
     {
      ptr1=ptr;
      ptr=ptr->link;
     }
     printf("\nThe deleted element from the list is: %d",ptr->data);
     ptr1->link=NULL;
     }
     }
     }


 void traverse()
     {
      if(header==NULL)
      printf("List is empty\n");
      else
      {
       printf("\nThe elements in the list are: ");
      for(ptr=header;ptr!=NULL;ptr=ptr->link)
      printf(" %d",ptr->data);
 }
 }