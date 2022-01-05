#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,currsum=0,maxsum=INT_MIN,n;
    cout<<"Enter array size: ";
        cin>>n;
    cout<<"Enter the array: ";
  int A[n];  
    for(i=0;i<n;i++)
    cin>>A[i];    
        for(i=0;i<n;i++)
        {
           currsum+=A[i];
           if(currsum<0)
           currsum=0; 
           maxsum=max(maxsum,currsum);
        }

cout<<maxsum;
}