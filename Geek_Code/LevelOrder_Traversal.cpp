#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /*Level Order Traversal. It's a BFS Implementation*/
struct Node{
    
    int data;
    struct Node* left,*right;
};

Node* NewNode(int val)
{
    Node* node = new Node();
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

void LevelOrderTraversal(Node * root)
{
    if(root==NULL)
    return;

    queue<Node*> queue;
    queue.push(root);
    
    
        while(!queue.empty())
        {
            Node* root=queue.front();
            cout<<root->data<<" ";
            queue.pop();

            if(root->left!=NULL)
            queue.push(root->left);

            if(root->right!=NULL)
            queue.push(root->right);
            
        }
}

int main()
    {
            Node *root=NewNode(1);
            root->left=NewNode(2);
            root->right=NewNode(3);
            root->left->left=NewNode(4);
            root->left->right=NewNode(5);

            LevelOrderTraversal(root);

	return 0;
}