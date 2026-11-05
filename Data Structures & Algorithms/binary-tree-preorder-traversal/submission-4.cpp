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
// revision practice 

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st; 
        vector<int> ans;
        TreeNode *node = root;

        while (node || !st.empty()) {
            if (node) {
                // we first store the anser
                ans.push_back(node->val);
                // then store the answer
                st.push(node);
                node = node->left;
            } else {
                // means we are going to move left
                node = st.top();
                st.pop();
                node = node->right;
            }
        }
        return ans;
    }
};