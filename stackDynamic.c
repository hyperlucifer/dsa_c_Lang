#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if (ptr->top==-1){
      return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *ptr){
    if (ptr->top==ptr->size-1)
     {
      return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack *ptr,int x){
    if(isfull(ptr)){
        printf("the stack is overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->size]=x;
    }
    
}
int pop (struct stack * ptr){
    if(isEmpty(ptr)){
        printf("the stack underflow ");
        return -1;
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return printf(" the poped value is %d\n",val);
    }
}
void peek(struct stack *ptr,int i){
    if (ptr->arr[ptr->top-i+1]<0)
    {
        printf("invalid position in stack");
    }
    else
    {
        printf("%d",ptr->arr[ptr->top-i+1]);
    }
    
    
}
void display(struct stack * ptr){
    if (isEmpty(ptr))
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        for (int i = ptr->top ;i >=0; i--)
    {
       return printf("%d\n",ptr->arr[i]);
    }
    }
    
   
    
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size = 8;
    s->top= -1;
    s->arr=(int*)malloc(s->size * sizeof(int));
    printf("stack has been created \n");
   
    
    return 0;

}
