#include<stdio.h>
#include<stdlib.h>
int s[100],top=-1,size;
void push (int n){
    if (top==size-1)
    {
        printf("the stack is full");
        return;
    }
    else
    {
        top++;
        s[top]=n;
    }
}
int poop (){
    if (top==-1)
    {
        printf("the stack is empty");
    }
    else
    {
        int n=s[top];
        top--;
        return n;
    }
    
}
void display(){
    if (top==-1)
    {
        printf("the stack is empty");
    }
    else
    {
        for (int i = top; i > 0; i--)
        {
            printf("%d",s[i]);
        }
        
    }
    
}
void peek(){
     if (top=-1)
    {
        printf("the stack is empty");
    }
    else
    {
        printf("%d",top);
    }
    
}
int main()
{
    int ch,x,y;
    printf("enter the size\n");
    scanf("%d",&size);
    while (1)
    {
        printf("1.for push\n");
        printf("2.for delete\n");
        printf("3.for display\n");
        printf("4.for peek\n");
        printf("5.for exit\n");

        printf("enter your choice\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("enter the value\n");
            scanf("%d",&x);
            poop(x);
            break;
        
        case 2:
              y=poop();
        if (y!=-1)
        {
            printf("the poped value is %d\n",y);
        }
        break;
        case 3:
        display();
        break;
        case 4:
        peek();
        break;
        case 5:
            exit(0);
        }
    }
    
    
    return 0;
}
