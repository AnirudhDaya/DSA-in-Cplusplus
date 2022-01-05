#include <bits/stdc++.h>
using namespace std;

bool iscycle(int source, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
        stack[source] = true;    

        if(!visited[source])
           visited[source] = true;

        for(auto i: adj[source])
        {
                if(!visited[i] and iscycle(i,adj,visited,stack))
                    return true;

                if(stack[i])
                    return true;
        }
    stack[source] = false;
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
    }

    bool cycle = false;
    vector<bool> visited(n,false);
    vector<int> stack(n,0);

        for(i=0;i<n;i++)
        {
            if(!visited[i] and iscycle(i,adj,visited,stack))
                cycle = true;
        }

        if(cycle)
            cout<<"Cycle is present\n";
        else
        cout<<"Cycle is not present\n";

    cout<<endl;     
}
