#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cout<<"Enter the number of test cases\n";
        cin>>t;

    while(t--)
    {
        int n;

        cin>>n;

        vector<pair<int,int>> a(n);

        for(int i=0;i<n;i++)
            cin>>a[i].first>>a[i].second;

        int distance_to_town,fuel;

        cin>>distance_to_town>>fuel;

        for(int i=0;i<n;i++)
            a[i].first = distance_to_town - a[i].first;

        sort(a.begin(),a.end());

        int ans=0,curr = fuel;
       

        priority_queue<int,vector<int>> pq;
        bool flag=0;

        for(int i=0;i<n;i++)
        {
            if(curr >= distance_to_town)
            {
                break;
            }

            while(curr < a[i].first)
            {
                if(pq.empty())
                    {
                        flag=1;
                        break;
                    }

                ans++;
                curr += pq.top();
                pq.pop();
            }

        if(flag)
            break;

        pq.push(a[i].second);
        }

        if(flag)
        {
            cout<<"-1"<<endl;
            continue;
        }

        while(!pq.empty() && curr < distance_to_town)
        {
            curr += pq.top();
            pq.pop();
            ans++;
        }

        if(curr < distance_to_town)
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}
