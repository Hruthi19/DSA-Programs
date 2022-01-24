#include <iostream>
using namespace std;
struct date
{
   int d, m;
   long y;
};
int main()
{
   date *d1, *d2, da1, da2;
   d1 = &da1;
   d2 = &da2;
   cout << "Enter date1: ";
   cin >> (*d1).d;
   cin >> (*d1).m;
   cin >> (*d1).y;
   cout << "Enter date2: ";
   cin >> (*d2).d;
   cin >> (*d2).m;
   cin >> (*d2).y;
   if (((*d1).d == (*d2).d) && ((*d1).m == (*d2).m) && ((*d1).y == (*d2).y))
      cout << "The two dates Equal";
   else
      cout << "The two dates Not equal";
   return 0;
}
