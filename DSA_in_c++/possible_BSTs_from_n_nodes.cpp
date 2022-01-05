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

vector<Node*> Possible_BSTs(int start, int end)
{
        vector<Node*> Trees;
    if(start>end)
    {
        Trees.push_back(NULL);
        return Trees;
    }

        for(int i= start; i<=end;i++)
        {
            vector<Node*> LeftSubTrees = Possible_BSTs(start,i-1);
            vector<Node*> RightSubTrees= Possible_BSTs(i+1,end);    // right subtrees should have greater value

                for(int j=0;j<LeftSubTrees.size();j++)           //loops to combine smaller paths into 1 
                {   Node* left= LeftSubTrees[j];       

                    for(int k=0;k<RightSubTrees.size();k++)
                    {   Node* right = RightSubTrees[k];

                        Node* node = new Node(i);
                        node->left= left;
                        node->right=right;

                        Trees.push_back(node);
                    
                    }
                
                }
        }

    return Trees;
}

void const_preorder(Node* root)
{
    if(root==NULL)
        return ;

    cout<<root->data<<" ";
    const_preorder(root->left);
    const_preorder(root->right);
}

int main()
{
        vector<Node*> Totaltrees = Possible_BSTs(1,3);

        for(int i=0;i<Totaltrees.size();i++)
            {
                cout<<i+1<<" : ";
                const_preorder(Totaltrees[i]);   //since each path is stored in array
                cout<<'\n';
            }
}
