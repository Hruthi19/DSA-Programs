#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node
{
   int data;
   struct node *next;
} * p;

void sort_insert(int num)
{
   struct node *q, *t;
   q = p;
   if (p == NULL)
   {
      p = new node; //Creating first node
      p->data = num;
      p->next = NULL;
   }
   else
   {
      if (num < q->data)
      {
         t = new node;
         t->data = num;
         t->next = p;
         p = t;
      }
      else
      {
         while ((q->next != NULL) && !(num < q->next->data) && (num >= q->data))
            q = q->next;

         if (q->next == NULL)
         {
            q->next = new node;
            q = q->next;
            q->data = num;
            q->next = NULL;
         }
         else
         {
            t = new node;
            t->data = num;
            t->next = q->next;
            q->next = t;
         }
      }
   }
}

void display()
{
   struct node *q;
   float sum = 0;
   q = p;
   while (q != NULL)
   {
      if (q->next != NULL)
         cout << q->data << " -> ";
      else
         cout << q->data;

      sum += q->data;
      q = q->next; //move to next node
   }
   float average = sum / 25.0;
   cout << "\nSum = " << sum;
   cout << "\nAverage = " << average;
   cout << endl;
}
int main()
{
   struct node *p = NULL;
   srand(time(NULL));
   for (int i = 0; i < 25; i++)
   {
      int randomNumber = rand() % 101;
      sort_insert(randomNumber);
   }
   cout << "Current List is:\n";
   display();
   return 0;
}
