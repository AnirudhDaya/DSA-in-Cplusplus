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

bool identical_BST(Node* root1, Node* root2)
{
    if(root1 ==NULL && root2==NULL)
        return true;

    else
        if(root1 ==NULL || root2==NULL)
                return false;

    else
        {
           bool cond1 = root2->data==root1->data;
           bool cond2 = identical_BST(root1->left,root2->left);
           bool cond3 = identical_BST(root1->right,root2->right);

                if(cond1 && cond2 && cond3)
                    return true;

                else
                    return false;
        }
}

int main()
{
        Node* root1 = new Node(2);
        root1->right = new Node(3);
        root1->left = new Node(2);

        Node* root2 = new Node(2);
        root2->right = new Node(3);
        root2->left = new Node(-2);
        

        if(identical_BST(root1,root2))
            cout<<"Indentical\n";

        else
            cout<<"Not Identical\n";
}
