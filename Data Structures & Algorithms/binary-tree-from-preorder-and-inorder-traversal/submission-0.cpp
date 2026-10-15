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
    TreeNode *solve(vector<int> &pre, vector<int> &in, int start, int end, int &idx) {
        if (start > end) return nullptr;
        int i = start;
        int root_val = pre[idx];
        for (; i <= end; ++i) {
            if (in[i] == root_val) break;
        }
        idx++;
        TreeNode *node = new TreeNode(root_val);
        node->left  = solve(pre, in, start, i-1, idx);
        node->right = solve(pre, in, i + 1, end, idx);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n   = preorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx);
    }
};
