#include <bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

struct node *BSTInsert(struct node *root, int item)
{
   if (root == NULL)
   {
      struct node *newnode;
      newnode = new node;
      newnode->data = item;
      newnode->left = NULL;
      newnode->right = NULL;
      return newnode;
   }

   if (item < root->data)
      root->left = BSTInsert(root->left, item);
   else
      root->right = BSTInsert(root->right, item);

   return root;
}

void BSTInorderSTACK(struct node *root)
{
   stack<node *> s;
   node *curr = root;

   while (curr != NULL || s.empty() == false)
   {
      while (curr != NULL)
      {
         s.push(curr);
         curr = curr->left;
      }
      curr = s.top();
      s.pop();

      cout << curr->data << " ";
      curr = curr->right;
   }
}

int main()
{
   vector<int> vec;
   int n, item;
   struct node *root;
   root = NULL;
   cout << "\nEnter the no.of inputs: ";
   cin >> n;
   while (n > 0)
   {
      cout << "\nEnter element to be inserted: ";
      cin >> item;
      root = BSTInsert(root, item);
      n--;
   }

   cout << "\nInorder Traversal: \n";
   BSTInorderSTACK(root);

   return 0;
}