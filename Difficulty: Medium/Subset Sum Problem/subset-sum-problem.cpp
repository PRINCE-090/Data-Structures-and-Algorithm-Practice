// Tabulation
class Solution {
  public:
    bool sumequaltoK(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(idx == 0){
            return arr[idx] == target;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        bool notTake = sumequaltoK(idx-1,target,arr,dp);
        bool take = false;
        if(arr[idx] <= target){
            take = sumequaltoK(idx-1,target-arr[idx],arr,dp);
        }
        return dp[idx][target] = notTake | take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return sumequaltoK(n-1,sum,arr,dp);
    }
};

// Tabulation
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int i = 0;i<n;i++) dp[i][0] = true;
        if(arr[0] <= sum) dp[0][arr[0]] = true;
        
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target <= sum;target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target){
                    take = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};

// Space Optimization
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool>prev(sum+1,false),curr(sum+1,false);
        for(int i = 0;i<n;i++) prev[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        prev[0] = true;
        
        for(int ind = 1;ind<n;ind++){
            curr[0] = true;
            for(int target = 1;target <= sum;target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target){
                    take = prev[target-arr[ind]];
                }
                curr[target] = take || notTake;
            }
            prev = curr; 
        }
        return prev[sum];
    }
};
