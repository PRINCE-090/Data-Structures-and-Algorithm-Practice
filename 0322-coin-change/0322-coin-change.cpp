// memoization 
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

// tabulation 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int t = 0;t <= amount;t++){
            if(t % coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }
        for(int idx = 1;idx < n;idx++){
            for(int target = 0;target<=amount;target++){
             int notTake = 0 + dp[idx-1][target];
             int take  = 1e9;
              if(target >= coins[idx]){
               take = 1 + dp[idx][target-coins[idx]];
              }
                dp[idx][target] = min(take,notTake);
            }
        }
        if(dp[n-1][amount] >= 1e9) return -1;
        return dp[n-1][amount];
    }
};


// space optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int t = 0;t <= amount;t++){
            if(t % coins[0] == 0) prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }
        for(int idx = 1;idx < n;idx++){
            for(int target = 0;target<=amount;target++){
             int notTake = 0 + prev[target];
             int take  = 1e9;
              if(target >= coins[idx]){
               take = 1 + curr[target-coins[idx]];
              }
                curr[target] = min(take,notTake);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e9) return -1;
        return prev[amount];
    }
};
