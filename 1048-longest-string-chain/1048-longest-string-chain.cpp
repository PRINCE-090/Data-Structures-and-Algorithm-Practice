class Solution {
public:
    bool checkpossibility(string &s1 , string &s2){
        if(s1.size() != s2.size() +1) return false;
        int first = 0, second = 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    static bool comp(string const &s1,string const &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int maxi = 0;
        int n = words.size();
        vector<int>dp(n+1,1);
        for(int i = 0;i<words.size();i++){
           for(int prev = 0;prev<i;prev++){
              if(checkpossibility(words[i],words[prev]) && dp[i] < 1 + dp[prev]){
                dp[i] = 1 + dp[prev];
              }
           }
           maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};