class Solution {
  public:
       bool palindrome(int left,int right,string s){
           while(left <= right){
               if(s[left] != s[right]){
                   return false;
               }
               left++;
               right--;
           }
           return true;
       }
    int partion(int i,string &s,int n,vector<int>&dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mincost = INT_MAX;
        for(int j = i;j<n;j++){
            if(palindrome(i,j,s)){
                int cost = 1+partion(j+1,s,n,dp);
                mincost = min(mincost,cost);
            }
        }
        return dp[i] = mincost;
    }
    int palPartition(string &s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return partion(0,s,n,dp)-1;
    }
};