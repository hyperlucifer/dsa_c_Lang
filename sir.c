#include<stdio.h>
#include <math.h>
// Given two numbers 'N' and 'S' , find the largest number that can be
// formed with 'N' digits and whose sum of digits should be
// equals to 'S'. Return -1 if it is not possible.
// Example 1:
// Input: N = 2, S = 9 Output: 90 Explaination: It is the biggest number with
// sum of digits equals to 9.
// Example 2:
// Input: N = 3, S = 20 Output: 992 Explaination: It is the biggest number 
// with sum of digits equals to 20.
// Your Task:
// You do not need to read input or print anything. Your task is to complete
// the function findLargest() which takes N and S as input parameters and
// returns the largest possible number. Return -1 if no such number is possible.
void findLirgest(int n,int s){
   for (int i = 0; i <= 9*n; i++)
   {
    
    int t=i;
    
    int sum=0;
    while (i!=0)
    {
        int m=i%10;
        sum+=m;
        i/=10;
    }
    if (s==sum)
    {
       
    }
    
   }
   
}

int main()
{
    findLirgest(2,9);
    return 0;
}
