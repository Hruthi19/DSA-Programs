#include <iostream>
using namespace std;

struct node
{
   int data;
   struct node *next;
   struct node *prev;
} *head = NULL;

void insert_at_beg()
{
   int data;
   cout << "Enter data: ";
   cin >> data;

   struct node *p = NULL;
   p = new node;
   p->data = data;
   p->next = head;
   p->prev = NULL;

   head = p;
}

void Delete_at_pos(int n)
{
   int pos, i = 1;
   cin >> pos;
   struct node *p = NULL;
   struct node *end = NULL;
   end = new node;
   p = head;
   if (pos == 1)
   {
      p = p->next;
      head = p;
   }
   else if (pos == n)
   {
      for (i; i <= pos - 1; i++)
      {
         if (i == pos - 1)
            p->next = NULL;
         p = p->next;
      }
   }
   else
      for (int i = 1; i <= pos + 1; i++)
      {
         if (i == pos - 1)
         {
            end = p;
         }
         if (i == pos + 1)
         {
            end->next = p;
            p->prev = end;
         }
         if (p == NULL)
         {
            cout << "INCORRECT!" << endl;
         }
         p = p->next;
      }
}

int count()
{
   struct node *p;
   p = head;
   int c = 0;
   while (p != NULL)
   {
      c++;
      p = p->next;
   }
   return (c);
}
void display()
{
   struct node *p;
   p = head;
   while (p != NULL)
   {
      cout << p->data << " ";
      p = p->next;
   }
   cout << endl;
}
int main()
{
   int data;
   cout << "\nEnter element 1: ";
   cin >> data;

   head = new node;
   head->data = data;
   head->next = NULL;
   head->prev = NULL;
   int choice = -1;

   cout << "\n0. Insert at the begining" << endl;
   cout << "\n1. Delete element at some position" << endl;
   cout << "\n2. Count the nodes" << endl;
   cout << "\n3. Display" << endl;
   cout << "\n4. End prog" << endl;
   while (choice != 4)
   {
      cout << "\nEnter choice: ";
      cin >> choice;
      switch (choice)
      {
      case 0:
      {
         insert_at_beg();
         break;
      }
      case 1:
      {
         Delete_at_pos(count());
         break;
      }

      case 2:
      {
         cout << count() << endl;
         break;
      }

      case 3:
      {
         display();
         break;
      }
      }
   }
   return 0;
}
