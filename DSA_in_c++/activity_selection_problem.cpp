#include <bits/stdc++.h>
using namespace std;


int main()
{
    int i,n,k;

    cout<<"Enter size of array:\n";
        cin>>n;

    vector<vector<int>> a;

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
        {
            int start,end;

            cin>>start>>end;
            a.push_back({start,end});
        }

        sort(a.begin(),a.end(),[&](vector<int> &b, vector<int> &c)
        {
            return b[1] < c[1];   //sorted on the basis of end time
        });

        int take=1;
        int end = a[0][1];  // first element

        for(int i=1;i<n;i++)
        {
            if(a[i][0] >= end)     //compare end time with start time
                {
                    take++;
                    end=a[i][0];
                }
        }

        cout<<take<<'\n';
}
