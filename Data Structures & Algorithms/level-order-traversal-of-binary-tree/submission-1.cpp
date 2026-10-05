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

// practicing 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // using queue data structre
        if (!root) return {};
        vector<vector<int>> ans;
        TreeNode *temp = root;
        queue<TreeNode*> q;
        q.push(temp);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            while (sz > 0) {
                TreeNode *node = q.front();
                q.pop();

                temp.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                sz--;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
