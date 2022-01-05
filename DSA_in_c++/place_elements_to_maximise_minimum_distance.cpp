#include <bits/stdc++.h>
using namespace std;

bool isfeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements=1; //count for k
    
        for(int i=1 ;i<n;i++)
        {
            if((arr[i] - pos)>=mid)
            {
                pos=arr[i];
                elements++;

                if(elements==k)
                    return true;
            }
        }
    return false;
}

int Largestmindistance(int arr[], int n, int k)
{
    sort(arr, arr+n);

    int result = -1;
    int left=1, right=arr[n-1];

        while(left<right)
        {
                int mid =(left + right)/2;
            if(isfeasible(mid, arr, n, k))
            {
                left=mid+1;
                result=max(result,mid);
            }

            else
            {
                right=mid;
            }
        }
    return result;
}

int main()
{
    int n;
    cout<<"Enter the number of elements\n";
        cin>>n;
    int A[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
    int k;
        cout<<"enter k";
            cin>>k;

    cout<<Largestmindistance(A, n, k)<<endl;
}
