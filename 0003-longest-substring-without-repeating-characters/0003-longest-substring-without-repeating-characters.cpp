class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>mp;
       int n = s.size();
       int left = 0,ans = 0;
       for(int right = 0;right<n;right++){
          while(mp.find(s[right]) != mp.end()){
             mp.erase(s[left]);
             left++;
          }
         ans = max(ans,right-left+1);
          mp[s[right]]++;
       }
       return ans;
    }
};