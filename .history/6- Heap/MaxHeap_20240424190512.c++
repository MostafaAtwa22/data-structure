#include<iostream>
using namespace std;

class MaxHeap
{
private:
  int *arr;
  int size;
  int length;
public:
  MaxHeap(int size);
  int parent(int child);
  int left(int parent);
  int right(int parent);
  int top(int i);  
  void print();
  void Insert(int element);
};

MaxHeap::MaxHeap(int size)
{
  this->size = size;
  this->length = 0;
  arr = new int[size];
}

void MaxHeap::Insert(int element)
{
  if (length == size)
  {
    cout << "Overflow: Heap is Full\n";
    return;
  }
  length++;
  int i = length - 1;
  arr[i] = element;
  
  while (i != 0 && arr[parent(i)] > arr[i]) // Change here: '>' instead of '<'
  {
    swap(arr[i], arr[parent(i)]);
    i = parent(i);
  }
}
int MaxHeap::parent(int child)
{
  return (child / 2);
}

int MaxHeap::left(int parent)
{
  return (parent * 2 + 1);
}


int MaxHeap::right(int parent)
{
  return (parent * 2 + 2);
}

int MaxHeap::top(int i)
{
  return arr[0];
}

void MaxHeap::print()
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
  MaxHeap MH(n);
  cout << "Enter the Heap Elements !!\n";
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    MH.Insert(x);
  }
  MH.print();
}