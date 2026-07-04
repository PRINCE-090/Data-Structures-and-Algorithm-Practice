class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      long long total = 0;
      long long   sum  = (n*(n+1))/2;
      for(int num : nums){
        total+=num;
      } 
      int ans = sum - total;

      return ans;
    }
};