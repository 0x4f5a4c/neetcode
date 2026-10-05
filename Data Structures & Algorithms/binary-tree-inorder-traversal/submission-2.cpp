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

// this is the revision phase

class Solution {
public:
    void solve(TreeNode *root, vector<int> &ans) {
        if (!root) return;
        if (root) {
            solve(root->left, ans);
            ans.push_back(root->val);
            solve(root->right, ans);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // recursive solution
        if (!root) return {};

        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};