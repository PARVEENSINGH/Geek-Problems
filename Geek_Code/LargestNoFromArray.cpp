#include<bits/stdc++.h>
using namespace std;
 int comparefun(string a,string b){
        string ab = a.append(b);
        string ba = b.append(a);
        return ab.compare(ba)>0?1:0;
    } 
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
   
	string printLargest(vector<string> &arr) {
	    // code here
        string res = "";
        sort(arr.begin(),arr.end(),comparefun);
	    for(int i = 0;i<arr.size();i++)
            res+=arr[i];
        return res;    
	}
};