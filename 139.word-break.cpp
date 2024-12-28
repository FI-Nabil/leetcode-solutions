/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool>mp;
        for(auto u:wordDict){
            mp[u] = 1; 
        }
        set<int>st;
        st.insert(-1);
        while(st.size()){
            int ind = *st.begin();
            cout << ind << endl;
            if(ind + 1== s.size()){
                return true;
            }
            st.erase(ind);
            string str;
            for(int i=ind+1; i<s.size(); i++){
                str += s[i];
                if(str.size() > 20){
                    break;
                }
                if(mp[str]){
                    st.insert(i);
                }
            }
        }
        return false;
    }
};
// @lc code=end

