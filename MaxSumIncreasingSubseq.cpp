#include<bits/stdc++.h>
using namespace std;
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int a[n],*res;
        for(int i = 0;i<n;i++)
            a[i] = arr[i];
        for(int i = 1;i<n;i++){
            for(int j =0;j<i;j++){
                if(arr[i]>arr[j] && a[i]<arr[i]+a[j])
                   a[i] =  arr[i]+a[j];
            }
        }  
        res = max_element(a,a+n);
        return *res;
	}  
};
