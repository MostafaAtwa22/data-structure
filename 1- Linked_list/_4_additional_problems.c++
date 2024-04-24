#include <iostream>
#include <assert.h>
#include <vector>
#include <cmath>
using namespace std;

/*
    the problems:
        1- delete all nodes with key [void delete_key (int element)]
        2- delete odd positions [void delete_odd ()]
        3- delete even positions [void delete_even ()]
        4- check if linked list is palindrome [bool palindrome ()]
*/
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
    /* ------ */
    void delete_key (int element);
    void delete_odd1 ();
    void delete_odd2 ();
    void delete_even ();
    bool palindrome ();
    /* ------ */
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

void linked_list::print ()
{
    assert (!IsEmpty ());
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

/*****************************************/
void linked_list::delete_key (int element)
{
    assert (!IsEmpty ());
    node * cur = first;
    node * prev = NULL;
    while (cur != NULL)
    {
        bool ch = 1;
        if (cur->item == element)
        {
            if (cur == first)
            {
                first = first->next;
                cur->next = NULL;
                delete cur;
                cur = first;
                ch = 0;
            }
            else if (cur == last)
            {
                last = prev;
                last->next = NULL;
                delete cur;
                break;
            }
            else
            {
                prev->next = cur->next;
                cur->next = NULL;
                delete cur;
                cur = prev->next;
                ch = 0;
            }
            length--;
        }
        if (ch)
        {
            prev = cur;
            cur = cur->next;
        }
    }
    prev = cur = NULL;
}

void linked_list::delete_odd1 ()
{
    assert (!IsEmpty ());
    node * cur = first;
    first = first->next;
    cur->next = NULL;
    delete cur;
    length--;
    if (length == 0)
        return;
    delete_even ();
}

void linked_list::delete_odd2 ()
{
    assert (!IsEmpty ());
    node * cur = first;
    node * next = first->next;
    first = first->next;
    while (cur != NULL)
    {
        cur->next = NULL;
        delete cur;
        length--;   
        if (next == NULL || next->next == NULL)
            break;
        cur = next->next;
        if (last == cur)
            last = next;
        next->next = cur->next;
        next = cur->next;
    }
    next = cur = NULL;
}

void linked_list::delete_even ()
{
    assert (!IsEmpty ());
    if (length == 1)
        return;
    node * cur = first->next;
    node * prev = first;
    while (cur != NULL)
    {
        prev->next = cur->next;
        prev = cur->next;
        cur->next = NULL;
        delete cur;
        length--;
        if (prev == NULL)
            break;
        cur = prev->next;
        if (cur == last)
            last = prev;
    }
    cur = prev = NULL;
}

bool linked_list::palindrome ()
{
    vector <int> v;
    for (node * cur = first; cur != NULL; cur = cur->next)
        v.push_back (cur->item);
    int i = 0, j = v.size () - 1;
    while (i <= j)
    {
        if (v[i] != v[j])
            return false;
        i++, j--;
    }
    return true;
}

/*****************************************/
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
    l.delete_odd2 ();
    l.print ();
}