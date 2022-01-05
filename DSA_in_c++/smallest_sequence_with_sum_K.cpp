#include <bits/stdc++.h>
using namespace std;

void smallest_subsequence_with_sum_k(vector<int> arr, int k)
{
    priority_queue<int, vector<int>> pq;

    for(int i=0;i<arr.size();i++)
    {
        pq.push(arr[i]);
    }

    int sum=0,count=0;

    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();

        count++;

        if(sum>=k)
            break;
    }

    if(sum < k)
        cout<<"nope\n";

    else
        cout<<count<<endl;
}

int main()
{
    int i,n,k;

    cout<<"Enter size of array:\n";
        cin>>n;

    vector<int> a(n);

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];

    cout<<"Enter k: \n";
        cin>>k;  

    smallest_subsequence_with_sum_k(a,k);
}
