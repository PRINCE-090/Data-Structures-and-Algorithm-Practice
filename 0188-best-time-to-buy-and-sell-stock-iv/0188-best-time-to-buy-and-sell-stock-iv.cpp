// Memoization
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


// Tabulation
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


// Space optimation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
       vector<int>after(2*k+1,0);
       vector<int>curr(2*k+1,0); 
        for(int ind = n-1;ind>=0;ind--){
            for(int cap = 2*k-1;cap>=0;cap--){
                long maxprofit = 0;
                if(cap % 2 == 0){
                   maxprofit = max(-prices[ind] + after[cap+1] ,after[cap]);
                }
                else{
                  maxprofit = max(prices[ind] + after[cap+1], after[cap]);
                }
               curr[cap] = maxprofit;
            }
            after = curr;
        }
        return after[0];
    }
};
