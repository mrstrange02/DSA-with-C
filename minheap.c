//Min HEAP using Array |Insertion and Deletion|

#include<stdio.h>
//#define max 20

int minheap[20],n=0;
void insert();
void delete();
void display();
void create();

int main()
{
    create();
    int choice;

    printf("1.insert\n 2.delete\n 3.display\n 4.exit\n");
    while(choice!=4)
    {
       printf("\nenter your choice: ");
       scanf("%d",&choice);
       switch(choice)
       {
         case 1:insert();
         break;
         case 2:delete();
         break;
         case 3:display();
         break;
         case 4:printf("exit");
         break;
         deafult:printf("invalid choice");
       }
    }
}
    
 void create()
 {
    int N,i;
    printf("enter the size: ");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        insert();
    }
 }

 void insert()
 {
    int i;
    printf("enter the data: ");
    scanf("%d",&minheap[n]);
    n=n+1;
    i=n-1;
    while(i>0)
    {
        int parent;
        parent=(i-1)/2;
        if(minheap[parent]>minheap[i])
        {
            int temp;
            temp=minheap[parent];
            minheap[parent]=minheap[i];
            minheap[i]=temp;
            i=parent;
        }
        else
        {
           return;
        }
    }
 }

 void delete()
 { 
    int i;
    minheap[0]=minheap[n-1];
    n=n-1;
    i=0;
    while(i<n)
    {
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && minheap[left]<minheap[right])
        {
            smallest=left;
        }
        if(right<n && minheap[right]<minheap[left])
        {
           smallest=right;
        }
        if(smallest!=1)
        {
            int temp;
            temp=minheap[i];
            minheap[i]=minheap[smallest];
            minheap[smallest]=temp;
            i=smallest;
        }
        else
        {
            return;
        }
    }

 }
  
   void display()
   {
    int i;
    printf("Data in the leap: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",minheap[i]);
    }
   }