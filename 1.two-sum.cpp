/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int ind = 0;
        for(auto u:nums){
            ind++;
            // if(u > target){
            //     continue;
            // }
            if(mp[target-u]){
                vector<int>v;
                v.push_back(mp[target-u]-1);
                v.push_back(ind-1);
                return v;
            }
            mp[u] = ind;
        }
        vector<int>v;
        return v;
    }
};
// @lc code=end

