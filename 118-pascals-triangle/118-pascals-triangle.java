class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();
        
        for (int i = 0; i < numRows; i++) {
            List<Integer> level = new ArrayList<>();
            
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    level.add(1);
                    
                } else {
                    int a = triangle.get(i - 1).get(j - 1);
                    int b = triangle.get(i - 1).get(j);
                    level.add(a + b);
                }
            }
            
            triangle.add(level);
        }
        
        return triangle;
    }
}