#include<iostream>
#include<cassert>
#include<stack>
using namespace std;

/* 
* add     : O(n)
* pop     : O(1)
* fornt   : O(1)
* isEmpty : O(1)
* print   : O(n)
*/

class Queue
{
private:
    stack<int> st1, st2;
    void move(stack<int> &from, stack<int> &to);
    int len;

public:
    Queue();
    void push(int element);
    int pop();
    bool isEmpty();
    void print();
    int front();
};

Queue::Queue()
{
    len = 0;
}

void Queue::move(stack<int> &from, stack<int> &to) 
{		
    while(!from.empty()) 
    {
        to.push(from.top());
        from.pop();
    }
}


void Queue::push(int element)
{
    move(st1, st2);
    st1.push(element);
    move(st2, st1);
    len++;
}

int Queue::pop()
{
    assert(!isEmpty());
    int val = st1.top();
    st1.pop();
    --len;
    return val;
}

bool Queue::isEmpty()
{
    return len == 0;
}

void Queue::print()
{
    stack<int> st = st1;
    cout << "Queue : [ ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "]\n";
}

int Queue::front()
{
    return st1.top();
}

int main() 
{
    Queue q;
    cout << "Enter the size : ";
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    q.print();
    cout << "Front = [ " << q.front() <<  " ]\n";
    q.pop();
    q.print();
    cout << "Front = [ " << q.front() <<  " ]\n";
    q.pop();
    q.print();
    cout << "Front = [ " << q.front() <<  " ]\n";
    q.pop();
    q.print();
    cout << "Front = [ " << q.front() <<  " ]\n";
}