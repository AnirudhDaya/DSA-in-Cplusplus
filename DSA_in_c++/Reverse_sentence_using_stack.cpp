#include <iostream>
#include <stack> //for using stack
using namespace std;

void reverseSentence(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    string s = "Hey, how you doin;)";
    reverseSentence(s);
}