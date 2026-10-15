class Solution {
  public:
   int mincost(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
       if(i == j) return 0;
       if(dp[i][j] != -1) return dp[i][j];
       int mini = 1e9;
       for(int k = i;k<j;k++){
           int steps = arr[i-1] * arr[k] * arr[j] + mincost(i,k,arr,dp) + 
           mincost(k+1,j,arr,dp);
           
           if(steps < mini) mini = steps;
       }
       return dp[i][j] = mini;
   }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return mincost(1,n-1,arr,dp);
    }
};