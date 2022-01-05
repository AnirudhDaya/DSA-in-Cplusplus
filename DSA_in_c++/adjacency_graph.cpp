#include <bits/stdc++.h>
using namespace std;

//#define vi vector<int>

vector<int> adj[1000];

int main()
{
   int i,j,n,m,x,y;

    cout<<"Enter the number of node: ";
        cin>>n;

    cout<<"Enter the number of connections (Edges): ";
        cin>>m;

    vector<vector<int>>  ajm(n+1,vector<int>(n+1,0));

    cout<<"Enter the connections:\n";

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        ajm[x][y] = 1;
        ajm[y][x] = 1;
    }

    cout<<"Adjacency matrix of above graph is given by:\n";

    for(i=1;i<(n+1);i++)
    {
        for(j=1;j<(n+1);j++)
            cout<<ajm[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl<<endl;

    cout<<"Enter the number of node: ";
        cin>>n;

    cout<<"Enter the number of connections (Edges): ";
        cin>>m;

    cout<<"Enter the connections:\n";

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Adjacency list of above graph is given by:\n";

    for(i=1;i<(n+1);i++)
    {
        cout<<i<<"->";

        for(int x : adj[i])
            cout<<x<<" ";

        cout<<endl;
    }

}
