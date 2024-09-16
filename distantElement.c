#include<stdio.h>
int main()
{
    int arr[5]={4,3,5,3,9};
    int count=0;
    for (int i = 0,j = i+1; i < 5,j < 5; i++,j++)
    {
         if (arr[i]!=arr[j])
            {
                count++;
            }
        
    }
    printf("%d\n",count);
    
    return 0;
}
//remming