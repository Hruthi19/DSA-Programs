#include <iostream>
using namespace std;

struct node
{
   int data;
   struct node *next;
} *head = 0;

void create(int arr[], int num)
{
   int i;
   struct node *newnode, *end;
   head = new node;
   head->data = arr[0];
   head->next = NULL;
   end = head;
   for (i = 1; i < num; i++)
   {
      newnode = new node;
      newnode->data = arr[i];
      newnode->next = NULL;
      end->next = newnode;
      end = newnode;
   }
}

void remove_elements(struct node *p, struct node *end)
{
   end->next = p->next;
}

void change(int M, int N, int num)
{
   int m = 0, n = 0, nochange = 0;
   struct node *p = NULL, *end = NULL;
   p = head;
   end = new node;
   for (int i = 1; i <= num; i++)
   {
      if (m == M)
      {
         if (n != N)
         {
            remove_elements(p, end);
            nochange = 1;
         }
         else
         {
            m = 1;
            n = -1;
         }
         n++;
      }
      else
         m++;
      if (nochange == 0)
         end = p;
      nochange = 0;
      p = p->next;
   }
}

void display(struct node *p)
{
   while (p != NULL)
   {
      cout << p->data << " ";
      p = p->next;
   }
}

int main()
{
   int num, M, N;
   cout << "\nEnter the number of elements in the linked list: ";
   cin >> num;
   int arr[num];
   cout << "\nEnter the elements : " << endl;

   for (int i = 0; i < num; i++)
      cin >> arr[i];

   create(arr, num);
   cout << "\nEnter the number (M) of nodes to retain: ";
   cin >> M;
   cout << "\nEnter the number of nodes (N) to delete : ";
   cin >> N;
   if (M == 0)
   {
      cout << "The linked list is now empty" << endl;
      return 0;
   }
   change(M, N, num);
   display(head);
}
