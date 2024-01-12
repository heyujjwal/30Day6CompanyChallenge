class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
         vector<int> ans;
         vector<int> result;
        int n=nums.size();
        sort(temp.begin(),temp.end());
       
        for(int i=n-k;i<n;i++){
            ans.push_back(temp[i]);
        }
        for(auto it:nums)
        {
            auto idx = find(ans.begin(),ans.end(),it);
            if(idx!=ans.end())
            {
                result.push_back(it);
                ans.erase(ans.begin()+(idx-ans.begin()));
            }
        }
        return result;
    }
};
