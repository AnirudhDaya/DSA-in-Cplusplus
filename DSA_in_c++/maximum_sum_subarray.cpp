#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray(vector<int> arr, int k, int x)
{
    int max_ans=INT_MIN,sum=0,start=0,end=(k-1);
    int n=arr.size();

    for(int i=0;i<n;i++)
    {
        if(i < k)
        {
            sum+=arr[i];
            continue;
        }

        if(sum <= x)
        {
            max_ans=max(max_ans, sum);
        }
            sum-=arr[start];
            sum+=arr[i];
            start++;
    }

    return max_ans;
}

int main()
{
    int i,k,m,n;
    
    cout<<"Enter size of array:\n";
        cin>>n;

    vector<int> a(n);

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];
    
    cout<<"Enter size of window\n";
        cin>>k;

    cout<<"Enter the maximum sum:\n";
        cin>>m;

    cout<<"\nMaximum sum of subarray is: "<<max_sum_subarray(a,k,m)<<endl;
}
