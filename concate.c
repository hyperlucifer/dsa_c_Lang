#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
};
struct node* create(struct node* head,int data){
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
    return head;
}
struct node* cocat(struct node* head1,struct node* head2){
    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next=head2;
}
void uni(struct node* head1,struct node* head2,struct node* head3){
     
     struct node*link2=head2;
     while (head1!=NULL)
        {
            link2=head2;
           while (link2->next!=NULL)
           {
            if (head1->data==link2->data)
            { 
               head3=create(head3,link2->data);
                printf("%d\n",head3->data);
            }
            link2=link2->next;
           }
            head1=head1->next; 
        }
        
}
void display(struct node* head){
    struct node * temp=head;
     while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
}
int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    struct node* head3=NULL;
    printf("the first link is\n");
    head1=create(head1,15);
    head1=create(head1,5);
    head1=create(head1,7);
    head1=create(head1,3);
    display(head1);
    printf("the second link is\n");
    head2=create(head2,15);
    head2=create(head2,5);
    head2=create(head2,7);
    head2=create(head2,9);
    display(head2);
    uni(head1,head2,head3);
    printf("the uni list is \n");
    display(head3);
    return 0;
}
