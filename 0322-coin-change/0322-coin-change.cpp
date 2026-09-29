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