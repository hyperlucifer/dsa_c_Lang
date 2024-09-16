#include<stdio.h>
#include<stdlib.h>
int q[100],f=-1,r=-1,size;

void qInsert(int x){
    if (r==size-1)
    {
        printf("the queue is full");
        return;
    }
    else
    {
        r++;
        q[r]=x;
    }
    if (f==-1)
    {
        f=0;
    }
}
int isFull(){
	 if (r==size-1)
    {
        printf("the queue is full");
        return;
    }
}
int qDelete(){
    int x;
    if(f=-1){
        printf("the queue is underflow");
        return -1;
    }
    else
    {
        x=q[f];
    }
    if (r==f)
    {
        f=r=-1;
    }
    else
    {
        f++;
    }
    return x;
}
int isEmpty(){
	if(f=-1){
        printf("the queue is empty");
        return -1;
    }
}
void dispay(){
    if (f=-1)
    {
        printf("the queue is emepty");
    }
    else
    {
        for (int i = f; i < r; i++)
        {
            printf("%d",q[i]);
        }
    }
    
}
int main()
{
    int ch,x,y;
    printf("enter your size\n");
    scanf("%d",&size);
    while (1)
    {
        printf("\n1.for insert element in queue\n");
        printf("\n2.for delete element in queue\n");
        printf("\n3.for display element in queue\n");
        printf("\n4.for exit \n");

        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter the element\n");
            scanf("%d",&x);
            qInsert(x);
            break;
        case 2:
            y=qDelete();
            if (y!=-1)
            {
                printf("Deleted value is %d\n",y);
            }
            break;
        case 3:
            dispay();
            break;
        case 4:
            exit(0);
        
        }
        
    }
    
    return 0;
}
