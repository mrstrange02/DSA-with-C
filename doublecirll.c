#include<stdio.h>
#include<stdlib.h>
void create();
void deletion();
void traverse();
int choice,i,pos;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*tail,*new,*ptr,*header=NULL;

void main()
{ 
  printf("This is menu\n");
  printf("1.Create\n 2.deletion\n 3.traverse\n 4.exit\n");
  while(1)
  {
    printf("\nenter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:create();
        break;
        case 2:deletion();
        break;
        case 3:traverse();
        break;
        case 4:exit(0);
        break;
        default:printf("invalid choice");
        

    }

  }
}
void create()
{
  
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&new->data);
    if(header==NULL)
    {
      header=tail=new;
      new->next=header;
      new->prev=tail;
    }
    else
    {
      tail->next=new;
      new->next=header;
      new->prev=tail;
      header->prev=new;
      tail=new;

    }
}
void deletion()
{ 
  
  if(header==NULL)
  {
    printf("list is empty\n");
  }
  else
  {
    printf("1.begin\n 2.pos\n 3.end\n");
    scanf("%d",&choice);
    ptr=header;
    if(choice==1)
    {
      if(header->next==header)
      {
        header=NULL;
        tail=NULL;
        free(ptr);
      }
      else
      {
        header=header->next;
        header->prev=tail;
        tail->next=header;
        free(ptr);
      }
    }
    if(choice==2)
    {
      ptr=header;
      printf("enter the position ");
      scanf("%d",&pos);
      if(pos==1)
      {
        header=header->next;
        header->prev=tail;
        tail->next=header;
        free(ptr);
      }
      else
      {
        for(i=0;i<pos-1;i++)
        {
          ptr=ptr->next;
        }
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        if(ptr->next==header)
        {
          tail=ptr->prev;
          free(ptr);
        }
        else
        {
          free(ptr);
        }
      }
    }
    if(choice==3)
    {
      if(header->next==header)
      {
       header=NULL;
        tail=NULL;
        free(ptr);
        
      }
      else
      {
         tail=tail->prev;
         tail->next=header;
         header->prev=tail;
         free(ptr);
      }
    }
  }
}


void traverse()
  {
    ptr=header;
    if(header==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
       
         while(ptr!=tail)
         {
         printf("%d ",ptr->data);
            ptr=ptr->next;
         }
         printf("%d",ptr->data);
    }
  }
