#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
      int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int plat = 1,res = 1,i=1,j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                plat++;
                i++;
            }
            else if(arr[i]>dep[j]){
                plat--;
                j++;
            }
            if(res<plat)
                res = plat;
        }
        return res;
    	// Your code here
    }
};