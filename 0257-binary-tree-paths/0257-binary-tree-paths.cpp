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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string point;
        binaryTreePathsHelper(root, result, point);
        return result;
    }
    
    void binaryTreePathsHelper(TreeNode* root, vector<string>& result, string point) {     
        if (root == nullptr) {
            return;
        }
        
        if (root->left != nullptr || root->right != nullptr) {
            point += to_string(root->val) + "->";
        } else {
            point += to_string(root->val);
            result.push_back(point);
        }
        
        
        if (root->left != NULL) {
            binaryTreePathsHelper(root->left, result, point);
        }
        
        if (root->right != NULL) {
            binaryTreePathsHelper(root->right, result, point);
        }
    }
};