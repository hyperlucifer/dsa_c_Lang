	#include<stdio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    }*head=NULL;

void lCreate(int x){
    struct node *nm,*temp=head;
    nm=(struct node*)malloc(sizeof(struct node));
    nm->data=x;
    nm->next=NULL;
    if (head==NULL)
    {
        head=nm;
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nm;
}
void addAtBeg(int x){
    struct node *nm;
    nm=(struct node*)malloc(sizeof(struct node));
    nm->data=x;
    nm->next=head;
    head=nm;
}
void addAtPos(int x ,int p){
    int i;
    struct node *temp=head,*nm;
    for ( i = 1; i < p-1; i++)
    {
        if (temp->next==NULL)
        {
            break;
        }
        temp=temp->next;
    }
    nm=(struct node*)malloc(sizeof(struct node));
    nm->data=x;
    nm->next=temp->next;
    temp->next=nm;
}
void lDelete(int x){
    struct node *temp=head,*prev;
    while (temp!=NULL)
    {
        if (temp->data==x)
        {
            if (temp==head)
            {
                head=temp->next;
            }
            else
            {
                prev->next=temp->next;
            }
            printf("node deleted");
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->next;
        
    }
    printf("element not found");
}
void ldisplay(){
    struct node *temp=head;
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    else
    {
        while (temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
        
    }
    printf("\n");
}
int main()
{
    int x,ch,p;
    while (1)
    {
        printf("\n1.for create\n");
        printf("2.addAtBeg\n");
        printf("3.addAtpost\n");
        printf("4.delete\n");
        printf("5.display\n");
        printf("6.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the value\n");
            scanf("%d",&x);
            lCreate(x);
            break;
        case 2:
            printf("enter the value\n");
            scanf("%d",&x);
            addAtBeg(x);
            break;
        case 3:
            printf("enter the value & position\n");
            scanf("%d %d",&x,&p);
            addAtPos(x,p);
            break;
        case 4:
            printf("enter the value\n");
            scanf("%d",&x);
            lDelete(x);
            break;
        case 5:
            ldisplay();
            break;
        case 6:
            exit(0);
        }
    }
    
    return 0;
}
