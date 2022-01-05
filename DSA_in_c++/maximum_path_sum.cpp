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

int path_sum_calculator(Node* root,int &ans)
{
    if(root==NULL)
        return 0;

    int left=path_sum_calculator(root->left,ans);
    int right=path_sum_calculator(root->right,ans);

    int Node_max=max(max(root->data,root->data + left + right),max(root->data + left, root->data + right));

    ans=max(ans,Node_max);

    int single_path_sum= max(root->data,max(root->data + left, root->data + right));    //for including ancestors
    return single_path_sum;
}

int path_sum(Node* root)
{
    int ans=INT_MIN;   //compared wtih other sum of nodes
    
    path_sum_calculator(root,ans);

    return ans;
}

int main()
{
   struct Node* root = new Node(1);                                      
    root->left=new Node(2);                                   
    root->right= new Node(3);                                 
    root->left->left= new Node(4);                                                   
    root->left->right=new Node(5);                             
    root->right->right=new Node(7);
    root->right->left=new Node(6);

 /*   struct Node* root = new Node(1);                                      
    root->left=new Node(-12);                                   
    root->right= new Node(3);                                 
    root->left->left= new Node(4);                                                                              
    root->right->right=new Node(-6);
    root->right->left=new Node(5);
    */

    cout<<path_sum(root)<<endl;
}
