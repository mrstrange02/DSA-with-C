#include<stdio.h>
#include<stdlib.h>

void traverse();
void insertion();
int i,choice,pos;

struct node
{
    int data;
    struct node *link;
}*header,*ptr,*new;

void main()
{
    header=NULL;
    ptr=header;
    printf("-------THIS IS A MENU----\n");
   printf("1.Insertion\n 2.traverse\n 3.exit\n");
   while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertion();
            break;
            case 2:traverse();
            break;
            case 3:exit(0);
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
   else
   {
    printf("\nenter the place to insert an item: ");
    printf("\n1.begin\n 2.pos\n 3.end\n");
    scanf("%d",&choice);
    if(choice==1)
    {
    new->link=header;
    header=new;
   }
   if(choice==2)
   {
      ptr=header;
      printf("enter the position to insert\n");
      scanf("%d",&pos);
      for(i=1;i<pos-1;i++)
      
        ptr=ptr->link;
        new->link=ptr->link;
        ptr->link=new;

}
 if(choice==3)
 {
     ptr=header;
     while(ptr->link!=NULL)
     ptr=ptr->link;
     
        new->link=NULL;
        ptr->link=new;
        }
        }
        }
        
        
    void traverse()
     {
      if(header==NULL)
      printf("List is empty\n");
      else
      {
       priNntf("\nThe elements in the list are: ");
      for(ptr=header;ptr!=NULL;ptr=ptr->link)
      printf(" %d",ptr->data);
 }
 }
