class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2 * k+1,0));
        
        for(int ind = n-1;ind>=0;ind--){
            for(int cap = 2*k-1;cap>=0;cap--){
                long maxprofit = 0;
                if(cap % 2 == 0){
                   maxprofit = max(-prices[ind] + dp[ind+1][cap+1] ,dp[ind+1][cap]);
                }
                else{
                  maxprofit = max(prices[ind] + dp[ind+1][cap+1], dp[ind+1][cap]);
                }
               dp[ind][cap] = maxprofit;
            }
        }
        return dp[0][0];
    }
};