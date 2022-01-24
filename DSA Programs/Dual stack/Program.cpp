#include <iostream>
#define maxi 10

using namespace std;
int a[maxi];
int top1 = -1, top2 = maxi;

void push1(int val)
{
   if (top1 == top2 - 1)
   {
      cout << "\nThe Front Stack is already full...";
   }
   else
   {
      a[++top1] = val;
   }
}

void pop1()
{
   if (top1 != -1)
   {
      cout << "\nThe popped element is " << a[top1] << endl;
      top1--;
   }
}
void push2(int val)
{
   if (top2 == top1 + 1)
   {
      cout << "\nThe Back Stack is already full...";
   }
   else
   {
      a[--top2] = val;
   }
}

void pop2()
{
   if (top2 != maxi)
   {
      cout << "\nThe popped element is " << a[top2] << endl;
      top2++;
   }
}

void display()
{
   if (top1 != -1)
   {
      int x = top1;
      while (x != -1)
      {
         cout << a[x] << " ";
         x--;
      }
   }

   cout << "-----------------------";
   if (top2 != maxi)
   {
      int y = top2;
      while (y != maxi)
      {
         cout << a[y] << " ";
         y++;
      }
   }
}

int main()
{

   cout << "Choice :\n 1) Push to Front stack.\n 2) Pop from Front stack.\n 3) Push to Back stack.\n 4) Pop from Back stack.\n 5) Display.\n";
   int ch, t;
   while (1)
   {
      cout << "\nEnter your choice.";
      cin >> ch;
      if (ch == 1)
      {
         cout << "Enter the element to insert in front stack.";
         cin >> t;
         push1(t);
      }
      else if (ch == 2)
      {
         pop1();
      }
      else if (ch == 3)
      {
         cout << "Enter the element to insert in front stack.";
         cin >> t;
         push2(t);
      }
      else if (ch == 4)
      {

         pop2();
      }
      else if (ch == 5)
      {
         display();
      }

      else
      {
         break;
      }
   }
   return 0;
}