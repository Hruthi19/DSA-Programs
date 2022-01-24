#include <iostream>

using namespace std;


void primefactors(int num)
{
   int count;

   printf("\nPrime Factors of %d are ..\n", num);
   for (count = 2; num > 1; count++)
   {
      while (num % count == 0)
      {
         printf("%d ", count);
         num = num / count;
      }
   }
   printf("\n");
}

int main()
{
   int n;
   cout << "Enter number";
   cin >> n;
   primefactors(n);

   return 0;
}
