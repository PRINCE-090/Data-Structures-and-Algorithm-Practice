class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      int prefixsum = 1;
      int suffixsum = 1,maxsum = INT_MIN;
      for(int i = 0;i<n;i++){
        if(prefixsum == 0) prefixsum = 1;
        if(suffixsum == 0) suffixsum = 1;
        prefixsum *= nums[i];
        suffixsum *= nums[n-i-1];
        maxsum = max(maxsum,max(prefixsum,suffixsum));
      }
      return maxsum;
    }
};