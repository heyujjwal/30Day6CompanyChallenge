class Solution {
public:
    string getHint(string secret, string guess) {
        int b=0, c=0, n=secret.size(); 
        
        unordered_map<int,int> sf, gf;
        for(int i =0;i<n;i++)
        if(secret[i]==guess[i]) 
        b++;
        else sf[secret[i]]++,gf[guess[i]]++;
        for(auto it :sf)
        if( gf[it.first]) 
        c+=min(gf[it.first],sf[it.first]);
        return to_string(b) + "A" + to_string(c) + "B";
    }
};
