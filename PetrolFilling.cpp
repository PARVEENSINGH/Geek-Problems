class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n = gas.size();
      int  res = 0,temp =0;
      int c = 0;
        
        for(int i = 0;i<n;i++){
            c+=gas[i]-cost[i];
            if(c<0){
                temp+=c*-1;
                c = 0;
                res = i+1;
            }
        }
        return c>=temp?res:-1; 
    }
};