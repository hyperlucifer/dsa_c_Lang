#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

void create(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data = data;
    nn->next = NULL;
    nn->prev = NULL;
    if (head == NULL)
    {
        head =nn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
}
void insertAtBeg(int data){
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=head;
    nn->prev=NULL;
    head->prev=nn;
    head=nn;
}

void insertAtpos(int data,int pos){
    struct node *nn=(struct node *)malloc (sizeof(struct node)),*temp=head;
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    if (pos==1)
    {
        insertAtBeg(data);
    }
    else
    {
        for (int i = 1; i < pos-1; i++)
        {
            temp=temp->next;
        }
        nn->prev=temp;
        nn->next=temp->next;
        temp->next=nn;
        nn->next->prev=nn;
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void insertAtEnd(int data){
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data=data;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nn;
    nn->prev=temp;
    nn->next=NULL;

}
void deleteAtFirst(){
    struct node * temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteAtEnd(){
    struct node * p=head,*q=head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}
void deleteAtPos(int pos){
    struct node * p=head,*q=head->next;
    for (int i =1; i < pos-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    q->next->prev=q->prev;
    free(q);
}
int main()
{
    create(12);
    create(2);
    create(4);
    create(52);
    // insertAtBeg(65);
    // insertAtEnd(90);
    // insertAtpos(32,2);
    deleteAtPos(2);
    display();
    return 0;
}
