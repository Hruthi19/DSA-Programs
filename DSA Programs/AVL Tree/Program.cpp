#include <iostream>
using namespace std;

struct node
{
   int data;
   int height;
   struct node *left;
   struct node *right;
};

int height(struct node *root)
{
   if (root == NULL)
      return 0;

   return root->height;
}

struct node *LL(struct node *root)
{
   struct node *p;

   p = root->left;
   root->left = p->right;
   p->right = root;

   return p;
}

struct node *RR(struct node *root)
{
   struct node *p;
   p = root->right;
   root->right = p->left;
   p->left = root;

   return p;
}

struct node *RL(struct node *root)
{
   struct node *p;
   p = root->right;
   root->right = LL(root);

   return RR(root);
}

struct node *LR(struct node *root)
{
   struct node *p;
   p = root->left;
   root->left = RR(root);

   return LL(root);
}

int BF(struct node *root)
{
   if (root == NULL)
      return 0;

   return (height(root->left) - height(root->right));
}

struct node *Insert(struct node *root, int x)
{
   if (root == NULL)
   {
      struct node *newnode;
      newnode = new node;
      newnode->data = x;
      newnode->left = NULL;
      newnode->right = NULL;
      newnode->height = 1;

      return newnode;
   }

   if (x < root->data)
      root->left = Insert(root->left, x);
   else
      root->right = Insert(root->right, x);

   return root;

   root->height = 1 + (height(root->left) > height(root->right)) ? height(root->left) : height(root->right);

   int balance = BF(root);

   if (balance > 1 && x < root->left->data)
      return RR(root);

   else if (balance < -1 && x > root->right->data)
      return LL(root);

   else if (balance > 1 && x > root->left->data)
      return LR(root);

   else
      return RL(root);

   return (root);
}

void Display(struct node *root)
{
   if (root == NULL)
   {
      return;
   }

   Display(root->left);
   cout << root->data << "\t";
   Display(root->right);
}

int main()
{
   struct node *root;
   root = NULL;
   int n, x;
   cout << "\nEnter the number of inputs you want to insert: ";
   cin >> n;
   while (n > 0)
   {
      cout << "\nEnter element: ";
      cin >> x;
      root = Insert(root, x);
      n--;
   }
   cout << "\nInorder form: ";
   Display(root);
}