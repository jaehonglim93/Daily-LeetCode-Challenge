class Solution {
    public int minimumSum(int num) {
        int[] digits = new int[4];
        int count = 0;
        
        while (num > 0) {
            digits[count] = num % 10;
            num /= 10;
            count++;
        }
        
        Arrays.sort(digits);
        int firstHalf = digits[0] * 10 + digits[2];
        int secondHalf = digits[1] * 10 + digits[3];
        
        return firstHalf + secondHalf;
    }
}