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