class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (map.get(target-nums[i]) != null && map.get(target-nums[i]) != i) {
                result[0] = i;
                result[1] = map.get(target-nums[i]);
            }
        }
        
        return result;
    }
}