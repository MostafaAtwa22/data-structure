#include<iostream>
using namespace std;

class MinHeap
{
private:
  int arr[this.size];
  int size;
  int heap_size;
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
}

MinHeap::Insert(int element)
{
  this->size = size;
}

MinHeap::~MinHeap()
{
}

int main()
{
  
}