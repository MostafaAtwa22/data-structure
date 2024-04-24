#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' 
            || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}');
}

int precedence (char s)
{
    if (s == '+' || s == '-')
        return 1;
    else if (s == '*' || s == '/' || s == '%')
        return 2;
    else if (s == '^')
        return 3;
    return 0;
}

string Infix_To_Postfix(string infix) 
{
    string postfix = "";
    stack<char> st;
    for (auto i : infix)
    {
        if (i == ' ')
            continue;
        else if (!isOperator(i))
            postfix += i;
        else if (i == '(' || i == '[' || i == '{')
            st.push(i);
        else if (i == '}' || i == ')' || i == ']')
        {
            while (st.top() != '(' && st.top() != '[' && st.top() !=  '{')
            {
                postfix += st.top();
                st.pop();
            }
            // to clear the open bracket
            st.pop();
        }
        else 
        {
            while ((!st.empty()) && 
            (precedence(i) <= precedence(st.top())))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

string Infix_To_Prefix(string infix)
{
    reverse(infix.begin(), infix.end());
    string prefix = "";
    stack<char> st;
    for (auto i : infix)
    {
        if (i == ' ')
            continue;
        else if (!isOperator(i))
            prefix += i;
        else if (i == '(' || i == '[' || i == '{')
            st.push(i);
        else if (i == '}' || i == ')' || i == ']')
        {
            while (st.top() != '(' && st.top() != '[' && st.top() !=  '{')
            {
                prefix += st.top();
                st.pop();
            }
            // to clear the open bracket
            st.pop();
        }
        else 
        {
            while ((!st.empty()) && 
            (precedence(i) < precedence(st.top())))
            {
                prefix += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

long double Math_Operation (long double number1, long double number2, char operat)
{
    switch (operat)
    {
    case '+':
        return number1 + number2;
        break;
    case '-':
        return number1 - number2;
        break;
    case '*':
        return number1 * number2;
        break;
    case '/':
        return number1 / number2;
        break;
    default:
        return pow(number1, number2);
        break;
    }
    return 0;
}

long double Posfix_Evaluation (string postfix)
{
    stack<long double> st;
    for (auto ch : postfix)
    {
        if (isOperator(ch))
        {
            long double second = st.top();
            st.pop();

            long double first = st.top();
            st.pop();

            long double result = Math_Operation(first, second, ch);
            st.push(result);
        }
        else
            st.push((long double)(ch - '0'));
    }
    return st.top();
}

long double Prefix_Evaluation (string prefix)
{
    stack<long double> st;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            long double first = st.top();
            st.pop();

            long double second = st.top();
            st.pop();

            long double result = Math_Operation(first, second, prefix[i]);
            st.push(result);
        }
        else
            st.push((long double)(prefix[i] - '0'));
    }
    return st.top();
}

string Remove_Expression_Brackets (string s)
{
    string exp = "";
    stack<char> st;
    bool ch = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' && i)
            st.push(s[i - 1]);
        else if (s[i] == ')')
            st.pop();
        if (!st.empty() && st.top() == '-')
        {
            if (s[i] == '-')
                s[i] = '+';
            else if (s[i] == '+')
                s[i] = '-';
        }
        if (s[i] != '(' && s[i] != ')')
            exp += s[i];
    }
    return exp;
}

int main (void)
{
    cout << "Enter the Infix Expression : ";
    string s;
    cin >> s;
    cout << "Infix To Postfix : " << Infix_To_Postfix(s) << '\n';
    cout << "Infix To Prefix : " << Infix_To_Prefix(s) << '\n';

    cout << "Enter the Posfix Experssion : ";
    string Posfix;
    cin >> Posfix;
    cout << "Postfix Evaluation : " << Posfix_Evaluation(Posfix) << '\n';

    cout << "Enter the Prefix Experssion : ";
    string Prefix;
    cin >> Prefix;
    cout << "Prefix Evaluation : " << Prefix_Evaluation(Prefix) << '\n';

    cout << "Enter the Bracket Expression : ";
    string exp;
    cin >> exp;
    cout << "Expression After Removing Brackets : " << Remove_Expression_Brackets(exp) << '\n';
}