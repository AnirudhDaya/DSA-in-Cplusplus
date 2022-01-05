#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void vertical_order_print(Node* root, int hd, map<int,vector<int>> &m)
{
     if(root == NULL)
        return;

    m[hd].push_back(root->key);

    vertical_order_print(root->left, hd-1, m);
    vertical_order_print(root->right, hd+1, m);
}

int main()
{
    Node* root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->left->right = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);

    map<int,vector<int>> m;
    int hd = 0;

    vertical_order_print(root,hd,m);

    map<int,vector<int>> :: iterator it;

    for(it=m.begin() ; it!=m.end(); it++)
    {
        for(int i=0 ; i<(it->second).size(); i++)
                cout<<(it->second)[i]<<" ";

            cout<<endl;
    }
}
