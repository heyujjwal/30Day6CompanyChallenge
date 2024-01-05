class Solution {
public:
    using ll = long long;
    ll mod = 1000000007;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll ans = 0;
        vector<ll> active(n+1);
        vector<ll> infected(n+1);
        infected[1] = 1;
        for(ll i = 1 ; i<=n; i++){
            active[i]+=active[i-1]%mod;
            active[i]%=mod;
            if(active[i]>0){
                infected[i]+=active[i]%mod;
                infected[i]%=mod;
            }
            if(i+delay<=n){
                active[i+delay]+=infected[i]%mod;
                active[i+delay]%=mod;
            }
            if(i+forget<=n){
                active[i+forget]= (active[i+forget]%mod + mod - infected[i])%mod;
            }
        }
        for(int i = n; i>n-forget; i--){
            ans+= infected[i]%mod;
            ans%=mod;
        }
        return (int)(ans%mod);
    }
};
