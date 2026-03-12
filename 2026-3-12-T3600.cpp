#pragma optimize(1, 2, 3, "Ofast")
struct DSU {
    vector<int> p, sz;
    int mn;
    DSU(int n) {
        p.assign(n, 0);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        mn = 2e5 + 10;
    }
    DSU(DSU& v) {
        p = v.p;
        sz = v.sz;
        mn = v.mn;
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    bool merge(int u, int v, int k) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] > sz[v]) swap(u, v);
        p[u] = p[v];
        sz[v] += sz[u];
        mn = min(k, mn);
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int l = 0, r = 2e5+10;
        DSU dsu_cp(n);
        sort(edges.begin(), edges.end(), [](vector<int>& e1, vector<int>& e2) -> bool {
            return e1[2] > e2[2];
        });

        for (auto& e: edges) {
            auto [u, v, s, must] = tuple{e[0], e[1], e[2], e[3]};
            if (must == 1) {
                bool ok = dsu_cp.merge(u, v, s);
                if (!ok) return -1;
            }
        }

        auto check = [&] (int mid) -> bool {
            DSU dsu(dsu_cp);
            if (dsu.mn < mid) return false;
            int K = k;
            for (auto& e: edges) {
                auto [u, v, s, must] = tuple{e[0], e[1], e[2], e[3]};
                u = dsu.find(u), v = dsu.find(v);
                if (must || u == v) continue;
                if (s >= mid) {
                    dsu.merge(u, v, s);
                }
                else if (K && 2 * s >= mid) {
                    K--;
                    dsu.merge(u, v, 2 * s);
                }
            }
            int u = dsu.find(0);
            return dsu.sz[u] == n;
        };

        while (l != r) {
            int mid = l + r >> 1;
            if (check(mid)) l = mid + 1;
            else r = mid;
        }

        return l - 1;
    }
};