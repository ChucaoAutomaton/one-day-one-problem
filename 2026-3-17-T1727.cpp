class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> d(n + 1, vector<int> (m + 1, 0));
        for (int i = n; i; i--) {
            for (int j = 1; j <= m; j++) {
                if (i == n) {
                    d[i][j] = (matrix[i - 1][j - 1] == 1);
                }
                else {
                    if (matrix[i - 1][j - 1]) {
                        d[i][j] = d[i + 1][j] + 1;
                    }
                    else {
                        d[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            vector<int> cur;
            for (int j = 1; j <= m; j++) {
                cur.push_back(d[i][j]);
            }
            sort(cur.begin(), cur.end());
            for (int j = 1; j <= m; j++) {
                ans = max(ans, j * cur[m - j]);
            }
        }
        return ans;
    }
};