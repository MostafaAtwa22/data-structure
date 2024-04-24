#include <iostream>
#include <assert.h>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

/*
    the problems:
        1- chain the odd position with each other first and after that even ones [void Arrange odd & even nodes ()]
        2- add a linked list of elements to the linked list in odd positions [void insert_alternate(LinkedList &another)]
        3- add 2 linked lists [void add_num(LinkedList &another)]
        4- Remove all repeated [void unique ()]
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
    void pop_value (int element);
    void pop_front ();
    /* ------ */
    void Arrange_odd_even_nodes ();
    void insert_alternate(linked_list &another);
    void unique ();
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
void linked_list::Arrange_odd_even_nodes ()
{
    assert (!IsEmpty ());
    if (length < 3)
        return;
    node * odd = first;
    node * even = first->next;
    node * conect = first->next;
    int cntr = 0;
    while (1)
    {
        odd->next = even->next;
        if (even->next != NULL)
            odd = even->next;
        
        even->next = odd->next;
        if (odd->next != NULL)
            even = odd->next;
        
        if (even == last || odd == last)
            break;
    }
    last = even;
    last->next = NULL;
    odd->next = conect;
    odd = even = NULL;
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
    l.Arrange_odd_even_nodes ();
    l.print ();

    // linked_list l2;
    // cout << "Enter another list !";
    // int x;
    // cout << "Enter the size : ";
    // cin >> x;
    // for (int i = 0; i < x; i++)
    // {
    //     int y;
    //     cin >> y;
    //     l2.push_back (y);
    // }
    l.unique ();
    l.print ();
}