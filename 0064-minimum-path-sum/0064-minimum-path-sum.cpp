class Solution {
public:
 int minpath(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(row == 0 && col == 0) return grid[row][col];
    if(row < 0 || col < 0) return 1e9;
    if(dp[row][col] != -1) return dp[row][col];

    int up = grid[row][col] + minpath(row-1,col,grid,dp);
    int right = grid[row][col] + minpath(row,col-1,grid,dp);
    return dp[row][col] = min(up,right);
 }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minpath(n-1,m-1,grid,dp);
    }
};