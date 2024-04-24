#include<iostream>
#include<queue>
#include<deque>
#include<cassert>

using namespace std;

class monotonic_queue
{
private:
    queue<int> q;
    deque<int> dq;

public:
    void push(int element);
    int pop();
    int Max();
    bool empty();
    int size();
};

void monotonic_queue::push(int element)
{
    q.push(element);
    while(!dq.empty() && dq.back() < element)
        dq.pop_back();
    dq.push_back(element);
}
int monotonic_queue::pop()
{
    assert(!empty());
    int element = q.front();
    if (q.front() == dq.front())
        dq.pop_front();
    q.pop();
    return element;
}
int monotonic_queue::Max()
{
    assert(!empty());
    return dq.front();
}
bool monotonic_queue::empty()
{
    return q.empty();
}
int monotonic_queue::size()
{
    return q.size();
}

int main()
{
    monotonic_queue q;
    cout << "Enter the size : ";
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        q.push (x);
        cout << q.Max () << '\n';
    }
    q.pop ();
    cout << q.Max () << '\n';

    q.pop ();
    cout << q.Max () << '\n';

    q.pop ();
    cout << q.Max () << '\n';

    q.pop ();
    cout << q.Max () << '\n';
}