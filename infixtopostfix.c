/*
rules-->
    1)Print operands as they arrive.
    2)If the stack is empty or contains a left paranthesis on top ,
      push the incoming opertor into the stack.
    3)If the incoming symbol is '(' push it into the stack.
    4)If the incoming symbol is ')' pop the stack &print the operator
      until the left parantheius is found.
    5)If incoming symbol has higher precendence then the top of the stack ,
      push it on the stack.
    6)If incoming symbol has lower precendence then the top of the stack ,
      pop & print the top.then test the incoming operator against the new top of stack
    7)incoming symbol has equal precendence whith the top of the stack then pop ,
      then pop and print the top & then push incoming operator.
*/
#include <stdio.h>
#include <string.h>
#define size 30

char s[size];
int top = -1;

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
void intoPost(char infix[],char postfix[]){
  int i=0,j=0;

  while (infix[i]!='\0')
  {
    while (priority(infix[i])<=priority(s[top]))
    {
      postfix[j]=pop();
      j++;
    }
    push(infix[i]);
    i++;
  }
  while (s[top]!='#')
  {
    postfix[j]=pop();
    j++;
  }
  postfix[j]='\0';
  
}
int main()
{
  char infix[size],postfix[size];
  top++;
  s[top]='#';
  printf("enter the infix exp\n");
  gets(infix);
  intoPost(infix,postfix);
  printf("the postfix exp is %s\n",postfix);
  return 0;
}
