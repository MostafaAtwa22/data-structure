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
    void reverse ();
    bool search (int element);
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

void linked_list::reverse ()
{
    assert (!IsEmpty ());
    if (length == 1)
        return;
    node * prev = NULL;
    node * cur = first;
    node * next = NULL;
    while (next != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    last = first;
    first = prev;
}

bool linked_list::search (int element)
{
    for (node * cur = first; cur != NULL; cur = cur->next)
        if (cur->item == element)
            return true;
    return false;
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
    l.reverse ();
    l.print ();
    (l.search (3)) ? cout << "Found\n" : cout << "Not Found\n";
}