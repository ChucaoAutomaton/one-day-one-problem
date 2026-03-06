class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0, flag = 0;
        for (auto& c : s) {
            if (c == '0') flag = 0;
            else if (flag == 0) cnt++, flag = 1;
        }
        return cnt <= 1;
    }
};