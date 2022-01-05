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

void left_view(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

        while(!q.empty())
        {
            int n=q.size();                //shows the number of elements in that level

                for(int i=1;i<n;i++)
                {
                    Node* curr=q.front();                    
                    q.pop();

                    if(i==1)                           //displays the rightmost element
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
    root->left->left->left=new Node(7);
     
    left_view(root);
    cout<<endl;
}