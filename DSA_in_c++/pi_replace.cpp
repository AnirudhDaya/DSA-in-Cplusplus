#include <bits/stdc++.h>
using namespace std;
void pireplace(string str)
{  if(str.length()==0)
        return ;
     if(str[0]=='p' && str[1]=='i')
     {
        cout<<"3.14";
        pireplace(str.substr(2));
     }
     else
     {   
        cout<<str[0];
        pireplace(str.substr(1));
     }
}    
int main()
{
   pireplace("pippxxppiixipi");
}