class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum = 0, F0 = 0, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums [i];
            F0 += i * nums [i];
        }
        int dp [n];
        dp [0] = F0;
        mx = dp [0];
        for (int i = 1; i < n; i++) {
            dp [i] = dp [i-1] + sum - n * nums [n - i];
            mx = max(mx, dp [i]);
        }
        return mx;

    }
};
