#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void create(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data = data;
    if (head == NULL)
    {
        nn->next = nn;
        nn->prev = nn;
        head = nn;
    }
    else
    {
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = nn;
        nn->prev = temp;
        nn->next = head;
    }
}
int lengthl()
{
    int count = 0;
    struct node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
void insertAtBeg(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data = data;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = nn;
    nn->prev = temp;
    nn->next = head;
    head = nn;
}
void insertAtEnd(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data = data;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = nn;
    nn->prev = temp;
    nn->next = head;
}
void insertAtPos(int pos, int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data = data;
    if (pos == 1)
    {
        insertAtBeg(data);
    }
    else if (pos == lengthl())
    {
        insertAtEnd(data);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        nn->next = temp->next;
        nn->prev = temp;
        temp->next = nn;
    }
}

void display()
{
    struct node *temp = head;
    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void deleteAtBeg()
{
    struct node *temp = head, *p = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = head->next;
    head->next->prev = temp;
    head = head->next;
    free(p);
}
void deleteAtEnd()
{
    struct node *p = head, *q = head->next;
    do
    {
        p = p->next;
        q = q->next;
    } while (q->next != head);
    p->next = head;
    head->prev = p;
    free(q);
}
void deleteAtPos(int pos)
{
    struct node *p = head, *q = head->next;
   if (pos==1)
   {
        deleteAtBeg();
   }
   else if (pos==lengthl())
   {
    deleteAtEnd();
   }
   else
   {
     for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    q->prev->prev=p;
    free(q);
   }
   
}
int main()
{
    create(12);
    create(1);
    create(2);
    create(6);
    create(42);
    display();
    printf("gdfgh\n");
    deleteAtPos(3);
    display();
    return 0;
}
