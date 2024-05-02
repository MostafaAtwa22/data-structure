#include<iostream>
#include<cmath>
using namespace std;

class MaxHeap
{
private:
  int *arr;
  int size;
  int length;
  void MaxHeapify(int index);
  void DecreaseKey(int index);
public:
  MaxHeap(int size);
  bool Empty();
  bool Full();
  int Size();
  int parent(int child);
  int left(int parent);
  int right(int parent);
  void Push(int element);
  int Pop();
  void DeleteKey(int element);
  int top();  
  int Height();
  void print();
};

MaxHeap::MaxHeap(int size)
{
  this->size = size;
  this->length = 0;
  arr = new int[size];
}

bool MaxHeap::Empty()
{
  return length == 0;
}

bool MaxHeap::Full()
{
  return length == size;
}

int MaxHeap::Size()
{
  return length;
}

void MaxHeap::Push(int element)
{
  if (Full())
  {
    cout << "Overflow: Heap is Full\n";
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

void MaxHeap::MaxHeapify(int index)
{
  int l = left(index);
  int r = right(index);
  int Max = index;
  if (l < length && arr[l] > arr[Max])
    Max = l;
  if (r < length && arr[r] > arr[Max])
    Max = r;
  if (index != Max)
  {
    swap(arr[index], arr[Max]);
    return MaxHeapify(Max);
  }
}

int MaxHeap::Pop()
{
  if (Empty())
  {
    cout << "Out Of Range : Heap is Empty\n";
    return INT_MIN;
  }
  else if (length == 1)
  {
    length--;
    return arr[0]; 
  }
  int root = arr[0];
  arr[0] = arr[length - 1];
  length--;
  MaxHeapify(0); // make it min heap 
  return root;
}

void MaxHeap::DecreaseKey(int index)
{
  arr[index] = INT_MAX;
  while (index != 0 && arr[parent(index)] < arr[index])
  {
    swap(arr[index], arr[parent(index)]);
    index = parent(index);
  }
}

void MaxHeap::DeleteKey(int index)
{
  if (index < 0 || index >= length)
  {
    cout << "OverFlow !! Out Of Range !!";
    return;
  }

  DecreaseKey(index);
  Pop();
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

int MaxHeap::top()
{
  if (Empty())
  {
    cout << "Out Of Range : Heap is Empty\n";
    return -1;
  }
  return arr[0];
}

void MaxHeap::print()
{
  cout << "Heap: [ ";
  for (int i = 0; i < length; i++)
    cout << arr[i] << ' ';
  cout << "]\n";
}

int MaxHeap::Height()
{
  return ceil(log2(size + 1));
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
    MH.Push(x);
  }
  MH.print();
  cout << "Top : " << MH.top() << '\n';
  cout << "Height : " << MH.Height() << '\n';

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