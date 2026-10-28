class Solution {
public:
    int path(int row,int col,vector<vector<int>>&dp){
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0)return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int up = path(row-1,col,dp);
        int left = path(row,col-1,dp);
        return dp[row][col] = up + left;
    }
    int uniquePaths(int m, int n) {
     vector<int>prev(n,0);
     for(int row = 0;row<m;row++){
        vector<int>curr(n,0);
        for(int col = 0;col<n;col++){
            if(row == 0 && col == 0) curr[col] = 1;
            else {
            int left = 0, up = 0;
            if(row > 0) up = prev[col];
            if(col > 0) left = curr[col-1];
           curr[col] = up + left;
            }
        }
        prev = curr;
     }
     return prev[n-1];
    }
};