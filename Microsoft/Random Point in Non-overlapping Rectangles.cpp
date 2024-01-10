class Solution {
    vector<long long> cost;
    vector<vector<int>> r;
    mt19937_64 mt;
public:
    Solution(vector<vector<int>>& rects): mt(123) {
        r = rects;

        for (auto &u: r)
        {
            long long x = u[2] - u[0] + 1;
            long long y = u[3] - u[1] + 1;
            cost.push_back((cost.empty() ? 0 : cost.back()) + x * y);
        }
    }
    
    vector<int> pick() {
        auto g = mt() % cost.back();
        auto idx = upper_bound(cost.begin(), cost.end(), g) - cost.begin();
        if (idx > 0)
            g -= cost[idx - 1];
        return vector<int>{
            (int)(r[idx][0] + (g / (r[idx][3] - r[idx][1] + 1))),

            (int)(r[idx][1] + (g % (r[idx][3] - r[idx][1] + 1)))
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
