#include <bits/stdc++.h>
using namespace std;

//#define vi vector<int>
const int N=1e5+2;
bool visited[N]; 
vector<int> adj[N];

void dfs(int node)
{
    //preorder
    visited[node] = 1;

    //inorder
    vector<int> :: iterator it;
    for(it = adj[node].begin();it!= adj[node].end();it++)
    {
        if(visited[*it]);
        else
        {
            dfs(*it);
        }
    }

    //postorder
    cout<<node<<" ";

}

int main()
{
   int i,j,n,m,x,y;

    cout<<"Enter the number of node: ";
        cin>>n;

    cout<<"Enter the number of connections (Edges): ";
        cin>>m;

    for(i=0;i<N;i++)
        visited[i]=0;

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<endl;
    dfs(1);
}
