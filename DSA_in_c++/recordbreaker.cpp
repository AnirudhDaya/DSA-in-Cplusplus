#include<iostream>
using namespace std;
int main()
{
    int i,ans=0,max=-1,N;
    cout<<"Enter size: ";
        cin>>N;;
    int A[N];
    cout<<"\nEnter array: ";
        for(i=0;i<N;i++)
            cin>>A[i];
        if(N==1)
        {
            cout<<"1"<<endl;
            return 0;
        }
    if(A[0]>A[1])
    ans++;    
     for(i=1;i<N;i++)
     {if(A[i]>A[i-1] && A[i]>A[i+1] && A[i]>max)
     {
         ans++;
         max=A[i];
     }
     }
 cout<<ans<<"BC"<<endl;  
}