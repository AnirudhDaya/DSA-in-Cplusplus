#include <bits/stdc++.h>
using namespace std;
bool search(int B[1000][1000],int M, int N, int k)
{
int i=0,j=N-1;
while(i<M)
{
if(B[i][j]==k)
return true;
else
if(B[i][j]<k)
i++;
else
j--;
}
return false;
}
int main()
{
int i,j,P,Q,l;
cout<<"Enter the array size: ";
cin>>P>>Q;
int A[1000][1000];
cout<<"Enter the array: ";
for(i=0;i<P;i++)
for(j=0;j<Q;j++)
cin>>A[i][j];
cout<<"Enter the element to be searched";
cin>>l;
if(search(A,P,Q,l))
cout<<"Element is present";
else
cout<<"Element is not present";
}
