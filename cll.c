//Circular linked list

#include<stdio.h>
#include<stdlib.h>
void create();
void insertion();
void deletion();
void traverse();
int choice,i,pos;

struct node
{
    int data;
    struct node *next;
}*tail=NULL,*new,*ptr,*ptr1;

void main()
{ 
  printf("This is menu\n");
  printf("1.Create\n 2.insertion\n 3.deletion\n 4.traverse\n 5.exit\n");
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
        default:printf("invalid choice");
        

    }

  }
}
void create()
{
    new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    printf("enter the data: ");
    scanf("%d",&new->data);
    if(tail==NULL)
 {  
      tail=new;
      tail->next=new;

} 
else 
{
  new->next=tail->next;
  tail->next=new;
  tail=new;
}
}

void insertion()
{ 
    new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    printf("enter the data: ");
    scanf("%d",&new->data);
    if(tail==NULL)
    {
        tail=new; 
        tail->next=new;
    }
    else
    {
        printf("enter the place insert\n");
        printf("1.begin\n 2.pos\n 3.end\n");
        scanf("%d",&choice);
    if(choice==1)
    {
        new->next=tail->next;
        tail->next=new;
    }
    

   if(choice==2)
   {
     printf("enter the postion to insert: ");
     scanf("%d",&pos);
      if(pos==1)
      {
        new->next=tail->next;
        tail->next=new;
      }
       else
        {
           for(i=1;i<pos-1;i++) 
           {
             ptr=ptr->next;
           }
             new->next=ptr->next;
             ptr->next=new;
        }
      }

   

    if(choice==3)
    {
     
        if(tail==NULL)
        {
            tail=new;
            tail->next=new;
        }
        else
        {
          new->next=tail->next;
          tail->next=new;
          tail=new;          
         }
    }
    }
    }

    void deletion()
    {
       
        if(tail==NULL)
        {
            printf("list is empty");
            
        }
        else
        {
         ptr=tail->next;
          printf("enter the postion delete\n");
          printf("1.begin\n 2.pos\n 3.end\n");
          scanf("%d",&choice);
          
          if(choice==1)
          {
            
           printf("the deleted item from a list is %d\n",ptr->data);
            if(ptr->next==ptr)
            {
                tail=NULL;
                free(ptr);
            }
            else
            {
             tail->next=ptr->next;
             free(ptr);
            }
          }
          if(choice==2)
          {
            if(pos==1)
            {
              tail->next=ptr->next;
              free(ptr);
            }
            else
            { 
             printf("enter the position to delete: ");
             scanf("%d",&pos);
               for(i=1;i<pos-1;i++)
               {
                ptr=ptr->next;
               }
               ptr1=ptr->next;
               ptr->next=ptr1->next;
               free(ptr1);
            }
          }

          if(choice==3)
          {
            if(ptr->next==ptr)
            {
                tail=NULL;
                free(ptr);
            }
            else
            {
                while(ptr->next!=tail->next)
                {
                    ptr1=ptr;
                    ptr=ptr->next;
                }
             printf("the deleted item from a list is %d\n",ptr->data);
                ptr1->next=tail->next;
                tail=ptr1;
                free(ptr);
            }
          }

        }
    }

  void traverse()
  {
    ptr=tail->next;
    if(tail==NULL)
    {
        printf("list is empty\n");
    }
    else

    {
        printf("\nThe elements in the list are: ");
         while(ptr->next!=tail->next)
         {
         printf("%d ",ptr->data);
            ptr=ptr->next;
         }
         printf("%d",ptr->data);
    }
  }
