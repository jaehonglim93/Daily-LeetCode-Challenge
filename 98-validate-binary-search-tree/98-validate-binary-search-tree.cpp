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
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
    
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        if (root == nullptr) {
            return true;
        }
        
        if ((low && low->val >= root->val) || (high && high->val <= root->val)) {
            return false;
        }
        
        return validate(root->left, low, root) && validate(root->right, root, high);
    }
};