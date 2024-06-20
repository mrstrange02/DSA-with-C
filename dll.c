//Double linked list

#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void insertion();
void deletion();
int i,choice,pos;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*header=NULL,*ptr,*ptr1,*ptr2,*new;

void main()
{
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
    new->prev=NULL;
    header=ptr=new;
}
else
{
    ptr->next=new;
    new->prev=ptr;
    ptr=new;

}
}
void insertion()
{
    ptr=header;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the data to insert: ");
    scanf("%d",&new->data);
    if(header==NULL)
    {
        new->prev=NULL;
        new->next=NULL;
        header=new;
    }
    else
    {
        printf("enter the place to insert data: \n");
        printf("1.begin\n 2.pos\n 3.end\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            new->next=ptr;
            ptr->prev=new;
            new->prev=NULL;
            header=new;
        }
        if(choice==2)
        {
            printf("enter the position to insert: ");
            scanf("%d",&pos);
            for(i=1;i<pos-1;i++)
            {
                ptr=ptr->next;
            }
            if(ptr->next==NULL)
            {                  
                new->next=ptr;
                ptr->prev=new;
                new->prev=NULL;
            }
            else
            {
                ptr1=ptr->next;
                new->next=ptr1;
                ptr1->prev=new;
                new->prev=ptr;
                ptr->next=new;
            }
        }
        if(choice==3)
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
                new->next=NULL;
                new->prev=ptr;
                ptr->next=new;
            }
        }
    }



void deletion()
{
    ptr=header;
    if (header==NULL)
    {
     printf("the list is empty\n");
    }
    else
    {
        printf("enter the place to delete\n");
        printf("1.begin\n 2.pos\n 3.end\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("the deleted item from a list is %d\n",ptr->data);
            ptr1=ptr->next;
            ptr1->prev=NULL;
            header=ptr1;
            free(ptr);

        }
        if(choice==2)
        {
            printf("enter the position to delete: ");
            scanf("%d",&pos);
          
                for(i=0;i<pos-1;i++)
                {
                    ptr=ptr->next;
                }
                printf("the deleted item is %d",ptr->data);
                if(ptr==header)
                {
                    ptr1=ptr->next;
                    ptr1->prev=NULL;
                    header=ptr1;
                }
                else
                {
                   ptr1=ptr->next;
                   ptr2=ptr1->next;
                   ptr->next=ptr2;
                   ptr2->prev=ptr;
                   free(ptr1);
                }
            }
        
if(choice==3)
{
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    printf("the deleted item is %d",ptr->data);
    ptr1=ptr->prev;
    ptr1->next=NULL;
    free(ptr);
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
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }

}

