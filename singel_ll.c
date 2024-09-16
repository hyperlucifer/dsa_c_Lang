#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
}*head=NULL;
void create(int data){
    struct node * temp=head,*nn;
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    if (head==NULL)
    {
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
void display(){
    struct node * temp=head;
     while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
}
void insertAtBegg(int data){
    struct node * nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=head;
    head=nn;
}
int length(){
    int count=0;
    struct node *temp=head;
    while (temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
}
void insertAtpos(int data,int pos){
    struct node * nn,*temp=head;
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
   if (length()<pos)
   {
    printf("invalide position");
    return;
   }
   else
   {
     for (int i = 1; i < pos; i++)
    {
        temp=temp->next;
    }
    nn->next=temp->next;
    temp->next=nn;
   }
}
void insertAtEnd(int data){
    struct node * nn,*temp=head;
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nn;
    
}
void deleteAtBeg(){
    struct node *temp=head;
    head=head->next;
    free(temp);
}
void deleteAtEnd(){
    struct node *temp=head,*p;
    while (temp->next!=NULL)
    {
        p=temp;
        temp=temp->next;
    }
    p->next=NULL;
    free(temp);
}
void deleteAtPos(int pos){
     struct node *temp=head,*p;
     int i=1;
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    p=temp->next;
    temp->next=p->next;
    free(p);
}
void reverse(){
    struct node *p,*c,*n;
    p=NULL;
    c=n=head;
    while (n!=NULL)
    {
        n=n->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}
void first_to_last(){
    struct node *p=head,*temp;
    head=head->next;
    p->next=NULL;
    temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;

}

int main()
{
    create(12);
    create(1);
    create(2);
    // insertAtBegg(5);
    // insertAtpos(7,2);
    // insertAtEnd(8);
    // deleteAtBeg();
    // deleteAtPos(2);
    // reverse();
    display();
    printf("after\n");
    first_to_last();
    display();
    return 0;
}
