class Solution {
public:
    bool isPalindrome(int x) {
        long long n = x;
        long long newNo = 0;
        while(n > 0){
          newNo = newNo*10;
          newNo += n%10;
          n = n/10;
        }
        return x == newNo;
    }
};