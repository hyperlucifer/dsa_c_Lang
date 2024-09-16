#include<stdio.h>

void short1(int arr[],int size1)
{
   for (int i = 0; i < size1; i++)
   {
      if (arr[i]<arr[i+1])
      {
         int temp;
         temp=arr[i];
         arr[i]=arr[i+1];
         arr[i+1]=temp;
      }
      
   }
}
void display(int arr[],int k){
   int l;
   for (int i = 0; i < k; i++)
   {
      l=arr[i];
   }
   printf("The kth element id %d",l);
}
int main()
{
   int size=5;
   int k;
   printf("enter the array element\n");
   int arr[5];
   for(int i=0; i<5; i++){
      scanf("%d",&arr [i]);
   }
   printf("enter the kth element\n");
   scanf("%d",&k);
   short1(arr,size);
   display(arr,k);

   return 0;
}


