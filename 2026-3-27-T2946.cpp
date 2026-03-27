class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        bool ans = true;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int dir = i & 1 ? 1 : -1;
            for (int j = 0; j < m; j++) {
                int l = ((j + dir * k) % m + m) % m;
                if (mat[i][j] != mat[i][l]) {
                    ans = false;
                }
            }
        }
        return ans;
    }
};