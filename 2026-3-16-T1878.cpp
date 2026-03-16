class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), l = max(n, m);
        vector<vector<int>> sum1(n + m, vector<int> (l + 2, 0)), sum2(n + m, vector<int> (l + 2, 0));
        for (int s = 0; s < n + m; s++) {
            for (int i = 0; i < n; i++) {
                if (s - i >= 0) {
                    int j = s - i;
                    if (j < m) {
                        int cur = min(i + 1, m - j);
                        sum1[s][cur] = sum1[s][cur - 1] + grid[i][j];
                    }
                }
                if (i + m - s >= 0) {
                    //s = i - j + m;
                    int j = i + m - s;
                    if (j < m) {
                        int cur = min(i + 1, j + 1);
                        sum2[s][cur] = sum2[s][cur - 1] + grid[i][j];
                    }
                }
            }
        }

        vector<int> q;

        auto check = [&] (int x, int y) -> bool {
            if (x <= 0 || x > n || y <= 0 || y > m) return true;
            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 1; d <= min(n, m); d++) {
                    int x1 = i + 1, y1 = j + 1;
                    int x2 = x1 + d, y2 = y1 - d;
                    int x3 = x1 + 2 * d, y3 = y1;
                    int x4 = x1 + d, y4 = y1 + d;
                    int s1 = x1 + y1 - 2;
                    int s2 = x2 - y2 + m;
                    int s3 = x3 + y3 - 2;
                    int s4 = x4 - y4 + m;
                    if (check(x1, y1) || check(x2, y2) || check(x3, y3) || check(x4, y4)) continue;
                    int res =   -grid[x1 - 1][y1 - 1] - grid[x2 - 1][y2 - 1]
                                -grid[x3 - 1][y3 - 1] - grid[x4 - 1][y4 - 1];
                    res += sum1[s1][min(x1, m - y1 + 1) + d] - sum1[s1][min(x1, m - y1 + 1) - 1];
                    res += sum1[s3][min(x4, m - y4 + 1) + d] - sum1[s3][min(x4, m - y4 + 1) - 1];
                    res += sum2[s2][min(x2, y2) + d] - sum2[s2][min(x2, y2) - 1];
                    res += sum2[s4][min(x1, y1) + d] - sum2[s4][min(x1, y1) - 1];
                    q.push_back(res);
                }
                q.push_back(grid[i][j]);
            }
        }
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        reverse(q.begin(), q.end());
        while (q.size() > 3) q.pop_back();
        return q;
    }
};