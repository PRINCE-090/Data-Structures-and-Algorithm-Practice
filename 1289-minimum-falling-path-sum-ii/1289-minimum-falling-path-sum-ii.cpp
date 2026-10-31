class Solution {
public:
    int findmin(int i , int j ,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i == 0) return grid[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int n = grid[0].size();
        int mini = 1e6;
        for(int k = 0;k<n;k++){
            if(k != j){
               mini = min(mini,findmin(i-1,k,grid,dp));
            }
        }
        return dp[i][j] =  grid[i][j] + mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j = 0;j<grid.size();j++){
            mini = min(mini,findmin(n-1,j,grid,dp)); 
        }
        return mini;
    }
};