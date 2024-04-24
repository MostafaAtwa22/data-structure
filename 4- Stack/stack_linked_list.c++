#include <iostream>
#include <cassert>
using namespace std;

struct node
{
    int val;
    node *next;
};

class Stack
{
private:
    node *top;
    int length;

public:
    Stack();
    bool empty();
    void push(int element);
    void pop();
    int pop_top();
    int peek();
    void print();
    int size();
    void clear();
    ~Stack();
};

Stack::Stack()
{
    top = NULL;
    length = 0;
}

bool Stack::empty()
{
    return top == NULL;
}

void Stack::push(int element)
{
    node *newnode = new node;
    newnode->val = element;
    newnode->next = top;
    top = newnode;
    length++;
}

void Stack::pop()
{
    assert(!empty());
    node *cur = top;
    top = top->next;
    cur->next = NULL;
    delete cur;
    cur = NULL;
    length--;
}

int Stack::pop_top()
{
    assert(!empty());
    int element = top->val;
    node *cur = top;
    top = top->next;
    cur->next = NULL;
    delete cur;
    cur = NULL;
    length--;
    return element;
}

int Stack::peek()
{
    return top->val;
}

void Stack::print()
{
    cout << "Stack : [";
    for (node *i = top; i != NULL; i = i->next)
        cout << i->val << ' ';
    cout << "] !!?\n";
}

int Stack::size()
{
    return length;
}

void Stack::clear()
{
    node *prev = top;
    while (top != NULL)
    {
        prev = top->next;
        top->next = NULL;
        delete top;
        top = prev;
    }
    top = prev = NULL;
}

Stack::~Stack()
{
    clear();
}

int main()
{
    int size;
    cout << "Enter the size of the stack : ";
    cin >> size;
    Stack s;
    cout << "Enter the Elements !\n";
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    s.print();
    s.pop();
    cout << "Top : " << s.peek() << '\n';
    cout << "Size : " << s.size() << '\n';
    s.print();
    cout << "Top Deleted : " << s.pop_top() << '\n';
    cout << "Top : " << s.peek() << '\n';
    cout << "Size : " << s.size() << '\n';
    s.print();
    s.push(44);
    s.push(14);
    s.print();
    s.push(14);
}