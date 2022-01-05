#include <iostream>
#include<climits>
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

struct Info                   //for ease of access
{
    int max;
    int min;
    bool isBST;
    int size;
    int ans;
};

Info Largest_BST(Node* root)
{
    if(root==NULL)
        return {INT_MIN,INT_MAX,true,0,0};

    if(root->left ==NULL && root->right==NULL)                    //checks if its leaf node             
        return {root->data, root->data, true, 1, 1};
 
    Info left_BST = Largest_BST(root->left);              //calls for left subtree
    Info right_BST = Largest_BST(root->right);              //calls for right subtree

    Info curr;

    curr.size = (1+ left_BST.size + right_BST.size);

        if(left_BST.isBST && right_BST.isBST && root->data > left_BST.max && root->data < right_BST.min )        //conditions for BST
        {
            curr.min = min(left_BST.min, min(right_BST.min, root->data));
            curr.max = max(left_BST.max, max(right_BST.max, root->data));

            curr.ans = curr.size;
            curr.isBST = true;

            return curr;           
        }    

        curr.ans = max(left_BST.ans, right_BST.ans);            
        curr.isBST= false;


        return curr;    
}

int main()
{
    Node* root =new Node(5);
    root->left= new Node(2);
    root->right = new Node(4);

    cout<<"The largest BST is: "<<Largest_BST(root).ans<<'\n';
}
