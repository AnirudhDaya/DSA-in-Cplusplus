#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

void right_view(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

        while(!q.empty())
        {
            int n=q.size();                //shows the number of elements in that level

                for(int i=0;i<n;i++)
                {
                    Node* curr=q.front();                    
                    q.pop();

                    if(i==n-1)                           //displays the rightmost element
                        cout<<curr->data<<" ";
                

                    if(curr->left)
                        q.push(curr->left);
                
                    if(curr->right)
                        q.push(curr->right);

                }
        }
}

int main()
{
    struct Node* root = new Node(1);                                      
    root->left=new Node(2);                                   
    root->right= new Node(3);                                 
    root->left->left= new Node(4);                                                   
    root->right->left=new Node(5);                             
    root->right->right=new Node(6);
    root->right->left->left=new Node(7);
     
    right_view(root);
    cout<<endl;
}
