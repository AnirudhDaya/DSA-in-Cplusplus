#include <bits/stdc++.h>
using namespace std;
int countmaze(int n, int i,int j)
{  if(i==n-1 && j==n-1)
    return 1;
   if(i>=n || j>=n)
   {
       return 0;
   } 
return countmaze(n,i+1,j)+countmaze(n,i,j+1);
}
int main()
{
    cout<<countmaze(3,0,0)<<endl;
}