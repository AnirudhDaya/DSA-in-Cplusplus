#include <bits/stdc++.h>
using namespace std;

void longest_substring_without_repetition(string s)
{
   int n=s.size();
   vector<int> dict(256,-1); //intializes 256 places with value -1
   int maxlen=0;
   int start=-1;

   for(int i=0;i<n;i++)
   {
       if(dict[s[i]]>start)
        start=dict[s[i]];

        dict[s[i]]=i;
        maxlen=max(maxlen,i-start);
   }
   cout<<maxlen<<endl;
}
int main()
{
        string s;
    cout<<"Enter the string:\n";
    getline(cin,s);

   longest_substring_without_repetition(s);
}