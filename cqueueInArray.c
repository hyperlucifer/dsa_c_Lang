#include <stdio.h>
#include <stdlib.h>
#define size 5

int q[size], f = -1, r = -1;

void enqueue(int x){
    if (f==-1&&r==-1){
        f=r=0;
        q[r]=x;
    }
    else if ((r+1)%size==f)
    {
        printf("overflow");
        return;
    }
    else
    {
        r=(r+1)%size;
        q[r]=x;
    }
}
void dequeue(){
    if (f==-1&&r==-1)
    {
        printf("underflow");
        return;
    }
    else if (f==r)
    {
        f=r=-1;
    }
    else
    {
        f=(f+1)%size;
    }
    
}
void display()
{
    int i=f;
    if (f==-1&&r==-1)
    {
        printf("underflow");
        return;
    }
    else
    {
        while (i!=r)
        {
            printf("%d\n",q[i]);
            i=(i+1)%size;
        }
        printf("%d\n",q[r]);
    }
    
    
}
int main(int argc, char const *argv[])
{
    enqueue(12);
    enqueue(3);
    enqueue(4);
    enqueue(4);
    enqueue(4);
    
    display();

    return 0;
}
