#include<stdio.h>

void select(int a[],int n){

    int i,min_post,j,temp;
    for ( i = 0; i < n-1; i++)
    {
        min_post=i;
        for ( j = i+1; j < n; j++)
        {
            if (a[min_post]>a[j])
            {
                min_post=j;
            }
            if (min_post!=i)
            {
                temp=a[i];
                a[i]=a[min_post];
                a[min_post]=temp;
            }   
        }   
    }
}
void pair(int arr[],int n,int sum){
    int f=0;
    for(int i =0 ;i<n;i++){
        for (int j = i; j < n; j++)
        {
            if (arr[i]+arr[j]==sum)
            {
                printf("true");
                f=1;
            }
            if (f==1)
            {
                return;
            }
            
        }
        if (f==1)
            {
                return;
            }
    }
    printf("false");
}
int main()
{
    int sum;
    scanf("%d",&sum);
    int arr[5]={12,34,21,54,67};
    select(arr,5);
    pair(arr,5,sum);

    return 0;
}
