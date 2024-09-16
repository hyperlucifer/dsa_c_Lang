#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// this function will return the address of the node created,,
// the pointer variable thats why its return datatype is struct node*

struct node *create()
{
    // create a node
    int x;
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    printf("enter the value\n");
    scanf("%d", &x);
    //base case for recarcive funcation
    //-1 also represent null
    if (x==-1)
    {
        return 0;
    }
    nn->data = x;
    printf("enter left child\n");
    nn->left=create();
    printf("enter right child\n");
    nn->right=create();

    return nn;
}
//travisal there is three type of travisal 
/*
1)inorder---->left root right
2)preorder--->root left right
2)postorder--->left right root
*/
void preorder(struct node * root){
    if (root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//postorder
void postorder(struct node * root){
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
    
}
//inorder
void inorder(struct node * root){
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
    
}
int main()
{
    struct node *root = create();
    preorder(root);
    return 0;
}
