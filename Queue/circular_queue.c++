#include<iostream>
#include<cassert>
using namespace std;

class Queue
{
private:
    int size;
    int count;
    int first;
    int last;
    int *arr;

public:
    Queue(int size);
    int length();
    bool isEmpty();
    bool isFull();
    void push(int element);
    int pop();
    void print();
    int front();
    void clear();
    ~Queue();
};

Queue::Queue(int size)
{
    this->size = size;
    first = 0;
    last = size - 1;
    count = 0;
    arr = new int[size];
}

int Queue::length()
{ 
    return count;
}

bool Queue::isEmpty()
{
    return count == 0;
}

bool Queue::isFull()
{
    return count == size;
}

void Queue::push(int element)
{
    assert(!isFull());
    last = (last + 1) % size;
    arr[last] = element;
    count++;
}

int Queue::pop()
{
    assert(!isEmpty());
    int temp = arr[first];
    first = (first + 1) % size;
    count--;
    return temp;
}

void Queue::print()
{
    assert(!isEmpty());
    cout << "Queue : [";
    for (int i = first; i != last; i = (i + 1) % size)
        cout << arr[i] << ' ';
    cout << arr[last] << " ]\n";
}

int Queue::front()
{
    return arr[this->first];
}

void Queue::clear()
{
    delete[] arr;
}

Queue::~Queue()
{
    clear();
}

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    Queue s(n);

    while (n--)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    s.print();
    cout << "Front : " <<s.front() << '\n';
    s.pop();
    cout << "Print Use While Loop : ";
    while (!s.isEmpty())
    {
        cout << s.pop() << ' ';
    }
}