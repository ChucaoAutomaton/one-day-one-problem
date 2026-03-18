class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> s(n + 1, vector<int> (m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] + grid[i - 1][j - 1] - s[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            ans += upper_bound(s[i].begin(), s[i].end(), k) - s[i].begin() - 1;
        }
        return ans;
    }
};