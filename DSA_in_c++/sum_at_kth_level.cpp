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


void levelorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);     // push first element
    q.push(NULL);      // after the first level push NULL

    while(!q.empty())
    {
        Node* node= q.front();   //stores the element in front
        q.pop();
            if(node!=NULL)
            {
                cout<<node->data<<" ";     //prints the popped element

                if(node->left)
                    q.push(node->left);        //pushes any left element
                if(node->right)
                    q.push(node->right);      //pushes any right element
            }

        else
            if(!q.empty())               //if node is NULL i.e; next level 
            {
                q.push(NULL);
            }
    }
}

void sum_at_k(Node* root, int k)
{   
    if(root==NULL)
    {   
        exit(0);
    }

     queue<Node*> q;
     q.push(root);
     q.push(NULL);

     int sum=0;
     int level=0;

     while(!q.empty())
     {
         Node* node=q.front();
         q.pop();

            if(node!=NULL)
            {
                if(level==k)
                sum+=node->data;

                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
        else
            if(!q.empty())
            {
                q.push(NULL);
                level++;
            }
     }
     cout<<"\nSum at kth node is:  "<<sum<<endl;
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
    
    int k;
    cout<<"Enter the level whose sum is to be computed:\n";
        cin>>k;

    sum_at_k(root,k);
}
