#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push(int data)
{
    struct node *nn =(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=top;
    top=nn;
}
void display(){
    struct node * temp=top;
    if (top==NULL)
    {
        printf("list is empty");
        return;
    }
    else
    {
        while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        
    }
    
}
void peek(){
     if (top==NULL)
    {
        printf("list is empty");
        return;
    }
    else
    {
        printf("%d",top->data);
    }
    
}
void pop(){
    struct node*temp=top;
    if (top==NULL)
    {
        printf("list is empty");
        return;
    }
    else
    {
        top=top->next;
        free(temp);
    }
    
}
int main()
{
    push(12);
    push(1);
    push(2);
    push(3);
    pop();
    display();
    return 0;
}
