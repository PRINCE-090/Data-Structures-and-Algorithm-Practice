class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char,int>mp;
        int left = 0, maxlength = -1;
        for(int right = 0;right<n;right++){
            mp[s[right]]++;
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            if(mp.size() == k){
              maxlength = max(maxlength,(right - left +1));
            }
            
        }
        return maxlength;
        
    }
};