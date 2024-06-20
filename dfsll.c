#include<stdio.h>
#include<stdlib.h>
int vertices;

struct node
{ 
    int data;
    struct node *next;

};




void graph(struct node*adj[]);
void dfs(struct node*adj[],int start,int visited[]);

void graph(struct node*adj[])
{
    struct node *new,*tail;
    int k,x,i,j;
    for(i=0;i<vertices;i++)
    {
        printf("how many vertices are adjacent to %d: ",i);
        scanf("%d",&k);
        for(j=1;j<=k;j++)
        {
            new=(struct node*)malloc(sizeof(struct node));
            printf("enter the %d nighbour of %d",j,i);
            scanf("%d",&x);
            new->data=x;
            new->next=NULL;
            if(adj[i]==NULL)
            {
              adj[i]=tail=new;
            }
            else
            {
                tail->next=new;
                tail=new;

            }
        }
    }
}

void dfs(struct node*adj[],int start,int visited[])
{  
    int stack[vertices],top=-1;
    stack[++top]=start;
    while(top>=0)
    {
        int current=stack[top--];
        struct node *ptr=adj[current];
        if(visited[current]==0)
        {
            visited[current]=1;
            printf("%d",current);

        }
        while(ptr!=NULL)
        {
            if(visited[ptr->data]==0)
            {
                stack[++top]=ptr->data;
            }
            ptr=ptr->next;
        }

    

    }
}

int main()
{
    int i;
    printf("enter the no. of vertices: ");
    scanf("%d",&vertices);
    struct node *adj[vertices];
    for(i=0;i<vertices;i++)
    {
        adj[i]=NULL;

    }
    graph(adj);
    int visited[vertices],start;
    for(i=0;i<vertices;i++)
    {
      visited[i]=0;
    }
    printf("enter the vertices where you want to start to search for BFS: ");
    scanf("%d",&start);
    dfs(adj,start,visited);
    return 0;

}