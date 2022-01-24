#include <iostream>
using namespace std;

struct node
{
   int marks;
   int location;
   struct node *next;
} *start = NULL;

void arrange(struct node *start)
{
   struct node *p, *q;
   int i, j;

   for (p = start; p->next != NULL; p = p->next)
   {
      for (q = p->next; q != NULL; q = q->next)
      {
         if (p->location > q->location)
         {
            i = p->location;
            j = p->marks;
            p->location = q->location;
            p->marks = q->marks;
            q->location = i;
            q->marks = j;
         }
      }
   }
}

void display()
{
   struct node *ptr;
   ptr = start;
   cout << "\nItem\tLocation\n";
   while (ptr != NULL)
   {
      cout << ptr->marks << "\t";
      cout << ptr->location << "\n";
      ptr = ptr->next;
   }

   cout << endl;
}

int main()
{
   int n;
   cout << "Enter the number of students: ";
   cin >> n;

   while (n != 0)
   {
      int mark, loc;
      cout << "\nEnter marks: ";
      cin >> mark;
      cout << "Enter Location: ";
      cin >> loc;
      struct node *ptr = new node;
      if (loc > 0 && loc <= n)
      {
         ptr->marks = mark;
         ptr->location = loc;
         ptr->next = start;
         start = ptr;
         n--;
      }
      else
      {
         cout << "invalid" << endl;

         continue;
      }
   }

   arrange(start);
   cout << "\nAfter Rearranging: ";
   display();
   return 0;
}