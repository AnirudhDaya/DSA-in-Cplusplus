#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> col;
vector<bool> vis;
bool bipart = true;

void color(int u, int curr)
{
    if(col[u] != -1 && col[u] != curr)
    {   
        bipart = false;
        return;
    }

    col[u] = curr;

        if(vis[u])
            return;
        vis[u] = true;

        for(auto i: adj[u])
            color(i,curr xor 1);
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
    col= vector<int>(n,-1);

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            color(i,0);
    }

    if(bipart)
        cout<<"Graph is bipart\n";

    else
        cout<<"Graph is not bipart\n";
}
