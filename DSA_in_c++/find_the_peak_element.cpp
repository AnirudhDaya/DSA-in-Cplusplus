#include <bits/stdc++.h>
using namespace std;

int find_peak_element(int arr[], int low, int end, int n)
{
    int mid= low + (end-low)/2;                   //sometime may out of bound hence

        if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
            return mid;

    else
        if(mid != 0 && arr[mid-1]> arr[mid])
            return find_peak_element(arr, low, mid-1,n);

    else
            return find_peak_element(arr, mid+1, end, n);

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

        cout<<"position of peak element: "<<find_peak_element(A,0, n-1, n)<<'\n';
}
