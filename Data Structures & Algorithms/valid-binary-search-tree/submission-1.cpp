// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

// brute force solution
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

class Solution {
public:
    void solve(TreeNode *node, vector<int> &ans) {
        if (!node) return;
        solve(node->left, ans);
        ans.push_back(node->val);
        solve(node->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        for (int x : ans) cout << x << " ";
        cout << endl;
        for (int i = 1; i < ans.size(); ++i) {
            if (ans[i-1] >= ans[i]) return false;
        }
        
        return true;
    }
};
