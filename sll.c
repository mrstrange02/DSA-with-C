//Singled Linked list

#include<stdio.h>
#include<stdlib.h>

void traverse();
void insertion();
void deletion();
void create();
int i,choice,pos;

struct node
{
    int data;
    struct node *next;
}*header=NULL,*ptr,*ptr1,*new;

void main()
{
    
    ptr=header;
    printf("-------THIS IS A MENU----\n");
   printf("1.Create\n 2.Insertion\n 3.Deletion\n 4.traverse\n 5.exit\n");
   while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:insertion();
            break;
            case 3:deletion();
            break;
            case 4:traverse();
            break;
            case 5:exit(0);
            break;
            default:
            printf("Invalid Choice\n");
       
        }

    }
}
void create()
{
  new=(struct node*)malloc(sizeof(struct node));
   printf("\nenter the item to be inserted: ");
   scanf("%d",&new->data);
   if(header==NULL)
   {
    new->next=NULL;
    header=ptr=new;
}
else
{
    ptr->next=new;
    ptr=new;
}
}
void insertion()
{

   new=malloc(sizeof(struct node));
   printf("\nenter the item to be inserted: ");
   scanf("%d",&new->data);
   if(header==NULL)
   {
    new->next=NULL;
    header=new;
   }
   
   else
   {
    printf("\nenter the place to insert an item: ");
    printf("\n1.begin\n 2.pos\n 3.end\n");
    scanf("%d",&choice);
    if(choice==1)
    {
    new->next=header;
    header=new;
   }
   if(choice==2)
   {
      ptr=header;
      printf("enter the position to insert\n");
      scanf("%d",&pos);
      for(i=1;i<pos-1;i++)
      
        ptr=ptr->next;
        new->next=ptr->next;
        ptr->next=new;

}
 if(choice==3)
 {
     ptr=header;
     while(ptr->next!=NULL)
     ptr=ptr->next;
     
        new->next=NULL;
        ptr->next=new;
        }
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
   header=header->next;
   }
   if(choice==2)
   {
    printf("enter the position to delete an item: ");
    scanf("%d",&pos);
    for(i=0;i<pos-1;i++)
    {
      ptr1=ptr;
      ptr=ptr->next;
      }
      printf("the deleted item is: %d\n",ptr->data);
      ptr1->next=ptr->next;
      }
      if(choice==3)
      {
      while(ptr->next!=NULL)
     {
      ptr1=ptr;
      ptr=ptr->next;
     }
     printf("\nThe deleted element from the list is: %d",ptr->data);
     ptr1->next=NULL;
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
      for(ptr=header;ptr!=NULL;ptr=ptr->next)
      printf(" %d",ptr->data);
 }
 } 
 


        
     


    
