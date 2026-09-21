// Memoization
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

// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int j = 0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2;i>=0;i--){
            for(int j = i;j>= 0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};

// Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>front(n,0),curr(n,0);
        for(int j = 0;j<n;j++){
            front[j] = triangle[n-1][j];
        }
        for(int i = n-2;i>=0;i--){
            for(int j = i;j>= 0;j--){
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];
                curr[j] = min(down,diagonal);
            }
            front  = curr;
        }
        return front[0];
    }
};
