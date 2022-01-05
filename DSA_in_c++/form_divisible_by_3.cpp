#include <bits/stdc++.h>
using namespace std;

/*int sumofdigits(int a)
{
    int n = log(a) / 2.303   + 1;
    int sum=0;
        if(n==1)
            return a;

        while(a > 0)
        {
            sum+=a%10;
            a=a/10;
        }

        return sum;
}*/

void form_divisbleby_3(int arr[],int n, int k)
{
    int sum=0,i;
    pair<int, int> ans;

    for(i=0;i<k;i++)
        sum+=arr[i];

    bool found = false;

    if(sum%3 == 0)
    {
        ans =make_pair(0,k-1);
        found = true;
    }

    for(int j=k; j<n;j++)
    {
        if(found)
            break;

        sum+= arr[j] - arr[j-k];

        if(sum%3 == 0)
        {
            ans= make_pair(j-k+1, j);
            found =true;
        }
    }

    if(!found)
        ans = make_pair(-1,0);

    if(ans.first == -1)
        cout<<"no such subarray exists \n";

    else
    {
        for(int i=ans.first; i<=ans.second; i++)
            cout<<arr[i]<<" ";
            cout<<endl;
    }
}

int main()
{
    int i,k,m,n;
    
    cout<<"Enter size of array:\n";
        cin>>n;

    int a[n];

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];
    
    cout<<"Enter size of window\n";
        cin>>k;

    form_divisbleby_3(a, n, k);
}
