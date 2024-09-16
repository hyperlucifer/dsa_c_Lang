#include <stdio.h>
int main()
{
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2,sum;
    printf("enter the order of first matrix \n");
    scanf("%d%d", &r1, &c1);
    printf("enter the order of secound matrix \n");
    scanf("%d%d", &r2, &c2);
   
    if (r1 == r2 && c1 == c2)
    {
        printf("enter the elements of first matrix \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                scanf("%d", &a[i][j]);
            }
            printf("\n");
        }
        printf("enter the elements of second matrix \n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                scanf("%d", &b[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < r2; i++)
        {sum=0;
            for (int j = 0; j < c2; j++)
            {
                sum = a[i][j] + b[i][j];
                c[i][j]=sum;
            }
        }
        printf("the sum of the matrix is = \n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("addition is not possiable");
    }
    return 0;
}
