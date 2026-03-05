class Solution {
public:
    int minOperations(string s) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i & 1) {
                cnt0 += s[i] == '0';
                cnt1 += s[i] == '1';
            }
            else {
                cnt0 += s[i] == '1';
                cnt1 += s[i] == '0';
            }
        }
        return min(s.size() - cnt0, s.size() - cnt1);
    }
};