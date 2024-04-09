#include <iostream>
#include <assert.h>
using namespace std;

struct node
{
    int item;
    node * next;
};

class linked_list
{
private:
    node * first;
    node * last;
    int length;
public:
    linked_list();
    bool IsEmpty ();
    void push_back (int element);
    void pop_back ();
    void pop_front ();
    void pop_index (int index);
    void pop_value (int element);
    void print ();
    void clear ();
    ~linked_list();
};

linked_list::linked_list()
{
    first = last = NULL;
    length = 0;
}

bool linked_list::IsEmpty ()
{
    return length == 0;
}


void linked_list::push_back (int elment)
{
    node * newnode = new node;
    newnode->item = elment;
    if (IsEmpty ())
    {
        first = last = newnode;
        newnode->next = NULL;
    }
    else
    {
        last->next = newnode;
        newnode->next = NULL;
        last = newnode;
    }
    length++;
}

void linked_list::pop_back ()
{
    assert (!IsEmpty ());
    if (length == 1)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        node * cur = first;
        while (cur->next != last)
            cur = cur->next;
        last = cur;
        cur = cur->next;
        last->next = NULL;
        delete cur;
        cur = NULL;
    }
    length--;
}

void linked_list::pop_front ()
{
    assert (!IsEmpty ());
    if (length == 1)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        node * cur = first;
        first = first->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
    length--;
}

void linked_list::pop_index (int index)
{
    assert (!IsEmpty ());
    if (index < 0 || index >= length)
        cout << "out Of Range !\n";
    else
    {
        if (index == 0)
            pop_front ();
        else if (index == length - 1)
            pop_back ();
        else
        {
            node * cur = first;
            node * prev = NULL;
            for (int i = 1; i <= index; i++)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            cur->next = NULL;
            delete cur;
            cur = prev = NULL;
        }
        length--;
    }
}

void linked_list::pop_value (int element)
{
    assert (!IsEmpty ());
    if (first->item == element)
        pop_front (), length--;
    else
    {
        node * cur = first;
        node * prev = NULL;
        while (cur->item != element)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur != NULL)
        {
            prev->next = cur->next;
            cur->next = NULL;
            delete cur;
            cur = prev = NULL;
            length--;
        }
    }
}

void linked_list::print ()
{
    for (node * cur = first; cur != NULL; cur = cur->next)
        cout << cur->item << ' ';
    cout << '\n';
}

void linked_list::clear ()
{
    for (node * cur = first->next; cur != NULL; cur = cur->next)
    {
        first->next = NULL;
        delete first;
        first = cur;
    }
    last = first = NULL;
}

linked_list::~linked_list()
{
    clear ();
}

int main (void)
{
    int n;
    cout << "Enter the size : ";
    cin >> n;
    linked_list l;
    cout << "Enter the element!\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back (x);
    }
    l.print ();
    l.pop_back ();
    l.print ();
    l.pop_front ();
    l.print ();
    l.pop_index (2);
    l.print ();
    l.pop_index (1);
    l.print ();
    l.pop_value (5);
    l.print ();
}