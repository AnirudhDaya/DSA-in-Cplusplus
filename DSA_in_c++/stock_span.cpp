include <bits/stdc++.h>
using namespace std;

void stock_span(vector<int> b)
{
    int n=b.size();
    int i;
    stack<pair<int,int>> st;
   vector<int> ans(n);
    for(i=0;i<n;i++)
    {
        int days=1;   // all stocks are intially assigned 1 day

        while(!st.empty() && st.top().first <= b[i])    //if any larger element then smaller element is popped
        {
            days+=st.top().second;    // we add the days of popped element to the new one
            st.pop();
        }

        st.push({b[i],days});   //pushing the new element
        ans[i]=days;
    }

    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size of array:\n";
        cin>>n;
    vector<int> a(n);

    cout<<"Enter the stock prices\n";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

    stock_span(a);
}
