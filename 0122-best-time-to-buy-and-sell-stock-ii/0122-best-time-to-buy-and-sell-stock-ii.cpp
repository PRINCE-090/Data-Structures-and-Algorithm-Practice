// Memoization
class Solution {
public:
    int findprofit(int ind,int buy,int n,vector<int>&prices,vector<vector<int>>&dp){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + findprofit(ind+1,0,n,prices,dp),0+findprofit(ind+1,1,n,prices,dp));
        }
        else{
            profit = max(prices[ind]+findprofit(ind+1,1,n,prices,dp),0+findprofit(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return findprofit(0,1,n,prices,dp);

    }
};

// Ṭabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                long profit = 0;
               if(buy){
               profit = max(-prices[ind] + dp[ind+1][0],0+dp[ind+1][1]);
               }
             else{
              profit = max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
              }
             dp[ind][buy] = profit;
            }
        }
       return dp[0][1];
    }
};


// variable space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadbuy,aheadnotbuy,currbuy,currnotbuy;
        aheadbuy = 0, aheadnotbuy = 0;
        for(int ind = n-1;ind>=0;ind--){
            currnotbuy = max(prices[ind] + aheadbuy , 0 + aheadnotbuy);

            currbuy = max(-prices[ind] + aheadnotbuy , 0 + aheadbuy);

            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
       return aheadbuy;
    }
};
