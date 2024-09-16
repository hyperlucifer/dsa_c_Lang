#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define size 30

char s[size];
int top = -1;

void rev(char ch[]){
  int a=0,b=strlen(ch)-1;
  for (int i = 0; i < strlen(ch)/2; i++)
  {
    char t=ch[a];
    ch[a]=ch[b];
    ch[b]=t;
  }
  
}
void push(char ch)
{
  top++;
  s[top] = ch;
}
char pop()
{
  char ch = s[top];
  top--;
  return ch;
}
int priority(char ch)
{
  switch (ch)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
  case '%':
    return 2;
  case '^':
    return 3;
  case '#':
    return 0;
  default:
    return 4;
  }
}
void intoPre(char infix[],char prefix[]){
  int i=0,j=0;
    strrev(infix);
  while (infix[i]!='\0')
  {
    while (priority(infix[i])<=priority(s[top]))
    {
      prefix[j]=pop();
      j++;
    }
    push(infix[i]);
    i++;
  }
  while (s[top]!='#')
  {
    prefix[j]=pop();
    j++;
  }
  prefix[j]='\0';
  strrev(prefix);
}
int main()
{
  char infix[size],prefix[size];
  top++;
  s[top]='#';
  printf("enter the infix exp\n");
  scanf("%s",&infix);
  rev(infix);
  //intoPre(infix,prefix);
  printf("the prefix exp is %s\n",infix);
  return 0;
}
