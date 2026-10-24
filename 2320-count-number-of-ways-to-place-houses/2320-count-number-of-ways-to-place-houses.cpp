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