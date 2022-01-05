#include <bits/stdc++.h>
using namespace std;

void Largest_Area_Histogram(vector<int> heights)
{
     int i;
    int  n=heights.size();
       stack<int> st;
   int leftsmall[n];
   int rightsmall[n];
        for(i=0;i<n;i++)      //for left small
        {
            while(!st.empty() && heights[st.top()]>=heights[i])    // removes all greater elements in stack
                st.pop();

        if(st.empty())
            leftsmall[i]=0;     //stack is empty then left samll is always 0
        else
        leftsmall[i]=st.top()+1;     //add 1 to store position

        st.push(i);
        }
 
        while(!st.empty())    // removes all element from stack to reuse
            st.pop();

        for(i=n-1;i>=0;i--)      //for right  small
        {
            while(!st.empty() && heights[st.top()]>=heights[i])    // removes all greater elements in stack
                st.pop();

        if(st.empty())
            rightsmall[i]=n-1;     //stack is empty then left samll is always last element
        else
        rightsmall[i]=st.top()-1;     //add 1 to store position

        st.push(i);

        }

        int maxA=0;

            for(int i=0;i<n;i++)
                maxA= max(maxA , heights[i] * (rightsmall[i]-leftsmall[i]+1));

    cout<<maxA<<endl;
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

    Largest_Area_Histogram(h);
}