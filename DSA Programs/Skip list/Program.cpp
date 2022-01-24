#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int key;
   Node **forward;
   Node(int, int);
};

Node::Node(int key, int level)
{
   this->key = key;
   forward = new Node *[level + 1];
   memset(forward, 0, sizeof(Node *) * (level + 1));
};

class SkipList
{

   int MAXLVL;
   float P;
   int level;
   Node *header;

public:
   SkipList(int, float);
   int randomLevel();
   Node *createNode(int, int);
   void insertElement(int);
   void searchElement(int);
   void displayList();
};

SkipList::SkipList(int MAXLVL, float P)
{
   this->MAXLVL = MAXLVL;
   this->P = P;
   level = 0;
   header = new Node(-1, MAXLVL);
};

int SkipList::randomLevel()
{
   float r = (float)rand() / RAND_MAX;
   int lvl = 0;
   while (r < P && lvl < MAXLVL)
   {
      lvl++;
      r = (float)rand() / RAND_MAX;
   }
   return lvl;
};

Node *SkipList::createNode(int key, int level)
{
   Node *n = new Node(key, level);
   return n;
};

void SkipList::insertElement(int key)
{
   Node *current = header;
   Node *update[MAXLVL + 1];
   memset(update, 0, sizeof(Node *) * (MAXLVL + 1));

   for (int i = level; i >= 0; i--)
   {
      while (current->forward[i] != NULL &&
             current->forward[i]->key < key)
         current = current->forward[i];
      update[i] = current;
   }
   current = current->forward[0];

   if (current == NULL || current->key != key)
   {
      int rlevel = randomLevel();
      if (rlevel > level)
      {
         for (int i = level + 1; i < rlevel + 1; i++)
            update[i] = header;

         level = rlevel;
      }
      Node *n = createNode(key, rlevel);
      for (int i = 0; i <= rlevel; i++)
      {
         n->forward[i] = update[i]->forward[i];
         update[i]->forward[i] = n;
      }
      cout << "Successfully Inserted key: " << key << "\n";
   }
   cout << endl;
};

void SkipList::searchElement(int key)
{
   Node *current = header;
   for (int i = level; i >= 0; i--)
   {
      while (current->forward[i] && current->forward[i]->key < key)
         current = current->forward[i];
   }
   current = current->forward[0];

   if (current and current->key == key)
      cout << "\nFound the element!\n";
   else
      cout << "\nNot Found!";
};

void SkipList::displayList()
{
   cout << "\n*****Skip List*****"<< "\n";
   for (int i = 0; i <= level; i++)
   {
      Node *node = header->forward[i];
      cout << "\nLevel " << i << ": ";
      while (node != NULL)
      {
         cout << node->key << " ";
         node = node->forward[i];
      }
      cout << "\n";
   }
};

int main()
{

   srand((unsigned)time(0));
   SkipList lst(1, 0.5);
   int x, c, num, value;
   while (c)
   {
      cout << "Enter the number of nodes: ";
      cin >> x;
      for (int i = 0; i < x; i++)
      {
         cout << "Enter data: ";
         cin >> value;
         lst.insertElement(value);
      }
      cout << "\nDo you wish to continue: YES-1 , NO-0 : ";
      cin >> c;
   }

   lst.displayList();

   cout << "\nEnter the element you want to search: ";
   cin >> num;
   lst.searchElement(num);
}