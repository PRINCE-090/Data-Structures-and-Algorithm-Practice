class Solution {
public:
    int mincost(int ind , vector<int>&arr,vector<int>&dp){
        int minicost = INT_MAX;
        if(ind == arr.size()-1) return arr[ind];
        if(ind >= arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int onestep = arr[ind] + mincost(ind+1,arr,dp);
        int twostep = arr[ind] + mincost(ind+2,arr,dp);
        minicost = min(minicost , min(onestep,twostep));
        return dp[ind] = minicost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(mincost(0,cost,dp),mincost(1,cost,dp));
    }
};