#include<iostream>
using namespace std;

class MinHeap
{
private:
  int *arr;
  int size;
  int length;
public:
  MinHeap(int size);
  int parent(int child);
  int left(int parent);
  int right(int parent);
  int getMin(int i);  
  void print();
  void Insert(int element);
};

MinHeap::MinHeap(int size)
{
  this->size = size;
  this->length = 0;
  arr = new int[size];
}

void MinHeap::Insert(int element)
{
  if (length == size)
  {
    cout << "OverFlow : Heap is Full\n";
    return;
  }
  length++;
  int i = length - 1;
  arr[i] = element;
  
  while (i != 0 && arr[parent(i)] < arr[i])
  {
    swap(arr[i], arr[parent(i)]);
    i = parent(i);
  }
}

int MinHeap::parent(int child)
{
  return (child / 2);
}

int MinHeap::left(int parent)
{
  return (parent * 2 + 1);
}


int MinHeap::right(int parent)
{
  return (parent * 2 + 2);
}

void MinHeap::print()
{
  cout << "Heap: [ ";
  for (int i = 0; i < size; i++)
    cout << arr[i] << ' ';
  cout << "]\n";
}


int main()
{
  int n;
  cout << "Enter the Heap size : ";
  cin >> n;
  MinHeap MH(n);
  cout << "Enter the Heap Elements !!\n";
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    MH.Insert(x);
  }
  MH.print();
}