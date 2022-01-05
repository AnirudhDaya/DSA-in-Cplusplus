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

int calcheight(Node* root)
{
    if(root==NULL)
        return 0;

    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);

    return max(lheight,rheight) + 1;
}


bool balanced_height_tree(Node* root)
{
     if(root==NULL)
     {
         return true;
     }

     if(balanced_height_tree(root->left)==false)
        return false;

     if(balanced_height_tree(root->right)==false)
        return false;   

    int lh=calcheight(root->left);
    int rh=calcheight(root->right);

    if(abs(lh-rh)<=1)
        return true;
    else
        return false;
}

bool opt_balanced_height_tree(Node* root, int* height)
{   
         if(root==NULL)
     {
         return true;
     }

    int lh=0,rh=0;

     if(opt_balanced_height_tree(root->left, &lh)==false)
        return false;

     if(opt_balanced_height_tree(root->right, &rh)==false)
        return false;  

    *height=max(lh,rh) + 1;

        if(abs(lh-rh)<=1)
        return true;
    else
        return false;

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

    struct Node* root2 = new Node(1);                                      
    root2->left=new Node(2);                                                                   
    root2->left->left= new Node(4);                        

     int h=0;
    if(balanced_height_tree(root))
        cout<<"Balanced\n";
    else 
        cout<<"Unbalanced\n";

    if(opt_balanced_height_tree(root2, &h))
        cout<<"Balanced\n";
    else 
        cout<<"Unbalanced\n";
    
}