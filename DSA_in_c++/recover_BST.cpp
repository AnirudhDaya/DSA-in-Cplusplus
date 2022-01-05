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

void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b= temp;
}

void calcpointers(Node* root, Node* *first, Node* * mid, Node* *last, Node* *prev)
{
    if(root==NULL)
        return;

    calcpointers(root->left,first, mid, last, prev); // as in inorder

    if(*prev && root->data < (*prev)->data)
    {    if(!*first)        //first time
        {
            *first=*prev;         //previous node where violation
            *mid=root;          //node where vio
        }

        else //second time
        {
                *last=root;
        }
    }
    *prev = root;    //kind of like increment

    calcpointers(root->right, first, mid, last, prev);
}

void recover_BST(Node* root)
{
    Node* first, *mid, *last, *prev; //(for temp)
    first=NULL;
    last=NULL;
    mid =NULL;
    prev=NULL;

        calcpointers(root, &first, &mid, &last, &prev);

        if(first && last)                   // when swapped values are not adjacent
            swap(&(first->data), &(last->data));

    else

        if(first && mid)
            swap(&(first->data),&(mid->data));
}

void inorder(Node* root)
{
    if(root ==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
        Node* root = new Node(9);
        root->left =new Node(12);
        root->right = new Node(3);
        root->left->left = new Node(1);
        root->left->right = new Node(4);
        root->right->right = new Node(13);

        inorder(root);
        cout<<endl;
        recover_BST(root);
        inorder(root);
        cout<<endl;
}
