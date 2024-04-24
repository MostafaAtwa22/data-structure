#include<iostream>
using namespace std;

class MinHeap
{
private:
  int arr[this->size];
  int size;
  int length;
public:
  MinHeap(int size);
  int parent(int child);
  int left(int parent);
  int right(int parent);
  // public int getMin(int i);
  void Insert(int element);
  ~MinHeap();
};

MinHeap::MinHeap(int size)
{
  this->size = size;
  this->length = 0;
}

void MinHeap::Insert(int element)
{
  if (length >= size)
  {
    cout << "OverFlow : Heap is Full\n";
    return;
  }
  int i = length;
  length++;
  while (i != 0 && arr[parent(i)] > parent[i])
  {
    swap(arr[i], arr[parent(i)]);
    i = parent(i);
  }
}

int MinHeap::parent(int child)
{
  return child / 2;
}

int MinHeap::left(int parent)
{
  return parent * 2 + 1;
}


int MinHeap::right(int parent)
{
  return parent * 2 + 2;
}


MinHeap::~MinHeap()
{
}

int main()
{
  MinHeap MH();
  int n;
  cout << "Enter the Heap size : ";
  cin >> n;
  cout << "Enter the Heap Elements !!\n";
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    MH.Insert(x);
  }
}