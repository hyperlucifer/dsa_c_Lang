#include<stdio.h>
//remaining;
void short1(int array[],int size)
{
   int i, j, temp;

  for (i = 0; i < size - 1; i++) {
    for (j = i + 1; j < size; j++) {
      if (array[i] > array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}
void display(int arr[],int size1){
     for (int i = 0; i <size1; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[5]={12,4,1,88,56};
    int m=3;
    int min;
    int min2;
    short1(arr,5);
    int diff;

    for (int i = 0; min2 < 5; i++,min2++)
    {
        min=arr[i];
        min2=arr[i+m-1];
        diff= arr[i + m - 1] - arr[i];
    }
    printf("%d",diff);
    

    
    
    return 0;
}
