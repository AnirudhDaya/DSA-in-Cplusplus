#include <bits/stdc++.h>
using namespace std;

//#define vi vector<int>
const int N=1e5+2;
bool visited[N]; 
vector<int> adj[N];

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

    queue<int> q;
    q.push(1);
    visited[1] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            cout<<'\n'<<node<<"\n";


            for(int x : adj[node])
            {
                if(!visited[x])
                {
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }


}
