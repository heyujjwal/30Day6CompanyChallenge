class Solution {
public:
    int MOD = 1e9 + 7 ;
    int dp[3001][1001] ;
    
    int solve(int pos , int k , int end){
        if(!k) return pos == end ;
        if(dp[pos + 1000][k] != -1) return dp[pos + 1000][k] ;
        
        int ans = 0 ;
        ans += solve(pos + 1, k - 1 , end) , ans %= MOD ;
        ans += solve(pos - 1, k - 1 , end) , ans %= MOD ;
        
        return dp[pos + 1000][k] = ans ;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp)) ;
        
        return solve(startPos , k , endPos) ;
    }
};
