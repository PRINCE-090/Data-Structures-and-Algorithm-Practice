class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));
        for(int i = 0;i<=amount;i++){
            if(i%coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        for(int idx = 1;idx<n;idx++){
            for(int target = 0;target<=amount;target++){
           unsigned long long notTake = dp[idx-1][target];
           unsigned long long take = 0;
            if(coins[idx] <= target){
            take = dp[idx][target-coins[idx]];
            }
            dp[idx][target] = notTake+take;
            } 
        }
        return (int) dp[n-1][amount];
    }
};