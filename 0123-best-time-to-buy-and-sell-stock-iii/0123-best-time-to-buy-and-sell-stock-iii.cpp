class Solution {
public:
    int find(int ind,int trans,int n,vector<int>&prices,vector<vector<int>>&dp){
        if(ind == n || trans == 4) return 0;
         int maxprofit = 0;
         if(dp[ind][trans] != -1) return dp[ind][trans];
        if(trans%2 == 0){
         maxprofit = max(-prices[ind] + find(ind+1,trans+1,n,prices,dp), find(ind+1,trans,n,prices,dp));
        }
        else{
            maxprofit = max(prices[ind] + find(ind+1,trans+1,n,prices,dp), find(ind+1,trans,n,prices,dp));
        }
        return dp[ind][trans] = maxprofit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return find(0,0,n,prices,dp);
    }
};