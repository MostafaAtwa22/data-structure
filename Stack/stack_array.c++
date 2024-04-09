#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *arr{};

public:
    Stack();
    Stack(int size);
    bool full();
    bool empty();
    void push(int element);
    void insert_at_the_bottom(int element);
    void pop();
    int pop_top();
    int peek();
    void print();
    void reverse();
    int length();
    void clear();
    ~Stack();
};

Stack::Stack() 
{
    this->top = -1;
    this->size = 100;
    this->arr = new int[size];
}

Stack::Stack(int size)
{
    this->top = -1;
    this->size = size;
    this->arr = new int[size];
}

bool Stack::full() 
{
    return top == this->size - 1;
}

bool Stack::empty()
{
    return top == -1;
}

void Stack::push(int element)
{
    assert(!full());
    arr[++top] = element;
}

void Stack::insert_at_the_bottom(int element)
{
    if (empty())
        push(element);
    else
    {
        int cur = pop_top();
        insert_at_the_bottom(element);
        push(cur);
    }
}

void Stack::pop()
{
    assert(!empty());
    --top;
}

int Stack::pop_top()
{
    int element = arr[top--];
    return element;
}

int Stack::peek()
{
    return arr[top];
}

int Stack::length()
{
    return top + 1;
}

void Stack::print() 
{
    cout << "Stack : [ ";
    for (int i = top; i >= 0; i--)
        cout << arr[i] << ' ';
    cout << "]\n";
}

void Stack::reverse() 
{
    if (empty())
        return;
    int cur = pop_top();
    reverse();
    insert_at_the_bottom(cur);
}

void Stack::clear()
{
    delete[] arr;
}

Stack::~Stack()
{
    clear();
}

void delete_middle (Stack &st, int n, int cur)
{
    if (st.empty() || n == cur)
    {
        st.reverse();
        return;
    }

    int top = st.pop_top();

    delete_middle(st, n, cur + 1);

    if (cur != floor(n / 2) + 1)
        st.push(top);
}

int main () 
{
    int size;
    cout << "Enter the size of the stack : ";
    cin >> size;
    Stack s(size);
    cout << "Enter the Elements !\n";
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    s.print();
    s.print();
    s.pop();
    cout << "Top : " << s.peek() << '\n';
    cout << "Size : " << s.length ()<< '\n';
    s.print();
    cout << "Top Deleted : " << s.pop_top() << '\n';
    cout << "Top : " << s.peek() << '\n';
    cout << "Size : " << s.length ()<< '\n';
    s.print();
    s.push(14);
    s.print();
    s.insert_at_the_bottom(10);
    s.print();
    s.reverse();
    s.print();
    delete_middle(s, s.length(), 0);
    s.print();
}