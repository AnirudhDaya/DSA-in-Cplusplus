#include <bits/stdc++.h>
using namespace std;

int isfeasible(int a[], int n, int mid)
{
    int painters = 1, sum=0;

    for(int i=0; i<n; i++)
    {
        sum+=a[i];

            if(sum > mid)
            {
                sum =a[i];
                painters++;
            }
    }
    return painters;
}

int painters_partition(int a[], int n, int m)
{
    int total_lenth=0, k=0;

        for(int i=0;i<n;i++)
        {
            k=max(k,a[i]);
            total_lenth+=a[i];
        }

        int low=k, high = total_lenth;

        while(low < high)
        {
            int mid =(low + high)/2;

            int painters =isfeasible(a, n, mid);

            if(painters<=m)
                high=mid;

            else
                low=mid+1;
        }

        return low;
}

int main()
{   
     int n;
    cout<<"Enter the number of elements\n";
        cin>>n;
    int A[n];
    cout<<"Enter the array:\n";
    
        for(int i=0;i<n;i++)
            cin>>A[i];

            int m;
    cout<<"Enter the number of painters:\n";
        cin>>m;    

    cout<<"The minimum time is "<<painters_partition(A, n, m)<<endl;            
}
