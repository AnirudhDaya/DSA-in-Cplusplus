#include<iostream>
using namespace std;
int main()
{
    int j,n;
        cout<<"Enter size of array\n";
            cin>>n;
            int B[n];
        cout<<"Enter the array\n";    
    for(j=0;i<n;j++)
        cin>>B[j];
     int i=2,currlen=2,pd=(B[1]-B[0]),ans=2;
        while(i<n)
        {   
             if(pd==(B[i]-B[i-1]))
             {
                currlen++;
                
                
             }
             else
             {
                 currlen=2;
                pd=B[i]-B[i-1];
                 
             }
             ans=max(currlen,ans);
             i++;
        }
    cout<<"answer is: "<<ans;   
}