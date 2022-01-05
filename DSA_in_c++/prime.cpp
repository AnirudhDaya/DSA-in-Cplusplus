#include<iostream>
using namespace std;

bool prime(int p)
{  
    if(p%2==0 || p%3==0 || p%4==0 || p%5==0 || p%6==0 || p%7==0 || p%8==0 || p%9==0)
         return false;
   return true;        
}
int main()
{   int a,b,i;
    cout<<"Enter the limits: ";
    cin>>a>>b;
    cout<<"Answer is: ";
    for(i=a;i<=b;i++)
    if(prime(i))
    cout<<i<<" ";
}