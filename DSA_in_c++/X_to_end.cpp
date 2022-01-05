#include <bits/stdc++.h>
using namespace std;
string xtoend(string s)
{  if(s.length()==0)
        return "";
    char ch=s[0];
    string ans=xtoend(s.substr(1));
     if(ch=='x')
        return (ans+'x');
    return (ch+ans);

}    
int main()
{
   cout<<xtoend("axxbdxcefxhix")<<endl;
}