//program for checking the nesting of parantheses using stack

#include <stdio.h>
#include <string.h>
#define MAX 30
int top = -1;
int stack[MAX];
void push(char item)
{
  if (top == MAX - 1)
  {
    printf("Stack Overflow....");
    return;
  }
  top++;
  stack[top] = item;
}
char pop()
{
  if (top == -1)
  {
    printf("Stack Underflow....");
    return;
  }
  return (stack[top--]);
}
int match(char a, char b)
{
  if (a == '[' && b == ']')
    return 1;
  if (a == '{' && b == '}')
    return 1;
  if (a == '(' && b == ')')
    return 1;
  return 0;
}
int check(char exp[])
{
  int i;
  char temp;
  for (i = 0; i < strlen(exp); i++)
  {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
      push(exp[i]);
    if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
      if (top == -1)
      {
        printf("Right parantheses are more than left\n");
        return 0;
      }
      else
      {
        temp = pop();
        if (!match(temp, exp[i]))
        {
          printf("Missmatched parantheses are :");
          printf("%c and %c\n", temp, exp[i]);
          return 0;
        }
      }
  }
  if (top == -1)
  {
    printf("Balanced parantheses\n");
    return 1;
  }
  else
  {
    printf("Left parantheses are more than right parantheses\n");
    return 0;
  }
}
void main()
{
  char exp[MAX];
  int valid;
  printf("Enter an algebric expression :\n");
  gets(exp);
  valid = check(exp);
  if (valid == 1)
    printf("Valid expression\n");
  else
    printf("Invalid expression\n");
}
