/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        
        if (root == p) {
            return root;
        }
        
        if (root == q) {
            return root;
        }
         
        TreeNode* low = lowestCommonAncestor(root->left, p, q);
        TreeNode* high = lowestCommonAncestor(root->right, p, q);
        
        if (low == nullptr && high == nullptr) {
            return nullptr;
        } 
        
        if (low != nullptr && high != nullptr) {
            return root;
        }
        
        if (low == nullptr) {
            return high;
        }
        
        return low;
    }
};