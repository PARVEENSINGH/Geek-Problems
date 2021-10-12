#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<double> max_heap;
    priority_queue<double, vector<double>, greater<double>> min_heap;
    double med = 0.0;
    bool  flag = false;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if(!flag){
        //     med = num;
        //     flag = true;
        //     max_heap.push(num);
        // }
        if(max_heap.size()>min_heap.size()){
            if(num<med){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else
                min_heap.push(num);
            med = (max_heap.top()+min_heap.top())/2.0;   
        }

        else if(max_heap.size()<min_heap.size()){
            if(num>med){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else
                max_heap.push(num);
            med = (max_heap.top()+min_heap.top())/2.0;    
        }

        else{
            if(num>med){
                min_heap.push(num);
                med = min_heap.top();
            }
            else{
                max_heap.push(num);
                med = max_heap.top();
            }
        }
        
    }
    
    double findMedian() {
        return med;
    }
};