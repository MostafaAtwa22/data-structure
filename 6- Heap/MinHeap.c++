#include<iostream>
#include<cmath>
using namespace std;

class MinHeap
{
private:
  int *arr;
  int size;
  int length;
  void MinHeapify(int index);
  void DecreaseKey(int indexe);
public:
  MinHeap(int size);
  bool Empty();
  bool Full();
  int Size();
  int parent(int child);
  int left(int parent);
  int right(int parent);
  void Push(int element);
  int Pop();
  void DeleteKey(int index);
  int top();  
  int Height();
  void print();
}; 

MinHeap::MinHeap(int size)
{
  this->size = size;
  this->length = 0;
  arr = new int[size];
}

bool MinHeap::Empty()
{
  return length == 0;
}

bool MinHeap::Full()
{
  return length == size;
}

int MinHeap::Size()
{
  return length;
}

void MinHeap::Push(int element)
{
  if (length == size)
  {
    cout << "OverFlow : Heap is Full\n";
    return;
  }
  length++;
  int i = length - 1;
  arr[i] = element;
  
  while (i != 0 && arr[parent(i)] > arr[i])
  {
    swap(arr[i], arr[parent(i)]);
    i = parent(i);
  }
}

void MinHeap::MinHeapify(int index)
{
  int l = left(index);
  int r = right(index);
  int Min = index;
  if (l < length && arr[l] < arr[Min])
    Min = l;
  if (r < length && arr[r] < arr[Min])
    Min = r;
  if (Min != index)
  {
    swap(arr[index], arr[Min]);
    MinHeapify(Min); // make this operation again to make the min heap again
  }
}

int MinHeap::Pop()
{
  if (Empty())
  {
    cout << "Out Of Range : Heap is Empty\n";
    return INT_MAX;
  }
  else if (length == 1)
  {
    length--;
    return arr[0]; 
  }
  int root = arr[0];
  arr[0] = arr[length - 1];
  length--;
  MinHeapify(0); // make it min heap 
  return root;
}

void MinHeap::DecreaseKey(int index)
{
  arr[index] = INT_MIN;
  while(index != 0 && arr[index] < arr[parent(index)])
  {
    swap(arr[index], arr[parent(index)]);
    index = parent(index);
  }
}

void MinHeap::DeleteKey(int index)
{
  if (index < 0 || index >= length)
  {
    cout << "OverFlow !! Out Of Range !!";
    return;
  }
  DecreaseKey(index);
  Pop();
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

int MinHeap::top()
{
  if (Empty())
  {
    cout << "Out Of Range : Heap is Empty\n";
    return -1;
  }
  return arr[0];
}

void MinHeap::print()
{
  cout << "Heap: [ ";
  for (int i = 0; i < length; i++)
    cout << arr[i] << ' ';
  cout << "]\n";
}

int MinHeap::Height()
{
  return ceil(log2(size + 1));
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
    MH.Push(x);
  }
  MH.print();
  cout << "Top : " << MH.top() << '\n';

  cout << "Enter The index u want to delete : ";
  int ind;
  cin >> ind;
  MH.DeleteKey(ind);

  MH.print();
  cout << "Size : " << MH.Size() << '\n';

  cout << "Print Using Pop !!\n";
  while(!MH.Empty())
  {
    cout << MH.top() << ' ';
    MH.Pop();
  }
  cout << "\n";
}