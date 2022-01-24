#include <iostream>
using namespace std;
void print_array(float *grade, int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << grade[i] << "\t";
   }
   cout << endl;
}
void minimum(float *grade, int size)
{
   float min = grade[0];
   for (int i = 0; i < size; i++)
   {
      if (min > grade[i])
         min = grade[i];
   }
   cout << "\t" << min << "\n";
}
void maximum(float *grade, int size)
{
   float max = grade[0];
   for (int i = 0; i < size; i++)
   {
      if (max < grade[i])
         max = grade[i];
   }
   cout << "\t" << max << "\n";
}
void avg(float *grade, int size)
{
   float sum = 0;
   for (int i = 0; i < size; i++)
   {
      sum = sum + grade[i];
   }
   float avg = (sum / size);
   cout << "\t" << avg << "\n";
}
void end_program(float *grade, int size)
{
}
int main()
{
   float *grade;
   int size, choice;
   cout << "Enter the size of the array: ";
   cin >> size;
   grade = new float[size];
   if (!grade) // to check whether the memory is available or not
   {
      cout << "Out of memory!";
      return 1;
   }
   for (int i = 0; i < size; i++) // read in values in the array elements
   {
      cout << "Enter marks of the student: ";
      cin >> grade[i];
   }
   while (1)
   {
      cout << "Enter choice: ";
      cout << "\n\t0.Print the Array of grades";
      cout << "\n\t1.Minimum grade";
      cout << "\n\t2.Maximum grade";
      cout << "\n\t3.Average of all tests";
      cout << "\n\t4.End program\n";
      cin >> choice;
      switch (choice)
      {
      case 0:
         print_array(grade, size);
         break;
      case 1:
         minimum(grade, size);
         break;
      case 2:
         maximum(grade, size);
         break;
      case 3:
         avg(grade, size);
         break;
      case 4:
         end_program(grade, size);
         break;
      default:
         cout << "Wrong choice";
      }
   }
   return 0;
}
