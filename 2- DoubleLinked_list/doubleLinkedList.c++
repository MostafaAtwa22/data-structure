#include <iostream>
#include <assert.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node *prev;
};

class doubleLinkedList
{
private:
    node *head;
    node *tail;
    int length;

public:
    void clear();
    bool empty();
    int size();
    void push_front(int element);
    void push_back(int element);
    void add_index(int element, int index);
    void pop_front();
    void pop_back();
    void delete_element(int element);
    void delete_index(int index);
    void print();
    void print_reverse();
    doubleLinkedList();
    ~doubleLinkedList();
};

doubleLinkedList::doubleLinkedList()
{
    head = tail = NULL;
    length = 0;
}

bool doubleLinkedList::empty()
{
    return length == 0;
}

int doubleLinkedList::size() 
{
    return length;
}

void doubleLinkedList::push_front(int element) 
{
    node *newnode = new node;
    newnode->val = element;
    if (empty())
    {
        head = tail = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else 
    {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
    length++;
}

void doubleLinkedList::push_back(int element) 
{
    node *newnode = new node;
    newnode->val = element;
    if (empty())
    {
        head = tail = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else
    {
        newnode->next = NULL;
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
    length++;
}

void doubleLinkedList::add_index(int element, int index)
{
    if (index <= 0 || index > length) 
        cout << "Out Of Range !!?";
    else if (index == 0)
        push_front(element);
    else if (index == length)
        push_back(element);
    else 
    {
        node *newnode = new node;
        newnode->val = element;
        node *cur = head;
        for (int i = 1; i < index; i++)
            cur = cur->next;
        newnode->next = cur->next;
        newnode->prev = cur;
        cur->next->prev = newnode;
        cur->next = newnode;
        length++;
    }
}

void doubleLinkedList::pop_front()
{
    assert(!empty());
    node *cur = head;
    head = head->next;
    head->prev = NULL;
    cur->next = NULL;
    delete cur;
    length--;
}

void doubleLinkedList::pop_back()
{
    assert(!empty());
    node *cur = tail;
    tail = tail->prev;
    tail->next = NULL;
    cur->prev = NULL;
    delete cur;
    length--;
}

void doubleLinkedList::delete_element(int element)
{
    assert(!empty());
    if (element == head->val)
        pop_front();
    else 
    {
        node *cur = head;
        while (cur != NULL && cur->val != element)
            cur = cur->next;
        if (cur == NULL)
            cout << "Element Not Found !!?\n";
        else if (cur == tail)
            pop_back();
        else
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->next = cur->prev = NULL;
            delete cur;
            length--;
        }
    }
}

void doubleLinkedList::delete_index(int index)
{
    assert(!empty());
    if (index < 0 || index >= length)
        cout << "Out Of Range !!?";
    else if (index == 0)
        pop_front();
    else if (index == length - 1)
        pop_back();
    else 
    {
        node *cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->next = cur->prev = NULL;
        delete cur;
        length--;
    }
}

void doubleLinkedList::print ()
{
    assert(!empty ());
    cout << "List : [ ";
    for (node *i = head; i != NULL; i = i->next)
        cout << i->val << ' ';
    cout << "] !!?\n";
}

void doubleLinkedList::print_reverse()
{
    assert(!empty());
    cout << "List_reversed : [ ";
    for (node *i = tail; i != NULL; i = i->prev)
        cout << i->val << ' ';
    cout << "] !!?\n";
}

void doubleLinkedList::clear()
{
    node *cur = NULL;
    while (head) {
        cur = head;
        head = head->next;
        delete cur;
    }
    head = tail = cur = NULL;
}

doubleLinkedList::~doubleLinkedList()
{
    clear();
}


int main () 
{
    doubleLinkedList l;
    cout << "Enter the size : ";
    int n;
    cin >> n;
    cout << "Enter the Elements !\n";
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    l.print();
    l.print_reverse();
    l.push_front(0);
    l.print();
    l.print_reverse();
    l.add_index(22, 3);
    l.print();
    l.print_reverse();
    l.pop_back();
    l.print();
    l.print_reverse();
    l.pop_front();
    l.print();
    l.print_reverse();
    l.delete_element(22);
    l.print();
    l.print_reverse();
    l.delete_index(1);
    l.print();
    l.print_reverse();
}