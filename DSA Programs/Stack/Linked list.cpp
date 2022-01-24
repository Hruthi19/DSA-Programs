#include <iostream>
using namespace std;

struct node
{
   int data;
   node *next;
} * head;

void push()
{
   int val;
   struct node *temp = new node;
   if (temp == NULL)
   {
      cout << "Cannot push element!";
   }
   else
   {
      cout << "Enter the value: ";
      cin >> val;
      if (head == NULL)
      {
         temp->data = val;
         temp->next = NULL;
         head = temp;
      }
      else
      {
         temp->data = val;
         temp->next = head;
         head = temp;
      }
      cout << "Item pushed";
   }
}

void pop()
{
   int item;
   struct node *temp;
   if (head == NULL)
   {
      cout << "Underflow! Cannot delete elements";
   }
   else
   {
      item = head->data;
      temp = head;
      head = head->next;
      delete temp;
      cout << "Item popped";
   }
}

void display()
{
   int i;
   struct node *temp;
   temp = head;
   if (temp == NULL)
   {
      cout << "Stack is empty";
   }
   else
   {
      cout << "Stack elements:\t";
      while (temp != NULL)
      {
         cout << temp->data << "\t";
         temp = temp->next;
      }
   }
}

int main()
{

   int choice = 0;
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
      {
         push();
         break;
      }

      case 2:
      {
         pop();
         break;
      }

      case 3:
      {
         display();
         break;
      }

      case 4:
      {
         cout << "Ending the program!";
         break;
      }

      default:
      {
         cout << "Wrong input!";
      }
      };
      cout << endl;
   }

   return 0;
}
