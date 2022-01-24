#include <iostream>
using namespace std;

int main()
{
   int m, n;
   cout << "Enter rows: ";
   cin >> m;
   cout << "Enter columns: ";
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

   int size = 0;
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (matrix[i][j] != 0)
            size++;
      }
   }
   int newmatrix[size][3];
   int k = 0;
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (matrix[i][j] != 0)
         {
            newmatrix[k][0] = i;
            newmatrix[k][1] = j;
            newmatrix[k][2] = matrix[i][j];
            k++;
         }
      }
   }
   cout << "\nSparse matrix: \n";
   cout << "Row\tColumn\tValue\n";
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout << newmatrix[i][j] << "\t";
      }
      cout << endl;
   }

   int transpose[size][3];

   transpose[0][0] = newmatrix[0][1];
   transpose[0][1] = newmatrix[0][0];
   transpose[0][2] = newmatrix[0][2];

   int q = 1;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= size; j++)
      {
         if (newmatrix[j][2] == i)
         {
            transpose[q][0] = newmatrix[j][1];
            transpose[q][1] = newmatrix[j][0];
            transpose[q][2] = newmatrix[j][2];
            q++;
         }
      }
   }
   cout << "\nTranspose: \n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout << transpose[i][j] << "\t";
      }
      cout << endl;
   }

   return 0;
}
