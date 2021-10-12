#include<bits/stdc++.h>
using namespace std;
class Solution
{
  public:
  vector<int> vec;
    void getDivisor(int n){
        for(int i = 1;i<=sqrt(n);i++){
            if(n%i==0){
                if(n%i==i)
                    vec.push_back(i);
                else{
                    vec.push_back(i);
                    vec.push_back(n/i);
                }    
            }
        }
    }
    int printPairs(int arr[], int n, int k)
    {
        int res = 0;
    	unordered_set<int, bool> map;
        for(int i = 0;i<n;i++){
            map[arr[i]] = true; 
        }

        for(int i = 0;i<n;i++){
            if(map[arr[i]] && k<arr[i]){
                res++;
                continue;
            }
            getDivisor(arr[i]-k);
            for(int j = 0;j<vec.size();j++){
                if(map[vec[j]] && arr[i]%vec[j]==k && vec[j]!=arr[i])
                    res++;
            }
            vec.clear();
        }
        return res;
    }
};
