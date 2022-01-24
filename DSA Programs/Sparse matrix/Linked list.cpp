#include <iostream>
using namespace std;

struct node
{
   int row, column, value;
   struct node *next;
};

void create(node **p, int row, int col, int val)
{
   node *temp = *p;
   node *r;
   if (temp == NULL)
   {
      temp = new node;
      temp->row = row;
      temp->column = col;
      temp->value = val;
      temp->next = NULL;
      *p = temp;
   }
   else
   {
      while (temp->next != NULL)
         temp = temp->next;

      r = new node;
      r->row = row;
      r->column = col;
      r->value = val;
      r->next = NULL;
      temp->next = r;
   }
}

void display(node *start)
{
   node *ptr = start;
   cout << "Row vale:";
   while (ptr != NULL)
   {
      cout << ptr->row << " ";
      ptr = ptr->next;
   }
   cout << endl;
   ptr = start;
   cout << "\nColumn value: ";
   while (ptr != NULL)
   {
      cout << ptr->column << " ";
      ptr = ptr->next;
   }
   cout << endl;
   ptr = start;
   cout << "\n Value: ";
   while (ptr != NULL)
   {
      cout << ptr->value << " ";
      ptr = ptr->next;
   }
}

int main()
{
   int m, n;
   cout << "Enter rows: ";
   cin >> m;
   cout << "enter columns: ";
   cin >> n;

   int matrix[m][n];
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << "Enter matrix[" << i << "][" << j << "] element: ";
         cin >> matrix[i][j];
      }
   }
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }

   node *first = NULL;
   cout << endl;
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (matrix[i][j] != 0)
            create(&first, i, j, matrix[i][j]);
      }
   }
   display(first);
   return 0;
}
