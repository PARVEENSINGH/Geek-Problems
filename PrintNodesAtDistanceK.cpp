#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
class Solution
{
private:

public:

    vector<int> res;
    void printNodeAtDistanceKDown(Node *root,int k){
        if(root == NULL || k<0)
            return;
        if(k==0){
            res.push_back(root->data);   
            return;
        } 
        printNodeAtDistanceKDown(root->left,k-1);
        printNodeAtDistanceKDown(root->right,k-1);
    }

    int PrintNodeAtDistanceK(Node *root,int target,int k){
        if(root == NULL)
            return -1;
        if(root->data == target){
            printNodeAtDistanceKDown(root,k);
            return 0;
        }    
        int  distance_left = PrintNodeAtDistanceK(root->left,target,k);
        if(distance_left!=-1){
            if(distance_left+1 == k){
                res.push_back(root->data);
            }
            else
                printNodeAtDistanceKDown(root->right,k-distance_left-2);
            return 1+distance_left;    
        }

        int distance_right = PrintNodeAtDistanceK(root->right,target,k);
        if(distance_right!=-1){
            if(distance_right+1==k){
                res.push_back(root->data);
            }
            else
                printNodeAtDistanceKDown(root->left,k-distance_right-2);
            return 1+distance_right;    
        }

        //If target node is not found
        return -1;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
      
       res.clear();
       if(root==NULL)
        return res;
        PrintNodeAtDistanceK(root,target,k);
        sort(res.begin(),res.end());
        return res;
    }
};