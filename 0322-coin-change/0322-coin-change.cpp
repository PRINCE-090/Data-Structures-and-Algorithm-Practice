class Solution {
public:
    int mincoins(int idx,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(idx == 0){
            if(target % coins[idx] == 0) return target/coins[idx];
            return 1e9;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int notTake = 0 + mincoins(idx-1,target,coins,dp);
        int take  = 1e9;
        if(target >= coins[idx]){
            take = 1 + mincoins(idx,target-coins[idx],coins,dp);
        }
        return dp[idx][target] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = mincoins(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};