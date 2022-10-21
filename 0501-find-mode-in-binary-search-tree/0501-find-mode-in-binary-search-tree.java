/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<Integer, Integer> map;
    int max;
    
    public int[] findMode(TreeNode root) {
        if (root == null) {
            return new int[0];
        }
        
        this.map = new HashMap<>();
        
        traverse(root);
        
        List<Integer> result = new ArrayList<>();
        
        for (int key : map.keySet()) {
            if (map.get(key) == max) {
                result.add(key);
            }
        }
        
        int[] resultArray = new int[result.size()];
        
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }
        
        return resultArray;
    }
    
    private void traverse(TreeNode root) {
        if (root == null) {
            return;
        }
        
        map.put(root.val, map.getOrDefault(root.val, 0) + 1);
        max = Math.max(max, map.get(root.val));
        traverse(root.left);
        traverse(root.right);
    }
}