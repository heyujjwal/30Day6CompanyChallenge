class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1),res;
        vector<int> prev(n, -1);
        int max_ind = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[max_ind] < dp[i])
                max_ind = i;
        }
        int k = max_ind; 
        while (k >= 0) 
        { 
            res.push_back(nums[k]);
            k=prev[k];
        } 
        return res;
    }
};
