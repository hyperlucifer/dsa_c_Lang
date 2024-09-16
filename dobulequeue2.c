#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}*front=NULL,*rear=NULL;

void insert(int data){
    struct node * nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    if (front==NULL)
    {
        front=nn;
        rear=nn;
    }
    else
    {
        rear->next=nn;
        rear=nn;
    }
    
}
void delete(){
    struct node* temp=front;
    struct node* t=front->next;

    int ch;
    printf("\n1 for deletion Begining\n");
    printf("2 for deletion Last\n");
    scanf("%d",&ch);

    if (ch==1)
    {
        front=front->next;
        free(temp);
    }
    else if(ch==2)
    {
        while (t!=rear)
        {
            temp=temp->next;
            t=t->next;
        }
        rear=temp; 
        rear->next=NULL;
        free(t); 
    }
    else if(front==rear)
    {
        front=rear=NULL;
        free(temp);
    }
    
    
}
void display(){
    struct node* temp=front;
    while (temp!=rear)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    delete();
    printf("\n");
    display();
    return 0;
}
