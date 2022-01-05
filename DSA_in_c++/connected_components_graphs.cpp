#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> components;
vector<bool> vis;

int get_comp(int src)
{
    if(vis[src])
        return 0;

        vis[src] = true;

        int ans=1;

            for(auto i : adj[src])
            {
                if(!vis[i])
                {
                    ans += get_comp(i);
                    vis[i]=true;
                }
            }

        return ans;
}

int main()
{
   int i,j,n,m,x,y;

    cout<<"Enter the number of node: ";
        cin>>n;

    cout<<"Enter the number of connections (Edges): ";
        cin>>m;

    adj = vector<vector<int>>(n);
    vis= vector<bool>(n,0);

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i=0;i<n;i++)
    {
        if(!vis[i])
            components.push_back(get_comp(i));
    }

    for(auto it: components)
        cout<<it<<" ";
}
