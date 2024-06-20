//BFS-Breadth First Search |follows QUEUE FIFO|

#include<stdio.h>
#define max 6

int adj[max][max];
int que[max];
int visited[max]={0};
int rear=0,front=0;

void addedge(int src,int dest)
{
    adj[src][dest]=1;
    adj[dest][src]=1;
} 

void bfs(int start)
{
    int i;
    que[rear++]=start;
    visited[start]=1;
    while(front<rear)
    {
        int current=que[front++];
        printf("%d ",current);
        for(i=0;i<max;i++)
        {
            if(adj[current][i]==1 && !visited[i])
            {
                que[rear++]=i;
                visited[i]=1;

            }
        }
    }
}

int main()
{
    
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            adj[i][j]=0;
        }
    }
        for(i=0;i<max;i++)
        {
       int a,b;
     printf("enter the data: ");
        scanf("%d %d",&a,&b);
        addedge(a,b);
        }
        int s;
        printf("enter the source node: ");
        scanf("%d",&s);
      printf("BFS is:\n");
        bfs(s);
      printf("\n");
    
    /*addedge(0,1);
    addedge(0,2);
    addedge(1,2);
    addedge(1,3);
    addedge(2,3);
    addedge(3,4);*/
    
}
