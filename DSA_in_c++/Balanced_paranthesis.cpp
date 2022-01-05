#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    int i, n = s.size();
    stack<char> st;
    bool ans = true;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            st.push(s[i]);

        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
            {
                ans = false;
                break;
            }
        }

        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
            {
                ans = false;
                break;
            }
        }

        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
            {
                ans = false;
                break;
            }
        }
    }
    if(!st.empty())
    {
        return false;
    }
    return ans;
}

int main()
{
    string s = "{([])}}";
    if (isValid(s))
    {
        cout << "Valid String\n";
    }
    else
        cout << "Invalid String\n";
}