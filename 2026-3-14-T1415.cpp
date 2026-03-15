class Solution {
public:
    string getHappyString(int n, int k) {
        string s = "";
        if (k <= (1 << (n - 1))) s += "a";
        else if (k <= 2 * (1 << (n - 1))) s += "b", k -= (1 << (n - 1));
        else if (k <= 3 * (1 << (n - 1))) s += "c", k -= 2 * (1 << (n - 1));
        else return "";
        int N = n;
        n--;
        for (int i = 1; i < N; i++, n--) {
            if (k <= (1 << (n - 1))) {
                s.push_back(s[i - 1] == 'a' ? 'b' : 'a');
            }
            else {
                k -= (1 << (n - 1));
                s.push_back(s[i - 1] == 'c' ? 'b' : 'c');
            }
        }
        return s;
    }
};