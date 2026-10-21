class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,1e8);
        dp[n-1] = cost[n-1];
        dp[n] = 0;
        int minicost = INT_MAX;
        for(int ind = n-2;ind>=0;ind--){
            int onestep = cost[ind] + dp[ind+1];
            int twostep = cost[ind] + dp[ind+2];
            dp[ind] =  min(onestep,twostep);
            
        }
        return min(dp[0],dp[1]);
    }
};