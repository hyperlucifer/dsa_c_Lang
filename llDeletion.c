#include<stdio.h>
#include<stdlib.h>
//reaming
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
//deleting the first node
struct node * deletingFirst(struct node * head){
    struct node * ptr =head;
    head=head->next;
    free(ptr);
    return head;
}
//deletindg at index
struct node * deletingAtIndex(struct node * head,int index ){
    struct node * p =head;
    struct node * q =head->next;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    
    return head;
}
//deletindg at index
struct node * deletinglastElement(struct node * head){
    struct node * p =head;
    struct node * q =head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    
    return head;
}
//deleting given element
struct node * deletingelement(struct node * head,int value ){
    struct node * p =head;
    struct node * q =head->next;
    while(q->data!=value &&q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if (q->data==value)
    {
         p->next=q->next;
         free(q);
    }
    
    return head;
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
//    head= deletingAtIndex(head,1);
    head=deletingFirst(head);
    // head=deletinglastElement(head);
    //head=deletingelement(head,34);
    printf("after deletion\n");
    travisal(head);
}