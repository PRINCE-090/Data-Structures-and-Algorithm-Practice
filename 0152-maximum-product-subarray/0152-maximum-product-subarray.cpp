class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct = nums[0], minproduct = nums[0];
        int res = nums[0];
        for(int i = 1;i<nums.size();i++){
           int a = nums[i];
           int b = nums[i]*maxproduct;
           int c = nums[i]*minproduct;
            maxproduct = max(a,max(b,c));
            minproduct = min(a,min(b,c));
            res = max(res,max(maxproduct,minproduct));
        }
        return res;
    }
};


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
