class Solution {
  public:
    int floorSqrt(int n) {
        if(n == 0 || n==1) return n;
      long long left = 1,right = n/2;
      int sq = 0;
      while(left <= right){
          long long mid = left+(right-left)/2;
          if(mid*mid == n) return mid;
          else if(mid*mid > n){
              right = mid-1;
          }
          else{
              sq = mid;
              left = mid+1;
          }
      }
      
        return sq;
    }
};
