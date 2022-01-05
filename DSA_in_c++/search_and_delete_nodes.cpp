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

Node* search_BST(Node*  root, int key)
{
    if(root==NULL)
        return NULL;

    if(root->data== key)
        return root;

    if(root->data > key)
        return search_BST(root->left,key);

        return search_BST(root->right,key);
}

Node* inorder_successor(Node* root)
{   
    Node* curr = root;

    while(curr && curr->left)    //traverses till it finds the successor
        curr=curr->left;

    return curr;
}
Node* delete_BST(Node* root, int key)
{    //case 1 where the node to be deleted is at the end
        if(root->data > key)
            root->left = delete_BST(root->left,key);

    else
        if(root->data < key)
            root->right = delete_BST(root->right,key);
        //case2  node to be deleted has one child
    else
        if(root->left == NULL)
        {
            Node* temp = root->right;   //swap and delete
            free(root);
            return temp;
        }
   
    else 
     {   if(root->right == NULL)
        {
            Node* temp = root->left;   //swap and delete
            free(root);
            return temp;
        }
          //case 3 the node to be deleted has 2 child 
        Node* temp= inorder_successor(root->right);
        root->data=temp->data;
        root->right=delete_BST(root->right,temp->data);  //deleting the data of the node
     }
        return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    struct Node* root = new Node(4);                                      
    root->left=new Node(2);                                   
    root->right= new Node(5);                                 
    root->left->left= new Node(1);                                                                       
    root->right->right=new Node(6);
    root->left->right=new Node(3);
      inorder(root);
      cout<<'\n';
        root=delete_BST(root, 5 );
    /*if(search_BST(root,6))
        cout<<"Exists";
    else
        cout<<"Nope";
*/
inorder(root);
    cout<<'\n';
}
