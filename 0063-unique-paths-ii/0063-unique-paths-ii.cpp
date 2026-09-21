// Memoization 
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

// Tabulation 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

// Space Optimization 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int>prev(m,0);
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        for(int i = 0;i<n;i++){
            vector<int>curr(m,0);
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};
