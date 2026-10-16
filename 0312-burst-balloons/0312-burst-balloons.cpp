class Solution {
public:
    int maxcoin(int i,int j,vector<int>&a,vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int maxi = INT_MIN;
        for(int ind = i;ind <=j;ind++){
            int cost = a[i-1] * a[j+1] * a[ind] +maxcoin(i,ind-1,a,dp) + maxcoin(ind+1,j,a,dp);
            maxi  = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return maxcoin(1,n,nums,dp);
    }
};