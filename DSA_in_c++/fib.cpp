#include<iostream>
using namespace std;
void fibonacci(int m)
{    int a=0,b=1,c=0;

    for(int i=0;i<m;i++)
    {   if(i==1)
        cout<<1<<" "
        cout<<c<<" ";
        c=a+b;
        b=c;
        a=b;
    }
}
int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;
    fibonacci(n);
}