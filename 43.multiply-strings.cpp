/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    vector<string>v;
    string zero;
    for(char c1 : num1){
        int carry = 0;
        string s; 
        for(char c2: num2){
            int p = (c1-'0') * (c2-'0');
            p += carry;
            char ch = (p%10) + '0';
            carry = p/10;
            s += ch;
        }
        if(carry){
            s += (carry + '0');
        }
        reverse(s.begin(), s.end());
        if(v.size()){
            zero += "0";
            s += zero;
        }
        v.push_back(s);
    }    
    string fin = v.back();
    for(int i=0; i<v.size()-1; i++){
        int ex = fin.size() - v[i].size();
        string s;
        for(int j=1; j<=ex; j++){
            s += '0';
        }
        v[i] = s + v[i];
    }
    int r = v.size();
    int c = fin.size();
    int carry = 0;
    string res;
    for(int i = c-1; i >= 0; i--){
        int sum = 0;
        for(int j = 0; j < r; j ++){
            sum += (v[j][i])-'0';
        }
        sum += carry;
        res += (sum%10) + '0';
        carry = sum / 10;
    }
    while(carry){
        res += (carry % 10) + '0';
        carry /= 10;
    }
    while(res.size() > 1 and res.back() == '0'){
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
    }
};
// @lc code=end

