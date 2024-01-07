class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        if (s.size()<10)return {};
        string t;
        for (int i=0; i<10; i++)t+=s[i];
        mp[t]++;
        for (int i=10; i<s.size(); i++){
            t.erase(t.begin());
            t.push_back(s[i]);
            mp[t]++;
        }
        vector<string> ans;
        for (auto vl: mp){
            if (vl.second>1)ans.push_back(vl.first);
        }
        return ans;
    }
};
