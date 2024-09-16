#include<stdio.h>


void dublicate(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]==arr[j])
            {
                printf("true\n");
                return ; 
            }
            
        }
        
    }
    printf("false\n");
    return ;
}
void setdata(int arr[],int size){
    printf("enter the element of array \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
}
int main()
{
    int size1 =5;
    int arr[size1];
    setdata(arr,size1);
    dublicate(arr,size1);
    

    return 0;
}
