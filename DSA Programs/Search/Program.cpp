#include <iostream>

using namespace std;

int search_array(int a[], int n, int num)
{
   n--;
   if (n > 0)
   {
      if (a[n] == num)
         return n;
      else
         int x = search_array(a, n, num);
   }
   else
      return -1;
}

int main()
{
   int n, num, a[100];
   cout << "Enter the size of the array";
   cin >> n;
   cout << "Enter elements";
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   cout << "Enter the number you want to find";
   cin >> num;
   int x = search_array(a, n, num);
   if (x == -1)
      cout << "Element is not found in the array";
   else
      cout << "Element found at " << (x + 1) << " position";
}
