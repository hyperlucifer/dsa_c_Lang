#include <stdio.h>
#include <string.h>

int main()
{
    char name[50] = "sheth lok";
    int n = strlen(name);
    int s = 0;
    
    for (int i = 0; i <= n / 2; i++)
    {
        char temp = name[s];
        name[s] = name[n];
        name[n] = temp;
        n--;
        s++;
    }
    for (int i = 0; i <= 9; i++)
    {
        printf("%c", name[i]);
    }

    return 0;
}
