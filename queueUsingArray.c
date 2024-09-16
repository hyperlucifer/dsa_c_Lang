#include<stdio.h>
#include<stdlib.h>
#define size 10
int q[size],f=-1,r=-1;

void unqueue (int data){
    if (r==size-1)
    {
        printf("overflow\n");
        return ;
    }
    
    if (f==-1&&r==-1){
        f=0;r=0;
        q[r]=data;
    }
    else
    {
        r++;
        q[r]=data;
    }
    
}
void dequeue(){
    if(r==-1&&f==-1){
        printf("underflow");
        return ;
    }  
    else
    {
        f++;
    } 
}
void display(){
    for (int i = f; i <=r; i++)
    {
        printf("%d\n",q[i]);
    }
    
}
void reverce(){
    int s=f,l=r;
    int t;
    while (s<r)
    {
        t=q[s];
        q[s]=q[l];
        q[l]=t;
        s++;
        l--;
    }
    
}
int main()
{
    unqueue(2);
    unqueue(1);
    unqueue(3);
    unqueue(4);
    unqueue(25);
    unqueue(61);
    dequeue();
    display();
    return 0;
}
