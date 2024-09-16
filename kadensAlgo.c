#include<stdio.h>

int maxSubArray(int a[],int size){
    int maxsum=0;
    int currentsum=0;
    for (int i = 0; i < size; i++)
    {
        currentsum=currentsum+a[i];
        if (currentsum>maxsum)
        {
            maxsum=currentsum;
        }
        if (currentsum<0)
        {
            currentsum=0;
        }
    }
    return maxsum;
}

int main()
{
    int size=5;
    int arr[5]={-1,3,-5,6,-3};
    int k=maxSubArray(arr,size);
    printf("%d\n",k);
    return 0;
}
