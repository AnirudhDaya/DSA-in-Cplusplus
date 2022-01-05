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

int sum_nodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return sum_nodes(root->left) + sum_nodes(root->right) + root->data;
}

int count(Node* root)
{
    if(root==NULL)
        return 0;
     
    return count(root->left)+ count(root->right)+1;
}

int main()
{
    struct Node* root = new Node(1);                                      
    root->left=new Node(2);                                   
    root->right= new Node(3);                                 
    root->left->left= new Node(4);                        
    root->left->right=new Node(5);                            
    root->right->left=new Node(6);                             
    root->right->right=new Node(7);
     
     cout<<"Total number of nodes= "<<count(root)<<'\n';
     cout<<"Sum of all node= "<<sum_nodes(root)<<'\n';
}