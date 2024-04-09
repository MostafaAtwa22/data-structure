#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
* 1-  reverse subwords => reverse words between every space
* 2-  reverse number 
* 3-  valid parentheses
* 4-  remove adjacent duplicates => remove every simillar char after each other
*/

string reverse_subwords (string s) 
{
    string ans = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            st.push(s[i]);
        if (i == s.size() - 1 || s[i] == ' ')
        {
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            if (i != s.size() - 1)
                ans += " ";
        }
    }
    return ans;
}

int reverse_number (int num) 
{
    int tens = 1;
    stack<int> st;
    while (num)
    {
        st.push(num % 10);
        num /= 10;
    }
    while (!st.empty())
    {
        num = (st.top() * tens) + num;
        tens *= 10;
        st.pop();
    }
    return num;
}

bool balanced (char open, char close)
{
    return (open == '(' && close == ')' || open == '{' && close == '}' || open == '[' && close == ']');
}

bool valid_Parentheses (string expression)
{
    stack<char> st;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            st.push(expression[i]);
        else 
        {
            if (st.empty() || !balanced(st.top(), expression[i]))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

string Remove_Adjacent(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
        {
            while (!st.empty() && st.top() == s[i])
                st.pop();
        }
    }
    s = "";
    while (!st.empty())
    {
        s = st.top() + s;
        st.pop();
    }
    return (s == "") ? "Empty String !!" : s;
}

int main (void) 
{
    cout << "1 - Enter the words : ";
    string word;
    getline(cin, word);
    cout << "Reversed subwords : " << reverse_subwords(word) << '\n';

    cout << "2 - Enter the Number : ";
    int num;
    cin >> num;
    cout << "Reversed Number : " << reverse_number(num) << '\n';

    cout << "3 - Enter Expression : ";
    string exp;
    cin >> exp;
    (valid_Parentheses(exp)) ? cout << "True Expression !\n" : cout << "False Expression !\n";

    cout << "Enter the String : ";
    string s;
    cin >> s;
    cout << "Remove Adjacent : " << Remove_Adjacent(s) << '\n';
}