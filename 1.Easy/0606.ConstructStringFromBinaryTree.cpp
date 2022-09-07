// 9/7/22
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
    void buildStr(TreeNode* node, ostringstream& out) {
        if (!node) return;
        
        out << node->val;
        
        if (node->left || node->right) {
            out << "(";
            buildStr(node->left, out);
            out << ")";
            
            if (node->right) {
                out << "(";
                buildStr(node->right, out);
                out << ")";
            }
        }
    }
    
public:
    string tree2str(TreeNode* t) {
        ostringstream out;
        buildStr(t, out);
        return out.str();
    }
};