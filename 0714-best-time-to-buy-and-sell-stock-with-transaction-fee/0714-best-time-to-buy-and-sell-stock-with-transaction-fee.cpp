// Memoization
class Solution {
public:
   int find(int ind,int buy,int n,vector<int>&prices,vector<vector<int>>&dp,int fee){
    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy){
     return dp[ind][buy] = max(-prices[ind]+find(ind+1,0,n,prices,dp,fee),find(ind+1,1,n,prices,dp,fee));
    }
    return dp[ind][buy] = max(prices[ind] - fee + find(ind+1,1,n,prices,dp,fee),find(ind+1,0,n,prices,dp,fee));
   }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,1,n,prices,dp,fee);
    }
};


// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind = n-1;ind>=0;ind--){
            dp[ind][1] = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            dp[ind][0] = max(prices[ind] - fee + dp[ind+1][1],dp[ind+1][0]);
        }
        return dp[0][1];
    }
};

// Space optimization -2
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int currbuy= 0,currnotbuy =0,aheadbuy = 0,aheadnotbuy = 0;
        for(int ind = n-1;ind>=0;ind--){
            currbuy = max(-prices[ind]+aheadnotbuy,aheadbuy);
            currnotbuy = max(prices[ind] - fee + aheadbuy,aheadnotbuy);

            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};
