class Solution {
private:
    int MOD = 1e9 + 7;

    // prev represents the index of the previous number (N states)
    // visited is a bitmask of all the visited numbers (2^N states)
    // (N states) * (2^N states) => O(N * 2^N)
    // the helper itself is O(N) due to the for loop
    // total time complexity: O(N^2 * 2^N)
    int solve(vector<int>& nums, int prev, int visited, vector<vector<int>>& dp) {
        int ans = 0;
        int n = nums.size() - 1;

        // base case:
        // if all numbers are used, there is only 1 possible permutation of the remaining 0 numbers
        if (visited == ((1 << n) - 1)) return 1;
        // if this has been visited before, just return the memo
        if (dp[prev][visited] != -1) return dp[prev][visited];

        // iterate through all numbers
        // O(N)
        for (int i = 0; i < n; i++) {
            // if is divisible by the previous number or can divide the previous number
            // and isn't visited yet
            if ((nums[prev] % nums[i] == 0 || nums[i] % nums[prev] == 0) && !(visited & (1 << i))) {
                // recurse with the new number and updated mask
                ans += solve(nums, i, visited | (1 << i), dp);
                ans %= MOD;
            }
        }

        return dp[prev][visited] = ans;
    }
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        // placeholder number that can divide any number as the "first" number
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int> (1 << n, -1));
        return solve(nums, n, 0, dp);
    }
};
