// Memoization
class Solution {
public:
    int minOperations(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]) return minOperations(i-1,j-1,s1,s2,dp);
        return dp[i][j] =  1 + min(minOperations(i-1,j,s1,s2,dp),min(minOperations(i,j-1,s1,s2,dp),
                 minOperations(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return minOperations(n,m,word1,word2,dp);
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<=n;i++) dp[i][0] = i;
        for(int j = 0;j<=m;j++) dp[0][j] = j;

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                }
            }
        }
         return dp[n][m];
    }
};

// Space optimization 
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j = 0;j<=m;j++) prev[j] = j;

        for(int i = 1;i<=n;i++){
            curr[0] = i;
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = prev[j-1];
                }
                else {
                    curr[j] = 1 + min(curr[j-1],min(prev[j-1],prev[j]));
                }
            }
            prev = curr;
        }
         return prev[m];
    }
};
