#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /*Postorder Traversal is used because we have to delete child of a node before deleting a node itself*/

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

void deleteTree(Node * root)
{
    if(root==NULL)
    return;
/*In java this function can be replaced with root=NULL because java supports automatic Garbage Collection*/
    deleteTree(root->left);
    deleteTree(root->right);
    cout<<"Deleted node: "<<root->data<<"\n";
    delete root;
}

int main()
    {
            Node *root=NewNode(1);
            root->left=NewNode(2);
            root->right=NewNode(3);
            root->left->left=NewNode(4);
            root->left->right=NewNode(5);

            deleteTree(root);
           // root=NULL;
	return 0;
}