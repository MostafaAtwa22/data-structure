#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

/*
 * 1- Asteroid Collision
 * 2- Next Greater Element => Given an array, for every number, find the first number after it of a higher value
 * 3- score of parentheses => compute the score of the string () => 1, (()) => 2, ()() => 2, (()()) => 4
 */

vector<int>& Asteroid_Collision (vector<int> & arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); ++i)
    {
        int asteroid = arr[i];
        bool is_exploded = false;
        while (!st.empty() && asteroid < 0 && st.top() >= 0)
        {
            if (st.top() < -asteroid)
            {
                st.pop();
                continue;
            }
            else if (st.top() == -asteroid) 
                st.pop();
            is_exploded = true; 
            break;
        }
        if (!is_exploded)
            st.push(asteroid);
    }
    arr.clear();
    while (!st.empty())
    {
        arr.push_back(st.top());
        st.pop();
    }
    reverse(arr.begin(), arr.end());
    return arr;
}

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    int n = temperatures.size();
    stack<pair<int, int>> stk;
    vector<int> result(n, -1);
    
    for (int i = 0; i < n; i++) 
    {
        int currDay = i;
        int currTemp = temperatures[i];
        while (!stk.empty() && stk.top().second < currTemp) 
        {
            int prevDay = stk.top().first;
            int prevTemp = stk.top().second;
            stk.pop();
            
            result[prevDay] = currTemp;
        }
        stk.push({currDay, currTemp});
    }
    
    return result;
}

int Score_of_Parentheses (string s)
{
    stack<int> st;
    int score = 0;
    for (auto i : s)
    {
        if (i == '(') 
        {
            st.push(score);
            score = 0;
        }
        else
        {
            score = st.top() + max(score * 2, 1);
            st.pop();
        }
    }
    return score;
}



int main(void)
{
    // cout << "Enter the size of array : ";
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // cout << "Enter the array !\n";
    // for (auto &i : v)
    //     cin >> i;
    // vector<int> ans;
    // ans =  Asteroid_Collision(v);
    // cout << "Asteroid Collision : ";
    // for (auto i : ans)
    //     cout << i << ' ';
    // cout << '\n';
    
    // // Next Greatest element
    // cout << "Enter the size of array : ";
    // int s;
    // cin >> s;
    // vector<int> temp(s);
    // cout << "Enter the array !\n";
    // for (auto &i : temp)
    //     cin >> i;
    // vector<int> res;
    // res =  dailyTemperatures(temp);
    // cout << "Next Greatest elements : ";
    // for (auto i : res)
    //     cout << i << ' ';
    // cout << '\n';

    // // score of parentheses
    // cout << "Enter the Parentheses Expression : ";
    // string parentheses;
    // cin >> parentheses;
    // cout << "Score : " << Score_of_Parentheses(parentheses) << '\n';

    cout << "Enter the Size of Stack : ";
    int size;
    cin >> size;
    stack<int> st;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    delete_middle(st, size, 0);
    cout << "Stack : [ ";
    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << "]";
}