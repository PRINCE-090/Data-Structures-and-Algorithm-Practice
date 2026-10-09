class Solution {
public:
    int find(int ind,int cap,int n,int k,vector<int>&prices,vector<vector<int>>&dp){
        if(ind == n || cap == 2*k ) return 0;
        long maxprofit = 0;
        if(dp[ind][cap] != -1) return dp[ind][cap];
        if(cap % 2 == 0){
           maxprofit = max(-prices[ind] + find(ind+1,cap+1,n,k,prices,dp) , find(ind+1,cap,n,k,prices,dp));
        }
        else{
            maxprofit = max(prices[ind] + find(ind+1,cap+1,n,k,prices,dp), find(ind+1,cap,n,k,prices,dp));
        }
        return dp[ind][cap] = maxprofit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2 * k+1,-1));
        return find(0,0,n,k,prices,dp);
    }
};