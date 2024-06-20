#include<stdio.h>
#include<stdlib.h>
int vertices;

struct node
{ 
    int data;
    struct node *next;

};

void graph(struct node*adj[]);
void bfs(struct node*adj[],int start,int visited[]);

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
            printf("enter the %d nighbour of %d: ",j,i);
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

void bfs(struct node*adj[],int start,int visited[])
{
    int que[vertices];
    int rear=-1,front=-1;
    struct node *ptr;
    que[++rear]=start;
    front++;
    printf("\n The bfs traversals from %d is: ", start);
    while(front<=rear)
    {
        start=que[front++];
        ptr=adj[start];
        visited[start]=1;
        printf("%d ",start);
        while(ptr!=NULL)
        {
            if(visited[ptr->data]!=1)
            {
                que[++rear]=ptr->data;
                visited[ptr->data]=1;
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
    bfs(adj,start,visited);
    return 0;

}