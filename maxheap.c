//Max Heap using Array|Insertion and Deletion|
#include<stdio.h>
//#define max 20

int maxheap[20],n=0;
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
    scanf("%d",&maxheap[n]);
    n=n+1;
    i=n-1;
    while(i>0)
    {
        int parent;
        parent=(i-1)/2;
        if(maxheap[parent]<maxheap[i])
        {
            int temp;
            temp=maxheap[parent];
            maxheap[parent]=maxheap[i];
            maxheap[i]=temp;
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
    maxheap[0]=maxheap[n-1];
    n=n-1;
    i=0;
    while(i<n)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left>n && maxheap[left]>maxheap[right])
        {
            largest=left;
        }
        if(right>n && maxheap[right]>maxheap[left])
        {
           largest=right;
        }
        if(largest!=1)
        {
            int temp;
            temp=maxheap[i];
            maxheap[i]=maxheap[largest];
            maxheap[largest]=temp;
            i=largest;
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
        printf("%d ",maxheap[i]);
    }
   }

