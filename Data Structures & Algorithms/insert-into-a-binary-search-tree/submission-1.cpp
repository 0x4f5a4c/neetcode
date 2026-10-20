// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
// Question Link : https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// Question Link : https://neetcode.io/problems/insert-into-a-binary-search-tree/question

#include <bits/stdc++.h>
// #include "TreeNode.h"
using namespace std;

/**
 * another recursive approach
 * 
 */

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else 
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }
};