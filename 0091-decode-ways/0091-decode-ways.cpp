class Solution {
public:
    int solve(int ind,int n,string &s,vector<int>&dp){
        if(ind == n)return 1;
        if(s[ind] == '0')return 0;
        if(dp[ind] != -1) return dp[ind];
        int ways = solve(ind+1,n,s,dp);
        if(ind + 1 < n){
            int two_digit = (s[ind] - '0') * 10 + (s[ind+1] - '0');
            if(two_digit >= 10 && two_digit <= 26){
                ways += solve(ind+2,n,s,dp);
            }
        } 
        return dp[ind] = ways;
    }
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        int n = s.size();
        if(n == 1)return 1;
        vector<int>dp(n+1,0);
        dp[n] = 1;
        for(int ind = n-1;ind>= 0;ind--){
            int ways = solve(ind+1,n,s,dp);
           if(ind + 1 < n){
               int two_digit = (s[ind] - '0') * 10 + (s[ind+1] - '0');
               if(two_digit >= 10 && two_digit <= 26){
                  ways += solve(ind+2,n,s,dp);
                }
            } 
            dp[ind] = ways;
        }
       return dp[0];
    }
};