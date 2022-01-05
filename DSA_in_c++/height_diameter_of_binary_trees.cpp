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

int calch(Node* root)
{
        if(root==NULL)
        return 0;

    return max(calch(root->left),calch(root->right)) + 1;
}

int calcheight(Node* root)
{
    if(root==NULL)
        return 0;

    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);

    return max(lheight,rheight) + 1;
}

int calcdiameter(Node*  root)
{
    if(root==NULL)
        return 0;

    int lheight=calch(root->left);
    int rheight=calch(root->right);
     int currdiameter=lheight+rheight+1;

     int ldiameter=calcdiameter(root->left);
     int rdiameter=calcdiameter(root->right);

     return max(currdiameter,(ldiameter,rdiameter));
}

int calcoptdiameter(Node*  root, int* height)
{
    if(root==NULL)
        return 0;

    int lh=0,rh=0;
     int ldiameter=calcoptdiameter(root->left,&lh);
     int rdiameter=calcoptdiameter(root->right,&rh);

     int currdiameter=lh+rh+1;
     *height=max(lh,rh)+1;

     return max(currdiameter,max(ldiameter,rdiameter));

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
     int height=0;
     cout<<"Height= "<<calcheight(root)<<'\n';
     cout<<"Diameter= "<<calcdiameter(root)<<'\n';
     cout<<"Optimized Diameter= "<<calcoptdiameter(root,&height)<<'\n';
}