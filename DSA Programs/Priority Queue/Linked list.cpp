#include <iostream>
using namespace std;
struct node
{
   int data, p;
   struct node *next;
};
struct node *p = NULL;
struct node *q = NULL;

void enqueue(int d, int pr)
{
   struct node *temp;
   struct node *new_n;
   new_n = new node;
   new_n->data = d;
   new_n->p = pr;

   if ((p == NULL) || (pr))
   {
      new_n->next = p;
      p = new_n;
   }
   else
   {
      temp = p;
      while ((temp->next != NULL) && ((temp->next->p) <= pr))
         temp = temp->next;
      new_n->next = temp->next;
      temp->next = new_n;
   }
}
void print()
{
   struct node *temp = p;
   while (temp != NULL)
   {
      cout << "\nData = " << temp->data << "\tPriority =  " << temp->p;
      temp = temp->next;
   }
}
void dequeue()
{
   struct node *temp;
   if (p == NULL)
      cout << "\nQueue is Empty";
   else
   {
      temp = p;
      p = p->next;
      cout << "\nDeleted element:- " << temp->data << "\t and Its Priority:- " << temp->p;
      free(temp);
   }
}
int main()
{
   int opt, n, i, data, pr;

   do
   {
      cout << "\n\n1.Insert\n2.Delete\n3.Display\n0.Exit";
      cout << "\nEnter Your Choice:- ";
      cin >> opt;
      switch (opt)
      {
      case 1:
         cout << "\nEnter the data: ";
         cin >> data;
         cout << "\nEnter its priority: ";
         cin >> pr;
         enqueue(data, pr);
         break;
      case 2:
         dequeue();
         break;
      case 3:
         print();
         break;
      case 0:
         break;
      default:
         cout << "\nIncorrect Choice";
         break;
      }
   } while (opt != 0);
   return 0;
}