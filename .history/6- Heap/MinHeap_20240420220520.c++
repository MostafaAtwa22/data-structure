#include<iostream>
using namespace std;

class MinHeap
{
private:
  int arr[this.size];
  int size;
  int ptr;
public:
  MinHeap(int size);
  int parent(int i);
  int left(int i);
  int right(int i);
  int getMin(int i);
  void Insert(int element);
  ~MinHeap();
};

MinHeap::MinHeap(int size)
{
  this->size = size;
  ptr = 0;
}

void MinHeap::Insert(int element)
{
  if (prt )
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