class Solution {
  public:
    int maxpoint(int day,int last,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(day == 0){
            int points = 0;
            for(int task = 0;task<3;task++){
                if(task != last){
                    points = max(points,mat[0][task]);
                }
            }
            return points;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int maxpoints = 0;
        for(int task = 0;task<3;task++){
            if(task != last){
                int points = mat[day][task] + maxpoint(day-1,task,mat,dp);
                maxpoints = max(maxpoints,points);
            }
        }
        return dp[day][last] = maxpoints;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return maxpoint(n-1,3,mat,dp);
        
    }
};