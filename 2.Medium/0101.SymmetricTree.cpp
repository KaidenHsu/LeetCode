// 6/23/23

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
    bool helper(TreeNode* left, TreeNode* right){
        if(!left || !right) return left == right;
        if(left->val != right->val) return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
}
