// Memoization 
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

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take,notTake);
        }
        return dp[n-1];
    }
};


// Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0, prev = nums[0];
        for(int i = 1;i<n;i++){
            int take = nums[i] + prev2;
            int notTake = prev;

            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
