#include <iostream>

using namespace std;

struct node
{
   int data;
   struct node *next;
} * p;

void add_at_end(int num) //Adding new node at the end
{
   struct node *q, *t;
   if (p == NULL) //Checking if the list is empty
   {
      p = new node; //Creating first node
      p->data = num;
      p->next = NULL;
   }
   else
   {
      q = p;
      while (q->next != NULL) //Go to last node
         q = q->next;

      t = new node; //Adding node at the end
      t->data = num;
      t->next = NULL;
      q->next = t;
   }
}

void add_at_beg(int num) //Adding new node at the beginning
{
   struct node *q;
   q = new node;
   q->data = num;
   q->next = p;
   p = q;
}

void add_at_later(int c, int num) //Adding node after specific number of nodes
{
   struct node *q, *t;
   int i;

   for (i = 0, q = p; i < c; i++) //Skipping to the desired portion
   {
      q = q->next;
      if (q == NULL)
      {
         cout << "There aren't enough elements";
         return;
      }
   }

   t = new node; //Inserting new node
   t->data = num;
   t->next = q->next;
   q->next = t;
}

void display() //Displaying contents of the linked list
{
   struct node *q;
   cout << endl;
   q = p;
   while (q != NULL)
   {
      if (q->next != NULL)
         cout << q->data << " ->";
      else
         cout << q->data;

      q = q->next;
   }
}

int count() //Count the number of nodes
{
   struct node *q;
   int c = 0;
   for (q = p; q != NULL; q = q->next)
   {
      c++;
   }
   return (c);
}

int main()
{
   struct node *obj = NULL;
   add_at_end(40);
   add_at_end(50);
   add_at_end(60);
   add_at_end(70);
   add_at_end(80);
   add_at_end(90);

   add_at_beg(30);
   add_at_beg(20);
   add_at_beg(10);

   add_at_later(2, 35);
   add_at_later(4, 45);

   display();

   cout << "\nNumber of elements in the linked list: " << count();
   return 0;
}
