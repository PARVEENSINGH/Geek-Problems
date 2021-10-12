#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> res;
		    string temp = "";
		    for(int i = 0;i<(1<<s.size());i++){
		        temp = "";
		        for(int j = 0;j<s.size();j++){
		            if(i&(1<<j))
		                temp+=s[j];
		        }
		        res.push_back(temp);
		    }
		    return res;
		}
};
