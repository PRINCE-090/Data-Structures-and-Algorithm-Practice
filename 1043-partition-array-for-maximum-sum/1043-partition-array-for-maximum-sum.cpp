// Memoization
class Solution {
public:
    int maxSum(int ind,int n,int k,vector<int>&arr,vector<int>&dp){
        if(ind == n) return 0;
        if(dp[ind] != -1)return dp[ind];
        int len = 0, maxi = INT_MIN,maxsum = INT_MIN;
        for(int j = ind;j<min(ind+k,n);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len * maxi + maxSum(j+1,n,k,arr,dp);
            maxsum = max(maxsum,sum);
        }
        return dp[ind] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return maxSum(0,n,k,arr,dp);
    }
};


// Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        for(int ind = n-1;ind>=0;ind--){
            int len = 0, maxi = INT_MIN,maxsum = INT_MIN;
            for(int j = ind;j<min(ind+k,n);j++){
             len++;
             maxi = max(maxi,arr[j]);
             int sum = len * maxi + dp[j+1];
             maxsum = max(maxsum,sum);
            }
         dp[ind] = maxsum;
        }
        return dp[0];
    }
};
