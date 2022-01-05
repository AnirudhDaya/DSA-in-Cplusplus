#include <bits/stdc++.h>
using namespace std; 

int main()
{
   int i,j,n,m,x,y;

    cout<<"Enter the number of node: ";
        cin>>n;

    cout<<"Enter the number of connections (Edges): ";
        cin>>m;

vector<int> adj[n];
vector<int> indegree(n,0);

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        adj[x].push_back(y);     
        indegree[y]++;       //x --> y
    }
    queue<int> pq;

    for(i=0;i<n;i++)
    {
        if(indegree[i] == 0)
            pq.push(i);           //leaf node are pushed
    }

    while(!pq.empty())
    {
        int u = pq.front();
        pq.pop();
        cout<<u<<" ";

        for(int l: adj[u])
        {
            indegree[l]--;

                if(indegree[l] == 0)
                {
                    pq.push(l);
                }
        }
    }

    cout<<endl;
}
