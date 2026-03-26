#pragma optimize(1, 2, 3, "Ofast")
class Solution {
public:
    bool calc(const vector<vector<int>>& grid) {
        using i64 = long long;
        int n = grid.size(), m = grid[0].size();
        vector<vector<i64>> sum(n + 1, vector<i64> (m + 1));
        unordered_set<int> s; 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        bool ans = false;
        for (int i = 1; i < n; i++) {
            i64 cur = 2 * sum[i][m] - sum[n][m];
            if (m == 1 && i != 1) {
                ans = ans || cur == grid[i - 1][0] || cur == grid[0][0] || cur == 0;
                continue;
            }
            for (int j = 1; j <= m; j++) {
                s.insert(grid[i - 1][j - 1]);
            }
            if (i == 1 && m != 1) {
                ans = ans ||cur == grid[i - 1][0] || cur == grid[i - 1][m - 1] || cur == 0;
                continue;
            }
            auto it = s.find(cur);
            if (it != s.end() && *it == cur || cur == 0) ans = true;
        }
        return ans;
    }

    void reverseMat(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            swap(mat[i], mat[j]);
        }
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        bool ans = false;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[j][i] = grid[i][j];
            }
        }
        ans = ans || calc(grid);
        ans = ans || calc(mat);
        reverseMat(grid);
        reverseMat(mat);
        ans = ans || calc(grid);
        ans = ans || calc(mat);
        return ans;
    }
};