/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* node, vector<int> &ans) {
        if (!node) return;
        solve(node->left, ans);
        ans.push_back(node->val);
        solve(node->right, ans);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        int mini_distance = INT_MAX;
        for (int i = 1; i < ans.size(); ++i) {
            mini_distance = min(mini_distance, abs(ans[i] - ans[i-1]));
        }
        return mini_distance;
    }
};
