class Solution {
public:
    int mod = 1e9 + 7;
    int countHousePlacements(int n) {
        vector<long long>dp(n+1,0);
        if(n == 1)return 4;
        if(n == 2) return 9;
        dp[1] = 2;
        dp[2] = 3;
        for(int i = 3;i<=n;i++){
            int placehouse = dp[i-2];
            int notplace = dp[i-1];
            dp[i] = (placehouse + notplace) % mod;
        }
        long long ans = (dp[n] * dp[n]) %mod; 
        return ans%mod;
    }
};