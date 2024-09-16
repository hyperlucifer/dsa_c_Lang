#include<stdio.h>
#include<stdlib.h>
#define size 5

struct node
{
    int data;
    struct node *next ;
}*f=NULL,*r=NULL;

void enqueue(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    if (f==NULL&&r==NULL)
    {
        f=r=nn;
        nn->next=nn;
    }
    int pos;
    printf("\n1.for frount\n2.for rear\n\n");
    scanf("%d",&pos);
    if (pos==2)
    {
        r->next=nn;
        r=nn;
        r->next=f;
    }
    else if (pos==1) 
    {
        nn->next=f;
        f=nn;
        r->next=f;
    }
}
void dequeue()
{
   struct node *temp=f;
   if (f==NULL&&r==NULL)
   {
    printf("underflow");
   }
   else if (f==r)
   {
    f==NULL,r==NULL;
    free(temp);
   }
   else 
   {
    f=f->next;
    r->next=f;
    free(temp);
   }
   
}
void display()
{
   struct node * temp=f;
   do
   {
    printf("%d\n",temp->data);
    temp=temp->next;
   } while (temp!=f);
   
}
int main(int argc, char const *argv[])
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("the elements are\n");
    display();
    return 0;
}
