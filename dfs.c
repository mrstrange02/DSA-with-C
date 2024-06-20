//Depth First Search ||follows STACK LIFO||

#include<stdio.h>
#define max 6

int adj[max][max];
int stack[max];
int visited[max]={0};
int top=-1;

void addedge(int src,int dest)
{
    adj[src][dest]=1;
    adj[dest][src]=1;
}

void dfs(int start)
{
    int v,i;
    stack[++top]=start;
    while(top>=0)
    {
        v=stack[top--];
        if(visited[v]==0)
        {
            printf("%d ",v);
            visited[v]=1;
            
            for(i=0;i<max;i++)
            {
                if(adj[v][i]==1 && !visited[i])
                {
                    stack[++top]=i;
                }
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
        printf("enter  the data: ");
        scanf("%d %d",&a,&b);
        addedge(a,b); 
    }
    int s;
    printf("enter a source node: ");
    scanf("%d",&s);

    /*addedge(0,1);
    addedge(0,2);
    addedge(1,2);
    addedge(1,3);
    addedge(2,3);
    addedge(3,4);*/
    
    printf("DFS is : \n");
    dfs(s);
    printf("\n");
    
}

