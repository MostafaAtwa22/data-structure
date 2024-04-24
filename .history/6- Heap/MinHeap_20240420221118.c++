#include<iostream>
using namespace std;

class MinHeap
{
private:
  private int arr[this.size];
  private int size;
  private int length;
public:
  public MinHeap(int size);
  public int parent(int child);
  public int left(int parent);
  public int right(int parent);
  public int getMin(int i);
  public void Insert(int element);
  public ~MinHeap();
};

MinHeap::MinHeap(int size)
{
  this->size = size;
  length = 0;
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
  return parent * 2 + 1
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
  
}