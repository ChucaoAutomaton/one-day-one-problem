class Solution {
public:
    int minFlips(string s) {
        auto calc = [&] (string& s, int l, int r) -> pair<int, int> {
            int cnt0 = 0, cnt1 = 0;
            for (int i = l; i < r; i++) {
                if ((i - l) & 1) {
                    cnt0 += s[i] == '0';
                    cnt1 += s[i] == '1';
                }
                else {
                    cnt0 += s[i] == '1';
                    cnt1 += s[i] == '0';
                }
            }
            return {cnt0, cnt1};
        };

        int n = s.size();
        s = s + s;
        vector<vector<int>> dp(2, vector<int> (n));
        auto [cnt0, cnt1] = calc(s, 0, n);
        dp[0][0] = cnt0, dp[1][0] = cnt1;

        int ans = min(dp[0][0], dp[1][0]);
        for (int i = 1; i < n; i++) {
            int h = s[i - 1];
            dp[0][i] = dp[1][i - 1] - (h == '0') + (n % 2 == 0 ? (h == '0') : (h == '1'));
            dp[1][i] = dp[0][i - 1] - (h == '1') + (n % 2 == 0 ? (h == '1') : (h == '0'));
            ans = min({ans, dp[0][i] + i, dp[1][i] + i});
        }
        for (int i = 1; i < n; i++) {
            ans = min({ans, dp[0][i], dp[1][i]});
        }
        return ans;
    }
};