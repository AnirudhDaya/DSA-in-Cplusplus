#include <bits/stdc++.h>
using namespace std;
int tilings(int n)
{  if(n==0)
    return 0;
   if(n==1)
   {
       return 1;
   } 
return tilings(n-1)+tilings(n-2);
}
int main()
{
    cout<<tilings(4)<<endl;
}