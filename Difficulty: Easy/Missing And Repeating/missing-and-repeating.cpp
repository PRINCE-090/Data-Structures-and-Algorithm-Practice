class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n = arr.size();
      long long s =0, sn =0, s2 =0, s2n = 0;
      long long x = 0, y = 0;
      sn = 1LL*n*(n+1)/2;
      s2n = 1LL*n*(n+1)*(2LL*n+1)/6;
      for(int num : arr){
          s += num;
          s2 += (long long)num* (long long)num;
      }
      long long val1 = s - sn;
      long long val2 = s2 - s2n;
      val2 = val2/val1;
      
      x = (val1+val2)/2;
      y = val2 - x;
      
      return {(int)x,(int)y};
    }
};