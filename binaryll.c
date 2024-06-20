#include<stdio.h>
#include<stdlib.h>
void inorder();
void preorder();
void postorder();
struct node *create();

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL,*new;

int main()
{
    struct node* root=NULL;
    printf("enter the binary elements\n ");
    root=create();
    printf("Inorder Traversals\n");
    inorder(root);
    printf("\n");
    printf("Preorder Traversals\n");
    preorder(root);
    printf("\n");
    printf("Postorder Traversals\n");
    postorder(root);
    //printf("\n");
   return 0;
    

}
    

struct node *create()
{
    int x;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->left=NULL;
    new->right=NULL;
    printf("enter the data: ");
    scanf("%d",&x);

    if(x==-1)
    {
    return 0;
    }
    new->data=x;
    printf("enter the left child of %d\n",x);
    new->left=create();
    printf("enter the right child of %d\n",x);
    new->right=create();
    return new;

}

void inorder(struct node *root)
{
    if(root==NULL)
    
        return;
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);

}

void preorder(struct node *root)
{
  if(root==NULL)
   return ;
   printf("%d ",root->data);
   preorder(root->left);
   preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
   return ;
   postorder(root->left);
   postorder(root->right);
   printf("%d ",root->data);
}





    



