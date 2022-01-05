#include <bits/stdc++.h>
using namespace std;
int kadane(int B[], int N)
{
      int i,currsum=0,maxsum=INT_MIN; 
        for(i=0;i<N;i++)
        {
           currsum+=B[i];
           if(currsum<0)
           currsum=0; 
           maxsum=max(maxsum,currsum);
        }
     return maxsum;   
}
int main()
{
int i,n;
    cout<<"Enter array size: ";
        cin>>n;
    cout<<"Enter the array: ";
  int A[n];  
    for(i=0;i<n;i++)
    cin>>A[i]; 
        int wrapsum,totalsum=0;
        int nonwrapsum=kadane(A,n);
    for(i=0;i<n;i++)
    {  totalsum+=A[i];
       A[i]=-A[i];  
    } 
    wrapsum=totalsum+kadane(A,n);
    cout<<max(wrapsum,nonwrapsum);
}