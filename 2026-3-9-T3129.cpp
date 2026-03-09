class Solution {
public:
    const static int mod = 1e9 + 7;
    const static int MAXN = 405;
    int dp[MAXN][MAXN][2], s[MAXN][MAXN][2];
    int numberOfStableArrays(int zero, int one, int limit) {
        int n = zero + one;
        memset(dp, 0, n * n * 2 * sizeof(int));
        memset(dp, 0, n * n * 2 * sizeof(int));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        for (int i = 0; i <= n; i++) {
            s[i][0][0] = 1;
            s[i][0][1] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int c = 1; c <= i; c++) {
                int o = max(0, i - limit);
                if (o) {
                    dp[i][c][0] = s[i - 1][i - c][1] - s[o - 1][i - c][1];
                    dp[i][c][1] = s[i - 1][i - c][0] - s[o - 1][i - c][0];
                }
                else {
                    dp[i][c][0] += s[i - 1][i - c][0];
                    dp[i][c][1] += s[i - 1][i - c][1];
                }
                dp[i][c][0] %= mod;
                dp[i][c][1] %= mod;
                s[i][c][0] = (s[i - 1][c][0] + dp[i][c][0]) % mod;
                s[i][c][1] = (s[i - 1][c][1] + dp[i][c][1]) % mod;
            }
        }
        return ((dp[n][zero][0] + dp[n][one][1]) % mod + mod) % mod;
    }
};