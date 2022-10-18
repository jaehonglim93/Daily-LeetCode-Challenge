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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> level;
        level.push(root);
        
        while (!level.empty()) {
            int count = level.size();
            double sum = 0;
            
            for (int i = 0; i < count; i++) {
                TreeNode* temp = level.front();
                level.pop();
                
                if (temp->left != NULL) {
                    level.push(temp->left);
                }
                
                if (temp->right != NULL) {
                    level.push(temp->right);
                }
                
                sum += temp->val;
            }
            
            result.push_back(sum / count);
        }
        
        return result;
    }
};