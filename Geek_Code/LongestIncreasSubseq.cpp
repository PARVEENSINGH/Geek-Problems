#include<bits./stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       int lis[n];
       lis[0] = 1;
       for(int i = 1;i<n;i++){
           lis[i] = 1;
           for(int j = 0;j<i;j++){
               if(a[i]>a[j] && lis[i] <1+lis[j])
                lis[i]  = lis[j]+1;
           }
       }
       return *max_element(lis,lis+n);
    }
};