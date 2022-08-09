// 8/9/22
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> mp; // [x][y, val]
        traverse(root, 0, 0, mp);
        vector<vector<int>> res;

        for(auto& [x, st]: mp) {
            res.push_back({});
            for(auto& [y, val]: st) res.back().push_back(val);
        }

        return res;
    }
    
protected:
    void traverse(TreeNode* node, int x, int y,  map<int, multiset<pair<int, int>>>& mp) {
        if(!node) return;

        mp[x].insert({y, node->val});

        traverse(node->left, x - 1, y + 1, mp);
        traverse(node->right, x + 1, y + 1, mp);
    }
};