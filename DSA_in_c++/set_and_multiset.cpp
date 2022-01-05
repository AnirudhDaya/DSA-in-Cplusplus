#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(5);
   
   for(auto i=s.begin();i!=s.end();i++)
        cout<<*i<<" ";
        cout<<'\n';

  /* cout<<*s.lower_bound(1)<<endl;
   cout<<*s.lower_bound(2)<<endl;
   cout<<*s.lower_bound(3)<<endl;
   cout<<*s.lower_bound(5)<<endl;
   cout<<*s.upper_bound(1)<<endl;
   cout<<*s.upper_bound(2)<<endl;
   cout<<*s.upper_bound(3)<<endl;
   cout<<*s.upper_bound(5)<<endl;*/
    s.erase(s.find(3));
    for(auto i: s)
        cout<<i<<" ";
        cout<<'\n';
}
