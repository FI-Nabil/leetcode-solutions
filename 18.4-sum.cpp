/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

#define ll  long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<ll,vector<ll>>mp;
        for(ll i = 0; i< nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        set<vector<int>>st;

        for(ll i = 0; i < nums.size(); i++){
            for(ll j = i+1; j < nums.size(); j++){
                for(ll k = j + 1; k < nums.size(); k++){
                    ll val = target ;
                    val-= nums[i];
                    val-=  nums[j];
                    val-= nums[k];
                    if(mp[val].size() and mp[val].back() > k){
                        ll l = mp[val].back();
                        vector<int>ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[k]);
                        ans.push_back(nums[l]);
                        sort(ans.begin(),ans.end());
                        st.insert(ans);
                    }
                }
            }
        }
        vector<vector<int>>v;
        v.assign(st.begin(), st.end());
        return v;

    }
};
// @lc code=end

