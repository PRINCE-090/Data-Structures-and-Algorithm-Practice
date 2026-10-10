// Memoization & Tabulation 
class Solution {
public:
    int findlength(int ind,int prev_ind,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        int len = 0 + findlength(ind+1,prev_ind,n,nums,dp);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len , 1+findlength(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
         
        for(int ind = n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>= -1;prev_ind--){
                int len = 0 + dp[ind+1][prev_ind+1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len , 1+dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1] = len;
            }
        }
        return dp[0][0];
    }
};

// Space optimization -2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 0;
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i],1+dp[prev]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};

// Binary search Optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 0;i<n;i++){
            if(nums[i] > temp.back()){
                len++;
                temp.push_back(nums[i]);
            }
            else{
             *lower_bound(temp.begin(),temp.end(),nums[i]) = nums[i];
                
            }
        }
        return len;
    }
};
