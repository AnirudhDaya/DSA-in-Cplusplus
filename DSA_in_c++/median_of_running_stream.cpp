#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

void insert(int a)
{
    if(pqmax.size() == pqmin.size())
    {
        if(pqmax.size() == 0)
        {
            pqmax.push(a);
            return;
        }

        if(a < pqmax.top())
            pqmax.push(a);

        else
            pqmin.push(a);
    }
    else
    {
        if(pqmax.size() > pqmin.size())
        {    if(a >= pqmax.top())
                pqmin.push(a);

            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(a);
            }

        }
        else
        {
            if( a <= pqmin.top())
                pqmax.push(a);

            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(a);
            }
        }
    }
}

double findmedian()
{
    if(pqmin.size() == pqmax.size())
        return (pqmin.top() + pqmax.top())/2.0;

    else
        if( pqmax.size() > pqmin.size())
            return pqmax.top();
    else
        return pqmin.top();
}

int main()
{
    insert(10);
        cout<<findmedian()<<endl;

    insert(15);
        cout<<findmedian()<<endl;

    insert(21);
        cout<<findmedian()<<endl;    

    insert(30);
        cout<<findmedian()<<endl;
    
    insert(18);
        cout<<findmedian()<<endl;

    insert(19);
        cout<<findmedian()<<endl;
}
