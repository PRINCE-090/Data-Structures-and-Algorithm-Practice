class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totalsum = 0;
        for(int i = 0;i<n;i++) totalsum += arr[i];
        int k = totalsum;
        vector<vector<bool>>dp(n,vector<bool>(k+1,0));
        for(int i = 0;i<n;i++) dp[i][0] = true;
        if(arr[0] <=k ) dp[0][arr[0]] = true;
        
        for(int ind = 1;ind < n ;ind++){
            for(int target = 1;target <= k;target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target){
                    take = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = take | notTake;
            }
        }
        int mini = 1e8;
        for(int i = 0;i<=totalsum/2;i++){
            if(dp[n-1][i] == true){
                mini = min(mini,abs(totalsum - i) - i);
            }
        }
        return mini;
        
    }
};
