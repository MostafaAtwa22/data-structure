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
  public int parent(int i);
  public int left(int i);
  public int right(int i);
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
}

int MinHeap::parent(int element)
{
  return i / 2;
}

int MinHeap::left(int element)
{
  return i * 2 + 1
}


int MinHeap::right(int element)
{
  return i * 2 + 2;
}


MinHeap::~MinHeap()
{
}

int main()
{
  
}