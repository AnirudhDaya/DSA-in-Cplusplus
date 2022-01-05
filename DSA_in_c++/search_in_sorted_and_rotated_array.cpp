#include <bits/stdc++.h>
using namespace std;

int search(int a[], int key, int left, int right)
{
    if(left > right)
        return -1;

    int mid= (left + right)/2;

        if(a[mid] == key)
            return mid;

        if(a[left] <= a[mid])
            if(key >= a[left] && key<= a[mid])
                return search(a, key, left, mid-1);

                return search(a, key, mid+1, right);

        if(key >= a[mid] && key<= a[right])
                return search(a, key, mid+1, right);

                       return search(a, key, left, mid-1);                 
}

int main()
{
     int n;
    cout<<"Enter the number of elements\n";
        cin>>n;
    int A[n];
    cout<<"Enter the array:\n";
    
        for(int i=0;i<n;i++)
            cin>>A[i];
        int k;

        cout<<"Enter the element to be searched for:\n";
            cin>>k;
        if(search(A, k, 0, n-1)==-1)
            cout<<"Element doesn't exist\n";

        else
            cout<<"Element "<<k<<" exist at position "<<search(A, k, 0, n-1)<<endl;
}
