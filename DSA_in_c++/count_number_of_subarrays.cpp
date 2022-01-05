#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,k;

    cout<<"Enter size of array:\n";
        cin>>n;

    vector<int> a(n);

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];

    map<int,int> m;
    int prefix_sum=0;

    for(i=0;i<n;i++)
    {
        prefix_sum+=a[i];
        m[prefix_sum]++;
    }
    int ans=0;
        map<int,int> :: iterator it;

    for(it = m.begin() ; it!= m.end() ; it++)
       {
           int c=it->second;
            ans+= (c*(c-1))/2;

            if(it->first == 0)
                ans+=it->second;
       }

       cout<<ans<<endl;
}
