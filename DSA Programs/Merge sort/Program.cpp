#include <bits/stdc++.h>
using namespace std;

void Merge(int a[], int l, int mid, int r)
{
   int b[r + 1];
   int i = l;
   int j = mid + 1;
   int k = 0;
   while (i <= mid && j <= r)
   {
      if (a[i] < a[j])
      {
         b[k++] = a[i++];
      }
      else
      {
         b[k++] = a[j++];
      }
   }

   while (i <= mid)
   {
      b[k++] = a[i];
      i++;
   }
   while (j <= r)
   {
      b[k++] = a[j];
      j++;
   }

   for (int i = l; i <= r; i++)
   {
      a[i] = b[i - l];
   }
}

void Final_Merge(int a[], int l, int r)
{

   int mid = (l + r) / 2;
   int b[mid];
   for (int i = 0; i <= mid; i++)
   {
      b[i] = a[i];
   }
   int i = 0;
   int j = mid + 1;
   int k = 0;
   while (i <= mid && j <= r)
   {
      if (a[j] < b[i])
      {
         a[k++] = a[j++];
      }
      else
      {
         a[k++] = b[i++];
      }
   }
   while (i <= mid)
   {
      a[k++] = b[i];
      i++;
   }
}
void mergesort(int a[], int l, int r)
{

   if (l < r)
   {
      int mid = (l + r) / 2;
      mergesort(a, l, mid);
      mergesort(a, mid + 1, r);
      if (l == 0 && r == mid - 1)
      {
         Final_Merge(a, 0, r);
      }
      else
      {
         Merge(a, l, mid, r);
      }
   }
}

int main()
{
   int n;
   cout << "Enter the Size: ";
   cin >> n;
   int a[n];
   cout << "\nEnter elements of the array: ";
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
   }

   mergesort(a, 0, n - 1);
   cout << "\nSorted array: ";
   for (int i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
   return 0;
}
