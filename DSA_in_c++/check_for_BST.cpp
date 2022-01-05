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

bool check_BST(Node* root, Node* min, Node* max)
{
   if(root==NULL)
        return true;

    if(min!=NULL && root->data<=min->data)
        return false;

    if(max!=NULL && root->data>=max->data)
        return false;

    int leftValid=check_BST(root->left,min,root);        //checks if any element onleft is greater than it 
    int rightValid=check_BST(root->right,root,max);      //checks if any element on right is grater than it

    return leftValid && rightValid;
}

int main()
{
        Node* root = new Node(1);
        root->left= new Node(0);
        root->right = new Node(3);

        if(check_BST(root,NULL,NULL))
            cout<<"Valid\n";

        else
            cout<<"Invalid\n";
}
