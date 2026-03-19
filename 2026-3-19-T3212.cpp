class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> sum_x(n + 1, vector<int> (m + 1, 0)), sum_y(n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum_x[i][j] = sum_x[i - 1][j] + sum_x[i][j - 1] - sum_x[i - 1][j - 1] + 
                                (grid[i - 1][j - 1] == 'X');
                sum_y[i][j] = sum_y[i - 1][j] + sum_y[i][j - 1] - sum_y[i - 1][j - 1] + 
                                (grid[i - 1][j - 1] == 'Y');
                if (sum_x[i][j] && sum_x[i][j] == sum_y[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};