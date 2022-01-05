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

Node*  Build_BST(int preorder[], int* i, int key, int min, int max, int n)    //root, iterator, curr element , min, max
{
    if(*i>=n)     //preorder array is fully traversed
        return NULL;
    
    Node* root=NULL;     //initial node

    if(key > min && key < max)
    {
        root = new Node(key);     //for first node 
        *i+=1;    //increment iterator

        if(*i<n)
            {
                root->left=Build_BST(preorder, i, preorder[*i], min, key, n);      
                root->right=Build_BST(preorder, i, preorder[*i], key, max, n);            
            }

    }

    return root;
}

void const_preorder(Node* root)
{
    if(root==NULL)
        return ;

    cout<<root->data<<" ";
    const_preorder(root->left);
    const_preorder(root->right);
}

int main()
{
        int preorder[]={69, 50, 42, 360, 361};
        int i=0;

        Node* root=Build_BST(preorder, &i, preorder[0], INT_MIN, INT_MAX, 5);
        const_preorder(root);
        cout<<'\n';
}
