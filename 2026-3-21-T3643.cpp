class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x, j = x + k - 1; i < j; i++, j--) {
            for (int l = 0; l < k; l++) {
                swap(grid[i][y + l], grid[j][y + l]);
            }
        }
        return grid;
    }
};