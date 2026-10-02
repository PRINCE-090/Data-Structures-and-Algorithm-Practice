class Solution {
public:
   int lcs(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i == 0 || j == 0){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j]; 
    if(s[i-1] == t[j-1]) return 1 + lcs(i-1,j-1,s,t,dp);
    
    return dp[i][j] = max(lcs(i-1,j,s,t,dp),lcs(i,j-1,s,t,dp));
   }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return lcs(n,m,text1,text2,dp);
    }
};