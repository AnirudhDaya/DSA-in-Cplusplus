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

Node* BST(Node* root, int val)
{
    if(root==NULL)
        return new Node(val);   //no node are connected hence its the first node of BST

    if(root->data > val)
        root->left=BST(root->left,val);

    else
        root->right=BST(root->right,val);

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node* root =NULL;
    root= BST(root,5);
    BST(root,1);
    BST(root,3);
    BST(root,4);
    BST(root,2);
    BST(root,7);

    inorder(root);
    cout<<'\n';
}
