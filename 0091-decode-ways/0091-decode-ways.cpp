class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        int n = s.size();
        if(n == 1)return 1;
        vector<int>dp(n+1,0);
        dp[n] = 1;
        for(int ind = n-1;ind>= 0;ind--){
             if(s[ind] == '0'){
                dp[ind] = 0;
                continue;
             }
            int ways = dp[ind+1];
           if(ind + 1 < n){
               int two_digit = (s[ind] - '0') * 10 + (s[ind+1] - '0');
               if(two_digit >= 10 && two_digit <= 26){
                  ways += dp[ind+2];
                }
            } 
            dp[ind] = ways;
        }
       return dp[0];
    }
};