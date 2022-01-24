#include <iostream>
using namespace std;

struct node
{
public:
   int data;
   struct node *next;
   void delete_duplicate();
   void display();
} *head = NULL;

void delete_duplicate()
{
   struct node *p = NULL, *end = NULL;
   p = head;
   p = p->next;
   end = head;
   while (p != NULL)
   {
      if (p->data == end->data)
      {
         end->next = p->next;
      }

      if (p->data != end->data)
         end = p;
      p = p->next;
   }
}

void display()
{
   struct node *p = NULL;
   p = head;
   cout << "The elements which are not duplicate are: " << endl;
   while (p != NULL)
   {
      cout << p->data << endl;
      p = p->next;
   }
}
int main()
{
   int n;
   cout << "\nEnter the number of elements: ";
   cin >> n;

   int a[n];
   head = new node;
   struct node *end = NULL;
   cout << "\nEnter the elements in sorted form: ";
   cin >> a[0];

   head->data = a[0];
   head->next = NULL;
   struct node *t = NULL;
   end = head;
   for (int i = 1; i < n; i++)
   {
      cin >> a[i];
      t = new node;
      t->data = a[i];
      t->next = NULL;
      end->next = t;
      end = t;
   }
   delete_duplicate();
   display();
   return 0;
}
