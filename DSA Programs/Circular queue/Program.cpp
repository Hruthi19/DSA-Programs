#include <iostream>
using namespace std;

#define max 6
int queue[max];
int front = -1, rear = -1;

void enqueue(int element)
{
   if (front == -1 && rear == -1)
   {
      front = 0;
      rear = 0;
      queue[rear] = element;
   }
   else if ((rear + 1) % max == front)
   {
      cout << "Queue is overflow..";
   }
   else
   {
      rear = (rear + 1) % max;
      queue[rear] = element;
   }
}

int dequeue()
{
   if ((front == -1) && (rear == -1))
   {
      cout << "\nQueue is underflow..";
   }
   else if (front == rear)
   {
      cout << "\nThe dequeued element is " << queue[front];
      front = -1;
      rear = -1;
   }
   else
   {
      cout << "\nThe dequeued element is " << queue[front];
      front = (front + 1) % max;
   }
   return 0;
}

void display()
{
   int i = front;
   if (front == -1 && rear == -1)
   {
      cout << "\n Queue is empty..";
   }
   else
   {
      cout << "\nElements in a Queue are :";
      while (i <= rear)
      {
         cout << queue[i] << "\t";
         i = (i + 1) % max;
      }
   }
}

int main()
{
   int choice = 1, x;

   while (choice != 4)
   {
      cout << "\n1.Insert\n2.Delete\n3.Display\n4.Quit";
      cout << "\nEnter choice: ";
      cin >> choice;

      switch (choice)
      {

      case 1:
         cout << "Enter the element which is to be inserted";
         cin >> x;
         enqueue(x);
         break;
      case 2:
         dequeue();
         break;
      case 3:
         display();
         break;
      case 4:
         break;

      default:
         cout << "Wrong choice!";
         break;
      }
   }
   return 0;
}