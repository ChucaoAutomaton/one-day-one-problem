class Solution {
public:
    int r[4][2][2] = {
        {{0, 1}, {-1, 0}},
        {{-1, 0}, {0, -1}},
        {{0, -1}, {1, 0}},
        {{1, 0}, {0, 1}}
    };
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        auto map = [&](int x, int y, int k) -> array<int, 2> {
            x = 2 * x + 1 - n, y = 2 * y + 1 - n;
            int X = r[k][0][0] * x + r[k][0][1] * y;
            int Y = r[k][1][0] * x + r[k][1][1] * y;
            X = (X + n - 1) / 2, Y = (Y + n - 1) / 2;
            return {X, Y};
        };

        bool ans = false;
        for (int k = 0; k < 4; k++) {
            bool cur = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    auto [x, y] = map(i, j, k);
                    if (mat[i][j] != target[x][y]) cur = false;
                }
            }
            ans |= cur;
        }
        return ans;
    }
};