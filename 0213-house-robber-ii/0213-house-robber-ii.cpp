class Solution {
public:
    int maxsum(vector<int>&nums,vector<int>&dp){
       dp[0] = nums[0];
       for(int i = 1;i<nums.size();i++){
        int nottake = dp[i-1];
        int take = nums[i];
        if(i > 1) take = nums[i] + dp[i-2];
        dp[i] = max(take,nottake);
       }
       return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i = 0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1)temp2.push_back(nums[i]);
        }
        int size1 = temp1.size() , size2 = temp2.size();
        vector<int>dp1(size1,-1),dp2(size2,-1);
        return max(maxsum(temp1,dp1),maxsum(temp2,dp2));
    }
};