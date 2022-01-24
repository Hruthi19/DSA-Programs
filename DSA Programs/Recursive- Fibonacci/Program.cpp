#include <iostream>
using namespace std;
int fibonacci(int n)
{
   if (n == 1)
      return 0;
   else if (n == 2 || n == 3)
      return 1;
   else
      return (fibonacci(n - 1) + fibonacci(n - 2));
}
int main()
{
   int n;
   cout << "Enter num: ";
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
      cout << fibonacci(i) << " ";
   }
   return 0;
}
