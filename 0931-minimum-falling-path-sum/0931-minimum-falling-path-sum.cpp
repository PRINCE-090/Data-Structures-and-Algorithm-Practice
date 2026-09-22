class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mini = INT_MAX;
         for(int i = 0;i<m;i++) dp[0][i] = matrix[0][i];
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                int down = matrix[i][j] + dp[i-1][j];

                int ld = matrix[i][j];
                if(j-1 >=0) ld += dp[i-1][j-1];
                else ld+= 1e8;

                int rd = matrix[i][j];
                if(j +1 < m) rd += dp[i-1][j+1];
                else rd += 1e8;

                dp[i][j] = min(down,min(ld,rd));
            }
        }
        for(int j = 0;j<m;j++){
            mini = min(mini,dp[n-1][j]);
        }
        return mini;
    }
};