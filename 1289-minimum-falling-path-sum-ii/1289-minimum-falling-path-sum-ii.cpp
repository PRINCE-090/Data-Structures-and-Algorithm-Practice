class Solution {
public:
    // int findmin(int i , int j ,vector<vector<int>>&grid,vector<vector<int>>&dp){
    //     if(i == 0) return grid[0][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int n = grid[0].size();
    //     int mini = 1e6;
    //     for(int k = 0;k<n;k++){
    //         if(k != j){
    //            mini = min(mini,findmin(i-1,k,grid,dp));
    //         }
    //     }
    //     return dp[i][j] =  grid[i][j] + mini;
    // }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j = 0;j<n;j++) dp[0][j] = grid[0][j];
    
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
            int mini = 1e6;
                for(int k = 0;k<n;k++){
                  if(k != j){
                    mini = min(mini,dp[i-1][k]);
                   }
                }
                dp[i][j] =  grid[i][j] + mini;
            }
        }
        int minsum = INT_MAX;
        for(int j = 0;j<n;j++){
            minsum = min(minsum,dp[n-1][j]);
        }
        return minsum;
    }
};