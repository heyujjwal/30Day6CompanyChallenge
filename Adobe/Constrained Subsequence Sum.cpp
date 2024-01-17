class Solution {
public:
     int constrainedSubsetSum(vector<int>& nums, int k) 
     {
        int n = nums.size();
        vector<int> mapp(n, 0);
        priority_queue< pair<int, int>, vector< pair<int, int>>> pq;

        mapp = nums;
        pq.push({mapp[0], 0});
        int maxi = mapp[0];
        
        for(int i = 1; i<n; i++) 
        {  
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            
            mapp[i] = max(mapp[i], nums[i] + pq.top().first);
            pq.push({mapp[i], i});
            
            maxi = max(maxi, mapp[i]);
        }
        
        return maxi;
    }
};
