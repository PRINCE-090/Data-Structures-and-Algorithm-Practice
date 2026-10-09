class Solution {
public:
    int findprofit(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(cap == 0) return 0;
        if(ind == n) return 0;
        long maxprofit = 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy){
         maxprofit = max(-prices[ind] + findprofit(ind+1,0,cap,prices,dp), findprofit(ind+1,1,cap,prices,dp));
        }
        else {
            maxprofit = max(prices[ind] + findprofit(ind+1,1,cap-1,prices,dp), findprofit(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap] = maxprofit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return findprofit(0,1,2,prices,dp);
    }
};