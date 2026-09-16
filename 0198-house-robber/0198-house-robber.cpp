class Solution {
public:
    int maxmoney(int idx,vector<int>&nums,vector<int>&dp){
        if(idx < 0) return 0;
        if(idx == 0) return nums[idx];
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + maxmoney(idx-2,nums,dp);
        int notTake = 0 + maxmoney(idx-1,nums,dp);
        
        return dp[idx] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return maxmoney(n-1,nums,dp);
    }
};