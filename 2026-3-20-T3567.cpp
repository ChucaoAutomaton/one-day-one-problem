class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        multiset<int> s, diff;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int> (m - k + 1));

        auto printSet = [&] (multiset<int>& s) -> void {
            for (auto it = s.begin(); it != s.end(); it++) {
                cout << (*it) << " ";
            }
            cout << "\n";
        };

        for (int i = 0; i < n - k + 1; i++) {
            s.clear(), diff.clear();
            for (int j = 0; j < m; j++) {
                for (int l = i; l < i + k; l++) {
                    if (j >= k) {
                        auto it = s.lower_bound(grid[l][j - k]);
                        if (it != s.begin()) {
                            auto p = diff.lower_bound((*it) - (*prev(it)));
                            diff.erase(p);
                        }
                        if (next(it) != s.end()) {
                            auto p = diff.lower_bound((*next(it)) - (*it));
                            diff.erase(p);
                            if (it != s.begin()) {
                                diff.insert((*next(it)) - (*prev(it)));
                            }
                        }
                        s.erase(it);
                    }
                    auto it = s.insert(grid[l][j]);
                    if (it != s.begin()) {
                        diff.insert((*it) - (*prev(it)));
                    }
                    if (next(it) != s.end()) {
                        diff.insert((*next(it)) - (*it));
                        if (it != s.begin()) {
                            auto p = diff.lower_bound((*next(it)) - (*prev(it)));
                            diff.erase(p);
                        }
                    }
                }
                if (j >= k - 1) {
                    auto it = diff.lower_bound(1);
                    ans[i][j - k + 1] = it == diff.end() ? 0 : *it;
                }
            }
        }
        return ans;
    }
};