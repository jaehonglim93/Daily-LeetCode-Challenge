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
    int minDiffInBST(TreeNode* root) {
        int result = INT_MAX;
        int min = -1;
        helper(root, min, result);
        return result;
    }
    
    void helper(TreeNode* root, int &min, int& result) {
        if (root != NULL) {
            helper(root->left, min, result);
            
            if (min != -1) {
            result = std::min(root->val - min, result);
            }
        
            min = root->val;
            helper(root->right, min, result);
        }
    }
};