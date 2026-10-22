class Solution {
public:
    int mincost(int ind,int n , vector<int>&arr,vector<int>&dp){
        if(ind > n) return 1e8;
        if(ind ==n)return 0;
        if(dp[ind] != -1) return dp[ind];
        int oneStep = (arr[ind] + 1) + mincost(ind+1,n,arr,dp);
        int twoStep = ind + 2 <= n ? arr[ind+1] + 4 + mincost(ind+2,n,arr,dp) : 1e9;
        int threeStep = ind +3 <= n ? arr[ind+2] + 9 + mincost(ind + 3,n,arr,dp) : 1e9;

        return dp[ind] = min({oneStep,twoStep,threeStep}); 
    }
    int climbStairs(int n, vector<int>& arr) {
        vector<int>dp(n+4,0);
        for(int ind = n-1;ind>=0;ind--){
         int oneStep = (arr[ind] + 1) + mincost(ind+1,n,arr,dp);
         int twoStep = ind + 2 <= n ? arr[ind+1] + 4 + mincost(ind+2,n,arr,dp) : 1e9;
         int threeStep = ind +3 <= n ? arr[ind+2] + 9 + mincost(ind + 3,n,arr,dp) : 1e9;
 
           dp[ind] = min({oneStep,twoStep,threeStep});
        }
        return dp[0];
    }
};