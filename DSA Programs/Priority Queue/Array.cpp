#include <iostream>
using namespace std;

#define N 20
int Q[N], Pr[N];
int r = -1, f = -1;
void enqueue(int data, int p) //Enqueue function to insert data and its priority in queue
{
   int i;
   if ((f == 0) && (r == N - 1)) //Check if Queue is full
      cout << "Queue is full";
   else
   {
      if (f == -1) //if Queue is empty
      {
         f = r = 0;
         Q[r] = data;
         Pr[r] = p;
      }
      else if (r == N - 1) //if there there is some elemets in Queue
      {
         for (i = f; i <= r; i++)
         {
            Q[i - f] = Q[i];
            Pr[i - f] = Pr[i];
            r = r - f;
            f = 0;
            for (i = r; i > f; i--)
            {
               if (p > Pr[i])
               {
                  Q[i + 1] = Q[i];
                  Pr[i + 1] = Pr[i];
               }
               else
                  break;
               Q[i + 1] = data;
               Pr[i + 1] = p;
               r++;
            }
         }
      }
      else
      {
         for (i = r; i >= f; i--)
         {
            if (p > Pr[i])
            {
               Q[i + 1] = Q[i];
               Pr[i + 1] = Pr[i];
            }
            else
               break;
         }
         Q[i + 1] = data;
         Pr[i + 1] = p;
         r++;
      }
   }
}
void print() //print the data of Queue
{
   int i;
   for (i = f; i <= r; i++)
   {
      cout << "\nElement = " << Q[i] << "\tPriority = " << Pr[i];
   }
}
int dequeue() //remove the data from front
{
   if (f == -1)
   {
      cout << "Queue is Empty";
   }
   else
   {
      cout << "deleted Element = " << Q[f] << "\t Its Priority = " << Pr[f];
      if (f == r)
         f = r = -1;
      else
         f++;
   }
   return 0;
}
int main()
{
   int opt, n, i, data, p;

   do
   {
      cout << "\n\n1. Insert\n2. Delete\n3. Display\n0.Exit ";
      cout << "\nEnter Your Choice:- ";
      cin >> opt;
      switch (opt)
      {
      case 1:
         cout << "\nEnter the data: ";
         cin >> data;
         cout << "\nEnter its priority: ";
         cin >> p;
         enqueue(data, p);
         break;
      case 2:
         dequeue();
         break;
      case 3:
         print();
         break;
      case 0:
         break;
      default:
         cout << "\nIncorrect Choice";
         break;
      }
   } while (opt != 0);
   return 0;
}