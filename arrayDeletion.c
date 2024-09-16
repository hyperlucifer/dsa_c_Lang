#include<stdio.h>
void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    
}
void indDeletion(int arr[],int size,int index){
    
    for (int i = index; i< size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    
    return 1;
}
int main(){
    int arr[100]={1,4,21,6,43};
    int size=5,index=3;
    display(arr,size);
    indDeletion(arr,size,3);
    size--;
    printf("\n");
    display(arr,size);
}