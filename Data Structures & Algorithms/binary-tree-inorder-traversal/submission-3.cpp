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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;  // for storing the nodes
        vector<int> ans;  // for storing the answer
        TreeNode *temp = root;
        while (temp || !st.empty()) {
            if (temp) {
                st.push(temp);       // first storing the node into the stack
                temp = temp->left;  // we are moving left
            } else {
                // get the top node from the stack
                temp = st.top();
                st.pop();  // pop the node out
                ans.push_back(temp->val);  // store the answer or value
                temp = temp->right; // move right
            }
        }

        return ans;
    }
};