#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node *next;

} *head = NULL;

void reverse_linkedlist(int x)
{
   int arr[x], i = 0;
   Node *p = NULL;
   p = head;
   while (p != NULL)
   {
      arr[i] = p->data;
      i++;
      p = p->next;
   }
   cout << "The reversed linked list is: ";
   for (i = 0; i < x; i++)
   {
      cout << arr[x - i - 1] << " ";
   }
}

int main()
{
   int n;
   cout << "\nEnter the no of elements: ";
   cin >> n;

   int arr[n];
   head = new Node;
   struct Node *end = NULL, *p = NULL;
   cout << "\nEnter the elements : ";
   cin >> arr[0];
   head->data = arr[0];
   head->next = NULL;
   end = head;
   for (int i = 1; i < n; i++)
   {

      cin >> arr[i];
      p = new Node;
      p->data = arr[i];
      p->next = NULL;
      end->next = p;
      end = p;
   }
   reverse_linkedlist(n);
   return 0;
}
