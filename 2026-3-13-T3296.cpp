struct Node {
    long long sum, s;
    int v;
    bool operator < (const Node &t) const {
        return s + sum > t.s + t.sum;
    }
};
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0;
        priority_queue<Node> pq;
        for (auto v : workerTimes) {
            pq.push((Node){0, v, v});
        }
        while (mountainHeight) {
            auto [sum, s, v] = pq.top();
            pq.pop();
            mountainHeight--;
            sum += s;
            ans = max(ans, sum);
            s += v;
            pq.push((Node){sum, s, v});
        }
        return ans;
    }
};