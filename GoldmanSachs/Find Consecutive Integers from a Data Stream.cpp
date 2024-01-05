class DataStream {
public:
   vector<pair<int,int>> v;
    int val,kval;
    DataStream(int value, int k) {
        val=value;
        kval=k;
    }
    
    bool consec(int num) {
        
        if(v.size()==0){
            if(num==val)
            {
                v.push_back({num,1});
                if(kval==1)return true;
                return false;
            }
            else{
                v.push_back({num,0});
                return false;
            }
                
        }
        
        if(num==val){
            if(v[v.size()-1].first==val){
                v.push_back({num, v[v.size()-1].second+1});
                if(v[v.size()-1].second>=kval)return true;
                
                return false;
            }
            else{
                v.push_back({num, 1});
                if(kval==1)return true;
                return false;
            }
        }
        else{
            v.push_back({num, 0});
            return false;
        }
        
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
