#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char item)
{
   if (top >= MAX - 1)
   {
      cout << "\nStack Overflow.";
   }
   else
   {
      top = top + 1;
      stack[top] = item;
   }
}

char pop()
{
   char item;
   if (top < 0)
   {
      cout << "\nStack Underflow: invalid infix expression";
      return 0;
   }
   else
   {
      item = stack[top];
      top = top - 1;
      return (item);
   }
}

int is_operator(char symbol)
{
   if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int get_next_token(char symbol)
{
   if (symbol == '^')
   {
      return (3);
   }
   else if (symbol == '*' || symbol == '/')
   {
      return (2);
   }
   else if (symbol == '+' || symbol == '-')
   {
      return (1);
   }
   else
   {
      return (0);
   }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
   int i, j;
   char item;
   char x;

   push('(');
   strcat(infix_exp, ")");

   i = 0;
   j = 0;
   item = infix_exp[i];

   while (item != '\0')
   {
      if (item == '(')
      {
         push(item);
      }
      else if (isdigit(item))
      {
         postfix_exp[j] = item;
         j++;
      }
      else if (is_operator(item) == 1)
      {
         x = pop();
         while (is_operator(x) == 1 && get_next_token(x) >= get_next_token(item))
         {
            postfix_exp[j] = x;
            j++;
            x = pop();
         }
         push(x);

         push(item);
      }
      else if (item == ')')
      {
         x = pop();
         while (x != '(')
         {
            postfix_exp[j] = x;
            j++;
            x = pop();
         }
      }
      else
      {
         cout << "\nInvalid infix Expression.\n";
         return;
      }
      i++;
      item = infix_exp[i];
   }
   if (top > 0)
   {
      printf("\nInvalid infix Expression.\n");
      getchar();
      exit(1);
   }

   postfix_exp[j] = '\0';
}

int main()
{
   char infix[MAX], postfix[MAX];

   cout << "\nEnter Infix expression : ";
   cin.getline(infix, MAX);

   InfixToPostfix(infix, postfix);
   cout << "Postfix Expression: " << postfix;

   return 0;
}