class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        int n = s.size();
        if(n == 1)return 1;
        int prev2 = 1, prev = 1;
        for(int ind = n-1;ind>= 0;ind--){
            int ways = 0;
             if(s[ind] == '0'){
                prev2 = prev;
                prev = 0;
                continue;
             }
             ways = prev;
           if(ind + 1 < n){
               int two_digit = (s[ind] - '0') * 10 + (s[ind+1] - '0');
               if(two_digit >= 10 && two_digit <= 26){
                  ways += prev2;
                }
            } 
            prev2 = prev;
            prev = ways;
            
        }
       return prev;
    }
};