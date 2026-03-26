class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pre(n + 1, vector<int> (m + 1)), suc(n + 1, vector<int> (m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) pre[i][j] = grid[i - 1][j - 1];
                else if (j == 1) pre[i][j] = 1ll * pre[i - 1][m] * grid[i - 1][j - 1] % mod;
                else pre[i][j] = 1ll * pre[i][j - 1] * grid[i - 1][j - 1] % mod;
            }
        }
        for (int i = n; i; i--) {
            for (int j = m; j; j--) {
                if (i == n && j == m) suc[i][j] = grid[i - 1][j - 1];
                else if (j == m) suc[i][j] = 1ll * suc[i + 1][1] * grid[i - 1][j - 1] % mod;
                else suc[i][j] = 1ll * suc[i][j + 1] * grid[i - 1][j - 1] % mod;
            }
        }
        vector<vector<int>> ans(n, vector<int> (m));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans[i - 1][j - 1] = 1;
                if (i == 1 && j == 1) ;
                else if (j == 1) ans[i - 1][j - 1] = 1ll * ans[i - 1][j - 1] * pre[i - 1][m] % mod;
                else ans[i - 1][j - 1] = 1ll * ans[i - 1][j - 1] * pre[i][j - 1] % mod;
                if (i == n && j == m) ;
                else if (j == m) ans[i - 1][j - 1] = 1ll * ans[i - 1][j - 1] * suc[i + 1][1] % mod;
                else ans[i - 1][j - 1] = 1ll * ans[i - 1][j - 1] * suc[i][j + 1] % mod;
            }
        }
        return ans;
    }
};