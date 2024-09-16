/*
properties of BST

1)all the nodes of left subtree are smaller then root
2)all the nodes of right subtree are greater then root
3)left and right subtree are also binery scearch trees
4)there are no dublicate nodes
5)inorder travical of a binary scearch tree gives an assanding sorted array
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
}
//travisal there is three type of travisal 
/*
1)inorder---->left root right
2)preorder--->root left right
2)postorder--->left right root
*/
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\n", root->data);
        inOrder(root->right);
    }
}
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    printf("this is recrivse function");
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}
struct node *search_iear(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}
void insert(struct node *root, int key)
{
    //prev is the node that is parant of the current root node
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("cannot insert ");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = create(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
// For deletion in tree

struct node *inOrderpre(struct node *root)
{
    //this funcation is used to find our the inorder 
    //predisser of the node that is been passed
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return NULL;
}
struct node *deletenode(struct node *root, int value)
{    
    //1)when the node is leaf node then just search node and delete it
    //2)when the node is not a leaf but leaf nodes paraent then
    //replace it with it's inorder predesser or postdesser
    //3)when deleting root node / node in between    
    //replace it with it's inorder predesser or postdesser
    //and keep repeating this process until there is no empty node 
    //in the tree


    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    //if only single node is present
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    //searching the node
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    //deletion strategy when the node is found
    
    else
    {
        ipre = inOrderpre(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}
int main()
{
    struct node *p = create(5);
    struct node *p1 = create(3);
    struct node *p2 = create(6);
    struct node *p3 = create(1);
    struct node *p4 = create(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    // inOrder(p);
    // insert(p, 7);
    // printf("%d\n", p->right->right->data);
    deletenode(p,6);
    inOrder(p);
    return 0;
}

