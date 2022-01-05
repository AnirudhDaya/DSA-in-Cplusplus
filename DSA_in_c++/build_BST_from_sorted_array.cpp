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

Node* build_balanced_BST_FROM_SORTED_array(int arr[], int start, int end)
{
    if(start>end)
        return NULL;

    int mid= (start + end)/2;
    Node* root = new Node(arr[mid]);

    root->left= build_balanced_BST_FROM_SORTED_array(arr, start, mid-1);
    root->right=build_balanced_BST_FROM_SORTED_array(arr, mid+1, end);

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
        int arr[]={1, 25, 36, 69, 70, 70};
        Node* root= build_balanced_BST_FROM_SORTED_array(arr, 0, 5);

            const_preorder(root);
            cout<<'\n';

}
