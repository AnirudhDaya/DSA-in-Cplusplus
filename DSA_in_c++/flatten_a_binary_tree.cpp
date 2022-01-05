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

void Flatten(Node* root)
{
   if(root==NULL || (root->left==NULL && root->right==NULL))
    return;

    if(root->left != NULL)
   {   Flatten(root->left);

    Node* temp= root->right;     //Swapping
    root->right=root->left;
    root->left=NULL;     //no use of left subtree

    Node* t=root->right;

    while(t->right!=NULL)       //traverses till tail node
        t=t->right;

    t->right=temp;
   }

    Flatten(root->right);
}

void inorder(Node* root)
{

  if(root==NULL)
     return;
    inorder(root->left);
        cout<<root->data<<" ";
    inorder(root->right);
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

    Flatten(root);
    inorder(root);
    cout<<'\n';    

}
