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
    cout << "[ ";
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


class Priority_Queue
{
private:
    int size;
    int len;
    Queue q1, q2, q3;

public:
    Priority_Queue(int size);
    void push(int element, int priority);
    int pop();
    bool isEmpty();
    bool isFull();
    void print();
};

Priority_Queue::Priority_Queue(int size) : q1(size), q2(size), q3(size) 
{
    this->size = size;
    len = 0;
}


void Priority_Queue::push(int element, int priority)
{
    assert(!isFull());
    if (priority == 3)
        q3.push(element);
    else if (priority == 2)
        q2.push(element);
    else if (priority == 1)
        q1.push(element);
    else
        assert(false);
    len++;
}

int Priority_Queue::pop()
{
    assert(!isEmpty());
    len--;
    if (!q3.isEmpty())
        return q3.pop();
    else if (!q2.isEmpty())
        return q2.pop();
    return q1.pop();
}

bool Priority_Queue::isEmpty()
{
    return len == 0;
}

bool Priority_Queue::isFull()
{
    return len == size;
}

void Priority_Queue::print()
{
    assert(!isEmpty());
    if (!q3.isEmpty())
    {
        cout << "Priority #3 tasks : ";
        q3.print();
    }
    if (!q2.isEmpty())
    {
        cout << "Priority #2 tasks : ";
        q2.print();
    }
    if (!q1.isEmpty())
    {
        cout << "Priority #1 tasks : ";
        q1.print();
    }
}

int main()
{
    Priority_Queue tasks(8);

	tasks.push(1131, 1);
	tasks.push(3111, 3);
	tasks.push(2211, 2);
	tasks.push(3161, 3);

	tasks.print();
	//Priority #3 tasks : [ 3111 3161 ]
	//Priority #2 tasks : [ 2211 ]
	//Priority #1 tasks : [ 1131 ]

	cout << tasks.pop() << "\n";	// 3111
	cout << tasks.pop() << "\n";	// 3161

	tasks.push(1535, 1);
	tasks.push(2815, 2);
	tasks.push(3845, 3);
	tasks.push(3145, 3);

	tasks.print();
	//Priority #3 tasks: 3845 3145
	//Priority #2 tasks: 2211 2815
	//Priority #1 tasks: 1131 1535

    cout << "Priority Queue : [ ";
    while (!tasks.isEmpty())
		cout << tasks.pop() << " ";
    cout << "]\n";
}