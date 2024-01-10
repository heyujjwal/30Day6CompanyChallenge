class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        int mat[27][27];
        memset(mat, -1, sizeof(mat));
        for(int i = 0; i<m; i++) {
            if(mat[original[i]-'a'][changed[i]-'a'] == -1) {
                mat[original[i]-'a'][changed[i]-'a'] = cost[i];
            }
            else mat[original[i]-'a'][changed[i]-'a'] = min(mat[original[i]-'a'][changed[i]-'a'], cost[i]);
        }
        for(int x = 0; x<26; x++) {
            for(int i = 0; i<26; i++) {
                for(int j = 0; j<26; j++) {
                    if(i == j) mat[i][j] = 0;
                    else if(mat[i][x]!=-1 && mat[x][j]!=-1) {
                        if(mat[i][j] == -1) mat[i][j] = mat[i][x]+mat[x][j];
                        else mat[i][j] = min(mat[i][j], mat[i][x]+mat[x][j]);    
                    }                
                }
            }
        }
        
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            if(mat[source[i]-'a'][target[i]-'a'] == -1) return -1;
            ans += mat[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
