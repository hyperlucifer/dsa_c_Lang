#include<stdio.h>

int main()
{
    int arr[5]={6,2,3,4,5};
    int b=10;
    //the name of arr itself is a base address of arr
    //'*'->is a dereferancing operator 
    printf("%d \n",*arr);
    printf("%d \n",*arr+1);
    printf("%d \n",arr[1]);
    printf("%d \n",1[arr]);
    printf("%d \n",*(arr+1));
    printf("%d \n",*arr+1);
    int *q;
    //the poiner q cointans the address of variable 
    //and the datatype of that variable is int
    //q is a pointer to int
    //to print the address %p format specifier is used
    printf("%p\n",&arr);
    //you can only store the address of variable in array as bellow
    q=&b;
    //q=b -->this is wrong way because it store value of b in the pointer var
    return 0;
}
