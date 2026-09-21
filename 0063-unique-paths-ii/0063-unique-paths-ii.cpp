class Solution {
public:
     int paths(int row,int col,vector<vector<int>>&path,vector<vector<int>>&dp){
        if(row >= 0 && col >= 0 && path[row][col] == 1) return 0;
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0 ) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int up = paths(row-1,col,path,dp);
        int left = paths(row,col-1,path,dp);
        return dp[row][col] = up+left;
     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return paths(n-1,m-1,obstacleGrid,dp);
    }
};