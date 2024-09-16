#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
   struct node *prev;
}*head=NULL;

void create(int x){
    struct node *nn,*temp=head;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=x;
    nn->next=NULL;
    if (head==NULL)
    {
        head=nn;
        nn->prev=NULL;
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
        temp->next=nn;
        nn->prev=nn;
        return;
    }
}
void addatbeg(int x){
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=x;
    nn->next=head;
    nn->prev=NULL;
    if (head!=NULL)
    {
        head->prev=nn;
        head=nn;
    }

}
void addatpost(int x,int p){
    struct node *temp=head,*nn;
    int i;
    if (p<=1)
    {
        addatbeg(x);
        return;
    }
    for ( i = 1; i <p-1; i++)
    {
        if (temp->next==NULL)
        {
            break;
        }
        temp=temp->next;
        
    }
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=x;
    nn->next=temp->next;
    nn->prev=temp;
}
void display(){
    struct node *temp=head;
    if (head=NULL)
    {
        printf("the list is empty");
        return;
    }
    while (temp->next!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int x,ch;
    while (1)
    {
        printf("1.for create\n");
        printf("2.for addatbeg\n");
        printf("3.for display\n");
        printf("enter your choice \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the value");
            scanf("%d",&x);
            create(x);
            break;
        case 2:
            printf("enter the value");
            scanf("%d",&x);
            create(x);
        case 3:
            display();
        }
    }
    
    return 0;
}
