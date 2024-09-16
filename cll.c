#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void travisal( struct node *head)
{
    struct node *p=head;
    do
    {
        printf("the element is %d\n", p->data);
        p = p->next;
    } while (p != head);
}
struct node * insertAtFirst(struct node* head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p= head->next;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
struct node * insertAtEnd(struct node* head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p= head;
   do
    {
        p = p->next;
    } while (p != head);
    p->next=ptr;
    ptr->next=head;
    ptr->data=data;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 3;
    head->next = second;
    second->data = 5;
    second->next = third;
    third->data = 6;
    third->next = fourth;
    fourth->data = 8;
    fourth->next = head;

    // head=insertAtEnd(head,45);
    head=insertAtFirst(head,56);
    travisal(head);
    return 0;
}
