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

    int kthSmallest(TreeNode* root, int k) {
        //brute force solution
        // traverse in the tree inorder and form an array and return the arr[k-1]
        vector<int> ans;
        solve(root, ans);
        return ans[k-1];
    }
};
