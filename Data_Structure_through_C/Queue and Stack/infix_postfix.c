/**
Name: Kumar shanu
Roll no: 1773513025
**/
//program for convert infix to postfix expression using stack
//for only single digit numbers

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 50
#define BLANK ' '
#define TAB '\t'
int top;
char infix[MAX], postfix[MAX];
long int stack[MAX];
int isEmpty()
{
  if (top == -1)
    return 1;
  else
    return 0;
}
int isFull()
{
  if (top == MAX - 1)
    return 1;
  else
    return 0;
}
void push(char item)
{
  if (isFull())
  {
    printf("Stack Overflow...");
    return;
  }
  top++;
  stack[top] = item;
}
char pop()
{
  if (isEmpty())
  {
    printf("Stack Underflow...");
    return;
  }
  return (stack[top--]);
}
int priority(char symbol)
{
  switch (symbol)
  {
  case '(':
    return 0;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
  case '%':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}
int white_space(char symbol)
{
  if (symbol == BLANK || symbol == TAB)
    return 1;
  else
    return 0;
}
void infix_to_postfix()
{
  int i, p = 0;
  char next;
  char symbol;
  for (i = 0; i < strlen(infix); i++)
  {
    symbol = infix[i];
    if (!white_space(symbol))
    {
      switch (symbol)
      {
      case '(':
        push(symbol);
        break;
      case ')':
        while ((next = pop()) != '(')
          postfix[p++] = next;
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
        while (!isEmpty() && priority(stack[top]) >= priority(symbol))
          postfix[p++] = pop();
        push(symbol);
        break;
      default:
        postfix[p++] = symbol;
      }
    }
  }
  while (!isEmpty())
    postfix[p++] = pop();
  postfix[p] = '\0';
}
long int eval_post()
{
  long int a, b, temp, result;
  unsigned int i;
  for (i = 0; i < strlen(postfix); i++)
  {
    if (postfix[i] <= '9' && postfix[i] >= '0')
      push(postfix[i] - '0');
    else
    {
      a = pop();
      b = pop();
      switch (postfix[i])
      {
      case '+':
        temp = b + a;
        break;
      case '-':
        temp = b - a;
        break;
      case '*':
        temp = b * a;
        break;
      case '/':
        temp = b / a;
        break;
      case '%':
        temp = b % a;
        break;
      case '^':
        temp = pow(b, a);
        break;
      }
      push(temp);
    }
  }
  result = pop();
  return result;
}
void main()
{
  long int value;
  top = -1;
  printf("Enter Infix:\n");
  gets(infix);
  infix_to_postfix();
  printf("Postfix: %s\n", postfix);
  value = eval_post();
  printf("Value of expression: %ld\n", value);
}
