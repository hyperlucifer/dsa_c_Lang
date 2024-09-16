#include<stdio.h>
#include<string.h>
char ispal(char s[],int l,int r){
    if (l>=r)
    {
        printf("string is paladrome "); 
        return 1;

    }

    if (s[l]!=s[r])
    {
        return ispal(s,l+1,r-1);
    }
    
}
int main()
{
    char orig[100]; 
    gets(orig);
    int l=0;
    int r=strlen(orig);
    ispal(orig,l,r);
    return 0;
}
