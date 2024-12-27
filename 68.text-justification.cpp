/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        bool first = true;
        int cnt = 0;
        int sz = 0;
        vector<int>v;
        for(auto u:words){
            if(first){
                first = false;
                sz += u.size();
                cnt++;
            }
            else{
                if(sz+1+u.size() <= maxWidth){
                    cnt++;
                    sz += u.size() + 1;
                }
                else{
                    v.push_back(cnt);
                    cnt = 1;
                    sz = u.size();
                }
            }
        }
        v.push_back(cnt);
        vector<string>ans;
        int j = 0;
        for(int i=0; i<v.size()-1; i++){
        
            vector<string>temp;
            int wrd = v[i];
            int siz = 0;
            while(wrd>0){
                wrd--;
                siz += words[j].size();
                temp.push_back(words[j++]);
            }
            int totSpace = maxWidth - siz;
            int fixSpace = totSpace;
            if(v[i] > 1){
                fixSpace = totSpace/(v[i]-1);
            }
            int exSpace =  totSpace - (fixSpace * (v[i]-1));
            string s;
            string space;
            for(int in = 1; in <= fixSpace; in++){
                space += ' ';
            }
            for(int k = 0; k < temp.size(); k++){
                if(k == 0){
                    s += temp[k];
                }
                else{
                    s += space;
                    if(exSpace){
                        exSpace--;
                        s += ' ';
                    }
                    s += temp[k];
                }
            }
            while(s.size() < maxWidth){
                s += ' ';
            }
            ans.push_back(s);
        }
        string final;
        final ="";
        for(int i = 1; i <= v.back(); i++)
        {
          if(final.size() == 0){
            final += words[j];
          }
          else{
            final += " ";
            final += words[j];
          }
          j++;
        }
        int val = maxWidth-final.size();
      //  cout <<maxWidth - final.size() << endl;
        for(int i = 1; i <= val; i++){
            final += " ";
        }
        ans.push_back(final);
        return ans;

    }
};
// @lc code=end

