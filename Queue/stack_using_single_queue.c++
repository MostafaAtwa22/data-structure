#include<iostream>
#include<cassert>
#include<queue>
using namespace std;

class Stack
{
private:
    queue<int> q;
    int length;
    void insert(int element);

public:
    Stack();
    bool isEmpty();
    void push(int element);
    int pop();
    int size();
    int top();
    void print();
};

Stack::Stack()
{
    length = 0;
}
void Stack::insert(int element) 
{
    q.push(element);
    int x = length;
    while (x--)
    {
        q.push(q.front());
        q.pop();
    }
    length++;
}
bool Stack::isEmpty()
{
    return q.empty();
}
void Stack::push(int element)
{
    insert(element);
}
int Stack::pop()
{
    assert(!isEmpty());
    int element = q.front();
    q.pop();
    length--;
    return element;
}
int Stack::top()
{
    return q.front();
}
int Stack::size()
{
    return length;
}
void Stack::print()
{
    queue<int> copy = q;
    cout << "Stack : [ ";
    while (!copy.empty())
    {
        cout << copy.front() << ' ';
        copy.pop();
    }
    cout << "]\n";
}

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    Stack s;

    while (n--)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    s.print();
    cout << "Top : " << s.top() << '\n';
    s.top();
    cout << s.pop() << '\n';
    s.print();
    cout << "Print Use While Loop : ";
    while (!s.isEmpty())
    {
        cout << s.pop() << ' ';
    }
}