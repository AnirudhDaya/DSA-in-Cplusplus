#include <bits/stdc++.h>
using namespace std;


void trapping_rainwater(vector<int> height)
{
    int i,ans=0;
    int n=height.size();
    int left=0,right=n-1;      //pointers
    int maxleft=0, maxright=0;     //stores maximum of left and right pointers

    while(left<=right)
    {
        if(height[left]<=height[right])       //ensures that there is another building of same or larger height on right side
        {
                if(height[left]>=maxleft)
                    maxleft=height[left];     //update
                else
                    ans+=maxleft-height[left];

                left++;
                
        }

        else
        {
                if(height[right]>=maxright)
                    maxright=height[right];     //update
                else
                    ans+=maxright-height[right];

                right--;
        }
    }

    cout<<ans<<endl;
}

int main()
{
        int n,i;
    
    cout<<"Enter size of array\n";
        cin>>n;
        vector<int> h(n);
    cout<<"Enter the heights:\n";
    for(i=0;i<n;i++)
        cin>>h[i];

        trapping_rainwater(h);
}
