// Memoization
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

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int ind = n-1;ind>=0;ind--){
             for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<3;cap++){
                    long maxprofit = 0;
                    if(buy){
                      maxprofit = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                    }
                    else {
                      maxprofit = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = maxprofit;
                }
            }
        }
       return dp[0][1][2];
    }
};


// Space optimization 2 
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


// variable space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long long buy1 = INT_MAX, buy2 = INT_MAX,profit = 0, profit2 = 0;
        for(int i  = 0;i<n;i++){
            buy1 = min(buy1,(long long)prices[i]);
            profit = max(profit,prices[i] - buy1);
            buy2 = min(buy2,(long long)prices[i] - profit);
            profit2 = max(profit2,prices[i] - buy2);
        }
        return profit2;
    }
};
