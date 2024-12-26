/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll  long long
#define ff first
#define ss second
#define pb push_back
#define YES cout <<"Yes\n"
#define NO cout <<"No\n"
#define endl '\n';
#define setbit __builtin_popcountll
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
        bool f = false;
        for(int i = n-2; i>=0; i--){
              if(nums[i] < nums[i+1]){
                f = true;
                pair<int,int>p;
                p.first = 101;
                for(int j = i+1; j < n; j++){
                    if(nums[j] > nums[i]){
                        if(nums[j] < p.first){
                            p.first = nums[j];
                            p.second = j;
                        }
                    }
                }
                swap(nums[i], nums[p.second]);
                sort(nums.begin()+i+1, nums.end());

                break;
              }
        }
       
        if(!f){
            sort(nums.begin(), nums.end());
        }

    }
};
// @lc code=end

