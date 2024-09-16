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

}