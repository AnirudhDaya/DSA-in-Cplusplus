#include <bits/stdc++.h>

using namespace std;

int posstring(vector<int> s,int key,int n)
{
    int i;
                for(i=0;i<n;i++)
                {
                    if(s[i]==key)
                    return i;
                }
        return -1;
}


int migratoryBirds(vector<int> arr)
{
int n,i;
    n=arr.size();
    int ans;
    vector<int> dupe(n);
        dupe=arr;

    sort(arr.begin(),arr.end());
    int m=arr[n-1];
     vector<int> count(m,0);
    vector<int> countdupe(m);
            for(i=0;i<n;i++)
            {
                count[dupe[i]]++;
            }

            countdupe=count;

        sort(count.begin(),count.end());
        if(count[m-1]!=count[m-2])
        {
         ans=posstring(countdupe,count[m-1],m);
         return ans;   
        }
        else
        
        {for(i=(m-1);i>=0;i--)
        {
            if(count[i]==count[i-1])
            {    int p=posstring(countdupe,count[i],m);
                countdupe[p]=-1;
                int q=posstring(countdupe,count[i-1],m);
                ans=min(p,q);
            }
            else 
            break;
        }
        }
    return ans;
}


int main()
{
    int i,n;

        cout<<"\n Enter size:\n";
        cin>>n;
  vector<int> A(n);
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }

        cout<<'\n'<<migratoryBirds(A)<<'\n';
}
