#include <stdio.h>
#include <stdlib.h>
/*
* need of AVL tree

1)Almost all the operations in bst are of order of O(h) 
  where the h is height of a tree 
2)If we don't plan our tree properly,this height can get as high as n 
  is the total number of nodes in a bst
3)To gurantee an upper bond of O(log n) fo all of these operations ,
  we use AVL(balance tree).

* what is AVL tree?
Height difference between of left and and right subtrees for every node 
is >=1
* the formula is 
   Balance factor =height of right subtree - height of left subtree

* rotations 
  there are 4 types of rotations 
  1)LL->left left
  eg      5
         / 
        4
       /
      3  

    =      4
          / \
         3   5
  2)RR->right right 
  eg      6
           \
            7
             \
              8
    =
          7
         / \
        6   8
  3)LR->left right 
  eg      6
         / 
        4
         \
          5
    
    = first rotation is left between 4 and 5
         
          6
         / 
        5
       /
      4
    
    = second rotation is right 

        5
       / \
      4   6

  4)RL->right left 
  eg      7
           \
            11
           /
          10

    = first rotation is right between 10 and 11
          
          7
           \
            10
             \
              11

    = second rotation is left 
           
           10
          /  \
         7    11


Rotate operation
1)Left rotate with respect to node->node moves towards the left
2)Right rotate with respect to node->node moves towards the right

*) for inseration in AVL tree and balance the tree

1)for left-left inseration = Right rotate once with respect the first imbalance node
2)for Right-Right inseration = left rotate once with respect the first imbalance node
3)for left-Right inseration = left rotate once and then right rotate once
4)for Right-left inseration = Right rotate once and then left rotate once


*/
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int hight;
};
int gethight(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return p->hight;
    }
}
int getbalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return gethight(n->left) - gethight(n->right);
}
struct node *create(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->hight = 1;
    return node;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
/*
      for right rotation
      of the following tree

           y
          / \
         x   t3
        / \
       t1  t2
  
     we should get the following tree

            x
           / \
          t1  y
             / \
            t2  t3
*/
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->hight = max(gethight(y->right), gethight(y->left)) + 1;
    x->hight = max(gethight(x->right), gethight(x->left)) + 1;

    return x;
}
/*
      for left rotation
      of the following tree           
            x
           / \
          t1  y
             / \
            t2  t3
     we should get the following tree

           y              
          / \         
         x   t3
        / \
       t1  t2
*/
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->hight = max(gethight(y->right), gethight(y->left)) + 1;
    x->hight = max(gethight(x->right), gethight(x->left)) + 1;

    return y;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return create(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    node->hight = 1 + max(gethight(node->left), gethight(node->right));
    int bf = getbalanceFactor(node);
    // left left case
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }
    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    // left right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // right left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\n", root->key);
        inOrder(root->right);
    }
}
int main()
{
    struct node * root =NULL;

    root =insert(root,31);
    root =insert(root,1);
    root =insert(root,12);
    root =insert(root,36);
    root =insert(root,98);
    root =insert(root,23);
    inOrder(root);
    return 0;
}
