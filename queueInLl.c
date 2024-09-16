#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
}*head=NULL;
void enque(int data){
    struct node* nn= (struct node *)malloc(sizeof(struct node)),*temp=head;
    nn->data=data;
    nn->next=NULL;
    if (head==NULL){
        head=nn;
    }
    else{
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
    }
}
void dequeue(){
    struct node * f=head;
    head=head->next;
    free(f);
}
void display(){
    struct node * f=head;
    while (f!=NULL)
    {
        printf("%d\n",f->data);
        f=f->next;
    }
    
}
int main()
{
    enque(12);
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    dequeue();
    display();
    return 0;
}
