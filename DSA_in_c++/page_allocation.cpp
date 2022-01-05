#include <bits/stdc++.h>
using namespace std;

bool isfeasible(int a[], int n, int m, int mid)
{
    int studentsrequired = 1, sum=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]> mid)
            return false;

        if((sum + a[i]) > mid)
            {
                studentsrequired++;
                sum = a[i];


                    if(studentsrequired > m)
                        return false;
            }
        else
            sum+=a[i];
    }
    return true;
}

int allocate_min_page(int a[], int n, int m)
{
    int sum=0;

        if(n<m)
            return -1;

        for(int i=0;i<n;i++)
            sum+=a[i];          //find total number of pages

        int start=0, end=sum, ans=INT_MAX;

        while(start<=end)
        {
            int mid =(start+end)/2;

                if(isfeasible(a, n, m, mid))
                {    ans= min(ans,mid);
                    end=mid-1;
                }
                else
                    start = mid+1;
        }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of books\n";
        cin>>n;
    int A[n];
    cout<<"Enter the pages of books:\n";
    
        for(int i=0;i<n;i++)
            cin>>A[i];

int m;

    cout<<"Enter the number of students:\n";
        cin>>m;    

    cout<<"The minimum number of maximum pages allocated is: "<<allocate_min_page(A, n, m)<<endl;
}
