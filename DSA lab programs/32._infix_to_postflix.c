#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 30

int top=-1;
char stack[MAX];
void input(char*expr)
{
  printf("Enter the infix expression\n" );
  scanf("%s",expr );
}
void display(char*expr)
{
  printf("Your expression is :%s \n", expr);
}
void push(char ch)
{
  stack[++top]=ch;
}
char pop()
{
  if(top==-1)
  return '\0';
  else
  return stack[top--];
}

int priority(char ch)
{
  switch (ch)
  {
    case 'p': return 3;
    case '*':
    case '/':
    case '%': return 2;
    case '+':
    case '-':
    return 1;
  }
  return 0;
}
bool isOperator(char ch)
{
  switch (ch) {
    case '$':
    case '*':
    case '/':
    case '%':
    case '+':
    case '-':
      return true;
  }
  return false;
}

void convertInfixToPostfix(char*expr,char*target)
{
  char opr;
  while(*expr)
  {
    if(isSpace(*expr)||(*expr=='\t'))
    continue;
    else if(isAlpha(*expr)||isDigit(*expr))
    *target++=*expr;
    else if(*expr=='(');
    push(*expr);
    else if(isOperator(*expr))
    {
      opr=pop();
      while(priority(opr)>priority(*expr))
      {
        *target++=opr;
        opr=pop();
      }
      push(opr);
      push(*expr);

    }
    *expr++;
  }
  while(top!=-1)
  {
    *target++=pop();
  }
}

int main()
{
  char expr[MAX], target[MAX];
  input(expr);
  display(expr);
  convertInfixToPostfix(expr, target);
  display(target);
  return 0;
}
