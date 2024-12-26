/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 1;
        int cnt = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] == 1){
                cnt++;
                ans = max(ans, cnt);
            }
            else if(nums[i] - nums[i-1] == 0){
                continue;
            }
            else{
                cnt = 1;
            }
        }
        return ans;
        // kundu bhai
    }
};
// @lc code=end

