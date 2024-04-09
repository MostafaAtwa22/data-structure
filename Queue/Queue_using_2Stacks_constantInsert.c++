#include<iostream>
#include<cassert>
#include<stack>
using namespace std;

/* 
* add     : O(1)
* pop     : O(n)
* fornt   : O(n)
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
    st1.push(element);
    len++;
}

int Queue::pop()
{
    assert(!isEmpty());
    move(st1, st2);
    int val = st2.top();
    st2.pop();
    move(st2, st1);
    --len;
    return val;
}

int Queue::front()
{
    assert(!isEmpty());
    move(st1, st2);
    int val = st2.top();
    move(st2, st1);
    return val;
}

bool Queue::isEmpty()
{
    return len == 0;
}

void Queue::print()
{
    move(st1, st2);
    stack<int> st = st2;
    cout << "Queue : [ ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "]\n";
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