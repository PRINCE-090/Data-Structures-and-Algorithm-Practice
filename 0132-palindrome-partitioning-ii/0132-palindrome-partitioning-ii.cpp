// Memoization
class Solution {
public:
    bool ispalindrome(int i,int j,string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int cuts(int i,int n,string &s,vector<int>&dp){
        if(i == n)return 0;
        if(dp[i] != -1) return dp[i];
        int min_cost = 1e9;
        for(int j = i;j<n;j++){
            if(ispalindrome(i,j,s)){
              int cost = 1 + cuts(j+1,n,s,dp);
                min_cost = min(min_cost,cost);
            }
        }
        return dp[i] = min_cost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return cuts(0,n,s,dp)-1;
    }
};


// Tabulation
class Solution {
public:
    bool ispalindrome(int i,int j,string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        for(int i = n-1;i>=0;i--){
            int min_cost = INT_MAX;
            for(int j = i;j<n;j++){
               if(ispalindrome(i,j,s)){
                 int cost = 1 + dp[j+1];
                  min_cost = min(min_cost,cost);
                }
           }
          dp[i] = min_cost;
        }
        return dp[0]-1;
    }
};
