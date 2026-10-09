class Solution {
public:
    int findprofit(int ind,int buy,int n,vector<int>&prices,vector<vector<int>>&dp){
      if(ind >= n) return 0;
      if(dp[ind][buy] != -1) return dp[ind][buy];
      if(buy){
        return dp[ind][buy] = max(-prices[ind] + findprofit(ind+1,0,n,prices,dp), findprofit(ind+1,1,n,prices,dp));
      }
        return dp[ind][buy] = max(prices[ind]+findprofit(ind+2,1,n,prices,dp), findprofit(ind+1,0,n,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        return findprofit(0,1,n,prices,dp);
    }
};