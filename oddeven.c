#include<stdio.h>
#include<stdlib.h>
void even(int a[],int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2==0)
        {
           sum+=a[i];
        }
        
    }
    printf("the sum of even is %d",sum);
}
void odd(int a[],int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2!=0)
        {
           sum+=a[i];
        }
        
    }
    printf("the sum of odd is %d",sum);
}
int main(int argc, char const *argv[])
{
    int arr[5]={1,3,5,3,2};
    int ch=0;
    do
    {
        printf("\n1.for even\n");
        printf("2.for odd\n");
        printf("3.for exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            even(arr,5);
            break;
        case 2:
            odd(arr,5);
            break;
        case 3:
            exit(0);
            break;
        
        default:
            break;
        }
    } while (1);
    
    return 0;
}
