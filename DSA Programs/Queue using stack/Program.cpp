#include <iostream>
using namespace std;

#define N 5
int stack1[5], stack2[5];

int top1 = -1, top2 = -1;
int count = 0;

void push1(int data)
{

   if (top1 == N - 1)
   {
      cout << "\n Stack is overflow...";
   }
   else
   {
      top1++;
      stack1[top1] = data;
   }
}

int pop1()
{

   if (top1 == -1)
   {
      cout << "\nStack is empty..";
   }
   else
   {
      int a = stack1[top1];
      top1--;
      return a;
   }
}

void push2(int x)
{

   if (top2 == N - 1)
   {
      cout << "\nStack is full..";
   }
   else
   {
      top2++;
      stack2[top2] = x;
   }
}

int pop2()
{
   int element = stack2[top2];
   top2--;
   return element;
}

void enqueue(int x)
{

   while (top1 != -1)
   {
      push2(pop1());
   }
   push1(x);
   while (top2 != -1)
   {
      push1(pop2());
   }
}

void dequeue()
{
   int element = stack1[top1];
   top1--;
   cout << "Deleted element: " << element << endl;
}

void display()
{
   cout << "\n";
   for (int i = top1; i >= 0; i--)
   {
      cout << stack1[i] << " ";
   }
}
int main()
{
   int choice = 1, x;

   while (choice != 4)
   {
      cout << "\n1.Insert\n2.Delete\n3.Display\n4.Quit";
      cout << "\nEnter choice: ";
      cin >> choice;

      switch (choice)
      {
      case 1:
         cout << "Enter the element which is to be inserted";
         cin >> x;
         enqueue(x);
         break;
      case 2:
         dequeue();
         break;
      case 3:
         display();
         break;
      case 4:
         break;

      default:
         cout << "Wrong choice!";
         break;
      }
   }
   return 0;
}