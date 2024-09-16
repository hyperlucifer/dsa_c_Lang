#include <stdio.h>
int short1(int arr[],int size1)
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
   int l;
   for (int i = 0; i <= 2; i++)
   {
      l=arr[i];
   }
   return l;
   
}
int main()
{
    int size1;
    printf("enter the size");
    scanf("%d\n", &size1);
    int height[size1];
    printf("enter the elements\n");
    for (int i = 0; i <= size1; i++)
    {
        scanf("%d", &height[i]);
    }
    int max=height[0];
    for (int i = 0; i < size1; i++)
    {
        if (max<height[i])
        {
            max=height[i];
            printf("%d",i);
        }
        
    }
    printf("the first maximum index is %d\n",max);
    int max2=short1(height,size1);
    
    printf("the second maximum index is %d\n",max2);
}