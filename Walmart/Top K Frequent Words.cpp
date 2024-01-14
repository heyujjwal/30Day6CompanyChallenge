class Solution {
public:
    string solve(map<string, int>&m){
        int maxi = INT_MIN;
        string ans;
        for(auto x:m){
           if(x.second>maxi){
               maxi = x.second;
               ans = x.first;
           }
        }
        m.erase(ans);
        return ans;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string, int>m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        while(k--){
            ans.push_back(solve(m));
        }
        
        return ans;
    }
};
