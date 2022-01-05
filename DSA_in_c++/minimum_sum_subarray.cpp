#include <bits/stdc++.h>
using namespace std;

int min_sum_subarray(vector<int> arr, int k, int x)
{
   // sort(arr.begin(), arr.end());
    int n=arr.size();
    int i,min_size=n+1,sum=0,start=0,end=0;

    while(end < n)
    {
        while(sum <= x && end < n)
            sum += arr[end++];

        while(sum > x && start < n)
        {
            if(end-start < min_size)
                min_size = end -start;

            sum -= arr[start++];
        }
    }

    return min_size;
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

    cout<<"Enter the minimum sum:\n";
        cin>>m;

    cout<<"\nMinimum size of subarray is: "<<min_sum_subarray(a,k,m)<<endl;
}
