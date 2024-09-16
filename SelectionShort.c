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
int main()
{
    int a[100],n,i;
    printf("enter the size of array \n");
    scanf("%d",&n);
    printf("enter the elements of array \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    select(a,n);
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
