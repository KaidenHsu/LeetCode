// 8/11/22
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
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }
   
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        inOrder(root);
        for (int i = 1; i < tree.size(); i++)
            if (tree[i] <= tree[i - 1]) return false;
        return true;
    }
    
private:
    vector<int> tree;
};