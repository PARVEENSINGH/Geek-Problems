#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> res;
    void GetMinAndMax(Node* root,int *min_ele,int *max_ele, int wr){
        if(root == NULL)
            return;
        if(wr<*min_ele)
            *min_ele = wr;
        if(wr>*max_ele)
            *max_ele = wr;  
        GetMinAndMax(root->left,min_ele,max_ele,wr-1);
        GetMinAndMax(root->right,min_ele,max_ele,wr+1);
    }
    void GetNodes(Node * root,int i,int wr){
        if(root == NULL)
            return;
        if(i==wr)
            res.push_back(root->data);
        GetNodes(root->left,i,wr-1);
        GetNodes(root->right,i,wr+1);       
    }
    vector<int> verticalOrder(Node *root)
    {   res.clear();
        int min_ele = 0,max_ele = 0;
        if(root== NULL)
            return res;
        GetMinAndMax(root,&min_ele,&max_ele,0);    
        for(int i = min_ele;i<=max_ele;i++){
            GetNodes(root,i,0);
        }
        return res;
        //Your code here
    }
};