class Solution {
  public:
    int maxvalue(int idx,int n,vector<int>&price,vector<vector<int>>&dp){
        if(idx == 0){
            return n * price[0];
        }
        if(dp[idx][n] != -1) return dp[idx][n];
        int  notTake = 0 + maxvalue(idx-1,n,price,dp);
        int take = INT_MIN;
        int rodlength = idx+1;
        if(rodlength <= n){
            take = price[idx] + maxvalue(idx,n-rodlength,price,dp);
        }
        return dp[idx][n] = max(take,notTake);
        
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return maxvalue(n-1,n,price,dp);
        
    }
};