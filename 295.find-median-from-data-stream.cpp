/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:

    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> larger;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smaller.push(num);
        if(!larger.empty() and smaller.top() > larger.top()){
            larger.push(smaller.top());
            smaller.pop();
        }
        if(smaller.size() > larger.size()+ 1){
            larger.push(smaller.top());
            smaller.pop();
        }
        else if(larger.size() > smaller.size()){
            smaller.push(larger.top());
            larger.pop();
        }
        
    }
    
    double findMedian() {
        if(smaller.size() == larger.size()){
            double x = smaller.top() + larger.top();
            x /= 2.00;
            return x;
        }
        else{
            double x = smaller.top();
            return x;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

