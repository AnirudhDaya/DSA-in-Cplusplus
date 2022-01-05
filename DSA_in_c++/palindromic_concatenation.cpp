#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num)
{
    int temp =num, number=0;

    while(temp>0)
    {
        number = number*10 + temp%10;
        temp/=10;
    }

    if(number == num)
        return true;
        
        return false;
}

int find_Palindromic_subarray(vector<int> arr, int k, int n)
{  
    int num=0;

    for(int i=0;i<k;i++)
    {
        num = num*10 + arr[i];
    }

    if(isPalindrome(num))
    {
        return 0;
    }

    for(int j=k; j<n;j++)
    {
        num = (num % (int)pow(10,k-1))*10 + arr[j]; //removes first element

        if(isPalindrome(num))
            return j-k+1;

    }
    return -1;
}


int main()
{
    int i,k,m,n,ans;
    
    cout<<"Enter size of array:\n";
        cin>>n;

    vector<int> a(n);

    cout<<"Enter the array\n";
        for(i=0;i<n;i++)
            cin>>a[i];
    
    cout<<"Enter size of window\n";
        cin>>k;

    ans = find_Palindromic_subarray(a, k, n);

    if(ans==-1)
        cout<<"Palindromic subarray doesn't exist";

    else
    {
        for(int i= ans; i< ans+k ;i++)
        {
            cout<<a[i]<<" ";
        }

        cout<<endl;
    }
}
