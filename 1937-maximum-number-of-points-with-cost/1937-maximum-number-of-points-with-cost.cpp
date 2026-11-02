class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long>dp(m);
        for(int j = 0;j<m;j++){
           dp[j] = points[0][j];
        }
       for(int i = 1;i<n;i++){
           vector<long long>left(m) , right(m),curr(m);
           left[0] = dp[0];
           for(int j = 1;j<m;j++){
            left[j] = max(left[j-1]-1,dp[j]);
           }
           right[m-1] = dp[m-1];
           for(int j = m-2;j>=0;j--){
            right[j] = max(right[j+1]-1,dp[j]);
           }
           for(int j = 0;j<m;j++){
            curr[j] = points[i][j] + max(left[j],right[j]);
           }
           dp = curr;
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};