class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        using i64 = long long;
        int n = grid.size(), m = grid[0].size();
        vector<vector<i64>> sum(n + 1, vector<i64> (m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        bool ans = false;
        for (int i = 2; i <= n; i++) {
            if (2 * sum[i - 1][m] == sum[n][m]) ans = true;
        }
        for (int i = 2; i <= m; i++) {
            if (2 * sum[n][i - 1] == sum[n][m]) ans = true;
        }
        return ans;
    }
};