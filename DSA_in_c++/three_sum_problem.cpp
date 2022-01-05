#include <bits/stdc++.h>
using namespace std;

void three_sum(vector<int> b,int target)
{
    int n=b.size();
    int i,low,hi;

        for(i=0;i<n;i++)
        {
            low=i;
            hi=n-1;

            while(low<hi)
            {
                int current= b[i] + b[low] + b[hi];

                if(current==target)
                    {
                        cout<<"true\n";
                        exit(0);
                    }
            else
                if(current<target)
                    low++;

            else
                    hi++;

            }
        }
    cout<<"False\n";
}


int main()
{
    int n;
    cout<<"Enter size of array:\n";
        cin>>n;
    vector<int> a(n);
      int targett;
    cout<<"Enter the numbers\n";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
      cout<<"Enter the target\n";
        cin>>targett;
        three_sum(a,targett);
}
