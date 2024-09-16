#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*top=NULL;
void push(int data)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node)),*temp=top;
    nn->data=data;
    nn->next=NULL;
    if(top==NULL)
    {
        top=nn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            
        }
    }
}