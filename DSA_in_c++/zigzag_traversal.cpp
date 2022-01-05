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

void zigzag(Node* root)
{
    if(root==NULL)
        return;

        stack<Node*> Currentlevel;
        stack<Node*> Nextlevel;

        Currentlevel.push(root);
        bool lefttoright=true;

        while(!Currentlevel.empty())
        {
            Node* temp = Currentlevel.top();
            Currentlevel.pop();

                if(temp)
                {
                    cout<<temp->data<<" ";

                        if(lefttoright)
                        {
                            if(temp->left)
                                Nextlevel.push(temp->left);

                            if(temp->right)
                                Nextlevel.push(temp->right);
                        }

                    else
                        {
                            if(temp->right)
                                Nextlevel.push(temp->right);

                            if(temp->left)
                                Nextlevel.push(temp->left);
                        }
                }
                    if(Currentlevel.empty())
                    {
                        lefttoright = !lefttoright;
                        swap(Currentlevel, Nextlevel);
                    }
        }

}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right =new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->left = new Node(7);

    zigzag(root);
    cout<<endl;
}
