// Memoization
class Solution {
public:
    int mod = 1e9 + 7;
    int totalways(int n,vector<int>&dp){
        if(n == 1) return 2;
        if(n == 2) return 3;
        if(dp[n] != -1) return dp[n];
        int placeHouse = totalways(n-2,dp);
        int notPlace = totalways(n-1,dp);
        return dp[n] = (placeHouse + notPlace) % mod;
    }
    int countHousePlacements(int n) {
        vector<int>dp(n+1,-1);
        long long ways =  totalways(n,dp);
        return (ways * ways)%mod;
    }
};


// Tabulation
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


// space optimization
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
