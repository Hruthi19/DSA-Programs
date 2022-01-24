#include <iostream>
using namespace std;

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

struct node *Insert()
{
   int x;
   struct node *newnode;
   newnode = new node;
   cout << "\nEnter the data or -1 for no value: ";
   cin >> x;
   if (x == -1)
   {
      return 0;
   }
   newnode->data = x;
   cout << "\nLeft child of " << x << " : ";
   newnode->left = Insert();
   cout << "\nRight child of " << x << " : ";
   newnode->right = Insert();
   return newnode;
}

int height(struct node *root)
{
   if (root == NULL)
      return 0;
   else
      return 1 + max(height(root->left), height(root->right));
}

void Preorder(struct node *root)
{
   if (root == NULL)
   {
      return;
   }
   cout << root->data << " ";
   Preorder(root->left);
   Preorder(root->right);
}
void Postorder(struct node *root)
{
   if (root == NULL)
   {
      return;
   }
   Postorder(root->left);
   Postorder(root->right);
   cout << root->data << " ";
}

int main()
{
   struct node *root;
   root = NULL;
   root = Insert();
   int x = height(root);
   cout << "\n\n Height of the tree: " << x;
   cout << "\n\n Preorder: ";
   Preorder(root);

   cout << "\n\n Postorder: ";
   Postorder(root);

   return 0;
}