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

    TreeNode *solve(vector<int> &in, vector<int> &post, int inStart, int inEnd, int pStart, int pEnd) {
        if (inStart > inEnd) return nullptr;
        int i = inStart;
        TreeNode *node = new TreeNode(post[pEnd]); // we know the last element becomes the root
        for (; i <= inEnd; ++i) {
            // try to find the node in the inorder
            if (in[i] == node->val) break;
        }
        // now what are the size in the left and right of the inorder except the root
        int left_size = i - inStart;
        int right_size = inEnd - i;

        // now go left and right
        node->left = solve(in, post, inStart, i-1, pStart, pStart + left_size - 1);
        node->right = solve(in, post, i+1, inEnd, pEnd - right_size, pEnd - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0, inEnd = n-1;
        int pStart = 0, pEnd = n-1;

        return solve(inorder, postorder, inStart, inEnd, pStart, pEnd);
    }
};