#include<iostream>
#include<stack>
using namespace std;

// it will based on increase order
struct Monotonic_stack
{
    // s1 use to push all elements and the s2 use to push the max elements at every push
    stack <int> s1 , s2;
    void push (int n)
    {
        s1.push (n);
        // to push at s2 the element should be bigger than the top or the stack be empty
        if (s2.empty () || n >= s2.top ())
            s2.push (n);
    }

    void pop ()
    {
        if (s1.top () == s2.top ())
            s2.pop ();
        s1.pop ();
    }

    int Max ()
    {
        return s2.top ();
    }

    void clear ()
    {
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
    }
};

int main()
{
    Monotonic_stack s;
    int n;
    cout << "Enter the size : ";
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        s.push (x);
        cout << s.Max () << '\n';
    }
    s.pop ();
    cout << s.Max () << '\n';
    s.pop ();
    cout << s.Max () << '\n';
    s.pop ();
    cout << s.Max () << '\n';
}