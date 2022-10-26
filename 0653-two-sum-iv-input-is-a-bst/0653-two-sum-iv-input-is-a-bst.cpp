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
    bool findTarget(TreeNode* root, int k) {
        vector<int> rep;
        fillVector(root, rep);
        
        int left = 0;
        int right = rep.size() - 1;
        
        while (left < right) {
            if (rep[left] + rep[right] == k) {
                return true;
            } else if (rep[left] + rep[right] > k) {
                right--;
            } else {
                left++;
            }
        }
        
        return false;
    }
    
    void fillVector(TreeNode* root, vector<int>& rep) {
        if (root == NULL) {
            return;
        }
        
        fillVector(root->left, rep);
        rep.push_back(root->val);
        fillVector(root->right, rep);
    }
};