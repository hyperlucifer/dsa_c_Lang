#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    char email[100];
    int contact;
    char address[150];
    struct node *next;
    struct node *prev;
} *head = NULL;
void create(char name[], char email[], int contact, char address[])
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    strcpy(nn->name, name);
    strcpy(nn->email, email);
    nn->contact = contact;
    strcpy(nn->address, address);
    nn->next = NULL;
    nn->prev = NULL;
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
void insertAtBeg(char name[], char email[], int contact, char address[])
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    strcpy(nn->name, name);
    strcpy(nn->email, email);
    nn->contact = contact;
    strcpy(nn->address, address);
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = nn;
    nn->prev = temp;
    nn->next = head;
    head = nn;
}
void insertAtEnd(char name[], char email[], int contact, char address[])
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    strcpy(nn->name, name);
    strcpy(nn->email, email);
    nn->contact = contact;
    strcpy(nn->address, address);
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = nn;
    nn->prev = temp;
    nn->next = head;
}
void insertAtPos(int pos, char name[], char email[], int contact, char address[])
{
    struct node *nn = (struct node *)malloc(sizeof(struct node)), *temp = head;
    strcpy(nn->name, name);
    strcpy(nn->email, email);
    nn->contact = contact;
    strcpy(nn->address, address);
    if (pos == 1)
    {
        insertAtBeg(name, email, contact, address);
    }
    else if (pos == lengthl())
    {
        insertAtEnd(name, email, contact, address);
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
    if (pos == 1)
    {
        deleteAtBeg();
    }
    else if (pos == lengthl())
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
        p->next = q->next;
        q->prev->prev = p;
        free(q);
    }
}
void display()
{
    struct node *temp = head;
    do
    {
        printf("the name of coustomer %s \n", temp->name);
        printf("the email of coustomer %s \n", temp->email);
        printf("thecontact of coustomer %d \n", temp->contact);
        printf("the address of coustomer %s \n", temp->address);

        temp = temp->next;
    } while (temp != head);
}
int main()
{
    char name[50];
    char email[100];
    int contact;
    char address[150];
    int p;
    int pos;
    int ch;
   do
    {
        printf("\n1.for create a record\n");
        printf("2.for add record on specific postion\n");
        printf("3.for delete record at specific postion\n");
        printf("4for display record\n");
        printf("5.for exit from code\n");

        printf("enter your choise\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            printf("enter the name\n");
            scanf("%s", &name);
            printf("enter the email\n");
            scanf("%s", &email);
            printf("enter the contact number\n");
            scanf("%d", &contact);
            printf("enter the address\n");
            scanf("%s", &address);
           
           create(name, email, contact, address);
            break;

        case 2:
            printf("enter the name\n");
            scanf("%s", &name);
            printf("enter the email\n");
            scanf("%s", &email);
            printf("enter the contact number\n");
            scanf("%d", &contact);
            printf("enter the address\n");
            scanf("%s", &address);
            printf("enter the postion where you want to insert the data\n");
            scanf("%d", &p);
            insertAtPos(p,name, email, contact, address);
            break;
        case 3:

            printf("enter the postion from where you want to delete");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;

        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        }
    }while(ch<=5);

    return 0;
}
