#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>  &a, int n, int i)
{
    int maxidx = i;
    int l = 2*i+1;    //left child
    int r = 2*i+2;    //right child
 
    if(l<n /* checks whether left child exists*/ && a[l] > a[maxidx])
    {
        maxidx = l;
    }

    if(r<n && a[r] > a[maxidx])
    {
        maxidx =r;
    }

    if( maxidx!=i)
    {
        swap(a[i], a[maxidx]);
        heapify(a, n, maxidx);
    }
}

void heapsort(vector<int> &a)
{
    int n=a.size();

    for(int i=n/2-1; i>=0;i--)     //for making maxheap
    {
        heapify(a, n, i);
    }

    for(int i=n-1; i>0 ;i--)       //for sort
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int i,n;

    cout<<"Enter size of array:\n";
        cin>>n;

    vector<int> a(n);

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];

    heapsort(a);

    cout<<"The sorted array is:\n";
        for(i=0;i<n;i++)
