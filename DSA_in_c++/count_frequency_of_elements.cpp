#include <bits/stdc++.h>
using namespace std;

void frequency(int a[],int n)
{
    map<int,int> m;

    for(int i=0;i<n;i++)
        m[a[i]]++;

    map<int,int> :: iterator it;

    for(it = m.begin() ; it!= m.end() ; it++)
        cout<<it->first<<" "<<it->second<<endl;
}

int main()
{
    int i,n,k;

    cout<<"Enter size of array:\n";
        cin>>n;

    int a[n];

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];

    frequency(a,n);
}
