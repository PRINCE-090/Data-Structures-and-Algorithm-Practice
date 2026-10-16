// Memoization 
class Solution {
public:
    int cost(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind = i;ind <=j;ind++){
            int costs = cuts[j+1] - cuts[i-1] + cost(i,ind-1,cuts,dp) + cost(ind+1,j,cuts,dp);
            mini = min(mini,costs);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int size = cuts.size();
        vector<vector<int>>dp(size+1,vector<int>(size+1,-1));
        return cost(1,size-2,cuts,dp);
    }
};


// Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int size = cuts.size();
        vector<vector<int>>dp(size+2,vector<int>(size+2,0));
        for(int i = size-1;i >= 1;i--){
            for(int j = 1;j<=size-2;j++ ){
            if(i > j) continue;
           int mini = INT_MAX;
          for(int ind = i;ind <=j;ind++){
            int costs = cuts[j+1] - cuts[i-1] + dp[i][ind-1]+ dp[ind+1][j];
            mini = min(mini,costs);
           }
             dp[i][j] = mini;
            }
        }
        return dp[1][size-2];
    }
};
