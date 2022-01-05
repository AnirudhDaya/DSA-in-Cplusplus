#include <bits/stdc++.h>
using namespace std;

void most_frequent_elements(vector<int> a, int k)
{
    map<int,int> m;

    vector<pair<int,int>> ans;

    for(int i=0;i<(a.size());i++)
    {
        int present_size = m.size();   

        if(m[a[i]] == 0 && present_size == k)
            break;

        m[a[i]]++;
    }

    map<int,int> :: iterator it;

    for(it = m.begin() ; it!= m.end() ; it++)
    {
        if(it->second != 0)
        {
            pair<int,int> p;
            p.first =it->second;
            p.second = it->first;
            ans.push_back(p);
        }
    }

    sort(ans.begin(),ans.end(),greater<pair<int,int>>());

    vector<pair<int,int>> :: iterator it1;

    for(it1 = ans.begin() ; it1!= ans.end() ; it1++)
        cout<<it1->second<<" occurs "<<it1->first<<" times"<<endl;
    
}

int main()
{
    int i,n,k;

    cout<<"Enter size of array:\n";
        cin>>n;

    vector<int> a(n);

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];

    cout<<"\nEnter k: ";
        cin>>k;

    most_frequent_elements(a,k);
}
