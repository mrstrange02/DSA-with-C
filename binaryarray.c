#include<stdio.h>
#include<stdlib.h>
int  setright(char key,int parent);
int  setleft(char key,int parent);
int root(char key);
int printtree();
void inorder();
void preorder();
void postorder();


char tree[20];
int main()
{
    root('A');
    setleft('B',0);
    setright('C',0);
    setleft('D',1);
    setright('E',1);
    setright('F',2);
    printtree();
    printf("\nInorder Traversals: ");
    inorder(0);
    printf("\n");

    printf("Preorder Traversals: ");
    preorder(0);
    printf("\n");

    printf("Postorder Traversals: ");
    postorder(0);
    printf("\n");
    return 0;

}
int root(char key)
{
    if(tree[0]!='\0')
    {
       printf("tree already have key");
    }
    
    else
    {
        tree[0]=key;
    }
    
    return 0;
}

 int setleft(char key,int parent)
 {
    if(tree[parent]=='\0')
    {
        printf("can't set child at %d,no parent found",(parent*2)+1);
    }
    else
    {
        tree[(parent*2)+1]=key;

    }
    return 0;
 }

 int setright(char key,int parent)
 {
    if(tree[parent]=='\0')
    {
        printf("can't set child at %d,no parent found",(parent*2)+2);
    }
    else
    {
        tree[(parent*2)+2]=key;

    }
    return 0;
 }

 int printtree()
 {
   int i;
    printf("\n");
    for(i=0;i<10;i++)
    {
      if(tree[i]!='\0')
      {
      
        printf("%d",tree[i]);
      }
      else{
        printf("-");
      }
    
    }
 }

 void inorder(int ind)
 {
    if(tree[ind]!='\0')
    {
    inorder((ind*2)+1);
    printf("%c",tree[ind]);
    inorder((ind*2)+2);
 }
 }

 void preorder( int ind) 
 {
    if(tree[ind]!='\0')
    {
    printf("%c",tree[ind]);
    preorder((ind*2)+1);
    preorder((ind*2)+2);

 }
 }

 void postorder(int ind)
 {
   if(tree[ind]!='\0')
    {
    postorder((ind*2)+1);
    postorder((ind*2)+2);
    printf("%c",tree[ind]);
 }
 }
