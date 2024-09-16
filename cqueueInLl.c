#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}*rear=NULL,*frout=NULL;
void push(int data)
{
    struct node * nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    if (frout==NULL)
    {
        frout=rear=nn;
        nn->next=rear;
    }
    else
    {
        rear->next=nn;
        rear=nn;
        rear->next=frout;
    }
    
    
}
void pop()
{
   struct node *temp=frout;
   if (frout==NULL&&rear==NULL)
   {
    printf("underflow");
   }
   else if (frout==rear)
   {
    frout==NULL,rear==NULL;
    free(temp);
   }
   else 
   {
    frout=frout->next;
    rear->next=frout;
    free(temp);
   }
   
}
void display()
{
   struct node * temp=frout;
   do
   {
    printf("%d\n",temp->data);
    temp=temp->next;
   } while (temp!=frout);
   
}
int main()
{
   push(1);
   push(2);
   push(3);
   push(4);
   pop();
   display();
}