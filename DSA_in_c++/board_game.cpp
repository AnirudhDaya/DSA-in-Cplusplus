#include <bits/stdc++.h>
using namespace std;
int count(int s, int e)
{  if(s==e)
    return 1;
   if(s>e)
   {
       return 0;
   } 
   int cunt=0;
   for(int i=1;i<7;i++)
   {
       cunt+=count(s+i,e);
   }
   return cunt;
}
int main()
{
    cout<<count(0,3)<<endl;
}