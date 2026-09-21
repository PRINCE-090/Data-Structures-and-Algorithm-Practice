class Solution {
public:
     int minpathsum(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp,int n){
        if(row == n-1) return grid[row][col];
        if(dp[row][col] != -1e9) return dp[row][col];

        int down = grid[row][col] + minpathsum(row + 1,col,grid,dp,n);
        int diagonal = grid[row][col] + minpathsum(row + 1, col + 1 ,grid,dp,n);
        return dp[row][col] = min(down,diagonal);
     }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        return minpathsum(0,0,triangle,dp,n);
    }
};