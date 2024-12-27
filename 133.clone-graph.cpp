/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start

// Definition for a Node.

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr; // Return nullptr for a null input
        }
        map<Node*, Node*> cln;
        queue<Node*>q;
        q.push(node);
        cln[node] = new Node(node->val);
        while(!q.empty()){
            Node * nd = q.front();
            q.pop();

            for(auto u:nd->neighbors){
                if(cln.find(u) == cln.end()){
                    cln[u] = new Node(u->val);
                    q.push(u);
                }
            cln[nd]->neighbors.push_back(cln[u]);
            }
        }
        return cln[node];
    }
};
// @lc code=end

