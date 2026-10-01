class Solution {
  public:
    int maxvalue(int idx,int n,vector<int>&price,vector<vector<int>>&dp){
        if(idx == 0){
            return n * price[0];
        }
        if(dp[idx][n] != -1) return dp[idx][n];
        int  notTake = 0 + maxvalue(idx-1,n,price,dp);
        int take = INT_MIN;
        int rodlength = idx+1;
        if(rodlength <= n){
            take = price[idx] + maxvalue(idx,n-rodlength,price,dp);
        }
        return dp[idx][n] = max(take,notTake);
        
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return maxvalue(n-1,n,price,dp);
        
    }
};

// Tabualtion
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int N = price.size();
        vector<vector<int>>dp(N,vector<int>(N+1,0));
        for(int i = 0;i<=N;i++){
            dp[0][i] = i * price[0];
        }
        for(int idx = 1;idx<N;idx++){
            for(int n = 0;n<=N;n++){
                 int  notTake = 0 + dp[idx-1][n];
                 int take = INT_MIN;
                 int rodlength = idx+1;
                 if(rodlength <= n){
                   take = price[idx] + dp[idx][n-rodlength];
                  }
                   dp[idx][n] = max(take,notTake);
            }
        }
        return dp[N-1][N];
        
    }
};


// one array space optimization

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int N = price.size();
        vector<int>prev(N+1,0);
        for(int i = 0;i<=N;i++){
            prev[i] = i * price[0];
        }
        for(int idx = 1;idx<N;idx++){
            for(int n = 0;n<=N;n++){
                 int  notTake = 0 + prev[n];
                 int take = INT_MIN;
                 int rodlength = idx+1;
                 if(rodlength <= n){
                   take = price[idx] + prev[n-rodlength];
                  }
                   prev[n] = max(take,notTake);
            }
        }
        return prev[N];
        
    }
};

