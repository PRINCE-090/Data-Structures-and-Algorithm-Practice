// Memoization 
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

// Tabulation 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up+= dp[i-1][j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left+= dp[i][j-1];
                    else left += 1e9;
                    
                dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

// Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>prev(m,0);
        for(int i = 0;i<n;i++){
            vector<int>curr(m,0);
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up+= prev[j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left+= curr[j-1];
                    else left += 1e9;
                    
                curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};
