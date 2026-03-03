class Solution {
public:
    char findKthBit(int n, int k) {
        auto dfs = [&] (auto self, int n, int k) -> int {
            if (n == 1) return 0;
            int mid = n / 2 + 1;
            if (k == mid) return 1;
            else if (k < mid) return self(self, n / 2, k);
            else return 1 ^ self(self, n / 2, n - k + 1);
        };
        return '0' + dfs(dfs, (1 << n) - 1, k);
    }
};