#include<stdio.h>
#include<math.h>
int main()
{
    int a[5];
    scanf("%d",&a);
    int squ[5];
    for (int i=0,j = 0; i<5,j< 5; j++,i++)
    {
        squ[i]=pow(a[j],2);
    }
    printf("the original array is \n ");
    for (int i = 0; i < 5; i++)
    {
       printf("%d\t",a[i]);
    }
    printf("\nthe square of given array is \n");
    for (int i = 0; i < 5; i++)
    {
       printf("%d\t",squ[i]);
    }
    
    return 0;
}
