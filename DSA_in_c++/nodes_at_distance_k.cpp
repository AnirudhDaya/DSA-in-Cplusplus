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

void printsubtreenodes(Node* root, int k)
{
    if(root==NULL || k<0)
        return;

    if(k==0)
        {
            cout<<root->data<<" ";      //traverse downwards a tree till reaches distance k from target
            return;
        }        

    printsubtreenodes(root->left,k-1);
    printsubtreenodes(root->right,k-1);
}

int Nodes_at_distance_k(Node* root,Node* target, int k)
{
    if(root==NULL)
        return -1;

    if(root==target)
    {
        printsubtreenodes(root,k);
        return 0;
    }

    int dl=Nodes_at_distance_k(root->left,target,k);
 
    if(dl !=-1)         //if child exist in left subtree
    {
        if(dl+1==k)         //distance from child to target
            cout<<root->data<<" ";

     else
        printsubtreenodes(root->right,k-dl-2);   //sus

        return 1+dl;
    }

        int dr=Nodes_at_distance_k(root->right,target,k);
 
    if(dr !=-1)         //if child exist in right subtree
    {
        if(dr+1==k)         //distance from child to target
            cout<<root->data<<" ";

     else
        printsubtreenodes(root->left,k-dl-2);   //sus

        return 1+dr;
    }


    return -1;   //nothing words

}

int main()
{
    struct Node* root = new Node(1);                                      
    root->left=new Node(2);                                   
    root->right= new Node(3);                                 
    root->left->left= new Node(4);                                                   
    root->left->right=new Node(5);                             
    root->right->right=new Node(6);
    root->right->left=new Node(7);
     

     Nodes_at_distance_k(root,root->left,1);
     cout<<'\n';
}
