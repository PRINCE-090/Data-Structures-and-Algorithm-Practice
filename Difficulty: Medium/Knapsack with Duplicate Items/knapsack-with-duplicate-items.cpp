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


// Tabulation 
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int cap) {
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(cap+1,0));
        for(int i = 0;i<=cap;i++){
            dp[0][i] = (i/wt[0])*val[0];
        }
        for(int idx = 1;idx<n;idx++){
            for(int capacity = 0;capacity<=cap;capacity++){
                int notTake = 0 + dp[idx-1][capacity];
                int take = INT_MIN;
                if(wt[idx] <= capacity){
                 take = val[idx] + dp[idx][capacity-wt[idx]];
                }
                dp[idx][capacity] = max(take,notTake);
            }
        }
        return dp[n-1][cap];
        
    }
};

// SPACE OPTIMIZATION USING 2 ARRAYS 
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int cap) {
        int n = wt.size();
        vector<int>prev(cap+1,0),curr(cap+1,0);
        for(int i = 0;i<=cap;i++){
            prev[i] = (i/wt[0])*val[0];
        }
        for(int idx = 1;idx<n;idx++){
            for(int capacity = 0;capacity<=cap;capacity++){
                int notTake = 0 + prev[capacity];
                int take = INT_MIN;
                if(wt[idx] <= capacity){
                 take = val[idx] + curr[capacity-wt[idx]];
                }
                curr[capacity] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[cap];
        
    }
};

// USING ONE ARRAY 

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int cap) {
        int n = wt.size();
        vector<int>prev(cap+1,0);
        for(int i = 0;i<=cap;i++){
            prev[i] = (i/wt[0])*val[0];
        }
        for(int idx = 1;idx<n;idx++){
            for(int capacity = 0;capacity<=cap;capacity++){
                int notTake = 0 + prev[capacity];
                int take = INT_MIN;
                if(wt[idx] <= capacity){
                 take = val[idx] + prev[capacity-wt[idx]];
                }
                prev[capacity] = max(take,notTake);
            }
        }
        return prev[cap];
        
    }
};
