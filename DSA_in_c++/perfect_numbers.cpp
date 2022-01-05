#include <bits/stdc++.h>
using namespace std;

bool isperfect(int n)
{
    int sum = 1;

    for(int i= 2 ;i<sqrt(n); i++)
    {
        if(n%i == 0)
            {
                if(i == n/i)
                    sum+=i;

                else

                    sum+= i + n/i;
            }
    }

    if(sum == n && n!=1)
        return true;

    return false;
}

int maxSum(int arr[] , int n, int k)
{
    if(n<k)
    {
        cout<<"invalid values\n";
        return -1;
    }

    int res=0,i,j;

    for(i=0 ;i< k; i++)
    {
        res += arr[i];
    }

    int sum= res;

    for(i=k; i<n; i++)
    {
        sum+=arr[i] - arr[i-k];\
        res = max(res, sum);
    }

    return res;
}

int max_numberof_perfects(int arr[], int n, int k)
{
    for(int i=0;i<n;i++)
    {
        if(isperfect(arr[i]))
            arr[i] = 1;

        else

            arr[i] = 0;
    }

    return maxSum(arr, n, k);
}

int main()
{
    int i,k,m,n,ans;
    
    cout<<"Enter size of array:\n";
        cin>>n;

    int a[n];

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];
    
    cout<<"Enter size of window\n";
        cin>>k;

    cout<<max_numberof_perfects(a,n,k)<<endl;
}
