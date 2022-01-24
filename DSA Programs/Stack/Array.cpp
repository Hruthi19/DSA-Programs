#include <iostream>
using namespace std;

const int MAX = 100;
int stack[MAX], top = -1;

void push(int val)
{
   if (top == MAX)
      cout << "Stack is full";
   else
   {
      top = top + 1;
      stack[top] = val;
   }
}

void pop()
{
   if (top < 0)
      cout << "\nStack is empty.Item cannot be deleted";
   else
   {
      int item;
      item = stack[top];
      top--;
      cout << "\n"
           << item << " element popped out";
   }
}

void display()
{
   cout << "\nThe values are: \t";
   for (int i = top; i >= 0; i--)
   {
      cout << stack[i] << "\t";
   }
   if (top < 0)
   {
      cout << "\nStack is empty";
   }
}

int main()
{
   int choice, val;
   while (choice != 4)
   {
      cout << "\n1. Addition of stack: ";
      cout << "\n2. Deletion of stack: ";
      cout << "\n3. Traverse the stack: ";
      cout << "\n4. Exit";
      cout << "\nEnter choice: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         int n;
         cout << "Enter the value: ";
         cin >> val;
         push(val);
         break;

      case 2:
         pop();
         break;

      case 3:
         display();
         break;

      case 4:
         cout << "Exciting the program";
         break;

      default:
         cout << "Wrong input!";
         break;
      };
      cout << endl;
   };

   return 0;
}
