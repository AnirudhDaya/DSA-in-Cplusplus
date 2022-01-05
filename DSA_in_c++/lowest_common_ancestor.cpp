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

bool getpath(Node* root,int key, vector<int> &path)
{
    if(root==NULL)
        return false;

    path.push_back(root->data);

    if(root->data==key)
        return true;

    if(getpath(root->left, key, path) || getpath(root->right, key, path))
        return true;

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2)
{
    vector<int> path1,path2;

    if(!getpath(root,n1, path1) || !getpath(root, n2, path2))
        return -1;

    int pc=0;

    for(pc=0;pc<path1.size() && path2.size();pc++)
        if(path1[pc] != path2[pc])
            break;

    return path1[pc-1];
}

Node* LCA2(Node* root, int n1, int n2)
{
    if(root==NULL)
        return NULL;

    if(root->data==n1 || root->data==n2)
        return root;

    Node* leftLCA= LCA2(root->left,  n1,  n2);
    Node* rightLCA=LCA2(root->right, n1, n2);

    if(leftLCA && rightLCA)
        return root;

    if(leftLCA!=NULL)
        return leftLCA;

    return rightLCA;
}

int main()
{
    Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left->left=new Node(7);

    Node* lca= LCA2(root, 7, 6);

    if(lca==NULL)
        cout<<"LCA doesn't exist;\n";

    else
    {
        cout<<"LCA "<<lca->data;
    }

    cout<<endl;
}
