class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxseq = 0;
        vector<int>dp(n,1),cnt(n,1);
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            maxseq = max(maxseq,dp[i]);
        }
        int total = 0;
        for(int i = 0;i<n;i++){
            if(maxseq == dp[i])
            total += cnt[i];
        }
        return total;
    }
};