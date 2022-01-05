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

Node* LCA(Node* root,int n1, int n2)
{
    if(root==NULL)
        return NULL;

    if(root->data==n1 || root->data==n2);      //checks whether current position is the required n1
        return root;

    Node* l=LCA(root->left,n1,n2);                 
    Node* r=LCA(root->right,n1,n2);

    if(l !=NULL && r != NULL)
        return root;

    if(l==NULL && r== NULL)
        return NULL;

    if(l!=NULL)
        return LCA(root->left,n1,n2);

        return LCA(root->right,n1,n2);

}

int find_distance(Node* root, int k, int currdist)
{
    if(root==NULL)
        return -1;

    if(root->data==k)
        return currdist;

    int l=find_distance(root->left,k,currdist+1);

    if(l!=-1)
        return l;


    return find_distance(root->right,k,currdist+1);
}

int distance(Node* root, int n1, int n2)
{    
    Node* lca=LCA(root,n1,n2);

    int d1= find_distance(root,n1,0);
    int d2=find_distance(root,n2,0);

    return d1+d2;
}

int main()
{
    struct Node* root = new Node(1);                                      
    root->left=new Node(2);                                   
    root->right= new Node(3);                                 
    root->left->left= new Node(4);                                                                       
    root->right->right=new Node(5);
 
    cout<<distance(root,4,5)<<'\n';

}
