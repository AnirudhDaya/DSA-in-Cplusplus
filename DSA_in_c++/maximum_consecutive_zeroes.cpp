#include <bits/stdc++.h>
using namespace std;

void max_consecutive_ones(vector<int> b, int k)
{
    int i=0,j;
    int n=b.size();
    int zerocount=0;
    int ans=0;
    for(j=0;j<n;j++)
    {
        if(b[j]==0)    //counts the number of zeroes in the window
            zerocount++;
        while(zerocount>k)
        {
            if(b[i]==0)     //ensures that zerocount decreases with increase in the window size from left
                zerocount--;
            i++;
        }

        ans=max(ans,j-i+1);
    }
    cout<<ans<<endl;
}


int main()
{
    int n;
    cout<<"Enter size of array:\n";
        cin>>n;
    vector<int> a(n);
      int targett;
    cout<<"Enter the numbers\n";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }   
    int j;
    cout<<"Enter the number of conversions that can be made:\n";
        cin>>j;

    max_consecutive_ones(a,j);
}
