/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int  solve(int i, int target, vector<int>& nums){
        if(i == nums.size()){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
       int ways = solve(i+1, target-nums[i], nums);
       ways += solve(i+1, target+nums[i], nums);
       return ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       return solve(0, target, nums);
    }
};
// @lc code=end

