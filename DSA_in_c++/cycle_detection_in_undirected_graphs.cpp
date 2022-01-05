#include <bits/stdc++.h>
using namespace std;

bool iscycle(int source, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[source] = true;

        for(auto i: adj[source])
        {
            if(i != parent)
            {
                if(visited[i])
                    return true;

                if(!visited[i] and iscycle(i,adj,visited,source))
                    return true;
            }
        }

    return false;
}

int main()
{
   int i,j,n,m,x,y;

    cout<<"Enter the number of node: ";
        cin>>n;

    cout<<"Enter the number of connections (Edges): ";
        cin>>m;

vector<vector<int>> adj(n);

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool cycle = false;
    vector<bool> visited(n,false);


        for(i=0;i<n;i++)
        {
            if(!visited[i] and iscycle(i,adj,visited,-1))
                cycle = true;
        }

        if(cycle)
            cout<<"Cycle is present\n";
        else
        cout<<"Cycle is not present\n";

    cout<<endl;     
}
