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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        
        return helper(root, targetSum, root->val);
    }
    
    bool helper(TreeNode* root, int targetSum, int sum) {
        if (root->left == NULL && root->right == NULL) {
            return targetSum == sum;
        }
        
        if (root->left != NULL && root->right != NULL) {
            return helper(root->left, targetSum, sum + root->left->val) || helper(root->right, targetSum, sum + root->right->val);
        }
        
        if (root->left != NULL) {
            return helper(root->left, targetSum, sum + root->left->val);
        } else {
            return helper(root->right, targetSum, sum + root->right->val);
        }
    }
};