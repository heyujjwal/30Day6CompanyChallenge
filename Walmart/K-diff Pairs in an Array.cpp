class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {

                if (nums[i] - nums[j] == k && i != j) {
                    ans.insert({nums[i], nums[j]});
                }
            }
        }
        return ans.size();
    }
};
