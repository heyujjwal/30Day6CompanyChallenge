class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//step1
        vector<pair<int,int>> coordinate;
        for(auto building: buildings){
            coordinate.push_back({building[0],-building[2]});
            coordinate.push_back({building[1],building[2]});
        }
		//step2
        sort(coordinate.begin(), coordinate.end());
        
		//step3
        multiset<int,greater<int>> pq = {0};
        vector<vector<int>> result;
        int prev = 0;
        for(auto p: coordinate){
            if (p.second<0) pq.insert(-p.second);
            else pq.erase(pq.find(p.second));
            int cur=*pq.begin();
            if (prev!=cur) {
                result.push_back({p.first,cur});
                prev=cur;
            }
        }
        return result;
    }
};
