#include <iostream>
#include <stack> //for using stack
using namespace std;

void insertAtBottom(stack<int> &st,int ele)
{    
    if(st.empty())    //base case 
    {
        st.push(ele);   
        return;
    }
    int topele=st.top();  //store the topmost element 
    st.pop();
    insertAtBottom(st,ele);

    st.push(topele);   //insert the topmost element at bottom
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();   //store the topmost element
    st.pop();
    reverse(st);       //recursively call to store the topmost element 
    insertAtBottom(st, ele);    //send to insert at the bottom
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    reverse(st);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}