class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row_sum(n), col_sum(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row_sum[i] += mat[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                col_sum[i] += mat[j][i];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 && row_sum[i] == 1 && col_sum[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};