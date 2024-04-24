#include <iostream>
#include <cassert>
using namespace std;

/*
 * int this problem we want to make 2 stacks in the same stack one add from begin and one from end
 */
class Stack
{
private:
    int top1 {};
    int top2 {};
    int size;
    int *arr{};

public:
    Stack();
    Stack(int size);
    bool full();
    void push(int id, int element);
    void pop(int id);
    int pop_top(int id);
    int peek(int id);
    void print();
    void clear();
    ~Stack();
};

Stack::Stack()
{
    this->top1 = -1;
    this->top2 = size;
    this->size = 100;
    this->arr = new int[size];
}

Stack::Stack(int size)
{
    this->top1 = -1;
    this->top2 = size;
    this->size = size;
    this->arr = new int[size];
}

bool Stack::full()
{
    return top1 == top2;
}


void Stack::push(int id, int element)
{
    assert(!full());
    (id == 1) ? arr[++top1] = element : arr[--top2] = element;
}

void Stack::pop(int id)
{
    if (id == 1 && top1 > -1)
        top1--;
    else if (id == 2 && top2 < size)
        top2++;
}

int Stack::pop_top(int id)
{
    if (id == 1)
        return arr[top1--];
    return arr[top2++];
}

int Stack::peek(int id)
{
    if (id == 1)
        return arr[top1];
    return arr[top2];
}

void Stack::print()
{
    cout << "Stack 1 : [ ";
    for (int i = top1; i >= 0; i--)
        cout << arr[i] << ' ';
    cout << "]\n";
    cout << "Stack 2 : [ ";
    for (int i = top2; i < size; i++)
        cout << arr[i] << ' ';
    cout << "]\n";
}

void Stack::clear()
{
    delete[] arr;
}

Stack::~Stack()
{
    clear();
}

int main()
{
    Stack stk(10);
    stk.push(2, 5);
    stk.push(2, 6);
    stk.pop(2);
    stk.push(2, 7);
    stk.push(2, 9);

    stk.push(1, 4);
    stk.push(1, 6);
    stk.push(1, 8);
    stk.print();
}