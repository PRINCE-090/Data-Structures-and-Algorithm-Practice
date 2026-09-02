class Solution {
public:
      int countall(string s){
        int left = 0, total = 0;
        int n = s.size();
        for(int right = 0;right < n;right++){
            total += (right - left +1);
        }
        return total;
      }
      int countTwo(string s){
        int n = s.size();
        unordered_map<char,int>mp;
        int left = 0, total = 0;
        for(int right = 0;right <n;right++){
            mp[s[right]]++;
            while(left <= right && mp.size() > 2){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            total += (right - left +1);
        }
        return total;
      }
    int numberOfSubstrings(string s) {
        return countall(s) - countTwo(s);
    }
};