#include<stdio.h>


    void display(int arr[],int size){
        for (int i = 0; i < size; i++)
        {
            printf("%d  \n",arr[i]);
        }
    }

void Lsearch(int arr[],int element,int size){
    int low=0,high= size-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (arr[mid]==element)
        {
            printf("the element");
            return mid;
        }
        if (arr[mid]<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
}
int main(){

    int arr[]={1,6,2,4,5,10};
    int size =sizeof(arr)/sizeof(int);
    printf("%d",size);
    display(arr,size);
    Lsearch(arr,10,size);
    
}