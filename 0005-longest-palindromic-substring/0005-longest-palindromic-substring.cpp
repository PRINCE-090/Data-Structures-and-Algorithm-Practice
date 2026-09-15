class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
       int start = 0, maxlen = 1;
        for(int i = 0;i<n;i++){
            int low = i, high = i;
           while(low >= 0 && high < n && s[low] == s[high]){
            int curr_len = high-low+1;
            if(curr_len > maxlen){
            maxlen = curr_len;
            start = low;
            }
            low--;
            high++;
           }
            
            low = i-1, high = i;
           while(low >= 0 && high < n && s[low] == s[high]){
            int curr_len = high-low+1;
            if(curr_len > maxlen){
            maxlen = curr_len;
            start = low;
            }
            low--;
            high++;
           }
        }
        return s.substr(start,maxlen);
    }
};