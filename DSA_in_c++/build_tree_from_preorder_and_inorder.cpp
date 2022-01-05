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

int search(int inorder[], int start, int end, int curr)
{
      for(int i=start;i<=end;i++)
      {
          if(inorder[i]==curr)
            return i;
      }
      return -1;
}

Node* buildtree(int preorder[], int inorder[], int start, int end)   
{
  static int idx=0;

    if(start>end)                    // base condition 
    {
        return NULL;
    }
     
     int curr=preorder[idx];  //find position of the elemnt in preorder
     idx++;

     Node* node= new Node(curr);    //creating nodes

      if(start==end)                //incase of only 1 element in inorder     //exception
      {
          return node;
      }

     int pos=search(inorder,start,end,curr);    //locate the element in inorder

     node->left=buildtree(preorder,inorder,start,pos-1);
     node->right=buildtree(preorder,inorder,pos+1,end);

    return node;
}


void inorderprint(struct Node* root)
{
   if(root==NULL)
   {
       return;
   }
      inorderprint(root->left);
      cout<<root->data<<" ";
      inorderprint(root->right);
}

int main()
{
    int preorder[]={1, 2, 4, 3, 5};
    int inorder[]={4, 2, 1, 5, 3}; 

    Node* root= buildtree(preorder,inorder,0,4);
    cout<<endl;
    inorderprint(root);
    cout<<endl;
}
