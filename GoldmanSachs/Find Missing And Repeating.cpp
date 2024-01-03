class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto it:arr){
            m[it]++;
        }
        for(auto it:m){
            int x=it.second;
            if(x!=1){
                int y=it.first;
                ans.push_back(y);
                break;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(m.find(i)==m.end()){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
