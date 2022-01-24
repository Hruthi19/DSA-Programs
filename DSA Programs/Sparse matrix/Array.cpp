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
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout << newmatrix[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}
