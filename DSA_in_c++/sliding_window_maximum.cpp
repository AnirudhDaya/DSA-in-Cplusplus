#include <bits/stdc++.h>
using namespace std;

void maxSlidingWindow(vector<int> b,int k)
{
    deque<int> dq;
    vector<int> ans;
     int i,n;
     n=b.size();
    for(i=0;i<n;i++)
    {
        if(!dq.empty() && dq.front()==i-k)    //removes out of bound element (removes elements out of window)
            dq.pop_front(); 
        
        while(!dq.empty() && b[dq.back()]<b[i])     //to maintain descending order
            dq.pop_back();

        dq.push_back(i);
        if(i>=k-1)
            ans.push_back(b[dq.front()]);  //after end of window stores the element in ans
    }
    for(i=0;i<(n-k+1);i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    int k; //window size
    cout<<"enter the size of array:\n";
    cin>>n;
    vector<int> a(n);
    cout<<"enter the array\n"; 
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the window size:\n";
        cin>>k;
    maxSlidingWindow(a,k);
}
