class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        using i64 = long long;
        int n = grid.size(), m = grid[0].size();
        vector<vector<i64>> mn(n + 1, vector<i64> (m + 1)), mx(n + 1, vector<i64> (m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) {
                    mn[i][j] = grid[i - 1][j - 1];
                    mx[i][j] = grid[i - 1][j - 1];
                }
                else {
                    if (i > 1 && j > 1) {
                        i64 x1 = mn[i - 1][j] * grid[i - 1][j - 1];
                        i64 x2 = mx[i - 1][j] * grid[i - 1][j - 1];
                        i64 x3 = mn[i][j - 1] * grid[i - 1][j - 1];
                        i64 x4 = mx[i][j - 1] * grid[i - 1][j - 1];
                        mn[i][j] = min({x1, x2, x3, x4});
                        mx[i][j] = max({x1, x2, x3, x4});
                    }
                    else if (i > 1) {
                        i64 x1 = mn[i - 1][j] * grid[i - 1][j - 1];
                        i64 x2 = mx[i - 1][j] * grid[i - 1][j - 1];
                        mn[i][j] = min({x1, x2});
                        mx[i][j] = max({x1, x2});
                    }
                    else if (j > 1) {
                        i64 x3 = mn[i][j - 1] * grid[i - 1][j - 1];
                        i64 x4 = mx[i][j - 1] * grid[i - 1][j - 1];
                        mn[i][j] = min({x3, x4});
                        mx[i][j] = max({x3, x4});
                    }
                }
            }    
        }
        i64 ans = mx[n][m];
        const int mod = 1e9 + 7;
        if (ans < 0) return -1;
        else return ans % mod;
    }
};