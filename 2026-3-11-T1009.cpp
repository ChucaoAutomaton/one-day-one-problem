class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int m = 32 - __builtin_clz(n);
        return n ^ ((1 << m) - 1);
    }
};