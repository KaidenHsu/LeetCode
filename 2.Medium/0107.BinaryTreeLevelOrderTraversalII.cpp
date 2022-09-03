// 9/3/22
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
    void rec(TreeNode* root, int level) {
        if (!root) return;
        res[depth - level - 1].push_back(root->val);
        rec(root->left, level + 1);
        rec(root->right, level + 1);
    }
    
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        depth = getDepth(root);
        res.assign(depth, {});
        rec(root, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    int depth;
};