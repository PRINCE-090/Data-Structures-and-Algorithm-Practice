class Solution {
  public:
   int mincost (int idx,vector<int>&height,vector<int>&dp){
       if(idx == 0) return 0;
       if(dp[idx] != -1) return dp[idx];
       int left = mincost(idx-1,height,dp) + abs(height[idx] - height[idx-1]);
       int right = INT_MAX;
       if(idx > 1){
           right = mincost(idx-2,height,dp) + abs(height[idx] - height[idx-2]);
       }
       return dp[idx] = min(left,right);
   }
    int minCost(vector<int>& height) {
      int n = height.size();
      vector<int>dp(n+1,-1);
        return mincost(n-1,height,dp);
    }
};

// Tabulation 
class Solution {
  public:
    int minCost(vector<int>& height) {
      int n = height.size();
      vector<int>dp(n+1,-1);
        dp[0] = 0;
        for(int i = 1;i<n;i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i > 1){
                ss = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(fs,ss);
        }
        return dp[n-1];
    }

// Space optimization 

class Solution {
  public:
    int minCost(vector<int>& height) {
      int n = height.size();
      int prev = 0,prev2 = 0;
            for(int i = 1;i<n;i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i > 1){
                ss = prev2 + abs(height[i] - height[i-2]);
            }
            int curr = min(fs,ss);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
};
