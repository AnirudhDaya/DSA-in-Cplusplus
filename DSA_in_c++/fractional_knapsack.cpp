#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    double  v1 = (double) p1.first/p1.second;
    double  v2 = (double) p2.first/p2.second;
    
    return v1>v2;
}

int main()
{
    int i,n,k;

    cout<<"Enter the number of items:\n";
        cin>>n;

    vector<pair<int,int>> a(n);

    cout<<"Enter value of each item\n";
        for(i=0;i<n;i++)
        {
            cin>>a[i].first>>a[i].second;
        }

    int maxw;

    cout<<"Enter the maximum value of knapsack: ";
        cin>>maxw;

        sort(a.begin(),a.end(),compare);

    int ans=0;

    for(i=0 ; i<n; i++)
    {
        if(maxw >= a[i].second)
        {
            ans+=a[i].first;
            maxw -= a[i].second;
            continue;
        }

        double vw = (double) a[i].first/a[i].second;
        ans += vw * maxw;
        maxw=0;
        break;
    }

    cout<<ans<<endl;
}
