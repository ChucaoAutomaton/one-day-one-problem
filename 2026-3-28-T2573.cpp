class Solution {
    struct DSU {
        int n;
        vector<int> p, sz;
        DSU(int N) {
            int n = N;
            p.assign(n, 0);
            sz.assign(n, 1);
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }

        int find(int x) {
            return x == p[x] ? x : p[x] = find(p[x]);
        }

        bool merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;
            if (sz[x] > sz[y]) swap(x, y);
            p[x] = y;
            sz[y] += sz[x];
            return true;
        }
    };
    struct HASH {
        int n;
        const int mod = 1e9 + 7, P = 13331;
        vector<int> h, p;
        HASH(string s) {
            n = s.size();
            h.assign(n + 1, 0);
            p.assign(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                h[i] = (1ll * h[i - 1] * P + s[i - 1]) % mod;
                p[i] = 1ll * P * p[i - 1] % mod;
            }
        }

        int getValue(int l, int r) {
            return ((h[r] - 1ll * h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
        }

        int getLCP(int i, int j) {
            i++, j++;
            int l = 1, r = n + 1;
            
            auto check = [&] (int mid) -> bool {
                if (i + mid - 1 > n || j + mid - 1 > n) return false;
                return getValue(i, i + mid - 1) == getValue(j, j + mid - 1);
            };

            while (l != r) {
                int mid = l + r >> 1;
                if (check(mid)) l = mid + 1;
                else r = mid;
            }
            return l - 1;
        }
    };
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        DSU dsu(n);
        set<int> pos;
        for (int i = 0; i < n; i++) {
            pos.insert(i);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int L = lcp[i][j];
                auto it = pos.lower_bound(i);
                while (it != pos.end() && (*it) < i + L) {
                    int k = (*it);
                    dsu.merge(k, j + k - i);
                    it = next(it);
                    pos.erase(prev(it));
                }
            }
        }
        
        string s = "";
        for (int i = 0, c = 'a'; i < n; i++) {
            int p = dsu.find(i);
            if (i == p) {
                if (c > 'z') return "";
                s.push_back(c);
                c++;
            }
            else {
                s.push_back(s[p]);
            }
        }

        HASH t(s);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (t.getLCP(i, j) != lcp[i][j] || lcp[i][j] != lcp[j][i]) {
                    return "";
                }
            }
        }
        return s;
    }
};