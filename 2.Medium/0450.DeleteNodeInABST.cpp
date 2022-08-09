// 8/9/22
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key); // We frecursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{ // key == root->val
                if(!root->left && !root->right) return NULL; // No child condition
                if (!root->left || !root->right) return root->left ? root->left : root->right; // One child contion -> replace the node with it's child

                // Two children condition
                // In this case, in order to conserve the BST properties, we need to replace the node with it's inorder successor
                // (The next node that comes in the inorder traversal) i.e; we need to replace it with either :
                // 1. The greatest value node in it's left subtree (or)
                // 2. The smallest value node in it's right subtree
                // and return the root.
                TreeNode* temp = root->left; // (or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right; // while(temp->left != NULL) temp = temp->left;
                root->val = temp->val; // root->val = temp->val;
                root->left = deleteNode(root->left, temp->val); // root->right = deleteNode(root->right, temp);		
            }

        return root;
    }   
};