#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
   int temp;
   temp = a;
   a = b;
   b = temp;
}
int rev_sub_array(int a[], int n, int k)
{
   int x = n / k;
   for (int i = 0; i < x; i++)
   {
      for (int j = 0; j < k / 2; j++)
      {
         swap(a[(i * k) + j], a[(i * k) + (k - 1 - j)]);
      }
   }

   int start = x * k;
   int end = n - start;
   for (int i = 0; i < end / 2; i++)
   {
      swap(a[start + i], a[start + end - i - 1]);
   }
   cout << "The new array is: ";
   for (int i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
   return 0;
}
int main()
{
   int n, k;
   cout << "Enter the number of elements in the array: ";
   cin >> n;
   int a[n];
   cout << "Enter the elements of the array";
   for (int i = 0; i < n; i++)
      cin >> a[i];
   cout << "Enter k value: ";
   cin >> k;
   rev_sub_array(a, n, k);

   return 0;
}
