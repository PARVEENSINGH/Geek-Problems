#include<bits/stdc++.h>
using namespace std;

int NeededMove(int M[][]){

    queue<pair<pair<int, int> ,int>> q;
    int n;
    for(auto i:n){
        for(auto j: n){
            if(M[i][j]==1)
                q.push(make_pair({i,j},0));
        }
    }

    int res = 1;
    while(!q.empty()){
        pair<int,int> temp = q.front().first;
        int dd=q.front().second;
        q.pop();
        if(M[temp.first][temp.second]==2)
            return res;
       
        if(isvalid(temp.first+1,temp.second) && M[temp.first+1][temp.second] ==3){
            temp.first++;
            q.push({temp,dd+1});
            M[temp.first+1][temp.second] = 4;
            temp.first--;
        }

        if(isvalid(temp.first-1,temp.second) && M[temp.first-1][temp.second] ==3){
            temp.first--;
            q.push(temp);
            M[temp.first-1][temp.second] = 4;
            temp.first++;
        }
        if(isvalid(temp.first,temp.second+1) && M[temp.first][temp.second+1] ==3){
            temp.second++;
            q.push(temp);
            M[temp.first][temp.second+1] = 4;
            temp.second--;
        }
            if(isvalid(temp.first,temp.second-1) && M[temp.first][temp.second-1] ==3){
            temp.second--;
            q.push(temp);
            M[temp.first][temp.second+1] = 4;  
        }
        
        res++;

    }
}