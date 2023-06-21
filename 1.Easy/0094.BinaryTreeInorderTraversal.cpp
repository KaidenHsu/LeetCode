// 6/21/23

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
private:
    vector<int> v;

    void helper (TreeNode* root) {
        if (root->left) helper(root->left);
        v.push_back(root->val);
        if (root->right) helper(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) helper(root);
        return v;
    }
}
