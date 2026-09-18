// Memoization

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

// tabulation 
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(4,0));
        dp[0][0] = max(mat[0][1],mat[0][2]);
        dp[0][1] = max(mat[0][0],mat[0][2]);
        dp[0][2] = max(mat[0][1],mat[0][0]);
        dp[0][3] = max({mat[0][1],mat[0][2],mat[0][0]});
        
        for(int day = 1;day<n;day++){
            for(int last = 0;last<4;last++){
                dp[day][last] = 0;
                
                for(int task = 0;task<3;task++){
                    if(task!=last){
                        int point = mat[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last],point);
                    }
                }
            }
        }
        
        return dp[n-1][3];
        
    }
};

// Space optimation 
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
       vector<int>prev(4,0);
        prev[0] = max(mat[0][1],mat[0][2]);
        prev[1] = max(mat[0][0],mat[0][2]);
        prev[2] = max(mat[0][1],mat[0][0]);
        prev[3] = max({mat[0][1],mat[0][2],mat[0][0]});
        
        for(int day = 1;day<n;day++){
            vector<int>temp(4,0);
            for(int last = 0;last<4;last++){
                temp[last] = 0;
                
                for(int task = 0;task<3;task++){
                    if(task!=last){
                        temp[last] = max(temp[last],mat[day][task]+prev[task]);
                    }
                }
            }
            prev = temp;
        }
        
        return prev[3];
        
    }
};
