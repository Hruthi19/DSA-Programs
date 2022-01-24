#include <iostream>
using namespace std;

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

struct node *insert(struct node *root, int item)
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
      root->left = insert(root->left, item);
   else
      root->right = insert(root->right, item);

   return root;
}

struct node *min_node(struct node *temp)
{
   while (temp && temp->left != NULL)
   {
      temp = temp->left;
   }
   return temp;
}

struct node *Deletion(struct node *root, int item)
{
   if (root == NULL)
   {
      return 0;
   }
   if (item < root->data)
   {
      root->left = Deletion(root->left, item);
   }
   else if (item > root->data)
   {
      root->right = Deletion(root->right, item);
   }
   else
   {
      if (root->left && root->right == NULL)
         return 0;
      else if (root->left == NULL)
      {
         struct node *temp = root->left;
         delete (root);
         return temp;
      }
      struct node *temp = min_node(root->right);

      root->data = temp->data;
      root->right = Deletion(root->right, temp->data);
   }
   return root;
}

void inorder(struct node *root)
{
   if (root == NULL)
   {
      return;
   }
   inorder(root->left);
   cout << root->data << "\t";
   inorder(root->right);
}

int main()
{
   struct node *root;
   root = NULL;
   int n, val, x, item;
   cout << "\nEnter the number of items you want to insert: ";
   cin >> n;
   while (n > 0)
   {
      cout << "\nEnter the items to be inserted:";
      cin >> val;
      root = insert(root, val);
      n--;
   }
   inorder(root);
   cout << "\nHow many items you want to delete: ";
   cin >> x;
   while (x > 0)
   {
      cout << "\nEnter item to be deleted: ";
      cin >> item;
      x--;
      root = Deletion(root, item);
   }
   cout << "\nAfter Deletion: ";
   inorder(root);

   return 0;
}