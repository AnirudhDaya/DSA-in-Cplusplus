#include <bits/stdc++.h>
using namespace std;

void min_notes_or_coins(int x, vector<int> a)
{
    int i,ans=0;

    for(i=0;i<(a.size());i++)
    {
        ans+=x/a[i];
        x -= x/a[i] * a[i];   //subtracts the money 
    }

    cout<<"The minimum number of coins or notes required is "<<ans<<endl;
}

int main()
{
    int x,n;

    cout<<"Enter the number of denominations: ";
        cin>>n;

    cout<<"Enter the denominations: \n";

    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a.begin(),a.end(),greater<int>());
    cout<<"Enter the money: ";
        cin>>x;

    min_notes_or_coins(x,a);
}
