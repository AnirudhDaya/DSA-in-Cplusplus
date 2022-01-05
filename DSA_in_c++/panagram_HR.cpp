#include <bits/stdc++.h>
using namespace std;

string panagram(string s)
{
    transform(s.begin(),s.end(),s.begin(),::tolower);
    int i;
    int count[26]={0};
        for(i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                count[s[i]-'a']++;
            }
        }
     for(i=0;i<26;i++)
     {
         if(count[i]==0)
         return "not panagram";
     }
    return "panagram";
}
int main()
{    string s;
    cout<<"Enter the string\n";
    getline(cin,s);
    cout<<endl;
    cout<<"answer is:\n"<<panagram(s);
}

