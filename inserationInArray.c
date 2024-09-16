#include<stdio.h>
void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}
void indinseration(int arr[],int size,int element,int capacity,int index){
    if (size>=capacity)
    {
       return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
int main(){
    int arr[100]={1,4,21,6,43};
    int size=5,element=45,index=3;
    display(arr,size);
    indinseration(arr,size,element,100,3);
    size++;
    display(arr,size);
}