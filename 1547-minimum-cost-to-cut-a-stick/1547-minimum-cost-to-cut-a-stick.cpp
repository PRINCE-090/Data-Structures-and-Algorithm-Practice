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