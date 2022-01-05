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


Node* buildtree(int postorder[], int inorder[], int start, int end)   
{
  static int idx=4;

    if(start>end)                    // base condition 
    {
        return NULL;
    }
     
     int curr=postorder[idx];  //find position of the elemnt in postorder
     idx--;

     Node* node= new Node(curr);    //creating nodes

      if(start==end)                //incase of only 1 element in inorder     //exception
      {
          return node;
      }

     int pos=search(inorder,start,end,curr);    //locate the element in inorder

     node->right=buildtree(postorder,inorder,pos+1,end);
     node->left=buildtree(postorder,inorder,start,pos-1);

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
    int postorder[]={4, 2, 5, 3, 1};
    int inorder[]={4, 2, 1, 5, 3}; 

    Node* root= buildtree(postorder,inorder,0,4);
    cout<<endl;
    inorderprint(root);
    cout<<endl;
}