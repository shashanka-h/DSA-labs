#include <stdio.h>
#include<stdlib.h>
#define MAX 30

int top=-1,temp;
int stack[MAX];

void input(char expr[])
{
  printf("Enter a postfix expression");
    scanf("%s",expr);
}

void push(int num)
{
  top=top+1;
  stack[top]=num;
}

int pop()
{
  int num;
  num=pop();
  top=top-1;
  return num;
}

int evaluatePostfix(char expr[])
{
  int operand1,operand2;
  int i=0;

  while(expr[i])
  {

    if(isspace(expr[i])||(expr[i])==1)
    continue;
    else if(isdigit(expr[i])==1)
    {
      temp=expr[i]-48;
      push(temp);
    }
    else if(expr[i]=='*'||expr[i]=='/'||expr[i]=='+'||expr[i]=='-'||expr[i]=='%')
    {
      operand2=pop();
      operand1=pop();
      switch (expr[i]) {
        case '*':temp=operand1*operand2;
          break;
        case '/':temp=operand1/operand2;
        break;
        case '+':temp=operand1+operand2;
        break;
        case'-':temp=operand1+operand2;
        break;
        case'%':temp=operand1%operand2;
        break;
        push(temp);
      }
    }
    i++;
  }
  return stack[top];

}
