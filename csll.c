#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data = data;
    nn->next = NULL;
    if (head == NULL)
    {
        head = nn;
        nn->next = head;
    }
    else
    {
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = nn;
        nn->next = head;
    }
}
void insertAtBeg(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    nn->data = data;
    nn->next = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = nn;
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
    nn->next = head;
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
        temp->next = nn;
    }
}
void deleteAtbeg()
{
    struct node *p = head, *temp = head;

    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = head->next;
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
    free(q);
}
void deleteAtPos(int pos)
{
    struct node *temp = head, *p = head->next;
    if (pos == 1)
    {
        deleteAtbeg();
    }
    else if (pos == lengthl())
    {
        deleteAtEnd();
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            p = p->next;
        }
        temp->next = p->next;
        free(p);
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

int main(int argc, char const *argv[])
{
    create(21);
    create(1);
    create(2);
    create(1);
    display();
    printf("asdytf\n");
    deleteAtPos(2);
    display();
    return 0;
}
