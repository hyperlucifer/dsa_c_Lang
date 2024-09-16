#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *f = NULL, *r = NULL;
void enqueue(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data=data;
    temp->next = NULL;
    if (f == NULL)
    {
        f = temp;
        r = temp;
    }
    else
    {
       r->next=temp;
       r=temp;
    }
}
void dequeue()
{
    struct node *temp = f;
    f = f->next;
    free(temp);
}
void display(){
    struct node *temp = f;
   while (temp!=r)
   {
    printf("%d\n",temp->data);
    temp=temp->next;
   }
   
    

}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    printf("\n");
   dequeue();
   display();

    return 0;
}