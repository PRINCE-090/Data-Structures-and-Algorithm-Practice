class Solution {
public:
    int  mod = 1e9+7;
    int findpower(long long value,long long power){
      if(power == 0){
        return 1;
      }
      long long half = findpower(value,power/2);
      long long result = (half*half)%mod;

      if(power%2 == 1){
        result = (result*value)%mod;
      }
      return result;
    }
    int countGoodNumbers(long long n) {
        return  (long long)findpower(5,(n+1)/2) *findpower(4,n/2)%mod;
    }
};