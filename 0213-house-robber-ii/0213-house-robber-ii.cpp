class Solution {
public:
    int maxsum(int ind,vector<int>&nums,vector<int>&dp){
        if(ind < 0) return 0;
       if(ind  == 0) return nums[ind];
       if(dp[ind] != -1)return dp[ind];
       int nottake = maxsum(ind-1,nums,dp);
       int take = INT_MIN;
       if(ind >= 1){
        take = nums[ind]+ maxsum(ind-2,nums,dp);
       }
       return dp[ind] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i = 0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1)temp2.push_back(nums[i]);
        }
        int size1 = temp1.size(), size2 = temp2.size();
        vector<int>dp1(size1,-1),dp2(size2,-1);
        return max(maxsum(size1-1,temp1,dp1),maxsum(size2-1,temp2,dp2));
    }
};