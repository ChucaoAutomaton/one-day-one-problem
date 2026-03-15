class Fancy {
public:
    static const int mod = 1e9 + 7;
    static const int N = 1e5 + 10;
    vector<int> add, mul, v;
    int n, sz, cur;
    Fancy() {
        sz = 2 * N + 5;
        n = 1e5;
        cur = 0;
        add.assign(sz, 0);
        mul.assign(sz, 1);
    }

    void pushDown(int u) {
        if (mul[u] != 1) {
            int c = mul[u];
            mul[u] = 1;
            mul[u << 1] = 1ll * mul[u << 1] * c % mod;
            mul[u << 1 | 1] = 1ll * mul[u << 1 | 1] * c % mod;
            add[u << 1] = 1ll * add[u << 1] * c % mod;
            add[u << 1 | 1] = 1ll * add[u << 1 | 1] * c % mod;
        }
        if (add[u]) {
            int c = add[u];
            add[u] = 0;
            add[u << 1] = (add[u << 1] + c) % mod;
            add[u << 1 | 1] = (add[u << 1 | 1] + c) %mod;
        }
    }

    array<int, 2> querry(int u, int l, int r, int x) {
        if (l == r) return {add[u], mul[u]};
        int mid = l + r >> 1;
        pushDown(u);
        if (x <= mid) return querry(u << 1, l, mid, x);
        else return querry(u << 1 | 1, mid + 1, r, x);
    }

    void pushTag(int u, int l, int r, int ql, int qr, int a, int b) {
        if (ql > qr) return ;
        if (l >= ql && r <= qr) {
            mul[u] = 1ll * mul[u] * b % mod;
            add[u] = (1ll * add[u] * b + a) % mod;
            return ;
        }
        int mid = l + r >> 1;
        pushDown(u);
        if (ql <= mid) pushTag(u << 1, l, mid, ql, qr, a, b);
        if (qr > mid) pushTag(u << 1 | 1, mid + 1, r, ql, qr, a, b);
    }
    
    void append(int val) {
        v.push_back(val);
        cur++;
    }
    
    void addAll(int inc) {
        pushTag(1, 1, n, 1, cur, inc, 1);
    }
    
    void multAll(int m) {
        pushTag(1, 1, n, 1, cur, 0, m);
    }
    
    int getIndex(int idx) {
        if (idx >= cur) return -1;
        auto [a, b] = querry(1, 1, n, idx + 1);
        return ((1ll * b * v[idx] % mod + a) % mod + mod) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */