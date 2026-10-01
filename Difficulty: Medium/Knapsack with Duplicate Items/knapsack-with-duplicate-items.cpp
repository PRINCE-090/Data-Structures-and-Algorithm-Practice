class Solution {
  public:
     int findmaximum(int idx,int capacity,vector<int>&val, vector<int>& wt,
     vector<vector<int>>&dp){
         if(idx == 0){
             if(wt[idx] <= capacity){
                 return (int(capacity/wt[0])) * val[0];
             }
             return 0;
         }
         if(dp[idx][capacity] != -1) return dp[idx][capacity];
         int notTake = 0 + findmaximum(idx-1,capacity,val,wt,dp);
         int take = INT_MIN;
         if(wt[idx] <= capacity){
             take = val[idx] + findmaximum(idx,capacity-wt[idx],val,wt,dp);
         }
         return dp[idx][capacity] = max(take,notTake);
     }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return findmaximum(n-1,capacity,val,wt,dp);
        
    }
};