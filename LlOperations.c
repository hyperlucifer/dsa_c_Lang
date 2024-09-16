#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};
void travisal(struct node * ptr){
    while (ptr!=NULL)
    {
        printf("the element is  %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}
struct node * insertAtFirst(struct node *head,int data ){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    return head;
}
struct node * insertAtBetween(struct node *head,int data,int index ){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p= head;
    for (int i = 0; i != index-1; i++)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node * insertAfterNode(struct node *head,struct node *prevnode,int data ){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p= head;
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}
struct node * insertAtEnd(struct node *head,int data ){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p= head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=data;

    return head;
}
struct node * reverce(struct node * head){
    struct node * prev=NULL;
    struct node * curr=head;
    struct node * next;
    while (curr!=NULL)
    {
        next =curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    return prev; 
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=34;
    second->next=third;

    third->data=45;
    third->next=NULL;

    travisal(head);
    // head = insertAtFirst(head,56);
    // head = insertAtBetween(head,24,2);
    // head = insertAtEnd(head,56);
    head = insertAfterNode(head,second,56);
    printf("\nvalue is inserted\n");
    travisal(head);
    struct node * newhead=reverce(head);
    travisal(newhead);
}