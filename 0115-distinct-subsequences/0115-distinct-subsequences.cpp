// memoization 
class Solution {
public:
    int total(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == t[j-1]){
            return total(i-1,j-1,s,t,dp) + total(i-1,j,s,t,dp);
        }
        return total(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return total(n,m,s,t,dp);
    }
};

// tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i = 0;i<=n;i++) dp[i][0] = 1;

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};


// using one array 
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double>dp(m+1,0);
       dp[0] = 1;

        for(int i = 1;i<=n;i++){
            for(int j = m;j>=1;j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j] + dp[j-1];
                }
            }
        }
        return (int)dp[m];
    }
};
