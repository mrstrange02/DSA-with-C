#include<stdio.h>
#include<stdlib.h>
#define size 10
int h[size]={0};

void insert();
void search();
void display();

int main()
{
    int choice;
    printf("1.insert\n 2.search\n 3.display\n 4.exit\n");
    while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
            break;
            case 2:search();
            break;
            case 3: display();
            break;
            case 4:exit(0);
            default:printf("Invalid Choice\n");
        }
    }
}

        
    


void insert()
{
    int key,index,i,hkey;
    printf("enter the key to insert: ");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0;i<size;i++)
    {
        index=(hkey+i)%size;
        if(h[index]==0)
        {
            h[index]=key;
            break;
        }
    }
    if(i==size)
    {
        printf("element cannot be inserted\n");
    }
}

void search()
{
    int key,i,index,hkey;
    printf("enter search element: ");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0;i<size;i++)
    {
        index=(hkey+i)%size;
        if(h[index]==key)
        {
            printf("value is found at %d",index);
            break;
        }
    }
    if(i==size)
    {
        printf("value is not found\n");
    }

}

void display()
{
    int i;
    printf("elements in the hash table are: ");
    for(i=0;i<size;i++)
    {
        printf("\nat index %d value is = %d",i,h[i]);
    }
}