class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    eraseOne(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    void eraseOne(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseOne(grid, i - 1, j);
        eraseOne(grid, i + 1, j);
        eraseOne(grid, i, j - 1);
        eraseOne(grid, i, j + 1);
    }
};