#include <bits/stdc++.h>

using namespace std;

int main()

{

int i,currcount=1,maxcount=INT_MIN;

string str="abcaacbade";

sort(str.begin(),str.end());

for(i=1;i<str.size();i++)

{

if(str[i]==str[i-1])

currcount++;

else

currcount=1;

maxcount=max(maxcount,currcount);

}

cout<<maxcount;

}
