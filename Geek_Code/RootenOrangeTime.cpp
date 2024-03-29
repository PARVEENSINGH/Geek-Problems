#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    
    typedef struct node{
        int a;
        int b;
        node(int x,int y){
            a = x;
            b = y;
        }
    }node;
    
   
    int ans = 0,r,c;
    
    bool isValid(int i,int j){
        if(i>=0 && i<r && j>=0 && j<c)
            return true;
        return false;    
    }
    
    bool isdelim(node temp){
        return (temp.a ==-1 && temp.b==-1);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
         queue<node> q;
         ans = 0;
        for(int i = 0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] ==2)
                    q.push(node(i,j));
            }
        }

        // adding delim
        q.push(node(-1,-1));
        //node temp;
        while(!q.empty()){
            //node temp = q.front();
            bool flag = false;
            while(!isdelim(q.front())){
                   node temp = q.front();
                    if(isValid(temp.a+1,temp.b) && grid[temp.a+1][temp.b] == 1){
                        if(!flag){
                            ans++;
                        flag = true;
                        }  
                        grid[temp.a+1][temp.b] = 2;    
                        temp.a++;    
                        q.push(temp);
                        temp.a--; 
                    }

                    if(isValid(temp.a-1,temp.b) && grid[temp.a-1][temp.b] == 1){
                        if(!flag){
                            ans++;
                        flag = true;
                        }    
                        grid[temp.a-1][temp.b] = 2;    
                        temp.a--;    
                        q.push(temp);
                        temp.a++; 
                    }

                    if(isValid(temp.a,temp.b+1) && grid[temp.a][temp.b+1] == 1){
                        if(!flag){
                            ans++;
                        flag = true;
                        }
                        grid[temp.a][temp.b+1] = 2;    
                        temp.b++;    
                        q.push(temp);
                        temp.b--; 
                    }

                    if(isValid(temp.a,temp.b-1) && grid[temp.a][temp.b-1] == 1){
                        if(!flag){
                            ans++;
                        flag = true;
                        }
                        grid[temp.a][temp.b-1] = 2;    
                        temp.b--;    
                        q.push(temp);
                        //temp.b++; 
                    }
                q.pop();
            }
            q.pop();
            if(!q.empty())
                 q.push(node(-1,-1));
            
        }
        for(int i = 0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] ==1)
                   return -1;
            }
        }
        return ans;
    }
};