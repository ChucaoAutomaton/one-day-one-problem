class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> arr;
        
        auto stringToInt = [&] (string& s) -> int {
            int res = 0;
            for (auto& c : s) {
                res = res * 2 + c - '0';
            }
            return res;
        };
        
        auto intToString = [&] (int x) -> string {
            string s = "";
            while (x) {
                s += '0' + (x & 1);
                x >>= 1;
            }
            while (s.size() < n) {
                s.push_back('0');
            }
            reverse(s.begin(), s.end());
            return s;
        };

        for (auto& s : nums) {
            arr.push_back(stringToInt(s));
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            if (arr[i] != i) {
                return intToString(i);
            }
        }
        return intToString(n);
    }
};