#include <bits/stdc++.h>
using namespace std;

void redundant_paranthesis(string a )
{
    stack<char> st;
     bool ans=false;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='/' || a[i]=='+' || a[i]=='-' || a[i]=='*' ) 
            st.push(a[i]);
        else
            if(a[i]=='(')
                st.push(a[i]);
        else
        
            if(a[i]==')')
            {     
                if(st.top()=='(')
                {
                    ans=true;
                }
                while(st.top()=='+' || st.top()=='/' || st.top()=='-' || st.top()=='*')
                    st.pop();
            
            st.pop();   // to remove opening brace;

            }

     }
    cout<<ans<<endl;
}

int main()
{
    string s;
    cout<<"Enter the expression:\n";
    getline(cin,s);

    redundant_paranthesis(s);
}