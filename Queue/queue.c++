#include<iostream>
#include<cassert>
using namespace std;

struct node
{
    int val;
    node *next;
};

class queue
{
private:
    int length;
    node *first, *last;

public:
    queue();
    int size();
    bool isEmpty();
    void push(int element);
    void pop();
    void print();
    int front();
    void clear();
    ~queue();
};

queue::queue()
{
    first = last = NULL;
    length = 0;
}

int queue::size() 
{
    return length;
}

bool queue::isEmpty()
{
    return first == NULL;
}

void queue::push(int element)
{
    node *newnode = new node;
    newnode->val = element;
    newnode->next = NULL;
    if (isEmpty())
        first = last = newnode;
    else
    {
        last->next = newnode;
        last = newnode;
    }
    length++;
}

void queue::pop()
{
    assert(!isEmpty());
    node *cur = first;
    first = first->next;
    delete cur;
    cur = nullptr;
    length--;
}

int queue::front() 
{
    assert(!isEmpty());
    return first->val;
}

void queue::clear()
{
    node *cur = NULL;
    while (cur) 
    {
        cur = first->next;
        delete first;
        first = cur;
    }
    first = cur = last = NULL;
}

void queue::print()
{
    assert(!isEmpty());
    cout << "Queue : [ ";
    for (node * i = first; i != NULL; i = i->next)
        cout << i->val << ' ';
    cout << "]\n";
}

queue::~queue()
{
    clear();
}

int main() 
{
    queue q;
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
    q.pop();
    q.print();
    cout << "Front : " << q.front() << '\n';
}