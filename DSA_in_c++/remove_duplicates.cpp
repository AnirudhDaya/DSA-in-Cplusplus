#include <bits/stdc++.h>
using namespace std;
string removedupes(string s)
{  if(s.length()==0)
        return "";
    char ch=s[0];
    string ans=removedupes(s.substr(1));
     if(ch==ans[0])
        return ans;
    return (ch+ans);

}    
int main()
{
   cout<<removedupes("aaaabbbeeecdddd")<<endl;
}