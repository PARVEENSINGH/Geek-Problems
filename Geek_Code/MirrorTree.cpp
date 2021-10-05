#include<bits/stdc++.h>
using namespace std;
void mirror(struct Node* node) {
    // code here
    if(node == NULL)
        return;
    mirror(node->left);
    mirror(node->right);
    struct Node* temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
}