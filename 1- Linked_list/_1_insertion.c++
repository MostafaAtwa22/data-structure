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
    int size ();
    void push_front (int element);
    void push_back (int element);
    void push_at_index (int index, int element);
    int front ();
    int back ();
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

int linked_list::size ()
{
    return length;
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

void linked_list::push_front (int elment)
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
        newnode->next = first;
        first = newnode;
    }
    length++;
}

void linked_list::push_at_index (int index, int element)
{
    if (index < 0 || index > length)
        cout << "Out of Range!\n";
    else
    {
        if (index == 0)
            push_front (element);
        else if (index == length)
            push_back (element);
        else
        {
            node * newnode = new node;
            newnode->item = element;
            node * cur = first;
            for (int i = 1; i < index; i++)
                cur = cur->next;
            newnode->next = cur->next;
            cur->next = newnode;
            cur = NULL;
        }
        length++;
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

int linked_list::front ()
{
    return first->item;
}

int linked_list::back ()
{
    return last->item;
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
    cout << "Enter from front : ";
    l.push_front (90);
    l.print ();
    cout << "Enter form index : ";
    l.push_at_index (2, 33);
    l.print ();
    cout << "Front : " << l.front () << '\n';
    cout << "Back : " << l.back () << '\n';
}