class Solution {
public:
     bool check(vector<int>&have,vector<int>&need){
        for(int i = 0;i<256;i++){
            if(need[i] > have[i]) return false;
        }
        return true;
     }
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size()) return "";
        vector<int>need(256,0);
        vector<int>have(256,0);
        for(char c : t){
           need[c]++;
        }
        int n = s.size(), minlen = INT_MAX;
        string res = "";
          int left = 0,start = -1;
          for(int right = 0;right <n;right++){
               have[s[right]]++;
               while(check(have,need)){
                  int len = right - left+1;
                  if(len < minlen){
                    minlen = len;
                    start = left;
                  }
                  have[s[left]]--;
                  left++;
               }
          }
          if(minlen == INT_MAX) return "";
        return s.substr(start,minlen);
    }
};